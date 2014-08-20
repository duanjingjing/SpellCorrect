#include "QueryServer.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
using namespace placeholders;

QueryServer::QueryServer(const InetAddress &addr,WordIndex &word):server_(addr),
	query_(word),
	pool_(1000,4){
	server_.setConnection(bind(&QueryServer::onConnection,this,_1));
    server_.setMessage(bind(&QueryServer::onMessage,this,_1));
}

void QueryServer::start(){
	//
	pool_.start();
	server_.start();
}

void QueryServer::onConnection(const TcpConnectionPtr &conn){
	cout<<conn->getPeerAddr().toIp()<<" port:"
		<<conn->getPeerAddr().toPort()<<endl;
	conn->send("hello,welcome to QueryServer! please input word:\n");
}

void QueryServer::onMessage(const TcpConnectionPtr& conn){
	string word(conn->receive());
	pool_.addTask(bind(&QueryServer::runQuery,this,word,conn));
}

/*
void QueryServer::onClose(const TcpConnectionPtr &conn){
	cout<<conn->getPeerAddr().toIp()<<" port: "
		<<conn->getPeerAddr().toPort()<<"Close"<<endl;
	conn->shutdown();
}
*/

void QueryServer::runQuery(const string& s,const TcpConnectionPtr& conn){
	string word=s;
	if(word.substr(word.size()-1,2)=="\r\n"){
		word.erase(word.size()-1);
		word.erase(word.size()-1);
	}

	string res=query_.run_query(word);
	conn->send(res+"\r\n");
}



