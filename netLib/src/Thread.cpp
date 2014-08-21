/*************************************************************************
	> File Name: Thread.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 06:07:43 AM PDT
 ************************************************************************/

#include "Thread.h"

Thread::Thread():tid_(0),isStarted_(false){
}


Thread::Thread(const ThreadFunc &callback):
		tid_(0),
		isStarted_(false),
		callback_(callback){
}

Thread::~Thread(){
	if(isStarted_){
		pthread_detach(tid_);
	}
}

void Thread::setCallback(const ThreadFunc &cb){
	callback_=cb;
}

void* Thread::threadFunc(void *arg){
	Thread* pt=static_cast<Thread*>(arg);
	pt->callback_();
	return NULL;
}

void Thread::start(){
    pthread_create(&tid_,NULL,threadFunc,this);
}

void Thread::join(){
	pthread_join(tid_,NULL);
}
