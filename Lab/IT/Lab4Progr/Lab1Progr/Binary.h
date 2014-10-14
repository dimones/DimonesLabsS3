//
//  Binary.h
//  Lab4Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#ifndef Lab4Progr_Binary_h
#define Lab4Progr_Binary_h
#include "Task.h"
#include <string>
#include <bitset>
using namespace std;
class Binary:public Task{ // наследуем класс для хранения строки в нем
    char *binary_value;
    int c;
public:
    Task string;
    //constructor
    Binary(int ch){
        c = ch;
        int temp = ch;
        long dec,rem,i=1,sum=0;
        string = (char*)test(ch);

        cout << endl;
    };
    //func for convert int into char*(binary format)
    char *decimal_to_binary(int n)
    {
        int c, d, count;
        char *pointer;
        
        count = 0;
        pointer = (char*)malloc(32+1);
        
        if ( pointer == NULL )
            exit(EXIT_FAILURE);
        
        for ( c = 31 ; c >= 0 ; c-- )
        {
            d = n >> c;
            
            if ( d & 1 )
                *(pointer+count) = 1 + '0';
            else
                *(pointer+count) = 0 + '0';
            
            count++;
        }
        *(pointer+count) = '\0';
        
        return  pointer;
    }
    const char *test(int ch)
    {
        std::string result = "";
        
        do
        {
            if ( (ch & 1) == 0 )
                result += "0";
            else
                result += "1";
            
            ch >>= 1;
        } while ( ch );
        
        reverse(result.begin(), result.end());
        return result.c_str();
    }
    char * int_to_bin(int ch)
    {
        char* _out = new char[124];
        while(ch>=2)
        {
            if(ch%2==0)
            {
                strcat("0",_out);
                //sprintf(_out,"%d",0);
            }
            else
                strcat("0",_out);
                //sprintf(_out,"%d",0);
            ch/=2;
        }
        cout << "BINARY: " << _out << endl;
        return _out;
    }
    //get value in binary(return char*)
    char* getValue(void)
    {
        return binary_value;
    }
    // return value from class
    int getValue(int){
        return c;
    }
    
};
//класс - запись в списке запланированных дел, содержащая начало и конец работы, признак выполнения.
class TaskList : public Task{
    char* signState;
    char* beginState;
    char* endState;
public:
    //default constructor
    TaskList();
    //full-equipment constructor
    TaskList(char* _beginState,char* _endState,char* _signState){
        beginState = strdup(_beginState);
        endState = strdup(_endState);
        signState = strdup(_signState);
    }
    // Funtions for manipulate with strings in this class
    void changeSignState(char* _signState){
        signState = strdup(_signState);
    }
    void changeBeginState(char* _beginState)
    {
        beginState = strdup(_beginState);
    }
    void changeEndState(char* _endState)
    {
        endState = strdup(_endState);
    }
    void print(){
        cout << "Begin: " << beginState << "   End state: " << endState << "   Sign state: " << signState << endl;
    }
    
};
#endif
