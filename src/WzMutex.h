
#ifndef WZMUTEX_H
#define WZMUTEX_H

/*
	类名：WzMutex
	作用：实现多线程中的互斥锁，目前封装了windows、linux的api。
	使用方法：
		1、请正确拷贝操作系统对应的*.cpp文件。
		2、在全局下，实例化WzMutex对象，调用lock()开启锁，unlock()释放锁。
	作者：欧阳伟
	日期：2017-9-25
*/

struct PWzMutex;

class WzMutex
{
public:
	WzMutex();
	~WzMutex();

	void lock();//开启锁
	void unlock();//释放锁
private:
	PWzMutex *pWzMutex;
};

#endif // WZMUTEX_H
