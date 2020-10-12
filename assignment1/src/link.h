/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CYKS
 * @Date: 2020-10-06 22:11:25
 * @LastEditors: CYKS
 * @LastEditTime: 2020-10-12 21:09:01
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
		 * @name: 
		 * @description: 
		 * @param {type} 
		 * @return {type} 
		 */
		node* delete_node(node* pre) {
			node* temp = pre->next;
			pre->next = temp->next;
			free(temp);
			return pre->next;
		}

		void print() {
			for(node* cur = head->next; cur != head; cur = cur->next) {
				std::cout << cur->data << " ";
			}
			std::cout << std::endl;
		}

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
			else return ((n + result - 2) % n) + 1;
		}
};

#endif