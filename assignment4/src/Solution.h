/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:26
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-26 22:02:42
 */
#include<iostream>
#include"matrix.h"

#ifndef SOLUTION_H_
#define SOLUTION_H_

using namespace std;

class Solution{
    private:
        Matrix *x,*y;
        Matrix result;
        int operate_code;
    public:
        void readMatrix(){
            int m,n,size,i,j,num;
            //初始化矩阵A
            cout<<"Inpput the Matrix A:\n"<<"rows,cols,size:\n";
            cin>>m>>n>>size;
            x=new Matrix(m,n,size);
            cout<<"i,j,num:\n";
            for(int s=0;s<size;s++){
                cin>>i>>j>>num;
                x->insert(i,j,num);
            }
            x->tuple_sort();

            //初始化矩阵B
            cout<<"Input the Matrix B:\n"<<"rows,cols,size:\n";;
            cin>>m>>n>>size;
            y=new Matrix(m,n,size);
            cout<<"i,j,num:\n";
            for(int s=0;s<size;s++){
                cin>>i>>j>>num;
                y->insert(i,j,num);
            }
            y->tuple_sort();
        }

        void operate(){
            cout<<"Please input the operator_code:\n";
            cout<<"\'1 for * and 0 for +\'\n";
            cin>>operate_code;
            if(!operate_code){
                cout<<"The result of Adding is:\n";
                result= (*x) + (*y);
            }
            else{
                cout<<"The result of Multiply is:\n";
                result= (*x) * (*y);
            }
        }

        void printMatrix(){
            result.printMatrix();
        }
};

#endif
