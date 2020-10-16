/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-16 15:11:29
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-16 17:33:28
 */
/*
Stack
用栈来 实现2进制转换为8进制
*/

#include <iostream>
#include "stack.h"
using namespace std;



int main()
{
    int input_mode = 0;
    //cout << "选择输入模式(0表示交互式输入,1表示文件输入)" << endl;
    cin >> input_mode;
    if(input_mode == 1) {
        //文件模式
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    //建立Solution对象
    Solution *solution = new Solution();
    //循环读入二进制串，并输出
    while (solution->readBinary())
        solution->writeOctal();

    delete solution;
}
