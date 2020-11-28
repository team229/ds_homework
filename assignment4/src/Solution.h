/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-27 23:00:32
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

        /**
         * @name: readMatrix 
         * @description: 读取A，B矩阵的三元组表
         * @param {*}
         * @return {void}
         */
        void readMatrix(){
            int m,n,size,i,j,num;
            //初始化矩阵A
            cout<<"Inpput the Matrix A:\n"<<"rows,cols,size:\n";
            cin>>m>>n>>size;
            x=new Matrix(m,n,size);
            cout<<"i,j,num:\n";
            for(int s=0;s<size;s++){
                cin>>i>>j>>num;
                x->insert_direct(i,j,num);
            }
            x->tuple_sort();

            //初始化矩阵B
            cout<<"Input the Matrix B:\n"<<"rows,cols,size:\n";;
            cin>>m>>n>>size;
            y=new Matrix(m,n,size);
            cout<<"i,j,num:\n";
            for(int s=0;s<size;s++){
                cin>>i>>j>>num;
                y->insert_direct(i,j,num);
            }
            y->tuple_sort();
        }

        /**
         * @name: operate 
         * @description: 
         * @param {*}
         * @return {void}
         */
        void operate(){
            cout<<"Please input the operator_code:\n";
            cout<<"\'1 for * and 0 for +\'\n";
            cin>>operate_code;
            if(!operate_code){
                result= (*x) + (*y);
                cout<<"The result of Adding is:\n";
            }
            else{
                result= (*x) * (*y);
                cout<<"The result of Multiply is:\n";
            }
        }

        /**
         * @name: printMatrix 
         * @description: 
         * @param {*}
         * @return {void}
         */
        void printMatrix(){
            result.printMatrix();
        }
};

#endif
