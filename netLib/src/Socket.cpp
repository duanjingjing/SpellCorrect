/*************************************************************************
	> File Name: Socket.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 07:46:54 PM PDT
 ************************************************************************/

#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define ERR_EXIT(m) \
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)


Socket::Socket(int sockfd):sockfd_(sockfd){
}

Socket::~Socket(){
	::close(sockfd_);
}

void Socket::bindAddress(const InetAddress& addr){
	if(::bind(sockfd_,(SA*)addr.getSockAddrInet(),sizeof(struct sockaddr_in))==-1)
		ERR_EXIT("bind");
}

void Socket::listen(){
	if(::listen(sockfd_,SOMAXCONN)==-1)
		ERR_EXIT("listen");
}

int  Socket::accept(){
	int peerfd;
	if((peerfd=::accept(sockfd_,NULL,NULL))==-1){
		ERR_EXIT("accept");
	}

	return peerfd;
}

void Socket::shutdownWrite(){
	::shutdown(sockfd_,SHUT_WR);
}

void Socket::setReusePort(){
	int on=1;
	if(::setsockopt(sockfd_,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))==-1){
		ERR_EXIT("setsockopt");
	}
}
