#pragma once
#include<chrono>
//支持steady_clock和high_resolution_clock计时的简单封装
using SC = std::chrono::steady_clock;
using HRC = std::chrono::high_resolution_clock;

template<typename T>
class Timer
{
public:
	//using std::chrono::duration;
	//using std::chrono::duration;
	Timer() {};
	~Timer() {};
	//第一次调用这个
	void startTick() {
		curr_ = T::now();
	}
	void tick() {
		auto curr = T::now();
		pre_ = curr_;
		curr_ = curr;
		duraSinceStart +=std::chrono::duration_cast<std::chrono::duration<double>>(curr-pre_).count();
	}
	double tickAndGet(){
		tick();
		return getDuraOfSecondOfLastTwo();
	}
	double getDuraOfSecondOfLastTwo() const{
		return std::chrono::duration_cast<std::chrono::duration<double>>(curr_-pre_).count();
	}
	double getDuraOfSecondSinceStart()const {
		return duraSinceStart;
	}
private:
	//调用now了以后的时间点记录
	std::chrono::time_point<T> curr_;
	//调用now之前的时间点记录
	std::chrono::time_point<T> pre_;
	double duraSinceStart;
};
