#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _listNode{
	int val;
	struct _listNode * next;
	listNode(int v){
		val = v;
		next = NULL;
	}
}listNode;

typedef struct _List{
	listNode * head;
	_List(){
		head = NULL;
	}
	void insert(int val){
		listNode * node = new ListNode(v);
		node->next = head->next;
		head = node;
	}
	void pop
}List;


typedef struct _Graph{
	int n 



