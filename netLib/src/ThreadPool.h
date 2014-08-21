/*************************************************************************
	> File Name: ThreadPool.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 05:10:49 AM PDT
 ************************************************************************/

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "NonCopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
#include <functional>
#include <memory>
#include <vector>

class Thread;

class ThreadPool:private NonCopyable{
public:
	typedef std::function<void ()> Task;
	ThreadPool(size_t queueSize,size_t poolSize);
	~ThreadPool();

	void start();
	void stop();

	void addTask(const Task&);
private:
	Task getTask();
	void runInThread();

	mutable MutexLock mutex_;
	Condition empty_;
	Condition full_;
	size_t queueSize_;
	std::queue<Task> queue_;
	size_t poolSize_;

	std::vector<std::unique_ptr<Thread> >threads_;
    bool isStarted_;//线程池是否开启
};



#endif
