//
//  main.cpp
//  Lab1Progr
//
//  Created by Дмитрий Богомолов on 12.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include <iostream>
#include "Task.h"
#include "Binary.h"
#include "List.h"
using namespace std;

int main(int argc, const char * argv[]) {
    List<Task> test = List<Task>();
    test.pushBack(new Task("test"));
    test.pushBack(new Task("LOL"));
    test.Print();
    cout << endl;
    test.deleteLast();
    test.Print();
    
    
    
    
    return 0;
}