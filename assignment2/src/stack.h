#include <iostream>

#ifndef _LINK_H

#define _LINK_H

//64位系统
#define MaxSize 64

using namespace std;

class Stack
{
    private:
        //top为栈顶指针
        //s为栈空间
        int top;
        int s[MaxSize];

    public:
    
        Stack() {
            top = -1;
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

        /**
         * @name: get_top
         * @description: 返回栈顶元素
         * @param {void} 
         * @return {int} 返回栈顶元素
         */    
        int get_top(){
            return s[top];
        }

        /**
         * @name: push
         * @description: 在栈顶上加入数据
         * @param {int} data 要加入的元素 
         * @return {void} 
         */    
        void push(int data) {
            s[++top] = data;
        }

        /**
         * @name: pop
         * @description: 弹出栈顶元素
         * @param {void} 
         * @return {void} 
         */    
        void pop(){
            top--;
        }
};

class Solution
{
private:
    Stack *binary;
    Stack *octal;

public:
    /**
     * @name: Stack 
     * @description: 初始化栈 
     */
    Solution()
    {
        // stk 要分配内存，否则成为野指针
        binary = new Stack();
        octal = new Stack();
    }

    void print(Stack * stk) {
        while(!stk->empty()) {
            cout << stk->get_top();
            stk->pop();
        }
        cout << endl;
    }

    /**
     * @name: getTop3Bits
     * @description: 得到栈顶的 3个二进制位转化为八进制位
     * @param {type} 
     * @return {char} 
     */
    int getTop3Bits()
    {
        int cnt = 0, result = 0;
        while(!binary->empty() && cnt <= 2) {
            result += binary->get_top() << cnt;
            binary->pop();
            cnt++;
        }
        return result;
    }

    /**
     * @name: ReadBinary 
     * @description: 从stdin中读取二进制串，并存入栈中
     * @param {Stack*} binary 
     * @return {int} 返回1表示读入成功
     */
    int readBinary()
    {
        char c;
        c = getchar();
        while (c != '#' && c != EOF)
        {
            if (c == '\n'){
                c = getchar();
                continue;
            }
            binary->push(c - '0');
            c = getchar();
        }
        return 1;
    }
    
    /**
     * @name: WriteOctal
     * @description: 向栈中写入八进制数，每次取2进制的3个数转换并存入8进制栈
     * @param {Stack*} binary,{Stack*} octal  
     * @return {void} 
     */
    void writeOctal()
    {
        int c;
        
        while (!binary->empty())
        {
            c = getTop3Bits();
            octal->push(c);
        }
        print(octal);
    }
};



#endif