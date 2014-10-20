//
//  CTask.h
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __ThreadPoolDemo__CTask__
#define __ThreadPoolDemo__CTask__

#include <stdio.h>
#include <iostream>
using namespace std;
class CTask
{

public:
    
    /**
     *执行方法，子类覆盖
     */
    virtual int Run() = 0;
    
    /** 
     *设置任务数据 
     *@param data 传参
     */
    void SetData(void* data);
    
    CTask(){}
    
    CTask(string taskName)
    {
        m_strTaskName = taskName;
        m_ptrData = NULL;
    }

    virtual ~CTask(){}
    
protected:
    string m_strTaskName;  /** 任务的名称 */
    void* m_ptrData;       /** 要执行的任务的具体数据 */
};
#endif /* defined(__ThreadPoolDemo__CTask__) */
