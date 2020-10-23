/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-10-23 17:28:15
 */
#include <iostream>

#ifndef	MATRIX_H_

#define MATRIX_H_

using namespace std;

typedef struct tuple{
	//i,j为非零结点的横标，纵标
	int i,j;
	//num为结点的数据域
	int num;
}*Tuple,tup;

class Matrix
{
	private:
		//m,n表示矩阵的行与列数，p表示稀疏矩阵中非零结点的个数
		int m,n,size,max_size;
		Tuple *tp;

	public:
		Matrix(int rows,int cols,int sum){
			m=rows;
			n=cols;
			max_size=sum;
			size=-1;
			tp=new Tuple[sum];
		}

		Matrix operator + (const Matrix &x) {
			if(x.m!=m || x.n!=n){
				printf("The couple of Matrixes can't add to each other!\n");
			}
			else{
				Matrix result=Matrix(m,n,size+x.size);
				int log1=0,log2=0;
				while(log1<=size||log2<=x.size){
					if(tp[log1]->i < x.tp[log2]->i){
						result.insert(tp[log1]);
						log1++;
					}
					else if(tp[log1]->i > x.tp[log2]->i){
						result.insert(x.tp[log2]);
						log2++;
					}
					else{
						if(tp[log1]->j < x.tp[log2]->j){
							result.insert(tp[log1]);
							log1++;						
						}
						else if(tp[log1]->j > x.tp[log1]->j){
							result.insert(x.tp[log2]);
							log2++;
						}
						else{
							Tuple temp=new tup;
							temp->i=tp[log1]->i;
							temp->j=tp[log1]->j;
							temp->num=tp[log1]->num+x.tp[log2]->num;
							result.insert(temp);
							delete temp;
							log1++;
							log2++;
						}
					}
				}
				for(int i=log1;i<=size;i++)
					result.insert(tp[i]);
				for(int i=log2;i<=x.size;i++)
					result.insert(x.tp[i]);
				return result;				
			}	
		}	

		Matrix operator * (const Matrix &x) {
			if(n!=x.m){
				printf("The couple of Matrixes can't multiple to each other!\n");
			}
			else{
				Matrix result=Matrix(m,x.n,m*x.m);
				for(int i=0;i<m;i++){
					for(int j=0;j<x.n;j++){
						Tuple temp=new tup;
						temp->i=i;
						temp->j=j;
						int sum=0;
						//枚举一行一列中非零元素
						for(int p=0;p<=size;p++){
							if(tp[p]->i==i+1){
								for(int q=0;q<=x.size;q++){
								    if(x.tp[q]->j==j+1&&x.tp[q]->i==tp[p]->j){
										sum+=tp[p]->num*x.tp[q]->num;
									 	break;
									}
								}
							}
						}
						if(sum)	{
							temp->num=sum;
							result.insert(temp);
						}
					}
				}
				return result;
			}
		}	

		int insert(Tuple node) {
			if(size>=max_size)
				return 0;
			size++;
			tp[size]->i=node->i;
			tp[size]->j=node->j;
			tp[size]->num=node->num;
			return 1;
		}
};

#endif