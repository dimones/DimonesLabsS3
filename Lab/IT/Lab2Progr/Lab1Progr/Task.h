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
    static char* sampleStatic;
public:
    Task(char*);
    Task() { value[0] = 0;}
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
    long operator+(Task b);
    friend long operator-(Task a,Task b);
    friend long operator++(Task a);
    friend long operator++(Task a,int);
    operator char* () { return value; } // возможна модификация объекта через результат приведения
    operator const char* () const { return value; }
    operator string() { return string(value); }
    long operator=(Task a);
};

#endif
