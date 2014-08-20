/*************************************************************************
	> File Name: Condition.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 01:18:55 AM PDT
 ************************************************************************/

#ifndef CONDITION_H
#define CONDITION_H


#include <pthread.h>

class MutexLock;

class Condition{
public:
	Condition(MutexLock &lock);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

private:
	pthread_cond_t cond_;
	MutexLock &lock_;
};








#endif
