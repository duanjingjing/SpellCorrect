/*************************************************************************
	> File Name: Thread.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 06:04:55 AM PDT
 ************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include "NonCopyable.h"
#include <functional>
#include <pthread.h>

class Thread:private NonCopyable{
public:
	typedef std::function<void ()> ThreadFunc;
	Thread();
	explicit Thread(const ThreadFunc &callback);
	~Thread();

	void setCallback(const ThreadFunc &cb);
	void start();
	void join();
private:
	static void* threadFunc(void *arg);
	pthread_t tid_;
	bool isStarted_;
	ThreadFunc callback_;
};


#endif
