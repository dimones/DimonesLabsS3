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
    cout << a.GetValue() << endl;
    a = "51";
    cout << a + "51" << endl;
    
    Task d = "5125121";
    
    
   // ofstream outfile ("out.txt",ofstream::binary);
    //outfile << d;
    
    Task e;
    ifstream infile("out.txt",ifstream::binary);
    infile >> e;
    
    ofstream outfile_bin ("out",ofstream::binary);
    cout <<"Write into binary:" << endl;
    d.Write(outfile_bin);
    outfile_bin.close();
    //outfile.close();

    return 0;
}
