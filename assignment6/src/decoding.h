/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-28 10:37:00
 * @LastEditTime: 2020-11-28 11:18:00
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>
#include"define.h"
using namespace std;

#ifndef _DECODING_H_
#define _DECODING_H_

class Decoding
{
    private:
        Node *root;         //哈夫曼树根节点
        string table[300];  //编码表
        long long total_bits = 0;   //encoding_file文件中编码内容的位长
    public:
        /**
         * @name: binary_to_string
         * @description: 将二进制char数，转化为字符串
         * @param {unsigned char}c,{int}len
         * @return {string}
         */
        string binary_to_string(unsigned char c,int len){
            string temp;
            for(int i=0;i<8;i++){
                if(c%2==0)
                    temp='0'+temp;
                else
                    temp='1'+temp;
                c>>=1;
            }
            return temp;
        }

        /**
         * @name: read_table
         * @description: 从encoding_file中读取编码表
         * @param {ifstream}&fin
         * @return {void}
         */
        void read_table(ifstream &fin){
            int size;
            char c;
            coding_table temp;
            //fin.read((char*)&total_bits,8);
            fin.read((char*)&size,4);
            for(int i=0;i<size;i++){
                string s;
                fin.read((char*)&temp,sizeof(temp));
                for(int j = 0; j < temp.size; j++) {
                    fin.read(&c, 1);
                    s += c;
                }
                table[temp.byte] = s;
            }
            /*for(int i=0;i<256;i++){
                if(!table[i].empty())
                    cout<<(char)i<<" "<<table[i]<<endl;
            }*/
        }

        /**
         * @name: build_decoding
         * @description: 递归生成解码树
         * @param {Node*}node,{unsigned char}i,{string}s
         * @return {void}
         */
        void build_decoding(Node *node,unsigned char i,string s){
            if(s.empty()) {
                node->flag=1;
                node->val=i;
            } else  if(s[0]=='0'){
                if(node->ld == NULL) {
                    node->ld = new Node();
                }
                build_decoding(node->ld,i,&s[1]);
            } else if(s[0]=='1'){
                if(node->rd == NULL) {
                    node->rd = new Node();
                }
                build_decoding(node->rd,i,&s[1]);
            }
        }
    
        /**
         * @name: decoding_tree
         * @description: 通过编码表还原哈夫曼树，进行解码
         * @param {*}
         * @return {void}
         */
        void decoding_tree(){
            root=new Node();
            for(int i=0;i<256;i++){
                if(!table[i].empty()){
                    build_decoding(root,i,table[i]);
                }
            }
        }

        /**
         * @name: read_data
         * @description: 从encoding_file中读取编码内容，解析后写入decoding_file
         * @param {ifstream}&fin,{ofstream}&fout
         * @return {*}
         */
        void read_data(ifstream &fin,ofstream &fout){
            unsigned char c;
            Node* temp=root;
            string str;
            while(fin.read((char*)&c,1)){
                if(total_bits>=8)
                    str=binary_to_string(c,8);
                else{
                    str=binary_to_string(c, total_bits);
                }
                for(int i=0;i < min(total_bits, 8ll);i++){
                    if(str[i]=='0'){
                        temp=temp->ld;
                    }
                    else{
                        temp=temp->rd;
                    }
                    if(temp->flag==1){
                        fout.write((char*)&(temp->val),1);
                        temp=root;
                    }
                }
                total_bits-=8;
                if(total_bits <= 0) break;
            }                
        }

        /**
         * @name: decoding_file
         * @description: 读取encoding_file，并解码后生成文件decoding_file
         * @param {*}
         * @return {*}
         */
        void decoding_file(string file_name){
            ifstream fin(file_name,ios::binary);
            ofstream fout("decoding_file",ios::binary);
            /*
            unsigned char c[1];
            while(fin.read((char*)c,1))
                printf("%02x",c[0]);
            */
            read_table(fin);
            decoding_tree();
            fin.read((char*)&total_bits, 8);
            read_data(fin,fout);
            fin.close();
            fout.close();   
        }
};  


#endif