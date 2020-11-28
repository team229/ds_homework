/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-28 10:34:04
 * @LastEditTime: 2020-11-28 11:17:06
 */
#include<iostream>
#include<algorithm>
#include<map>
#include <cstring>
#include<string>
#include <cstdio>
#include<fstream>
#include<queue>
#include"define.h"
using namespace std;

#ifndef _ENCODING_H_
#define _ENCODING_H_

class Encoding
{
    private:
        Node *root;         //哈夫曼树根节点
        string table[300];  //编码表
        string encode_str;  //取出8位编码字串
        map<unsigned char, int> fres;   //存储原8位字串与对应频率
        priority_queue<Node*, vector<Node*>, cmp> nodes;    //存储结点类型的编码结点
        long long total_bits = 0;   //存储编码后文件中比特位总数
    public:
        /**
         * @name: input
         * @description: 输入文件，生成哈夫曼树
         * @param {*}
         * @return {void}
         */
        void input(string file_name) {
            unsigned char* line = new unsigned char[256];
            ifstream fin(file_name, ios::binary);
            //每次读1024bits后生成编码表
            int file_start = fin.tellg();
            fin.seekg(0, ios::end);
            int file_end = fin.tellg();
            fin.seekg(0, ios::beg);
            int size = file_end - file_start;
            while(size >= 128){
                size -= 128;
                fin.read((char*)line, 128);
                calu_fre(line);
            }
            unsigned char temp;
            while(size != 0) {
                fin.read((char*)&temp, 1);
                if(fres.find(temp) != fres.end()){
                    fres[temp]++;
                } else {
                    fres[temp] = 1;
                }
                size--;
            }
            sort_map();
            fin.close();
            /*for(auto x = fres.begin(); x != fres.end(); x++) {
                cout << (*x).first << " " << (*x).second << endl;
            }*/
        }
        
        /**
         * @name: calu_fre
         * @description: 计算每个8位字串频率，存入map
         * @param {unsigned char*}line
         * @return {void}
         */
        void calu_fre(unsigned char* line){
            for(int i = 0; i < 128; i++) {
                if(fres.find(line[i]) != fres.end()){
                    fres[line[i]]++;
                } else {
                    fres[line[i]] = 1;
                }
            }
        }
        
        /**
         * @name: sort_map
         * @description: 将map存入priority_queue中，并进行小顶堆排序
         * @param {*}
         * @return {void}
         */
        void sort_map(){
            for(auto x = fres.begin(); x != fres.end(); x++) {
                PAIR temp = *x;
                Node* node=new Node(1,temp.first,temp.second);
                nodes.push(node);
            }
            /*
            while(!nodes.empty()){
                cout<<nodes.top()->val<<endl;
                nodes.pop();
            }
            */
           create_huffman();
        }

        /**
         * @name: create_huffman
         * @description: 通过优先队列来创建哈夫曼树
         * @param {*}
         * @return {*}
         */
        void create_huffman(){
            Node *temp,*node1,*node2;
            while(nodes.size()>1){
                node1=nodes.top();
                nodes.pop();
                node2=nodes.top();
                nodes.pop();
                temp=new Node(0,node1->fre+node2->fre);
                temp->ld= node1;
                temp->rd= node2;
                nodes.push(temp);
            }
            root=temp;
            string temp_str = "";
            encoding_tree(root, temp_str);
            
            /*for(int i = 0; i < 256; i++) {
                if(!table[i].empty())
                    cout << i << " " << table[i] << endl;
            }*/
        }

        /**
         * @name: encoding_tree
         * @description: 遍历哈夫曼树，生成编码表
         * @param {Node*}rt,{string}str
         * @return {void}
         */
        void encoding_tree(Node* rt, string str){
            if(rt->flag) {
                table[rt->val] = str;
                total_bits+=str.size()*rt->fre;
            } else {
                if(rt->ld != NULL) {
                    encoding_tree(rt->ld, str + "0");
                }
                if(rt->rd != NULL) {
                    encoding_tree(rt->rd, str + "1");
                }
            }
        }

        /**
         * @name: string_to_binary
         * @description: 将字符串转化为二进制char数
         * @param {string}str,{int}len
         * @return {unsigned char}
         */
        unsigned char string_to_binary(string str,int len){
            unsigned char temp=0;
            for(int i=0;i<len;i++){
                temp=(temp<<1);
                if(str[i]=='1')
                    temp|=1;
            }
            temp<<=(8-len);
            return temp;
        }

        /**
         * @name: write_table
         * @description: 向encoding_file中写入编码表
         * @param {ofstream}&fout
         * @return {void}
         */
        void write_table(ofstream &fout){
            int cur=0;
            char c;
            for(int i=0;i<256;i++){
                if(!table[i].empty()){
                    cur++;
                }
            }
            fout.write((char*)&cur,4);
            for(int i=0;i<256;i++){
                if(!table[i].empty()){
                    //test:  cout<<i<<" "<<table[i]<<endl;
                    coding_table temp;
                    temp.byte=i;
                    temp.size=table[i].size();
                    fout.write((char*)&temp,sizeof(temp));
                    for(int j = 0; j < table[i].length(); j++) {
                        c = table[i][j];
                        fout.write(&c, 1);
                    }
                }
            }
        }

        /**
         * @name: write_data
         * @description: 向encoding_file中写入编码后的二进制串
         * @param {unsigned char*}line,{ofstream}&fout
         * @return {void}
         */
        void write_data(unsigned char* line, ofstream &fout){
            unsigned char temp;
            for(int i=0;i< 128;i++){
                encode_str+=table[line[i]];
                if(encode_str.size()>7){
                    temp = string_to_binary(encode_str,8);
                    fout.write((char*)&temp,1);
                    encode_str=&encode_str[8];
                }
            }
        }

        /**
         * @name: encoding_file
         * @description: 产生编码文件encoding_file
         * @param {*}
         * @return {void}
         */
        void encoding_file(){
            unsigned char *line=new unsigned char[130];
            unsigned char temp;
            ifstream fin("data",ios::binary);
            ofstream fout("encoding_file",ios::binary);
            write_table(fout);
            fout.write((char*)&total_bits, 8);

            int file_start = fin.tellg();
            fin.seekg(0, ios::end);
            int file_end = fin.tellg();
            fin.seekg(0, ios::beg);
            int size = file_end - file_start;
            
            while(size >= 128){
                size -= 128;
                fin.read((char*)line,128);
                write_data(line,fout);
            }

            unsigned char c;

            while(size != 0) {
                fin.read((char*)&c, 1);
                encode_str+=table[c];
                if(encode_str.size()>7){
                    temp = string_to_binary(encode_str,8);
                    fout.write((char*)&temp,1);
                    encode_str=&encode_str[8];
                }
                size--;
            }
            temp= string_to_binary(encode_str,encode_str.size());
            fout.write((char*)&temp,1);
            fin.close();
            fout.close();
        }
};  

#endif