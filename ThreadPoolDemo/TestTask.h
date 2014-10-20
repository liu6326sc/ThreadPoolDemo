//
//  TestTask.h
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __ThreadPoolDemo__TestTask__
#define __ThreadPoolDemo__TestTask__

#include <stdio.h>
#include "CTask.h"
/**测试*/
class TestTask:public CTask
{
public:
    TestTask(){};
    ~TestTask(){};
    int Run();
};

#endif /* defined(__ThreadPoolDemo__TestTask__) */
