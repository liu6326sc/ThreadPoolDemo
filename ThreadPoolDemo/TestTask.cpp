//
//  TestTask.cpp
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#include "TestTask.h"
int TestTask::Run()
{
    printf("The task is doing of object is %s",this ->m_ptrData);
    return 1;
    
}