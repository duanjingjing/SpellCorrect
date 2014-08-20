/*************************************************************************
	> File Name: Thread.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 02:28:48 AM PDT
 ************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include "NonCopyable.h"
#include <pthread.h>
#include <functional>

class Thread:private NonCopyable{
public:
	typedef std::function<void()> ThreadFunc;

	Thread();
	explicit Thread(const ThreadFunc& callback);
	~Thread();

	void setCallback(const ThreadFunc &cb);
	void start();
	void join();

private:
	static void* threadFunc(void *);
	pthread_t tid_;
	bool isStarted_;
	ThreadFunc callback_;
};

#endif
