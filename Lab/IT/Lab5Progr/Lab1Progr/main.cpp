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
    List *t = new List();
    t->pushFirst(new Task("hello"));
    t->pushFirst(new Task("HI"));
    t->pushFirst(new Task("ZIGA"));
    t->pushFirst(new Task("AZAZAZA"));
    t->pushBack(new Task("51"));
    t->insert(1, new Task("TEST"));
    t->Print();
    
    cout << endl;
    t->deleteNth(3);
    t->Print();
    t->insert(2, new Task("HELLO NIGGA BITCH"));
    cout << endl;
    t->Print();
    cout << endl;
    
    
    
    
    
    return 0;
}
