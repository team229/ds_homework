#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>

using namespace std;

class Vector{
    private:
        int *a;
        int size;
        int max_size;
    public:
        Vector(int n){
            a=new int[n];
            size=0;
            max_size=n;
        }

        /**
         * @name: empty 
         * @description: 判断动态数组是否为空
         * @param {type} 
         * @return {int} 
         */
        int empty(){
            return size==0;
        }

        /**
         * @name: get_size
         * @description: 返回动态数组的当前大小
         * @param {type} 
         * @return {int} 
         */
        int get_size(){
            return size;
        }

        /**
         * @name: get_max_size 
         * @description: 返回动态数组的最大
         * @param {type} 
         * @return {int} 
         */
        int get_max_size(){
            return max_size;
        }

        /**
         * @name: resize
         * @description: 动态数组的重分配内存  
         * @param {type} 
         * @return {void} 
         */
        void resize(){
            int *b=new int[max_size];
            for(int i=0;i<max_size;i++)
                b[i]=a[i];
            a=new int[int(1.6*max_size)];
            for(int i=0;i<max_size;i++)
                a[i]=b[i];
            max_size*=1.6;
        }

        /**
         * @name: push_back
         * @description: 尾删除元素
         * @param {int} num 
         * @return {void} 
         */
        void push_back(int num){
            if(size>=max_size)
                resize();
            a[size++]=num;
        }

        /**
         * @name: back 
         * @description: 得到尾部数据
         * @param {type} 
         * @return {int} 
         */
        int back(){
            return a[size-1];
        }

        /**
         * @name: pop
         * @description: 尾删除
         * @param {type} 
         * @return {int} 
         */
        int pop(){
            if(size==0)
                return -1;
            return a[size--];
        }

        /**
         * @name: print 
         * @description: 输出动态数组元素
         * @param {type} 
         * @return {void} 
         */
        void print(){
            for(int i=0;i<size;i++)
                cout<<a[i]<<" ";
        }
};

/*
test:

int main(){
    Vector* vct=new Vector(5);
    for(int i=0;i<10;i++){
        vct->push_back(i);
    }
    vct->print();
}

*/

#endif