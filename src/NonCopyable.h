/*************************************************************************
	> File Name: NonCopyable.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Mon 18 Aug 2014 02:30:07 AM PDT
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
