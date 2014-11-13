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
#include <ctime>
#include <map>
#include <utility>
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
int* getRandomIndexToDelete(int count,int maxIndex)
{
    int* _out = new int[count];
    for(int i = 0;i<count;i++)
        _out[i] = rand() % (maxIndex-5)+1;
    return _out;
}
//Experimental
struct CompareByValue {
    bool operator() (const pair<int, Task>& a, const pair<int, Task>& b) const {
        return strcmp(a.second.value, b.second.value);
    };
};
int main(int argc, const char * argv[]) {
    const int countAll = 10000;
    const int wordLength = 32;
    //Деки
    int timeAddTask = 0;
    int timeAddCharPointer = 0;
    deque<Task> deqTask; // Дека с классом
    deque<char*> deqCharPointer; // Дека со строкой
    /* Добавление в деки */
    for(int i = 0;i<countAll;i++)
    {
        char *temp = getRandCharPointer(wordLength);//Генерируем строку
        Task _obj(temp); //Создаем экземпляр объекта
        int _timeTask = (int)clock();
        deqTask.push_front(_obj);//заносим в начало деки объект
        int __timeTask = (int)clock();
        timeAddTask+=__timeTask-_timeTask;
        int _timeCharPointer = (int)clock();
        deqCharPointer.push_front(temp);// заносим в начало деки строку
        int __timeCharPointer = (int)clock();
        timeAddCharPointer += __timeCharPointer-_timeCharPointer;
    }
    //for(deque<char*>::iterator i = deqCharPointer.begin();i!=deqCharPointer.end();i++)
    //    cout << *i << endl;
    /*for(auto it=deqCharPointer.begin(); it!=deqCharPointer.end();++it)
        std::cout << *it << "\n";*/
    // Результаты добавления
    cout << "Task: " << timeAddTask << "  char*: " << timeAddCharPointer << endl;
    /* Сортировка дек*/
    cout << "SORT BEGIN" << endl;
    int timeSortTask = 0;
    int timeSortCharPointer = 0;
    int _timeTask = (int)clock();
    sort(deqTask.begin(),deqTask.end(),
         [](const Task& task1, const Task& task2)
         { return strcmp(task1.value,task2.value); }
         );
    int __timeTask = (int)clock();
    timeSortTask = __timeTask - _timeTask;
    int _timeCharPoiter = (int)clock();
    sort(deqCharPointer.begin(),deqCharPointer.end(),
         [](const char* task1, const char* task2)
         { return strcmp(task1,task2); }
         );
    int __timeCharPointer = (int)clock();
    timeSortCharPointer = __timeCharPointer - _timeCharPoiter;
    
    // Результаты сортировки
    cout << "Sort results" << endl << "Task: " << timeSortTask << "  char*: " << timeSortCharPointer << endl;
    
    cout << "Search begin" <<endl;
    //Поиск
    const int countToSearch = 3500;
    int *indexesToFind = getRandomIndexToDelete(countToSearch, countAll);
    int timeFindTask = 0;
    int timeFindCharPointer = 0;
    for(int i = 0;i<countToSearch;i++)
    {
        int _timeFindTask = (int)clock();
        /*deque<Task>::iterator where = find(deqTask.begin(), deqTask.end(), [](const Task& t1,const Task& t2)
                                           { return strcmp(t1.value,t2.value); }
                                           );*/
        int __timeFindTask = (int)clock();
        timeFindTask = __timeFindTask - _timeFindTask;
        
        int _timeFindCharPointer = (int)clock();
        deque<char*>::iterator  _where = find(deqCharPointer.begin(), deqCharPointer.end(), deqCharPointer.at(indexesToFind[i]));
        int __timeFindCharPointer = (int)clock();
        timeFindCharPointer += __timeFindCharPointer - _timeFindCharPointer;
    }
    
    cout << "Results: " << endl << "Task: " << timeFindTask << "  char*: " << timeFindCharPointer << endl;
    
    cout << "Deletes begin" << endl;
    //Удаление
    const int countToDelete = 3500;
    int *indexToDelete = getRandomIndexToDelete(countToDelete,countAll); // Массив индексов для удаления
    int timeDeleteTask = 0;
    int timeDeleteCharPointer = 0;
    for(int i = 0;i<countToDelete;i++)
    {
        int _timeDelTask = (int)clock();
        deqTask.erase(deqTask.begin()+indexToDelete[i]);
        int __timeDelTask = (int)clock();
        timeDeleteTask += __timeDelTask - _timeDelTask;
        
        int _timeDelCharPointer = (int)clock();
        deqCharPointer.erase(deqCharPointer.begin()+indexToDelete[i]);
        int __timeDelCharPointer = (int)clock();
        timeDeleteCharPointer += __timeDelCharPointer - _timeDelCharPointer;
    }
    cout<< "Delete results: " << endl << "Task: " << timeDeleteTask << "  char*: " << timeDeleteCharPointer << endl;
    
    /* Словарь с дубликатами*/
    
    cout << "Multimap begin" << endl;
    //Вставка
    multimap<int,Task> mapTask;
    multimap<int,char*> mapCharPointer;
    int timeInsertTask = 0;
    int timeInsertCharPointer = 0;
    for(int i = 0;i<countAll;i++)
    {
        char *temp = getRandCharPointer(wordLength);//Генерируем строку
        Task _obj(temp); //Создаем экземпляр объекта
        int _timeTask = (int)clock();
        mapTask.insert(pair<int, Task>(i,_obj));//заносим в начало деки объект
        int __timeTask = (int)clock();
        timeInsertTask+=__timeTask-_timeTask;
        int _timeCharPointer = (int)clock();
        mapCharPointer.insert(pair<int, char*>(i,temp));// заносим в начало деки строку
        int __timeCharPointer = (int)clock();
        timeInsertCharPointer += __timeCharPointer-_timeCharPointer;
    }
    cout << "Results" << endl << "Task: " << timeInsertTask << " char*: " << timeInsertCharPointer << endl;
    
    //Сортировка
    cout << "Sort begin" << endl;
    int mapTaskSort = 0;
    int mapCharPointerSort = 0;
    int _mapTaskSort = (int)clock();
    //sort(mapTask.begin(), mapTask.end(), CompareByValue());
    int __mapTaskSort = (int)clock();
    mapTaskSort = __mapTaskSort - _mapTaskSort;
    
    int _mapCharPointerSort = (int)clock();
    /*sort(mapCharPointer.begin(), mapCharPointer.end(), [](pair<int, char*> p1, pair<char*, char*> p2)
         { return strcmp(p1.second, p2.second); }
         );*/
    int __mapCharPointerSort = (int)clock();
    mapCharPointerSort = __mapCharPointerSort - _mapCharPointerSort;
    cout << "Results" << endl << "Task: " << mapTaskSort << "  char*: " << mapCharPointerSort << endl;
    
    //Поиск
    cout << "Search" << endl;
    int mapFindTask = 0;
    int mapFindCharPointer = 0;
    int *indexesToSearch = getRandomIndexToDelete(countToSearch,countAll);
    for(int i = 0;i<countToDelete;i++)
    {
        int _mapFindTask = (int)clock();
        mapTask.find(indexesToFind[i]);
        int __mapFindTask = (int)clock();
        mapFindTask += __mapFindTask-_mapFindTask;
        
        int _mapFindCharPointer = (int)clock();
        mapCharPointer.find(indexesToFind[i]);
        int __mapFindCharPointer = (int)clock();
        mapFindCharPointer += __mapFindCharPointer - _mapFindCharPointer;
    }
    cout << "Results:" << endl << "Task: " << mapFindTask <<"  char*:" << mapFindCharPointer << endl;
    
    //Удаление
    cout << "Delete begin" << endl;
    int mapDeleteTask = 0;
    int mapDeleteCharPointer = 0;
    int *indexesToDelete = getRandomIndexToDelete(countToDelete, countToDelete);
    for(int i = 0;i<countToDelete;i++)
    {
        int _mapDeleteTask = (int)clock();
        mapTask.erase(indexesToDelete[i]);
        int __mapDeleteTask = (int)clock();
        mapDeleteTask += __mapDeleteTask - _mapDeleteTask;
        
        int _mapDeleteCharPointer = (int)clock();
        mapCharPointer.erase(indexesToDelete[i]);
        int __mapDeleteCharPointer = (int)clock();
        mapDeleteCharPointer+=__mapDeleteCharPointer - _mapDeleteCharPointer;
    }
    cout << "Results: "<< endl << "Task: " <<mapDeleteTask << "  char*: " << mapDeleteCharPointer << endl;
    return 0;
}
