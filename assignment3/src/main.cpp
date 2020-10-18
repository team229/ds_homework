/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-17 20:51:05
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-18 10:44:19
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
    
    //创建solution类
    Solution* slu=new Solution();
    //循环读取并检查
    while (slu->readString())
        slu->check();
    delete slu;
}