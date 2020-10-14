/*
Stack
用栈来 实现2进制转换为8进制
*/

#include <iostream>
#include "link.h"
using namespace std;


int main()
{
    //建立2进制栈
    Stack *binary = new Stack();

    //建立8进制数栈
    Stack *octal = new Stack();

    //循环读入二进制串，并输出
    while (ReadBinary(binary))
        WriteOctal(binary, octal);

    delete binary;
    delete octal;
}
