/*************************************************************************
	> File Name: EchoServer.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 07:47:33 AM PDT
 ************************************************************************/

#ifndef ECHO_TCP_SERVER_H
#define ECHO_TCP_SERVER_H

#include <echo/TcpServer.h>
#include <echo/NonCopyable.h>

class EchoServer:NonCopyable{
public:
	EchoServer(const InetAddress &addr);
	void start();
private:
	void onConnection(const TcpConnectionPtr &conn);
	void onMessage(const TcpConnectionPtr &conn);
	void onClose(const TcpConnectionPtr &conn);

	TcpServer server_;
};



#endif
