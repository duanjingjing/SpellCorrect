/*************************************************************************
	> File Name: MutexLock.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Mon 18 Aug 2014 02:26:05 AM PDT
 ************************************************************************/

#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H


#include <pthread.h>
#include <stdexcept>
#include "NonCopyable.h"

class MutexLock:private NonCopyable{
public:
	MutexLock(){
		if(pthread_mutex_init(&lock_,NULL)){
			throw std::runtime_error("mutex init error!");
		}
	}

	~MutexLock(){
		if(pthread_mutex_destroy(&lock_)){
			throw std::runtime_error("mutex destroy error!");
		}
	}

	void lock(){
		if(pthread_mutex_lock(&lock_)){
			throw std::runtime_error("mutex lock error");
		}
	}

	void unlock(){
		if(pthread_mutex_unlock(&lock_)){
			throw std::runtime_error("mutex unlock error!");
		}
	}

	pthread_mutex_t *getMutexPtr(){
		return &lock_;
	}


private:
	pthread_mutex_t lock_;

};











#endif
