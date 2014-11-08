//
//  List.h
//  Lab4Progr
//
//  Created by Дмитрий Богомолов on 14.09.14.
//  Copyright (c) 2014 Дмитрий Богомолов. All rights reserved.
//

#ifndef __Lab4Progr__List__
#define __Lab4Progr__List__
#include "Task.h"
template <class Task> class Node{
//class Node : public Task{
public:
    enum Types{ Int,Float,String,TaskValue};
    Types type;
    Task *obj;
   // Node *next;
    Node<Task> *next;
    int intValue;
    float floatValue;
    int index = 0;
    Node()
    {
        next = NULL;
    }
    Node(int _intValue)
    {
        type = Int;
        intValue = _intValue;
    }
    Node(float _floatValue)
    {
        type = Float;
        floatValue = _floatValue;
    }
    Node(Task *_taskValue)
    {
        type = TaskValue;
        obj = _taskValue;
    }
    int getValue()
    {
        return intValue;
    }
};
template <class Task> class List :public Node<Task>{
//class List: public Node {
    Node<Task> *head;
    int size;
public:
    List(){
        head = NULL;
    }
    ~List()
    {
        
    }
    void pushFirst(Task *t)
    {
        Node<Task> *tmp = (Node<Task>*) malloc(sizeof(Node<Task>));
        tmp->obj = t;
        tmp->next = (head);
        (head) = tmp;
        size++;
       // reNumber();
    }
    
    template <class List>
    Node<Task>* getLast(Node<Task> *head) {
        Node<Task> *temp = new Node<Task>();
        temp = head;
        if (temp == NULL) {
            return NULL;
        }
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }
    
    template <class List>
    Task* pop() {
        Node<Task>* prev = NULL;
        Task* val;
        if (head == NULL) {
            exit(-1);
        }
        prev = (head);
        val = prev->obj;
        (head) = (head)->next;
        free(prev);
        return val;
    }
    
    template <class List>
    Task* deleteNth(int n) {
        Task *val;
        if (n == 0) {
            head = NULL;
            return 0;
        } else {
            Node<Task> *prev = getNth<List>(head,n-1);
            Node<Task> *elm  = prev->next;
            val = elm->obj;
            prev->next = elm->next;
            free(elm);
            size--;
            return val;
        }
        size--;
        return val;
    }
    template <class List>
    Node<Task>* getNth(Node<Task>*& hh,int n)
    {
        Node<Task>* temp = new Node<Task>();
        temp = hh;
        int counter = 0;
        while (counter < n-1 && temp) {
            temp = temp->next;
            counter++;
        }
        return temp;
     }
    void pushBack(Task *t)
    {
        if(head == NULL) { pushFirst(t); return; }
        Node<Task> *last = getLast<List>(head);
        Node<Task> *tmp = (Node<Task>*) malloc(sizeof(Node<Task>));
        tmp->obj = t;
        tmp->next = NULL;
        last->next = tmp;
        size++;
        //reNumber();
    }
    void reNumber()
    {
        Node<Task> *list = new Node<Task>();;
        list = this->head;
        for(int i = 0;i <size-1;i++)
        {
            Node<Task> * tmp = new Node<Task>();
            tmp = getNth(head, i);
            tmp->index = i;
        }
    }
    template <class List>
    Task* toArray() {
        int leng = size;
        Node<Task> *tmp = (Node<Task>*) malloc(sizeof(Node<Task>));
        tmp = head;
        Task *values = (Task*) malloc(leng*sizeof(Task));
        while (tmp) {
            values[--leng] = *tmp->obj;
            tmp = tmp->next;
        }
        return values;
    }
    void deleteLast(){
        
    }
    void Print()
    {
        Node<Task>* temp = new Node<Task>();
        temp = this->head;
        while (temp) {
            temp->obj->Print();
            temp = temp->next;
        }
    }
    void insert(unsigned n, Task *t) {
        unsigned i = 0;
        Node<Task> *tmp = NULL;
        while (i < n-1 && head->next) {
            head = head->next;
            i++;
        }
        tmp = (Node<Task>*) malloc(sizeof(Node<Task>));
        tmp->obj = t;
        if (head->next) {
            tmp->next = head->next;
        } else {
            tmp->next = NULL;
        }
        head->next = tmp;
    }
    void deleteAt(unsigned int i){
        try {
            Node<Task> *_copy = head;
            if((head!=NULL)&&(i<size))
            {
                for(int _i = 0;i<_i-1;_i++) _copy = _copy->next;
                Node<Task> *tmp = _copy->next;
                if(_copy->next==NULL){}
                else _copy->next = _copy->next->next;
                size--;
                delete tmp;
            }
            head = _copy;
        }
        catch (int a) {
            cerr << "Delete Node exception, code error:" << a << endl;
        }
        
    }
    int Count(){ return size; }
    template <class List>
    Node<Task>* operator[](unsigned int i){
        Node<Task> *_out = head;
        for(int _i = 0; _i<i&&_out;_i++)
            _out = _out->next;
        return _out;
    }
};

#endif /* defined(__Lab4Progr__List__) */
