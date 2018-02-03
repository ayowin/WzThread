
#ifndef WZSEMAPHORE_H
#define WZSEMAPHORE_H

/*
	类名：WzSemaphore
	作用：实现多线程中的信号量，目前封装了windows、linux的api。
	使用方法：
		1、请正确拷贝操作系统对应的*.cpp文件。
		2、在全局下，实例化WzSemaphore对象（注意：需传入信号量初始值，默认为0），
		调用release()信号量加1，wait()信号量减1。
	作者：欧阳伟
	日期：2017-9-25
*/

struct PWzSemaphore;

class WzSemaphore
{
public:
	WzSemaphore(int defaultValue=0);//传入信号量初始值，默认为0
	~WzSemaphore();

	void wait();//信号量减1
	bool wait(int ms);//在ms时间内等待信号量
	void release();//信号量加1

private:
	PWzSemaphore *pWzSemaphore;

};

#endif // WZSEMAPHORE_H
