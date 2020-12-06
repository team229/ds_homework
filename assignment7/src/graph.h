/*
 * @Descripttion: 111
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-12-04 17:08:01
 * @LastEditTime: 2020-12-06 14:10:11
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//图的节点data类型
typedef char elem;

//邻接链表
struct adjList{
    int weight;
    int self;       //自己的节点索引
    int adjvex;     //相邻的节点索引
    adjList *next;
};

//结点结构
struct node {
    elem data;
    int indegree;   //入度
    int longest;    //到 m 节点的最长距离
    int father;     // 最长距离路径上的父亲节点
    adjList * firstAdj;
};

class Graph
{
    private:
        vector <node> vertex;
        int ver_num,edge_num;
        int max_node;
    public:
        //初始化节点数和边数
        Graph(int v,int e){
            ver_num=v;
            edge_num=e;
            max_node=-1;
        }

        /**
         * @name: create_graph
         * @description: 用邻接表创建图结构
         * @param {*}
         * @return {void}
         */
        void create_graph(){
            for(int i=0;i<ver_num;i++){
                node temp;
                temp.firstAdj=NULL;
                temp.indegree=0;
                temp.longest=0;
                temp.father=-1;
                vertex.push_back(temp);
            }
            cout << "Input the edges from i to j with weight:" <<endl;
            int x,y,w;
            for(int i=0;i<edge_num;i++){
                cin >> x >> y >> w;
                vertex[y].indegree++;
                adjList *temp=new adjList,*temp2=vertex[x].firstAdj;
                temp->self=y;
                temp->adjvex=x;
                temp->weight=w;
                temp->next=NULL;
                if(!temp2)
                    vertex[x].firstAdj=temp;
                else
                {
                    while(temp2->next)
                        temp2=temp2->next;
                    temp2->next=temp;
                }
            }
        }

        /**
         * @name: longest_path
         * @description: 计算图中某两点的最长路径
         * @param 
         * @return {void}
         */          
        void longest_path(){
            adjList *temp;
            queue <node> topo_node;
            for(int i=0;i< ver_num;i++){
                if(vertex[i].indegree==0){
                    vertex[i].father=i;
                    topo_node.push(vertex[i]);
                }
            }
            while (!topo_node.empty())
            {
                temp=topo_node.front().firstAdj;
                while(temp){
                    int sum=vertex[temp->adjvex].longest + temp->weight;
                    if(vertex[temp->self].longest < sum){
                        vertex[temp->self].longest = sum;  
                        vertex[temp->self].father = temp->adjvex;
                    }
                    if((--vertex[temp->self].indegree)==0)
                        topo_node.push(vertex[temp->self]);
                    temp=temp->next;
                }
                topo_node.pop();
            }
            int max=-1;
            for(int i=0;i<ver_num;i++)
                if(vertex[i].longest > max){
                    max=vertex[i].longest;
                    max_node=i;
                }
        }

        /**
         * @name: print_longest_path
         * @description: 倒序打印最长路径
         * @param {int}m,{int}n
         * @return {void}
         */
        void print_longest_path(){
            cout << "The longest disatance is: ";
            cout << vertex[max_node].longest << endl; 
            cout << "The longest_path is:" <<endl;
            
            stack <int> stk;
            int temp=max_node;
            while(vertex[temp].father!=temp){
                stk.push(temp);
                temp=vertex[temp].father;
            }
            stk.push(temp);
            while (!stk.empty())
            {
                cout << stk.top() << " >> ";
                stk.pop();
            }
            cout << "end "<< endl;
        }

        /**
         * @name: print_graph
         * @description: 按邻接表打印图结构
         * @param {*}
         * @return {void}
         */      
        void print_graph(){
            adjList* temp;
            for(int i=0;i<ver_num;i++){
                cout << i << " > ";
                temp=vertex[i].firstAdj;
                while (temp)
                {
                    cout << temp->self << " > ";
                    temp=temp->next;
                }
                cout << endl;
            }
        }
};

#endif