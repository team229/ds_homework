#ifndef _QUEUE_H
#define _QUEUE_H

#include<iostream>
#include"vector.h"
using namespace std;

//队列初始长度
#define BeginSize 50

class Queue{
    private:
        //front为队头指针,rear为队尾指针
        //vct为队列空间
        int front,rear;
        Vector* vct;
    public:
        Queue(){
            front=rear=-1;
            vct=new Vector(BeginSize);
        }
        bool empty(){
            return rear==-1;
        }
        int size(){
            return rear-front;
        }   
        void push(int data){
            rear++;
            if(empty())
                front++;
            vct->push_back(data);
        }
        int pop(){
            if(empty())
                return -1;
            if(front==1)
                front--;
            return vct->pop_head();
        }
        void print(){
            vct->print();
        }
};

/*
test:

int main(){
    Queue* qe= new Queue();
    for(int i=0;i<5;i++)
        qe->push(i);
    qe->pop();
    qe->pop();
    qe->print();
}
*/

#endif