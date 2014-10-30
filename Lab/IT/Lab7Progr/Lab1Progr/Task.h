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
#include <sstream>
#include <istream>
#include <fstream>
using namespace std;

class Task {
    enum Types{ Int,Float,String,TaskValue};
    Types type;
    char *value;
    int length;
    char *time_buf = new char[50];
    int intValue;
    float floatValue;
public:
    Task(char* v){
        if(!v) return;
        length = strlen(v);
        value = new char[length];
        value = v;
        time_t timed = time(NULL);
        strftime(time_buf, 50, "%H:%M:%S %b %m %y", localtime(&timed));
        type = Types::TaskValue;
    }

    Task(int _intValue) {
        type = Types::Int;
        intValue = _intValue;
        time_t timed = time(NULL);
        strftime(time_buf, 50, "%H:%M:%S %b %m %y", localtime(&timed));
    }
    Task(float _floatValue){
        type = Types::Float;
        floatValue = _floatValue;
        time_t timed = time(NULL);
        strftime(time_buf, 50, "%H:%M:%S %b %m %y", localtime(&timed));
    }
    Task() {}
    ~Task();
    Task(char*,char*,int);
    virtual void Print();
    char* GetValue();
    void changeString();
    void changeString(char*);
    int acrossIntoString(char *,char*);
    char* ToUpper(char*);
    char* ToUpper();
    char* ToLower();
    char* ToLower(char*);
    bool isNull() { if(!this) return true; else return false; }
    /*Lab 3*/
    long operator+(Task b);
    friend long operator-(Task a,Task b);
    friend long operator++(Task a);
    friend long operator++(Task a,int);
    long operator=(Task a);
    friend ostream &operator<<(ostream &stream,Task &t);
    friend istream &operator>>(istream &stream,Task &t);
    friend ofstream &operator<<(ofstream &stream,Task &t);
    friend ifstream &operator>>(ifstream &stream,Task &t);
    //Helper funcs
    void SetTime(char *);
    void SetLength(int);
    //Binary reader/writer
    void Read(ifstream &stream);
    void Write(ofstream &stream);
};

#endif
