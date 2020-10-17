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

        void clear(){
            front=rear=-1;
            delete vct;
            vct=new Vector(BeginSize);
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
         * @name: get_front
         * @description: 得到队头的值
         * @param {type} 
         * @return {int} 
         */
        int get_front(){
            //debug:   cout<<front<<endl;
            return vct->get_value(front);
        }

        /**
         * @name: push
         * @description: 尾插元素
         * @param {int} data 
         * @return {void} 
         */
        void push(int data){
            //debug:  cout<<front<<" "<<rear<<endl;
            if(rear==-1)
                front++;
            rear++;
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
            if(rear==0)
                front--;
            rear--;
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
    cout<<qe->get_front()<<endl;
    qe->print();
}

*/

#endif