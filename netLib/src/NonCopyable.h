/*************************************************************************
	> File Name: NonCopyable.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 06:03:07 AM PDT
 ************************************************************************/

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable{
public:
	NonCopyable(){}
	~NonCopyable(){}
private:
	NonCopyable(const NonCopyable&);
	void operator=(const NonCopyable&);
};

#endif
