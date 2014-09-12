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
    Task a = "51";
    Task b = "21";
    cout << a - b + 15 << endl;
    cout << ++a << endl;
    cout << a++ <<endl;
    cout << a.GetValue();
    a = "51";
    return 0;
}
