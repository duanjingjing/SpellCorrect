/*************************************************************************
	> File Name: EchoServer.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 08:19:01 AM PDT
 ************************************************************************/
#include "ChatServer.h"
using namespace std;
using namespace std::placeholders;

ChatServer::ChatServer(const InetAddress &addr)
	:server_(addr){
		server_.setConnection(bind(&ChatServer::onConnection,this,_1));
		server_.setMessage(bind(&ChatServer::onMessage,this,_1));
		server_.setClose(bind(&ChatServer::onClose,this,_1));
}

void ChatServer::start(){
	server_.start();
}

void ChatServer::onConnection(const TcpConnectionPtr &conn){
	//限制并发连接
	if(clients_.size()>=kMaxClients){
		conn->send("Chat Server is full,please Try later...\r\n");
		conn->shutdown();
		return;
	}

	clients_.insert(conn);
	conn->send("welcome to Chat server...\r\n");
}

void ChatServer::onMessage(const TcpConnectionPtr &conn){
	string s(conn->receive());
	for(set<TcpConnectionPtr>::iterator it=clients_.begin();
			it!=clients_.end();it++){
		(*it)->send(s);
	}
}

void ChatServer::onClose(const TcpConnectionPtr &conn){
	clients_.erase(conn);
	conn->shutdown();
}



