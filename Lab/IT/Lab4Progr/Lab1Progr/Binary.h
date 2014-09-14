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
enum STATE {
    BEGIN,IN_WORK,END
};
class Binary:public Task{
    char *binary_value;
    int c;
public:
    Task string;
    Binary(int ch){
        c = ch;
        int temp = ch;
        long dec,rem,i=1,sum=0;
        /*char *t = new char[100];
        while(temp>0)
        {
            if(temp%2==0)
                strcat(t,"0");
            else strcat(t, "1");
            temp/=2;
        }
        char *tout = new char[strlen(t)];
        char *binary_value = new char[strlen(t)];
        for(int j = strlen(t);i<strlen(t);i++,j--)
        {
            tout[i] = t[j];
        }
        binary_value = t;*/
        /*do
        {
            rem=dec%2;
            sum=sum + (i*rem);
            dec=dec/2;
            i=i*10;
        }while(dec>0);
        */
        string = decimal_to_binary(ch);

        cout << endl;
    };
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
    char* getValue(void)
    {
        return binary_value;
    }
    int getValue(int){
        return c;
    }
    
};
//класс - запись в списке запланированных дел, содержащая начало и конец работы, признак выполнения.
class TaskList : public Task{
    STATE state;
    bool begin;
    bool end;
public:
    TaskList();
    TaskList(bool _begin,bool _end,STATE _state){
        begin = _begin;
        end = _end;
        state = _state;
    }
    void changeState(STATE t){
        state = t;
    }
    void Begin()
    {
        state = STATE::BEGIN;
        begin = true;
    }
    void END()
    {
        state = STATE::END;
        end = true;
    }
    void print(){
        //cout << "Beginned: " << (begin==true)?"true":"false" << "  STATE: " << ((state == BEGIN)?"begin":((state == IN_WORK)?"in work":((state == END)?"ended":"don't know"))) << endl;
    }
    
};
#endif
