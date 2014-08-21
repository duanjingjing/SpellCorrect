/*************************************************************************
	> File Name: TcpConnection.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 08:10:25 PM PDT
 ************************************************************************/

#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "NonCopyable.h"
#include "InetAddress.h"
#include "Socket.h"
#include "Rio.h"
#include <string>
#include <functional>
#include <memory>

class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection:private NonCopyable,
	                 public std::enable_shared_from_this<TcpConnection>{
public:
	typedef std::function<void (const TcpConnectionPtr&)> TcpConnectionCallback;
    TcpConnection(int sockfd,const InetAddress& localaddr,const InetAddress& peeraddr);
	~TcpConnection();

	int fd() const{
		return sockfd_.fd();
	}

	ssize_t readn(char *usrbuf,size_t n);
	ssize_t readLine(char *usrbuf,size_t maxlen);
	ssize_t writen(const char* usrbuf,size_t n);
	void send(const std::string &s);
	std::string receive();
	void shutdown();

	void setConnectionCallback(const TcpConnectionCallback &cb){
		onConnectionCallback_=cb;
	}
	void setMessageCallback(const TcpConnectionCallback &cb){
		onMessageCallback_=cb;
	}
	void setCloseCallback(const TcpConnectionCallback &cb){
		onCloseCallback_=cb;
	}

	void handleConnection();
	void handleMessage();
	void handleClose();

	const InetAddress &getLocalAddr() const{
		return localAddr_;
	}

	const InetAddress &getPeerAddr() const{
		return peerAddr_;
	}

private:
	Socket sockfd_;
	Rio buffer_;

	const InetAddress localAddr_;//Local
	const InetAddress peerAddr_;

	TcpConnectionCallback onConnectionCallback_;
	TcpConnectionCallback onMessageCallback_;
	TcpConnectionCallback onCloseCallback_;
};


#endif
