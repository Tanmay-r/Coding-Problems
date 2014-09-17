/*Remove duplicates from an unsorted singly linked list*/
#include <iostream>
#include <set>

using namespace std;

struct node{
	int value;
	node * next;
};

void appendToEnd(node * linked_list, int value){
	node * iterator = linked_list;
	if(iterator == NULL){
		iterator = new node();
		iterator->value = value;
	}
	else{
		while(iterator->next != NULL){
			iterator = iterator->next;
		}
		node * new_node = new node();
		iterator->next = new_node;
		new_node->value = value;
	}
}

void print_list(node * linked_list){
	node * iterator = linked_list->next;
	while(iterator != NULL){
		cout << iterator->value << " ";
		iterator = iterator->next;
	}
	cout << endl;
}

void empty_list(node * linked_list){
	node * iterator = linked_list;
	int n = 0;
	while(iterator->next != NULL){
		n++;
		iterator = iterator->next;
	}
	iterator = linked_list->next;
	while(n--){
		iterator = iterator->next;
		delete(iterator);
	}
}

void input(node * linked_list, int N){
	if(linked_list->next != NULL){
		empty_list(linked_list);
	}
	else{
		node * iterator = linked_list;
		while(N--){
			node * new_node = new node();
			cin >> new_node->value;
			iterator->next = new_node;
			iterator = new_node;
		}
	}
}

void remove_duplicates(node * linked_list){
	set<int> hash_set;
	node * iterator = linked_list;
	while(iterator->next != NULL){
		if(hash_set.find(iterator->next->value) == hash_set.end()){
			hash_set.insert(iterator->next->value);
			iterator = iterator->next;
		}
		else{
			node * copy_node = iterator->next;
			iterator->next = copy_node->next;
			delete(copy_node);
		}
	}
}

int main(){
	node * linked_list = new node();
	int size = 0;
	cin >> size;
	input(linked_list, size);
	print_list(linked_list);
	remove_duplicates(linked_list);
	print_list(linked_list);
	return 0;
}

