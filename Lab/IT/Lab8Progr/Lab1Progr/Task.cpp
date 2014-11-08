//
//  Task.cpp
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include "Task.h"
//Init static vars
char* Task::sampleStatic = NULL;
/**
 *  Constructor with char array pointer
 */
Task::Task(char *v){
    length = strlen(v);
    value = new char[length];
    value = v;
    time_t timed = time(NULL);
    strftime(time_buf, 50, "%H:%M:%S %b %m %y", localtime(&timed));
}
/**
 *  Default destructor
 */
Task::~Task(){
    //cout << "Destructor (value:" << value << ")" << " with address: " << this <<endl;
}
/**
 *  Print value and info in class
 */
void Task::Print(){
    cout << "Value: " << value << " time: " <<time_buf  << " string length: " << length <<endl;
}
/**
 *  Give char array pointer from class data
 *
 *  @return array pointer
 */
char* Task::GetValue(){
    return value;
}

/**
 *  Automatically changed string
 */
void Task::changeString()
{
    cout << "Текущая строка: " << value <<endl;
    cout << "Введите новую строку" << endl;
    char* ch = new char[1000];
    cin.getline(ch,999);
    if(ch){
        if(!value)
        {
            value = new char[strlen(ch)];
            value = ch;
        }
        else{
            value = NULL;
            value = new char[strlen(ch)];
            value = ch;
        }
    }
    else cout <<"error: null string";
}
/**
 *  Change string with parameter
 *
 *  @param t input string
 */
void Task::changeString(char *t){
    if(t){
        if(!value)
        {
            value = new char[strlen(t)];
            value = t;
        }
        else{
            value = NULL;
            value = new char[strlen(t)];
            value = t;
        }
    }
    else cout <<"error: null string";
}
/**
 *  Find substring first entry in string
 *
 *  @param string    source string
 *  @param substring it's substring for find in string
 *
 *  @return pointer of substring entry string
 */
int Task::acrossIntoString(char *string,char* substring)
{
    if(!strstr(string, substring)) return -1;
    return strstr(string, substring)-string;
}
/**
 *  Upper case char * array pointer
 *
 *  @return UPPER CASED STRING )
 */
char* Task::ToUpper(){
    char *result = new char[strlen(value)];
    result = value;
    int i = 0;
    char c;
    while(result[i])
    {
        c = result[i];
        putchar(toupper(c));
        i++;
    }
    return result;    
}
/**
 *  Function upper case from source string
 *
 *  @param string source string
 *
 *  @return upper cased string
 */
char* Task::ToUpper(char *string){
    int i = 0;
    char c;
    while (string[i]) {
        c = string[i];
        putchar(toupper(c));
        i++;
    }
    return string;
}
/**
 *  Lower case char * array pointer
 *
 *  @return lower cased string )
 */
char* Task::ToLower()
{
    char *result = new char[strlen(value)];
    result = value;
    int i = 0;
    char c;
    while(result[i])
    {
        c = result[i];
        putchar(tolower(c));
        i++;
    }
    return result;
}
/**
 *  Function lower case from source string
 *
 *  @param string source string
 *
 *  @return lower cased string
 */
char* Task::ToLower(char *string){
    int i = 0;
    char c;
    while (string[i]) {
        c = string[i];
        putchar(tolower(c));
        i++;
    }
    return string;
}
