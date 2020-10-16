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

        /**
         * @name: empty 
         * @description: 判断是否为空 
         * @param {type} 
         * @return {bool} 
         */
        bool empty(){
            return rear==-1;
        }

        /**
         * @name: size
         * @description: 返回队列长度 
         * @param {type} 
         * @return {int} 
         */
        int size(){
            return rear-front;
        }   

        /**
         * @name: push
         * @description: 尾插元素
         * @param {int} data 
         * @return {void} 
         */
        void push(int data){
            rear++;
            if(empty())
                front++;
            vct->push_back(data);
        }

        /**
         * @name: pop
         * @description: 删除队头指针
         * @param {type} 
         * @return {int} 
         */
        int pop(){
            if(empty())
                return -1;
            if(front==1)
                front--;
            return vct->pop_head();
        }

        /**
         * @name: print
         * @description: 输出队列元素
         * @param {type} 
         * @return {void} 
         */
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