/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-22 15:17:20
 * @LastEditTime: 2020-11-22 18:25:20
 */
#include<iostream>
#include<cstring>
#include"tree.h"
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
    getchar();
    char str[100];
    //每个字符串建立一次二叉树
    while(1){
        gets(str);
        if(str[0]=='#')
            break;
        Solution* slu=new Solution();
        slu->input_tree(str);
        cout<<endl;
    }
    
    return 0;
}