/*************************************************************************
	> File Name: MutexLock.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 05:47:22 AM PDT
 ************************************************************************/

#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H

#include <pthread.h>
#include <assert.h>
#include "NonCopyable.h"

class MutexLock:private NonCopyable{
public:
	friend class MutexLockGuard;
	MutexLock();
	~MutexLock();

	pthread_mutex_t *getMutexPtr() {return &mutex_;}
	bool isLocked() const {return isLocked_;} 
private:
	void lock();
	void unlock();

	pthread_mutex_t mutex_;
	bool isLocked_;
};

inline MutexLock::MutexLock():isLocked_(false){
	pthread_mutex_init(&mutex_,NULL);
}

inline MutexLock::~MutexLock(){
	assert(isLocked_==false);
	pthread_mutex_destroy(&mutex_);
}

void MutexLock::lock(){
	pthread_mutex_lock(&mutex_);
	isLocked_=true;
}

void MutexLock::unlock(){
	pthread_mutex_unlock(&mutex_);
	isLocked_=false;
}

class MutexLockGuard{
public:
	MutexLockGuard(MutexLock &mutex):mutex_(mutex){
		mutex_.lock();
	}

	~MutexLockGuard(){
		mutex_.unlock();
	}
private:
	MutexLock &mutex_;
};







#endif
