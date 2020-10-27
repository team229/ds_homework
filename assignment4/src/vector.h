#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>

using namespace std;

struct Tuple{
	//i,j为非零结点的横标，纵标
	int i,j;
	//num为结点的数据域
	int num;
};

typedef Tuple Status;

class Vector{
    private:
        Status *a;
        int size;
        int max_size;
        int cost;
        int k;
    public:
        Vector(int n){
            a=new Status[n];
            size=0;
            max_size=n;
            cost = 0;
            k=2;
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
         * @name: get_value
         * @description: 得到位置n处的取值
         * @param {int}  n
         * @return {int} 
         */
        Status get_value(int n){
            if(n<=size)
                return a[n];
            else
                cout<<"n isn't valid";
        }

        /**
         * @name: resize
         * @description: 动态数组的重分配内存  
         * @param {type} 
         * @return {void} 
         */
        void resize(){
            Status *b=new Status[max_size];
            for(int i=0;i<max_size;i++)
                b[i]=a[i];
            cost += max_size;
            a=new Tuple[int(k*max_size)];
            for(int i=0;i<max_size;i++)
                a[i]=b[i];
            max_size*=k;
        }

        /**
         * @name: push_back
         * @description: 尾删除元素
         * @param {int} num 
         * @return {void} 
         */
        void push_back(Status temp){
            if(size>=max_size)
                resize();
            a[size++]=temp;
        }

        /**
         * @name: back 
         * @description: 得到尾部数据
         * @param {type} 
         * @return {int} 
         */
        Status back(){
            return a[size-1];
        }

        /**
         * @name: pop
         * @description: 尾删除
         * @param {type} 
         * @return {int} 
         */
        Status pop(){
            if(size==0)
                cout<<"There is no element.";
            else
                return a[size--];
        }

        Status pop_head(){
            if(size==0)
                return ;
            Status temp=a[0];
            for(int i=0;i<size;i++)
                a[i]=a[i+1];
            size--;
            return temp;
        }

        int get_cost() {
            return cost;
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