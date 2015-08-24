#include <iostream>

using namespace std

class SinglyLinkedListNode{
public:
	int value;
	SinglyLinkedListNode *next;
	SinglyLinkedListNode(int value){
		this->value = value;
		next = NULL;
	}
};

class SinglyLinkedList{
private:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;
public:
	SinglyLinkedList(){
		head = NULL;
		tail = NULL;
	}

	int traverse();
	void addLast(SinglyLinkedListNode *newNode);
	void addFirst(SinglyLinkedListNode *newNode);
	void insertAfter(SInglyLinkedListNode *previous, SinglyLinkedListNode *newNode);
	void removeFirst();
	void removeLast();
	void removeNext(SinglyLinkedListNode *previous);
};

int SinglyLinkedList::traverse(){
	int sum = 0;
	SinglyLinkedListNode *current = head;
	SinglyLinkedListNode *previous = NULL;
	while(current != NULL){
		sum + = current->value;
		previous = current;
		current = current->next;
	}
	return sum;
}

void SinglyLinkedList::addLast(SinglyLinkedListNode *newNode){
	if(newNode == NULL){
		return;
	}else{
		if(head == NULL){
			newNode->next = NULL;
			head = newNode;
			tail = newNode;
		}
		else{
			newNode->next = NULL;
			tail->next = newNode;
		}
	}
}
void SinglyLinkedList::addFirst(SinglyLinkedListNode *newNode){
	if(newNode == NULL){
		return;
	}else{
		if(head == NULL){
			newNode->next = NULL;
			head = newNode;
			tail = newNode;
		}
		else{
			newNode->next = head;
			head = newNode;
		}
	}
}
void SinglyLinkedList::insertAfter(SInglyLinkedListNode *previous, SinglyLinkedListNode *newNode){
	if(newNode == NULL){
		return;
	}else{
		if(previous == NULL){
			addFirst(newNode);
		}else if(previous == tail){
			addLast(newNode);
		}else{
			SinglyLinkedListNode *next = previous->next;
			previous->next = newNode;
			newNode->next = next;
		}
	}
}
void SinglyLinkedList::removeFirst(){
	if(head == NULL){
		return;
	}else{
		SinglyLinkedListNode *removedNode;
		removedNode = head;
		if(head == tail){
			head = NULL;
			tail = NULL;
		}else{
			head = head->next;
		}
		delete removedNode;
	}
}
void SinglyLinkedList::removeLast(){
	if(tail == NULL){
		return;
	}else{
		SinglyLinkedListNode *removedNode;
		removedNode = tail;
		if(head == tail){
			head = NULL;
			tail = NULL;
		}else{
			SinglyLinkedListNode *previousToTail = head;
			while(previousToTail->next != tail){
				previousToTail = previousToTail->next;
			}
			tail = previousToTail;
			tail->next = NULL;
		}
		delete removedNode;
}
void SinglyLinkedList::removeNext(SinglyLinkedListNode *previous){
	if(previous == NULL){
		removeFirst();
	}else if(previous->next == tail){
		SinglyLinkedListNode *removedNode = previous->next;
		tail = previous;
		tail->next = NULL;
		delete removeNode;
	}else if(previous == tail){
		return;
	}else{
		SinglyLinkedListNode *removedNode = previous->next;
		previous->next = removedNode->next;
		delete removedNode;
	}
}













