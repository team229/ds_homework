/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-22 22:51:35
 */
#include <iostream>

#ifndef	MATRIX_H_

#define MATRIX_H_

using namespace std;

typedef struct sparmattp{
	//i,j为非零结点的横标，纵标
	int i,j;
	int data;
	struct sparmattp* down;
	struct sparmattp* right;
}*sparmattp;

class Matrix
{
	private:
		//m,n表示矩阵的行与列数，p表示稀疏矩阵中非零结点的个数
		int m,n,p;
		sparmattp sparse;
	public:
		Matrix(int **a,int rows,int cols){
	
		}
		Matrix operator + (const Matrix &x) {
		
		}	

		Matrix operator * (const Matrix &x) {

		}	

		void insert(int i, int j, int val) {
		
		}
};

#endif