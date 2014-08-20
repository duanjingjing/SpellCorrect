/*************************************************************************
	> File Name: Timer.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 02:04:24 AM PDT
 ************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include "NonCopyable.h"
#include <functional>
#include <sys/timerfd.h>

class Timer:NonCopyable{
public:
	typedef std::function<void()> TimeCallback;
	Timer();
	~Timer();

	void setTimer(int val,int interval);
	void setTimerCallback(const TimeCallback &);
	void runTimer();
	void cancelTimer();

private:
	int timerfd_;
	struct itimerspec howlong_;
	TimeCallback timeCallback_;//用户逻辑
	bool isStarted_;
};











#endif
