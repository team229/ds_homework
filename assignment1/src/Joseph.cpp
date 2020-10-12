/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-06 21:27:01
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-12 21:54:52
 */
#include <iostream>
#include <algorithm>
#include "link.h"

using namespace std;

int main()
{
	int N_max, Y_max;
	cin >> N_max >> Y_max;
	freopen("output.out", "w", stdout);
    Link* link = new Link();
	/*
	for(int i = 1 ; i <= 1000; i++) {
		cout << i << " " << link->solve(i, 5, 0) <<  endl;
	}
	*/
	for(int i = 1 ; i <= Y_max; i++) {
		for(int j = 1 ; j <= N_max; j++) {
			 cout << "(" << j << "," << i << "," << link->solve(j, i, 0) << ")" << endl;
		}
	}
}