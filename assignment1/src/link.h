/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-06 22:11:25
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-12 22:47:03
 */
#include <iostream>

#ifndef _LINK_H

#define _LINK_H

struct node
{
	int data;
	node* next;
};

class Link{
	private:
		node* head;
	public:
		// 构造函数：构造头指针并且初始化为单循环链表
		Link() {
			head = new node();
			head->next = head;
		}
		
		/**
		 * @name: insert
		 * @description:  在链表中插入一个数据为data的元素
		 * @param {int} data  插入队员的编号
		 * @return {void} 
		 */  
		void insert(int data) {
			node* cur = new node();
			cur->data = data;
			cur->next = head->next;
			head->next = cur;			
		}

		/**
		 * @name: delete_node
		 * @description:  删除当前结点的下一个结点
		 * @param {node*}  pre 当前节点
		 * @return {node*}  返回被删除结点的下一个节点
		 */
		node* delete_node(node* pre) {
			node* temp = pre->next;
			pre->next = temp->next;
			free(temp);
			return pre->next;
		}

		/**
		 * @name: print
		 * @description: 输出调试信息
		 * @param {void} 
		 * @return {void} 
		 */  
		void print() {
			for(node* cur = head->next; cur != head; cur = cur->next) {
				std::cout << cur->data << " ";
			}
			std::cout << std::endl;
		}

		/**
		 * @name: solve
		 * @description: 解决一次约瑟夫问题 
		 * @param {int} n 队员的总数 
		 * @param {int} y 数数的间隔
		 * @param {bool} flag  开关，控制返回的结果是否变换到加里森编号为 1 的情况
		 * @return {int} 返回问题的答案
		 */  
		int solve(int n, int y, bool flag) {
			for(int i = n ; i >= 1; i--) insert(i);
			int cnt;
			node* cur = head;
			while(head != head->next->next) {
				cnt = 1;
				while(cnt != y) {
					cur = cur->next;
					if(cur == head) cur = cur->next;
					cnt++;
				}
				if(cur->next == head) cur = cur->next;
				delete_node(cur);
			}
			int result = head->next->data;
			delete_node(head);
			if(flag) return result;
			else return ((n + 1 - result) % n) + 1;
		}
};

#endif