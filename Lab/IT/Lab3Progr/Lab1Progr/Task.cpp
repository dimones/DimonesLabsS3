//
//  Task.cpp
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include "Task.h"
/**
 *  Constructor with char array pointer
 */
Task::Task(char *v){
    if(!v) return;
    length = strlen(v);
    value = new char[length];
    value = v;
    time_t timed = time(NULL);
    strftime(time_buf, 50, "%H:%M:%S %b %m %y", localtime(&timed));
}
//Constructor with different formal parameters
Task::Task(char* t1, char* t2,int t3){
    strcpy(time_buf,t1);
    strcpy(time_buf,t2);
    length = t3;
}
/**
 *  Default destructor
 */
Task::~Task(){
    cout << "Destructor (value:" << value << ")" << " with address: " << this <<endl;
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
long Task::operator+(Task a)
{
    return (atol(value)+atol(a.value));
}
/**
 *  Minus redefinition
 *
 *  @return counted value
 */
long operator-(Task a,Task b)
{
    return (atol(a.value)-atol(b.value));
}
/**
 *  Post-Increment redefinition
 *
 *  @return counted value
 */
long operator++(Task a)
{
    return (atol(a.value)+1);
}/**
  *  Prefix-Increment redefinition
  *
  *  @return counted value
  */
long operator++(Task a,int)
{
    Task oldValue(a.value);
    a.value++;
    return atol(oldValue.value);
}
/**
 *  Equals redefinition
 *
 *  @return counted value
 */
long Task::operator=(Task a){
    if(a.value == value)
        return atol(value);
    strcpy(value,a.value);
    return atol(value);
}
//Re-defenition block standard I/O
ostream& operator<<(ostream &stream,Task &t){
    stream << t.value;
    return stream;
}

istream& operator>>(istream &stream,Task &t){
    char * temp = new char[1024];
    stream >> temp;
    t.changeString(temp);
    return stream;
}
//Re-defenition output operator stream
ofstream& operator<< ( ofstream& os, Task& dt ) {
    os << dt.value << endl << dt.time_buf << endl << dt.length;
    return os;
}
//Re-defenition input operator stream
ifstream& operator>> ( ifstream& is, Task& dt ) {
    char * temp = new char[1024];
    char * temp_buf_time = new char[50];
    int temp_length;
    is >> temp >> temp_buf_time >> temp_length;    
    dt.SetTime(temp_buf_time);
    dt.changeString(temp);
    dt.SetLength(temp_length);
    return is;
}

void  Task::SetTime(char *t)
{
    if(!time_buf) time_buf = new char[50];
    strcpy(time_buf, t);
}
void Task::SetLength(int t)
{
    length = t;
}
//Binary I/O
//Read from fstream thread
void Task::Read(ifstream &stream)
{
    stream.read((char*)&value, sizeof(value));
    stream.read((char*)&time_buf, sizeof(time_buf));
    stream.read((char*)&length, sizeof(length));
}
//Write into fstream thread
void Task::Write(ofstream &stream)
{
    stream.write((char*)&value, sizeof(value));
    stream.write((char*)&time_buf, sizeof(time_buf));
    stream.write((char*)&length, sizeof(length));
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
