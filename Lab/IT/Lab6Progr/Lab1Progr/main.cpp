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
    ifstream infile("dgaout",ifstream::binary);
    Task e;
    e.Read(infile);
    cout << endl;
    
    
    
    
    
    return 0;
}
