/*************************************************************************
	> File Name: Thread.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 04:45:32 AM PDT
 ************************************************************************/

#include "Thread.h"
#include<iostream>
using namespace std;

Thread::Thread():isStarted_(false),tid_(0){
}

Thread::Thread(const ThreadFunc& callback):isStarted_(false),
tid_(0),callback_(callback){
}

Thread::~Thread(){
	if(isStarted_){
		pthread_detach(tid_);
	}
}

void Thread::setCallback(const ThreadFunc& cb){
	callback_=cb;
}

void Thread::start(){
	pthread_create(&tid_,NULL,threadFunc,this);
}

 void* Thread::threadFunc(void *arg){
	Thread *pt=static_cast<Thread*>(arg);
	pt->callback_();
	return NULL;
}

void Thread::join(){
	pthread_join(tid_,NULL);
}

