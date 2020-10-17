#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "vector.h"
using namespace std;

//初始长度64
#define BSize 64

class Stack
{
    private:
        //top为栈顶指针
        //vct为栈空间
        int top;
        Vector* vct;

    public:
    
        Stack() {
            top = -1;
            vct=new Vector(BSize);
        }

        /**
         * @name: empty
         * @description: 判断栈是否为空
         * @param {type} 
         * @return {bool} 如果为1则栈为空，否则栈非空 
         */    
        bool empty(){
            return top == -1;
        }

        void clear(){
            top=-1;
            delete vct;
            vct= new Vector(BSize);
        }

        /**
         * @name: get_top
         * @description: 返回栈顶元素
         * @param {void} 
         * @return {int} 返回栈顶元素
         */    
        int get_top(){
            return vct->back();
        }

        /**
         * @name: push
         * @description: 在栈顶上加入数据
         * @param {int} data 要加入的元素 
         * @return {void} 
         */    
        void push(int data) {
            top++;
            vct->push_back(data);
        }

        /**
         * @name: pop
         * @description: 弹出栈顶元素
         * @param {void} 
         * @return {void} 
         */    
        void pop(){
            top--;
            vct->pop();
        }
};



#endif