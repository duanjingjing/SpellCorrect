/*************************************************************************
	> File Name: Socket.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 07:44:39 PM PDT
 ************************************************************************/

#ifndef SOCKET_H
#define SOCKET_H

#include "NonCopyable.h"
#include "InetAddress.h"

class Socket:private NonCopyable{
public:
	explicit Socket(int sockfd);
	~Socket();

	int fd() const{return sockfd_;}
	void bindAddress(const InetAddress &addr);
	int accept();
    void listen();
	void shutdownWrite();
	void setReusePort();
private:
	const int sockfd_;
};

#endif
