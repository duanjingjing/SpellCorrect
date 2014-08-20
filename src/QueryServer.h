#ifndef QUERY_SERVER_H
#define QUERY_SERVER_H


#include <echo/TcpServer.h>
#include <echo/ThreadPool.h>
#include <echo/NonCopyable.h>
#include "TextQuery.h"
#include "WordIndex.h"
#include "Configure2.h"

class QueryServer:NonCopyable{
public:
	QueryServer(const InetAddress &addr,WordIndex & word);
	void start();
private:
	void onConnection(const TcpConnectionPtr &conn);
	void onMessage(const TcpConnectionPtr &conn);
//    void onClose(const TcpConnectionPtr &conn);

	void runQuery(const std::string& s,const TcpConnectionPtr& conn);
	TcpServer server_;
	TextQuery query_;
	ThreadPool pool_;
};







#endif
