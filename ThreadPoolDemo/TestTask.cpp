//
//  TestTask.cpp
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#include "TestTask.h"
#include <unistd.h>
int TestTask::Run()
{
    printf("The task is doing of object is %s",this ->m_ptrData);
    sleep(1);
    return 1;
    
}