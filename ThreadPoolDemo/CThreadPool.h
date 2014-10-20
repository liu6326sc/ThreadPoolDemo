//
//  CThreadPool.h
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __ThreadPoolDemo__CThreadPool__
#define __ThreadPoolDemo__CThreadPool__

#include <stdio.h>
#include <deque>
#include <string>
#include <pthread.h>
#include "CTask.h"
using namespace std;

/**任务优先级*/
enum PRIORITY
{
    NORMAL,
    HIGH
};

class CThreadPool
{
public:
    
    /**
     *构造方法
     */
    CThreadPool(int threadNum = 2);
    
    /**
     *把任务添加到任务队列中
     *@param task 任务执行单元
     */
    int addTask(CTask *task);
    
    /**
     *优先级添加队列
     *@param task 任务队列
     *@param priority 任务优先级
     */
    int addTask(CTask*task,PRIORITY priority);
    
    /**
     *使线程池中的线程退出
     */
    int stopAll();
    
    /**
     * 获取当前任务队列中的任务数
     */
    int getTaskSize();
    
    /**
     *获取线程池单例
     */
    static CThreadPool* sharedTheadPoll();
    
protected:
    
    /**
     *新线程的线程回调函数
     */
    static void* ThreadFunc(void * threadData);
    
    /**
     *创建线程池中的线程
     */
    int create();
    static int moveToIdle(pthread_t tid);       /** 线程执行结束后，把自己放入到空闲线程中 */
    static int moveToBusy(pthread_t tid);       /** 移入到忙碌线程中去 */
    
    
private:
    static 	deque<CTask*> m_vecTaskQue;     /** 任务列表 */
    static	bool shutdown;                    /** 线程退出标志 */
    int 	m_iThreadNum;                     /** 线程池中启动的线程数 */
    pthread_t	*pthread_id;
    
    static pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
    static pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */
    
    
};

#endif /* defined(__ThreadPoolDemo__CThreadPool__) */
