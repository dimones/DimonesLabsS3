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
    char *value;
    int length;
    char *time_buf = new char[50];
public:
    Task(char*);
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
