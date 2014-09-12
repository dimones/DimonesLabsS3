//
//  main.cpp
//  hello world number two
//
//  Created by Дмитрий Богомолов on 11.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

struct account{
    char *surname;
    int number;
    int percent;
    float money;
    account(char * surname0,int number0,int percent0,float money0)
    {
        surname = new char[strlen(surname0)];
        surname = surname0;
        number = number0;
        percent = percent0;
        money = money0;
    }
    void read()
    {
        cout << "Введите имя клиента" << endl;
        surname = new char[256];
        cin.getline(surname, 255);
        cout << "Введите номер счета и сумму в рублях" << endl;
        cin >> number >> money;
        cout << "Введите процент по счету" <<endl;
        cin >> percent;
        
    }
    void display()
    {
        cout << "Имя клиента:\n     " << surname << "\nНомер счета:\n      " << number << "\nСумма на счете\n     " << money << endl;
    }
    char *ToString()
    {
        char *result = new char[1000];
        sprintf(result, "Имя клиента: %s    Номер счета: %d     Сумма на счете: %f",surname,number,money);
        return result;
    }
};



struct account1{
    char *surname;
    int number;
    int percent;
    float money;
    void Init(char * surname0,int number0,int percent0,float money0)
    {
        surname = new char[strlen(surname0)];
        surname = surname0;
        number = number0;
        percent = percent0;
        money = money0;
    }
    void read()
    {
        cout << "Введите имя клиента" << endl;
        surname = new char[256];
        cin.getline(surname, 255);
        cout << "Введите номер счета и сумму в рублях" << endl;
        cin >> number >> money;
        cout << "Введите процент по счету" <<endl;
        cin >> percent;
        
    }
    void display()
    {
        cout << "Имя клиента:\n     " << surname << "\nНомер счета:\n      " << number << "\nСумма на счете\n     " << money << endl;
    }
    char *ToString()
    {
        char *result = new char[1000];
        sprintf(result, "Имя клиента: %s    Номер счета: %d     Сумма на счете: %f",surname,number,money);
        return result;
    }
};
void initStruct(account1 &A,char * surname0,int number0,int percent0,float money0)
{
    A.surname = surname0;
    A.number = number0;
    A.percent = percent0;
    A.money = money0;
}
void read(account1 &A)
{
    cout << "Введите имя клиента" << endl;
    A.surname = new char[256];
    cin.getline(A.surname, 255);
    cout << "Введите номер счета и сумму в рублях" << endl;
    cin >> A.number >> A.money;
    cout << "Введите процент по счету" <<endl;
    cin >> A.percent;
    
}
char *ToString(account1 &A)
{
    char *result = new char[1000];
    sprintf(result, "Имя клиента: %s    Номер счета: %d     Сумма на счете: %f",A.surname,A.number,A.money);
    return result;
}
void display(account1 &A)
{
    cout << "Имя клиента:\n     " << A.surname << "\nНомер счета:\n      " << A.number << "\nСумма на счете\n     " << A.money << "\nПроцент:\n      " << A.percent << endl;
}

void initStruct(account1 *A,char * surname0,int number0,int percent0,float money0)
{
    A->surname = new char[strlen(surname0)];
    A->surname = surname0;
    A->number = number0;
    A->percent = percent0;
    A->money = money0;
}
void read(account1*A)
{
    cout << "Введите имя клиента" << endl;
    A->surname = new char[256];
    cin.getline(A->surname, 255);
    cout << "Введите номер счета и сумму в рублях" << endl;
    cin >> A->number >> A->money;
    
    cout << "Введите процент по счету" <<endl;
    cin >> A->percent;
    
}
char *ToString(account1 *A)
{
    char *result = new char[1000];
    sprintf(result, "Имя клиента: %s    Номер счета: %d     Сумма на счете: %f",A->surname,A->number,A->money);
    return result;
}
void display(account1 *A)
{
    cout << "Имя клиента:\n     " << A->surname << "\nНомер счета:\n      " << A->number << "\nСумма на счете\n     " << A->money << "\nПроцент:\n      " << A->percent << endl;
}



int main(int argc, const char * argv[]) {
    /*GOOD*/
    
    
    
    struct account *cool = new account("GOOD",18732,0,2136.12f);
    cool->display();
    
    cout<< endl;
    /*BAD*/
    account1 bad;
    initStruct(&bad, "adhg", 136, 0, 12.51);// bad.Init("BAD", 15, 41, 125.12f);
    display(bad);
    
    
    
    /*WORSE*/
    account1 *worse = new account1;
    initStruct(bad, "WORSE", 136, 0, 12.51);
    //worse->Init("WORSE", 125125, 51, 512516.135f);
    display(worse);
    
    
    
    
    
    return 0;
}
