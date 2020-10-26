/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-21 19:15:20
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-26 21:59:09
 */

#include<iostream>
#include"solution.h"
using namespace std;

int main(){
    Solution slu;
    slu.readMatrix();
    slu.operate();
    slu.printMatrix();
    return 0;
}