//
//  Task.h
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#ifndef Lab1Progr_Task_h
#define Lab1Progr_Task_h
#include <iostream>
#include <time.h>
#include <xlocale.h>
#include <ctime>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class Task {
    char *value;
    int length;
    char *time_buf = new char[50];
public:
    Task(char*);
    ~Task();
    void Print();
    char* GetValue();
    void changeString();
    void changeString(char*);
    int acrossIntoString(char *,char*);
    char* ToUpper(char*);
    char* ToUpper();
    char* ToLower();
    char* ToLower(char*);
    
};

#endif
