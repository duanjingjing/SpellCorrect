/*************************************************************************
	> File Name: TcpConnection.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 11:12:49 PM PDT
 ************************************************************************/

#include "TcpConnection.h"
using namespace std;

#define ERR_EXIT(m) \
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

TcpConnection::TcpConnection(int sockfd,const InetAddress &localAddr,const InetAddress &peerAddr):sockfd_(sockfd),
buffer_(sockfd),localAddr_(localAddr),peerAddr_(peerAddr){

}

TcpConnection::~TcpConnection(){
	shutdown();
}

ssize_t TcpConnection::readn(char *usrbuf,size_t n){
	int nread=buffer_.readn(usrbuf,n);
	if(nread==-1)
		ERR_EXIT("nread");
	return nread;
}

ssize_t TcpConnection::readLine(char *usrbuf,size_t n){
	int nread=buffer_.readline(usrbuf,n);
	if(nread==-1)
		ERR_EXIT("readline");
	return nread;
}

ssize_t TcpConnection::writen(const char* usrbuf,size_t n){
	int nread=buffer_.writen(usrbuf,n);
	if(nread==-1)
		ERR_EXIT("nread");
	return nread;
}

void TcpConnection::send(const std::string &s){
	writen(s.c_str(),s.size());
}

string  TcpConnection::receive(){
	char buf[1024];
	readLine(buf,1024);
    return string(buf);
}

void TcpConnection::shutdown(){
	sockfd_.shutdownWrite();
}

void TcpConnection::handleConnection(){
	if(onConnectionCallback_)
		onConnectionCallback_(shared_from_this());
}

void TcpConnection::handleMessage(){
	if(onMessageCallback_)
		onMessageCallback_(shared_from_this());
}

void TcpConnection::handleClose(){
	if(onCloseCallback_)
		onCloseCallback_(shared_from_this());
}
