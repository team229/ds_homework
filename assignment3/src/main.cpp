#include<iostream>
#include"solution.h"

using namespace std;

int main(){
    int input_code=0;
    // cout<<"选择输入模式(0表示交互式输入,1表示文件输入)"<<endl;
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