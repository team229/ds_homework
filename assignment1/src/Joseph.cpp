/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-06 21:27:01
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-12 23:42:15
 */
#include <iostream>
#include <algorithm>
#include "link.h"

using namespace std;

//#define TEST

int main(int argc, char* argv[])
{
	int N_max, Y_max;
	#ifdef TEST
		freopen("test.in", "r", stdin);
	#endif
	cin >> N_max >> Y_max;
	freopen("output.out", "w", stdout);
    Link* link = new Link();
	/*
	for(int i = 1 ; i <= 1000; i++) {
		cout << i << " " << link->solve(i, 5, 0) <<  endl;
	}
	*/
	// 判断输入的合法性
	if(N_max < 1 ||  Y_max < 1) {
		cout << "输入错误(Input Error)" << endl;
	}
	else {
		//枚举所有所有n与y并计算相应的结果
		for(int i = 1 ; i <= Y_max; i++) {
			for(int j = 1 ; j <= N_max; j++) {
				cout << "(" << j << "," << i << "," << link->solve(j, i, 0) << ")" << endl;
			}
		}
	}
}