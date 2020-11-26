/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-25 17:31:12
 * @LastEditTime: 2020-11-26 14:12:50
 */
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

typedef struct HuffmanTree
{
    int flag;
    string s;
    int fre;
    struct HuffmanTree *ld,*rd;
    HuffmanTree(int a,string b,int c){
        flag=a;
        s=b;
        fre=c;
    }
    HuffmanTree(int a,int c){
        flag=a;
        fre=c;
    }
}node;

class Huffman
{
    private:
        ;
    public:
        Huffman(const map<string,int> &map){
            map;
        };
};