/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-12-04 17:08:01
 * @LastEditTime: 2020-12-05 13:18:38
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream>
#include<vector>
#include<queue>
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
    public:
        //初始化节点数和边数
        Graph(int v,int e){
            ver_num=v;
            edge_num=e;
        }

        /**
         * @name: create_graph
         * @description: 用邻接表创建图结构
         * @param {*}
         * @return {void}
         */
        void create_graph(){
            cout << "Input the vertexes:" << endl;;
            for(int i=0;i<ver_num;i++){
                node temp;
                temp.firstAdj=NULL;
                temp.indegree=0;
                temp.longest=0;
                temp.father=-1;
                cin >> temp.data;
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
         * @name: init_father
         * @description: 初始化每个结点的父亲索引
         * @param {int}m
         * @return {void}
         */        
        void init_father(int m){
            adjList* temp=vertex[m].firstAdj;
            while(temp){
                vertex[temp->self].father=m;
                temp=temp->next;
            }
            /*
            for(int i=0;i<ver_num;i++)
                cout<<vertex[i].father<<endl;
            */
        }

        /**
         * @name: longest_path
         * @description: 计算m到n的最长路径
         * @param {int}m,{int}n
         * @return {int}
         */       
        int longest_path(int m,int n){
            int sum=0;
            adjList *temp;
            queue <node> topo_node;
            init_father(m);
            topo_node.push(vertex[m]);
            while (!topo_node.empty())
            {
                temp=topo_node.front().firstAdj;
                while(temp){
                    sum=vertex[temp->adjvex].longest + temp->weight;
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
            return vertex[n].longest;
        }

        /**
         * @name: print_longest_path
         * @description: 倒序打印最长路径
         * @param {int}m,{int}n
         * @return {void}
         */
        void print_longest_path(int m,int n){
            cout << "The longest_path from m to n is:" <<endl;
            cout << n << " << "; 
            int cnt=vertex[n].father;
            while(cnt!=m){
                cout << cnt << " << ";
                cnt = vertex[cnt].father;
            }
            cout << m << endl; 
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