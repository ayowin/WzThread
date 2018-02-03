
#ifndef WZTHREAD_H
#define WZTHREAD_H

/*
	类名：WzThread
	作用：实现多线程，目前封装了windows、linux的api。
	使用方法：
		1、请正确拷贝操作系统对应的*.cpp文件。
		2、创建一个类，继承WzThread，重写run()函数，在run()函数中写线程业务内容。
		3、实例化对象，调用start()函数启动线程。
	作者：欧阳伟
	日期：2017-9-25
*/

struct PWzThread;

class WzThread
{
public:
    WzThread();
    virtual ~WzThread();

    virtual void run()=0;//线程主函数

    bool start();//启动线程
    void join();//等待线程结束，并回收线程资源
    void sleepS(int s);//sleep函数，单位：秒
    void sleepMs(int ms);//sleep函数，单位：毫秒

private:
    PWzThread *pWzThread;
};

#endif // WZTHREAD_H
