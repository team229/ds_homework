/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-27 22:20:37
 */
#include <iostream>
#include <algorithm>
#include "vector.h"

#ifndef	MATRIX_H_

#define MATRIX_H_

using namespace std;

// 判断x三元组的位置是否小于y
bool tuple_greater(Tuple &x, Tuple &y) {
	if(x.i != y.i) return x.i < y.i;
	else return x.j < y.j;
}

// 判断三元组x是否与y相等
bool tuple_equal(Tuple &x, Tuple &y){
	return x.i == y.i && x.j == y.j;
}

class Matrix
{
	private:
		//m,n表示矩阵的行与列数，p表示稀疏矩阵中非零结点的个数
		int m,n,size,max_size;
		Vector tp;
		
	public:
		Matrix(){
			m=n=size=max_size=0;
			tp = Vector(100);
		}

		/**
   		* @name: Matrix 
   		* @description: 初始化类
   		* @param {int}rows,{int}cols,{int}sum
   		* @return {*}
   		*/
		Matrix(int rows,int cols,int sum){
			m=rows;
			n=cols;
			max_size=sum;
			size=-1;
			tp = Vector(100);
		}

		/**
   		* @name: insert
   		* @description:向三元组表中插入三元组 
   		* @param {Tuple} node
   		* @return {*}
   		*/	
		void insert(Tuple node) {
			int i;
			// 尺寸超限时报错　
			if(size>=max_size)
				printf("Insertion failed!");
			for(i = 0; i <= size; i++) {
				if(tp[i].i == node.i && tp[i].j == node.j) {
					tp[i].num += node.num;
					break;
				}
			}
			if(i > size) {
				size++;
				tp[size].i=node.i;
				tp[size].j=node.j;
				tp[size].num=node.num;
			}
		}


		/**
   		* @name: insert_direct
   		* @description: 向三元组表插入三元组节点
   		* @param {Tuple}node
   		* @return {void}
  		*/
		void insert_direct(Tuple node) {
			if(size >= max_size)
				printf("Insertion failed!");
			size++;
			tp[size].i=node.i;
			tp[size].j=node.j;
			tp[size].num=node.num;
		}

		/**
   		* @name: insert_direct
   		* @description: 向三元组表插入三元组节点的内容
  		* @param {int}i,{int}j,{int}num
  		* @return {void}
 		*/
		void insert_direct(int i, int j, int num) {
			Tuple temp;
			temp.i = i;
			temp.j = j;
			temp.num = num;
			insert_direct(temp);
		}

		/**
  		* @name: insert
 		* @description: 插入前 
 		* @param {int}i,{int}j,{int}num
   		* @return {void}
   		*/
		void insert(int i,int j,int num) {
			Tuple temp;
			temp.i = i;
			temp.j = j;
			temp.num = num;
			insert(temp);
		}

		/**
  		* @name: tuple_sort
 		* @description: 排序三元组表
  		* @param {*}
		* @return {*}
 		*/  
		void tuple_sort() {
			sort(tp.begin(), tp.begin()+size, tuple_greater);
		}

		/**
   		* @name: get_size
   		* @description: 得到三元组表的大小
   		* @param {*}
   		* @return {int}
   		*/
		int get_size(){
			return size;
		}

		/**
   		* @name: operator +
   		* @description: 矩阵进行+运算
   		* @param {Matrix&}x
   		* @return {Matrix}
   		*/
		Matrix operator + (Matrix &x) {
			Matrix result;
			if(x.m!=m || x.n!=n){
				result=Matrix(0,0,0);
				cout<<"Math Error Code: 1" << endl;
				cout<<"The couple of Matrixes can't add to each other!" << endl;
			}
			else{
				result=Matrix(m,n,size+x.size);
				int log1=0,log2=0;
				while(log1<=size||log2<=x.size){
					if (log1 > size){
						result.insert_direct(x.tp[log2]);	
					} else if(log2 > x.size) {
						result.insert_direct(tp[log1]);
					} else if(tuple_equal(tp[log1], x.tp[log2])){
						result.insert_direct(tp[log1].i,tp[log1].j,tp[log1].num+x.tp[log2].num);
						log1++;
						log2++;
					}
					else if(tuple_greater(tp[log1], x.tp[log2])){
						result.insert_direct(tp[log1]);
						log1++;
					}
					else {
						result.insert_direct(x.tp[log2]);
						log2++;
					}
				}		
			}	
			return result;	
		}	

		/**
 		* @name: operator *
   		* @description: 矩阵进行*运算
   		* @param {Matrix&}x
   		* @return {Matrix}
   		*/
		Matrix operator * (Matrix &x) {
			Matrix result;
			if(n!=x.m){
				result=Matrix(0,0,0);
				cout<<"The couple of Matrixes can't multiple to each other!\n";
			}
			else{
				result=Matrix(m,x.n,m*x.m);
				int cur = 0;
				// 枚举行
				for(int i = 1; i <= m; i++) {
					while(tp[cur].i != i && tp[cur].i < i) cur++;
					if(tp[cur].i > i) continue;
					// 枚举列
					for(int j = 1 ; j <= x.n; j++) {
						// 初始化需要添加的三元组
						Tuple temp;
						temp.i = i; temp.j = j; temp.num = 0;
						//计算元素（i，j）处的值
						for(int index = cur; index <= size && tp[index].i == i; index++){
							for(int index_x = 0; index_x <= x.size; index_x++) {
								if(x.tp[index_x].j == j && (x.tp[index_x].i == tp[index].j))
									temp.num += x.tp[index_x].num * tp[index].num;
							}
						}
						// 将三元组添加到result中
						if(temp.num != 0)
							result.insert_direct(temp);
					}
				}
			}
			return result;	
		}
		
		/**
   		* @name: printMatrix
   		* @description: 输出矩阵的三元组表
   		* @param {*}
   		* @return {void}
   		*/
		void printMatrix(){
			cout<<m<<" "<<n<<""<<size<<endl;
			for(int i=0;i<=size;i++){
				cout<< "(" << tp[i].i<<" "<<tp[i].j<<" "<<tp[i].num<< ")" << endl;
			}
		}
};

#endif