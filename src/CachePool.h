/*************************************************************************
	> File Name: CachePool.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 06:33:08 AM PDT
 ************************************************************************/

#ifndef CACHEPOOL_H
#define CACHEPOOL_H

#include <queue>
#include "MutexLock.h"
#include "Condition.h"
#include "Cache.h"
using namespace std;

class CachePool{
public:
	CachePool(size_t size);
	~CachePool();

	bool isEmpty() const;
	bool isFull() const;
    
	void consume();
private:
	queue<Cache*>  queue_;
	
	//mutable代表在const函数中仍可以被修改
	mutable MutexLock mutex_;
	Condition cond_;
	static size_t size_=4;
};







#endif
