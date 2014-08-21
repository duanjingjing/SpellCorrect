/*************************************************************************
	> File Name: InetAddress.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 08:00:18 PM PDT
 ************************************************************************/

#include "InetAddress.h"

#define ERR_EXIT(m) \
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

InetAddress::InetAddress(uint16_t port){
	::memset(&addr_,0,sizeof(addr_));
	addr_.sin_family=AF_INET;
	addr_.sin_addr.s_addr=INADDR_ANY;
	addr_.sin_port=::htons(port);
}

InetAddress::InetAddress(const struct sockaddr_in &addr)
	:addr_(addr){
}

std::string InetAddress::toIp() const{
	return std::string(inet_ntoa(addr_.sin_addr));
}

uint16_t InetAddress::toPort() const{
	return ntohs(addr_.sin_port);
}

InetAddress InetAddress::getLocalAddress(int sockfd){
	struct sockaddr_in addr;
	socklen_t len=sizeof(addr);

	if(::getsockname(sockfd,(SA*)&addr,&len)==-1)
		ERR_EXIT("getsockname");
	return InetAddress(addr);
}

InetAddress InetAddress::getPeerAddress(int sockfd){
	struct sockaddr_in addr;
	socklen_t len=sizeof(addr);
	if(::getpeername(sockfd,(SA*)&addr,&len)==-1)
		ERR_EXIT("getpeername");
	return InetAddress(addr);
}
