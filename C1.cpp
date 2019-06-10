#include <bits/stdc++.h>
using namespace std;

struct Node {

	int val;
	Node *next , * prev ;
	

	Node ( int _val ) {
	val = _val ;
	next = NULL;
	prev = NULL;
	}
} ;

struct LinkedList{
public:
	Node *head , * tail;
	int size;
	LinkedList( ) {
	head = tail= NULL;
	size = 0;
}

	int cnt ( int x ) {
		Node* cur = head;
		int cnt = 0;
		while(cur != NULL){
			if(cur->val == x) cnt++;
			cur = cur -> next;
		}
		return cnt;
	}

	int getNth ( int n ) {
		Node * cur = head;
		while(cur != NULL){
			if(n-- == 0) return cur ->val;
			cur = cur -> next;
		}
		return -1;
	}

	void insertLast ( int x ) {
		Node * cur = new Node(x);
		size++;
		if(tail == NULL){
			head = cur;
			tail = cur;
		}else{
			tail -> next = cur;
			cur -> prev = tail;
			tail = cur;
		}
	}

void insertFirst(int x){
	Node* node = new Node(x);
	if (head == NULL){
		head = node;
		tail = node;
		return;
	}else{
		head->prev = node;
		node->next = head;
		head = node;
	}
}


void deleteFirst(){
	head = head->next;
	if(head != NULL){
		head->prev = NULL;
	}else{
		tail = NULL;
	}
}

void deleteLast(){
	tail = tail -> prev;
	if(tail != NULL){
		tail -> next = NULL;		
	}else{
		head = NULL;
	}
}

void del (int x){
	Node* cur = head;
	while(cur && cur->val != x){
		cur = cur -> next;
	}
	if (!cur) return;
	if(cur == head) deleteFirst();
	else
		if(cur == tail) deleteLast();
	else{
		cur -> next -> prev = cur -> prev;
		cur -> prev -> next = cur -> next;
	}
}

void print(){
	Node* cur = head;
	while(cur){
		if (cur != head) cout << " ";
		cout << (cur -> val);
		cur = cur -> next;	
		}
		cout << "\n";
}
};

int main(){

int n, x;
string s;
LinkedList* linkedList = new LinkedList();
cin >> n;   
	for(int i = 1; i <= n; i++){
		cin >> s;
		if (s == "insertFirst"){
			cin >> x;
			linkedList -> insertFirst(x);
		}
		if (s == "delete"){
			cin >> x;
			linkedList -> del(x);
		}
		if (s == "deleteLast"){
			linkedList -> deleteLast();
		}
		if (s == "insertLast"){
			cin >> x;
			linkedList -> insertLast(x);
		}
		if(s == "cnt"){
			cin >> x;
			cout << linkedList -> cnt(x) << "\n";
		}
		if(s == "getNth"){
			cin >> x;
			cout << linkedList -> getNth(x) << "\n";
		}
}
linkedList -> print();


	return 0;
}