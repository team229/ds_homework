/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-16 15:11:29
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-18 11:58:21
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
    cout << "choose prefered mode, 0 for interactive, 1 for file input(input.in)" << endl;
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
    //solution->print_cost();
    delete solution;
}
