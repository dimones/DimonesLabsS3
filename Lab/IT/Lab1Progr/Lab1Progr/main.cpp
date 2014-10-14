//
//  main.cpp
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include <iostream>
#include "Task.h"
using namespace std;

int main(int argc, const char * argv[]) {
    char* temp = new char[500];
    cout << "Input text value:"  << endl;
    cin.getline(temp,499);
    Task t(temp);
    t.Print();
    char* k = new char[strlen(t.GetValue())];
    k = t.GetValue();
    cout << "Введите подстроку для поиска" << endl;
    char* tempch = new char[3125];
    cin.getline(tempch, 125);
    cout << "нашлось со знака: " << t.acrossIntoString(temp, tempch) << endl;
    
    
    cout << "UPPER CASE =3 :" << t.ToUpper() << endl;
    
    cout << "lower case =3 :" << t.ToLower() << endl;
    
    
    
    //Static var demonstration:
    t.sampleStatic = "For test";
    
    cout << "From object: " << t.sampleStatic ;
    Task::sampleStatic = "daa";
    cout <<"   from class:" << Task::sampleStatic << endl;
    return 0;
}
