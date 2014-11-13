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
#include "Error.h"

class Node : public Task{
public:
    Task *obj;
    Node *next;
    int index = 0;
    Node()
    {
        next = NULL;
    }
};
class List: public Node {
    Node *head;
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
        Node *tmp = (Node*) malloc(sizeof(Node));
        tmp->obj = t;
        tmp->next = (head);
        (head) = tmp;
        size++;
       // reNumber();
    }
    
    Node* getLast(Node *head) {
        
            
        Node *temp = new Node();
        try {
            temp = head;
            if (temp == NULL) {
                return NULL;
            }
            while (temp->next) {
                temp = temp->next;
            }
        } catch (Error err) {
            
        }
        return temp;
    }
    Task* pop() {
        Node* prev = NULL;
        Task* val;
        try{
            if (head == NULL) {
                throw Error::NullPointerException();
                exit(-1);
            }
        }
        catch(Error err)
        {
            
        }
        prev = (head);
        val = prev->obj;
        (head) = (head)->next;
        free(prev);
        return val;
    }
    Task* deleteNth(int n) {
        Task *val;
        if (n == 0) {
            head = NULL;
            return 0;
        } else {
            Node *prev = getNth(head,n-1);
            Node *elm  = prev->next;
            val = elm->obj;
            prev->next = elm->next;
            free(elm);
            size--;
            return val;
        }
        size--;
        return val;
    }
    Node* getNth(Node*& hh,int n)
    {
        Node* temp = new Node();
        temp = hh;
        int counter = 0;
        while (counter < n-1 && temp) {
            temp = temp->next;
            counter++;
        }
        return temp;
     }
    //malloc
    void pushBack(Task *t)
    {
        try{
            if(head == NULL) { pushFirst(t); return; }
            Node *last = getLast(head);
            Node *tmp = (Node*) malloc(sizeof(Node));
            tmp->obj = t;
            tmp->next = NULL;
            last->next = tmp;
            size++;
        }
        catch(Error::MemoryAllocError err)
        {
            cerr << "Memory alloc error" << endl;
        }
        //reNumber();
    }
    void reNumber()
    {
        Node *list = new Node();;
        list = this->head;
        for(int i = 0;i <size-1;i++)
        {
            Node * tmp = new Node();
            tmp = getNth(head, i);
            tmp->index = i;
        }
    }
    Task* toArray() {
        int leng = size;
        Node *tmp = (Node*) malloc(sizeof(Node));
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
        Node* temp = new Node();
        temp = this->head;
        while (temp) {
            temp->obj->Print();
            temp = temp->next;
        }
    }
    void insert(unsigned n, Task *t) {
        unsigned i = 0;
        Node *tmp = NULL;
        while (i < n-1 && head->next) {
            head = head->next;
            i++;
        }
        tmp = (Node*) malloc(sizeof(Node));
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
            
        
            Node *_copy = head;
            if((head!=NULL)&&(i<size))
            {
                for(int _i = 0;i<_i-1;_i++) _copy = _copy->next;
                Node *tmp = _copy->next;
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
    
    Node* operator[](unsigned int i){
        Node *_out = head;
        for(int _i = 0; _i<i&&_out;_i++)
            _out = _out->next;
        return _out;
    }
};

#endif /* defined(__Lab4Progr__List__) */
