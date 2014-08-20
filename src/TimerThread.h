/*************************************************************************
	> File Name: TimerThread.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 04:58:22 AM PDT
 ************************************************************************/

#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H

#include "NonCopyable.h"
#include "Thread.h"
#include "Timer.h"
#include <functional>

class TimerThread:private NonCopyable{
public:
	typedef std::function<void ()> TimerCallback;
	void setTimer(int value,int interval);
	void setTimerCallback(const TimerCallback &cb);
	void startTimerThread();
	void cancelTimerThread();

private:
	Timer timer_;
	Thread thread_;
};









#endif
