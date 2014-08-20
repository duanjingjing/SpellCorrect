/*************************************************************************
	> File Name: Condition.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 01:21:02 AM PDT
 ************************************************************************/

#include "Condition.h"
#include "MutexLock.h"
#include <stdexcept>
#include <assert.h>

Condition::Condition(MutexLock &lock):lock_(lock){
	if(pthread_cond_init(&cond_,NULL)){
		throw std::runtime_error("cond init error!\n");
	}
}

Condition::~Condition(){
	if(pthread_cond_destroy(&cond_)){
		throw std::runtime_error("cond destroy error!\n");
	}
}

void Condition::wait(){
    if(pthread_cond_wait(&cond_,lock_.getMutexPtr())){
		throw std::runtime_error("wait cond error!\n");
	}
}

void Condition::notify(){
	if(pthread_cond_signal(&cond_)){
		throw std::runtime_error("signal error!\n");
	}
}

void Condition::notifyAll(){
	if(pthread_cond_broadcast(&cond_)){
		throw std::runtime_error("broadcast error!\n");
	}
}
