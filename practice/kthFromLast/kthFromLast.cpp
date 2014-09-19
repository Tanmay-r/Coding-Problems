/*Find the kth element from last in an unsorted singly linked list*/
#include <iostream>
#include <set>

using namespace std;

struct node{
	int value;
	node * next;
};

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

int kth_last(node * linked_list, int k){
	node * iterator1 = linked_list;
	node * iterator2 = linked_list;
	int i = 0;
	while(iterator1->next != NULL && i < k){
		i++;
		iterator1 = iterator1->next;
	}
	if(iterator1->next == NULL){
		return -1;
	}
	else{
		while(iterator1->next != NULL){
			iterator1 = iterator1->next;
			iterator2 = iterator2->next;
		}
		return iterator2->value;
	}
}

int main(){
	node * linked_list = new node();
	int size, k;
	cin >> size >> k;
	input(linked_list, size);
	print_list(linked_list);
	cout << kth_last(linked_list, k-1) << endl;
	return 0;
}

