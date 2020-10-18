/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-18 11:14:13
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-18 11:45:49
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	freopen("input.in", "w", stdout);
	int N = 1e4;
	int total = 0;
	srand(19114514);
	while(total != N) {
		int n =(rand() % N) + 1;
		if(n + total > N) n = N - total;
		total += n;
		for(int i = 0; i < n; i++){
			cout << rand() % 2;
		}
		cout << "#" << endl;
	}
}