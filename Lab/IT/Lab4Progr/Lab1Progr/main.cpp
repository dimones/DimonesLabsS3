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
    //cout << "Vvedite chislo" << endl;
    //cin >> d;
    cout << d + "125" <<endl;
    
    
    ofstream outfile ("out",ofstream::binary);
    //outfile << d;
    
    Task e;
    ifstream infile("out",ifstream::binary);
   // infile >> e;
    
    cout <<"eqasg";
    d.Write(outfile);
    outfile.close();
    
    cout <<"LOL" <<endl;
    e.Read(infile);
    
    Binary t = 32;
    t.string.Print();
    cout << endl;
    cout << "COOL:: " << t.string << endl;
    
    TaskList list(TaskList("Вымыть посуду", "Пропылесосить", "Не начато"));
    list.print();
    list.
    return 0;
}
