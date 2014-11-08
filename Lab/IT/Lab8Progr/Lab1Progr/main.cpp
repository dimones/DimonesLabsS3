//
//  main.cpp
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include <iostream>
#include <deque>
#include <iterator>
#include <string> 
#include <algorithm>
#include <functional>
#include "Task.h"
#include <string>
using namespace std;
static char randommmm[] = {
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '1', '2', '3', '4',
    '5', '6', '7', '8', '9', '0', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
    'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B',
    'N', 'M'};
char* getRandCharPointer(int length)
{
    char* result = new char[length];
    for (int i = 0; i < length; ++i)
    {
        char temp[ 2 ];
        temp[ 0 ] = randommmm[rand()%length];
        temp[ 1 ] = '\0';
        strcat(result, temp);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    deque<Task> deqTask;
    deque<char*> deqCharPointer;
    char **tempall = new char*[100];
    for(int i = 0;i<100;i++,tempall++)
    {
        char *temp = getRandCharPointer(32);
        Task _obj(temp);
        deqTask.push_front(_obj);
        deqCharPointer.push_front(temp);
    }
    for(deque<char*>::iterator i = deqCharPointer.begin();i!=deqCharPointer.end();i++)
        cout << *i << endl;
    for(deque<Task>::iterator i = deqTask.begin();i!=deqTask.end();i++)
        i->Print();
    /*for(auto it=deqCharPointer.begin(); it!=deqCharPointer.end();++it)
        std::cout << *it << "\n";*/
    sort( deqCharPointer.begin(), deqCharPointer.end(), std::greater<char*>());
    sort(deqTask.begin(), deqTask.end(), greater<Task>());
    return 0;
}
