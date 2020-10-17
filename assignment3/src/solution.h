#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include"queue.h"
#include"stack.h"

using namespace std;

class Solution{
    private:
        Stack* stk;
        Queue* que;

    public:
        Solution(){
            stk = new Stack();
            que = new Queue();
        }

        /**
         * @name: clear
         * @description: 清空栈和队列空间 
         * @param {type} 
         * @return {void} 
         */
        void clear(){
            stk->clear();
            que->clear();
        }

        /**
         * @name: readString
         * @description: 读取字符串
         * @param {type} 
         * @return {int} 
         */
        int readString(){
            char a;
            a=getchar();
            while(a!='#'&& a!=EOF){
                if((a>='0'&&a<='9')||(a>='a'&&a<='z')||(a>='A'&&a<='Z')){
                    stk->push(a);
                    que->push(a);
                }
                a=getchar();
            }
            return 1;
        }

        /**
         * @name: check
         * @description: 检查字符串是否是回文
         * @param {type} 
         * @return {int} 
         */
        int check(){
            while(!stk->empty()&&!que->empty()){
                /*
                    debug:   cout<<stk->get_top()<<" "<<que->get_front()<<endl;
                */
                if(stk->get_top()==que->get_front()){
                    stk->pop();
                    que->pop();
                    continue;
                }
                else{
                    clear();
                    cout<<"Dismatch\n";
                    return 0;
                }
            }
            clear();
            cout<<"Match\n";
            return 1;
        }
};



#endif