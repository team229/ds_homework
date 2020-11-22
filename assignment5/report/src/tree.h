/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-22 14:03:27
 * @LastEditTime: 2020-11-22 18:27:46
 */
#include<iostream>
#include<cstring>
using namespace std;

typedef struct binarytree {
    char data;
    struct binarytree *lc;
    struct binarytree *rc;
}btree;

class Solution
{
    private:
        btree *root;
    public:
        Solution(){
            root=new btree;
        };

        /**
         * @name: input_tree 
         * @description: 将输入的字符串转化为树
         * @param {char*}str
         * @return {void}
         */
        void input_tree(char* str){
            if(build_tree(root,str,0)==strlen(str)-1)
                print_tree(root);
            else
                cout<<"Input Error!";
        }
        
        /**
         * @name: build_tree
         * @description: 用递归建树
         * @param {btree*}node,{char*}str,{int}n
         * @return {int}
         */
        int build_tree(btree* node,char* str,int n){
            
            if(str[n]=='*')
                return n;
            else{
                node->data=str[n];
                node->lc=new btree;
                if(str[n+1]=='*')
                    node->lc=NULL;
                n=build_tree(node->lc,str,n+1);
                node->rc=new btree;
                if(str[n+1]=='*')
                    node->rc=NULL;
                n=build_tree(node->rc,str,n+1);
                return n;
            }
        }
        
        /**
         * @name: print_tree
         * @description: 将建成的二叉树输出
         * @param {btree*}root
         * @return {void}
         */
        void print_tree(btree* root){
            if(root){
                cout<<root->data;
                if(root->lc||root->rc){
                    printf("(");
                    print_tree(root->lc);
                    printf(",");
                    print_tree(root->rc);
                    printf(")");
                }
            }
        }   
};