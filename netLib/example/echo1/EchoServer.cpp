/*************************************************************************
	> File Name: EchoServer.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 07:49:57 AM PDT
 ************************************************************************/

#include "EchoServer.h"
#include<iostream>
#include <string>
using namespace std;
using namespace placeholders;

EchoServer::EchoServer(const InetAddress &addr)
	:server_(addr){
		server_.setConnection(bind(&EchoServer::onConnection,this,_1));
		server_.setMessage(bind(&EchoServer::onMessage,this,_1));
		server_.setClose(bind(&EchoServer::onClose,this,_1));
}

void EchoServer::start(){
	server_.start();
}

void EchoServer::onConnection(const TcpConnectionPtr &conn){
	cout<<conn->getPeerAddr().toIp()<<" port: "
		<<conn->getPeerAddr().toPort()<<endl;
	conn->send("hello,welcome to Echo Server!!!\r\n");
}

void EchoServer::onMessage(const TcpConnectionPtr &conn){
	string s(conn->receive());
	conn->send(s);
}

void EchoServer::onClose(const TcpConnectionPtr &conn){
	cout<<conn->getPeerAddr().toIp()<<" port: "
		<<conn->getPeerAddr().toPort()<< "close"<<endl;
	conn->shutdown();
}



