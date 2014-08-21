/*************************************************************************
	> File Name: Exception.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Fri 15 Aug 2014 06:12:18 AM PDT
 ************************************************************************/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>

class Exception:public std::exception{
public:
	explicit Exception(const char*);
	explicit Exception(const std::string&);
	virtual ~Exception() throw();
	virtual const char* what() const throw();
	const char* stackTrace() const throw();
private:
	void fillStackTrace();//填充栈痕迹

	std::string message_;//异常名字
	std::string stack_;
};


#endif
