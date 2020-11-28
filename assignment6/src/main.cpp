/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-28 10:41:06
 * @LastEditTime: 2020-11-28 11:18:09
 */
#include<iostream>
#include"decoding.h"
#include"encoding.h"

using namespace std;

int main(){
    int code_type;
    string file_name;
    cout << "Input the code_type: 0 for encoding , 1 for decoding" << endl;;
    cin >> code_type;
    if(code_type==0){
        cout << "Input your prepared encoding file name:" << endl;
        cin >> file_name;
        Encoding encode;
        encode.input(file_name);
        encode.encoding_file();
        cout << "encoding complete!"<<endl;
    }   else{
        cout << "Input your prepard decoding file name:" << endl;
        cin >> file_name;
        Decoding decode;
        decode.decoding_file(file_name);
        cout << "decoding complete!" <<endl;
    }
    return 0;
}