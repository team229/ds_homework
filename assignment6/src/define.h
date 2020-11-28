/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-28 10:27:22
 * @LastEditTime: 2020-11-28 10:55:48
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

#ifndef _DEFINE_H_
#define _DEFINE_H_

//定义哈夫曼树的结点类型
class Node
{
    public:
    Node* ld,* rd;      //左孩子，右孩子
    int flag;           //是否是叶子节点
    unsigned char val;  //存储的原8位字串
    int fre;            //原8位字串的频率
    Node(){
        flag=0;
        val=0;
        fre=0;
        ld = NULL;
        rd = NULL;
    };
    Node(int a,char b,int c){
        flag=a;
        val=b;
        fre=c;
        ld = NULL;
        rd = NULL;
    }
    Node(int a,int c){
        flag=a;
        val = 0;
        fre=c;
        ld = NULL;
        rd = NULL;
    }
};

//定义向encode_file中写入的编码表
struct coding_table
{
    unsigned char size;     //编码后对应字串的长度
    unsigned char byte;     //原8位字串
};

//另命名map每个元素的类型
typedef pair<const char,int> PAIR;

//priority_queue的排序函数，产生小顶堆
struct cmp
{
    bool operator() (const Node* a, const Node* b) {
        return a->fre > b->fre;
    }
};

#endif