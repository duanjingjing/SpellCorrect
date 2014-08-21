/*************************************************************************
	> File Name: PollPoller.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 11:28:41 PM PDT
 ************************************************************************/

#ifndef POLL_POLLER_H
#define POLL_POLLER_H


#include "NonCopyable.h"
#include "TcpConnection.h"
#include <map>
#include <functional>
#include <poll.h>

class PollPoller:private NonCopyable{
public:
	typedef TcpConnection::TcpConnectionCallback PollerCallback;

	explicit PollPoller(int listenfd);
	~PollPoller();

	void poll();
	void handleAccept();
	void handleData();

	void handleConnectionEvent(int peerfd);
	void handleMessageEvent(int peerfd);
	void handleCloseEvent(int peerfd);

	void processConnection(const TcpConnectionPtr& conn){
		conn->handleConnection();
	}
	void processMessage(const TcpConnectionPtr& conn){
		conn->handleMessage();
	}
	void processClose(const TcpConnectionPtr & conn){
		conn->handleClose();
	}

	void setConnectionCallback(const PollerCallback &cb){
		onConnectionCallback_=cb;
	}
	void setMessageCallback(const PollerCallback &cb){
		onMessageCallback_=cb;
	}
	void setCloseCallback(const PollerCallback &cb){
		onCloseCallback_=cb;
	}

private:
	struct pollfd event_[2048];
	int listenfd_;
	int maxi_;
	int nready_;
	std::map<int,TcpConnectionPtr> lists_;

	PollerCallback onConnectionCallback_;
	PollerCallback onMessageCallback_;
	PollerCallback onCloseCallback_;

	typedef std::map<int,TcpConnectionPtr>::iterator TcpIterator;
    
};









#endif
