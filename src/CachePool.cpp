/*************************************************************************
	> File Name: CachePool.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 06:36:33 AM PDT
 ************************************************************************/

#include "CachePool.h"
#include <iostream>
using namespace std;

CachePool::CachePool():queue_(),mutex_(),cond_(mutex_){

}

CachePool::~CachePool(){

}


bool CachePool::isEmpty() const{
	 mutex_.lock();
	 bool ret=queue_.empty();
	 mutex_.unlock();

	 return ret;
}

bool CachePool::isFull() const{
	mutex_.lock();
	bool ret=queue_.size()>=size_;
	mutex_.unlock();

	return ret;
}

Cache* CachePool::consume(){
	mutex_.lock();

	/*
	 *这里不能调用buffer本身的isEmpty()
	 */

	while(queue_.isEmpty()){
		cond_.wait();
	}

	Cache*  pt=queue_.top();
	queue_.pop();

	mutex_.unlock();
	return pt;
}



