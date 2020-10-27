/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:20
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-27 16:48:06
 */

#include<iostream>
#include"solution.h"
using namespace std;

int main(){
    int input_code=0;
    cout << "choose prefered mode, 0 for interactive, 1 for file input(input.in)" << endl;
    cin>>input_code;
    if(input_code==1){
        //文件模式
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    Solution slu;
    slu.readMatrix();
    slu.operate();
    slu.printMatrix();
    return 0;
}