/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-12-05 13:16:38
 * @LastEditTime: 2020-12-05 15:49:57
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-12-04 17:08:01
 * @LastEditTime: 2020-12-05 13:16:01
 */
#include<iostream>
#include"graph.h"

using namespace std;

int main(){

    int ver_num,edge_num,longest,m,n;
    cout << "Input the number of vertex and edges:" << endl;;
    cin >> ver_num >> edge_num;
    Graph* tu = new Graph(ver_num,edge_num);
    tu->create_graph();

    tu->longest_path();
    tu->print_longest_path();
    //tu->print_graph();
}