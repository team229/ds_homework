#include <iostream>

using namespace std;

#ifndef _LINK_H

#define _LINK_H

//64位系统
#define MaxSize 64

struct stack
{
    //top为栈顶指针
    //s为栈空间
    int top;
    char s[MaxSize];
};

class Stack
{
private:
    stack *stk;

public:
    /**
     * @name: Stack 
     * @description: 初始化栈 
     */
    Stack()
    {
        // stk 要分配内存，否则成为野指针
        stk = new stack();
        stk->top = -1;
    }

    /**
     * @name: Push
     * @description: 入栈操作 
     * @param {char} c
     * @return {void}
     */
    void Push(char c)
    {
        if (stk->top == (MaxSize - 1))
            cout<<"Stack is Full!";
        else
        {
            stk->top++;
            stk->s[stk->top] = c;
        }
    }

    /**
     * @name: Pop
     * @description: 出栈操作 
     * @param {} 
     * @return {void} 
     */
    void Pop()
    {
        if (stk->top == -1)
            cout<<"There is no element.";
        else
        {
            stk->top--;
        }
    }

    /**
     * @name: Print
     * @description: 从栈顶打印所有元素，并清空 
     * @param {type} 
     * @return {void} 
     */
    void Print()
    {
        for (int i = stk->top; i >= 0; i--)
        {
           cout<<stk->s[i];
        }
        cout<<endl;
        stk->top = -1;
    }

    /**
     * @name: getTop3Bits
     * @description: 得到栈顶的 3个二进制位转化为八进制位
     * @param {type} 
     * @return {char} 
     */
    char getTop3Bits()
    {
        if (stk->top == -1)
            return 0;
        int top = stk->top;
        char result;
        if (top >= 2)
        {
            stk->top -= 3;
            result = (stk->s[top] - '0') + 2 * (stk->s[top - 1] - '0') + 4 * (stk->s[top - 2] - '0') + '0';
        }
        else
        {
            stk->top = -1;
            if (top == 1)
                result = (stk->s[top] - '0') + 2 * (stk->s[top - 1] - '0') + '0';
            if (top == 0)
                result = stk->s[top];
        }
        return result;
    }
};

/**
 * @name: ReadBinary 
 * @description: 从文件读取二进制串，并存入栈中
 * @param {Stack*} binary ,{FILE*}fp
 * @return {int} 
 */
int ReadBinary(Stack *binary,FILE *fp)
{
    char c;
    c=fgetc(fp);
    if(c=='\n') c=fgetc(fp);
    while (c != '#')
    {
        binary->Push(c);
        c=fgetc(fp);
        if(c=='\n') c=fgetc(fp);
    }
    return 1;
}

/**
 * @name: WriteOctal
 * @description: 向栈中写入八进制数，每次取2进制的3个数转换并存入8进制栈
 * @param {Stack*} binary,{Stack*} octal  
 * @return {void} 
 */
void WriteOctal(Stack *binary, Stack *octal)
{
    char c;
    c = binary->getTop3Bits();
    while (c != 0)
    {
        octal->Push(c);
        c = binary->getTop3Bits();
    }
    octal->Print();
}

#endif