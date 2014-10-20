//
//  main.cpp
//  ThreadPoolDemo
//
//  Created by Ltian on 14/10/20.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//
#include <unistd.h>
#include <iostream>
#include "CThreadPool.h"
#include <iostream>
#include <stdlib.h>
#include "TestTask.h"
int main()
{
	TestTask taskObj;
	
	char szTmp[] = "this is the NORMAL thread ";
	taskObj.SetData((void*)szTmp);
    CThreadPool* threadPool = CThreadPool::sharedTheadPoll();
    
    /*测试方法*/
    /************************************************************************************/
    for(int i = 0; i < 20; i++)
    {
        //sleep(1);
        threadPool->AddTask(&taskObj);
    }
    sleep(1);
	for(int i = 0; i < 20; i++)
	{
        sleep(1);
        TestTask* task = new TestTask();
        char ss [] = "lalallalalalalala";
        task -> SetData((void*)ss);
		threadPool->AddTask(task,HIGH);
	}
    /************************************************************************************/
	
	while(1)
	{
		printf("there are still %d tasks need to handle/n", threadPool->getTaskSize());
		if (threadPool->getTaskSize() == 0)
		{
			if (threadPool->StopAll() == -1)
			{	
				printf("Now I will exit from main/n");
				exit(0);
			}
		}
		sleep(20000);
	}
	
	return 0;
}

