/*************************************************************************
	> File Name: TcpServer.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 05:56:25 AM PDT
 ************************************************************************/
#include "TcpServer.h"
#include "Socket.h"
#include "PollPoller.h"
#include <functional>
#include <signal.h>
#include<iostream>
using namespace std;
using namespace std::placeholders;

#define ERR_EXIT(m) \
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

class IgnoreSigpipe{
public:
	IgnoreSigpipe(){
		if(::signal(SIGPIPE,SIG_IGN)==SIG_ERR){
			ERR_EXIT("signal");
		}
	}
};

IgnoreSigpipe initObj;//全局对象，系统初始化必然处理SIGPIPE

TcpServer::TcpServer(const InetAddress &addr){
	int sockfd=::socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		ERR_EXIT("socket");
	}

	sock_.reset(new Socket(sockfd));
	sock_->setReusePort();
	sock_->bindAddress(addr);
	sock_->listen();
}

void TcpServer::start(){
	poller_.reset(new PollPoller(sock_->fd()));
	poller_->setConnectionCallback(onConnect_);
	poller_->setMessageCallback(onMessage_);
	poller_->setCloseCallback(onClose_);

	while(1){
		poller_->poll();
		poller_->handleAccept();
		poller_->handleData();
	}
}

