/*
Stack
用栈来 实现2进制转换为8进制
*/

#include <iostream>
using namespace std;

//64位系统
#define MaxSize 64

struct stack
{
    int top;
    char s[MaxSize];
};

class Stack
{
private:
    stack *stk;

public:
    //初始化
    Stack()
    {
        // stk 要分配内存，否则成为野指针
        stk = new stack();
        stk->top = -1;
    }
    void Push(char c)
    {
        if (stk->top == (MaxSize - 1))
            printf("Stack is Full!");
        else
        {
            stk->top++;
            stk->s[stk->top] = c;
        }
    }
    void Pop()
    {
        if (stk->top == -1)
            printf("There is no element.");
        else
        {
            stk->top--;
        }
    }
    void Print()
    {
        for (int i = 0; i <= stk->top; i++)
        {
            printf("%c", stk->s[i]);
        }
        printf("\n");
    }
    char getTop3Bits()
    {
        if (stk->top == -1)
            return 0;
        int top = stk->top;
        char result;
        if (top >= 2)
        {
            stk->top -= 3;
            result = (stk->s[top]-'0') + 2 * (stk->s[top - 1]-'0') + 4 * (stk->s[top - 2]-'0') + '0';
        }
        else
        {
            stk->top = -1;
            if (top == 1)
                result = (stk->s[top]-'0') + 2 * (stk->s[top - 1]-'0') + '0';
            if (top == 0)
                result = stk->s[top] + '0';
        }
        return result;
    }
};

int main()
{
    Stack *binary = new Stack();
    char c;
    scanf("%c", &c);
    while (c != '#')
    {
        binary->Push(c);
        scanf("%c", &c);
    }
    Stack *octal = new Stack();
    c = binary->getTop3Bits();
    while (c != 0)
    {
        octal->Push(c);
        c = binary->getTop3Bits();
    }
    octal->Print();
    
    delete binary;
    delete octal;
}
