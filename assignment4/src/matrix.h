/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-22 15:08:16
 */
#include <iostream>

#ifndef	MATRIX_H_

#define MATRIX_H_

typedef struct tuple{
	//i,j为非零结点的横标，纵标
	int i,j;
	int num;
}*tuple;

class Matrix
{
private:
	//m,n表示矩阵的行与列数，p表示稀疏矩阵中非零结点的个数
	int m,n,p;
	tuple* tuples;
public:
	Matrix(int **a,int rows,int cols){
		m=rows;
		n=cols;
		tuples=new tuple[m*n];
		int log=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(a[i][j]!=INT_MAX){
					tuples[log]->i=i+1;
					tuples[log]->j=j+1;
					tuples[log]->num=a[i][j];
				}
	}
	Matrix operator + (const Matrix &x) {
		
	}	

	Matrix operator * (const Matrix &x) {

	}

	void insert(int i, int j, int val) {
		
	}
};

#endif