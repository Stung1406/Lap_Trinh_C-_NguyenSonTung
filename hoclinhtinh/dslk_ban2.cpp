#include<iostream>
using namespace std;

struct ListNode{
	int data;
	LisrNode *next;
	ListNode() : data(0),next(nullptr) {}
	ListNode(int x) : data(x),next(nullptr) {}
	ListNode(int x,ListNode *next) : data(x),next(next) {}  
};



int main()
{
	ListNode *list;
	list = new ListNode(5,list);
	
	return 0;	
}
