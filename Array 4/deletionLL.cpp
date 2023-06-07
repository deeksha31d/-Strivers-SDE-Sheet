// C++ program to delete middle
// of a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
	int data;
	struct Node* next;
};
Node* removeFirstNode(struct Node* head)
{
    if (head == NULL)
        return NULL;
 
    // Move the head pointer to the next node
    Node* temp = head;
    head = head->next;
 
    delete temp;
 
    return head;
}
Node* removeLastNode(struct Node* head)
{
    if (head == NULL)
        return NULL;
 
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
 
    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = NULL;
 
    return head;
}
// Deletes middle node and returns
// head of the modified list
struct Node* deleteMid(struct Node* head)
{
	// Base cases
	if (head == NULL)
		return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	// Initialize slow and fast pointers
	// to reach middle of linked list
	struct Node* slow_ptr = head;
	struct Node* fast_ptr = head;

	// Find the middle and previous of middle.
// To store previous of slow_ptr
struct Node* prev;
	while (fast_ptr != NULL
&& fast_ptr->next != NULL) {
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}

	// Delete the middle node
	prev->next = slow_ptr->next;
	delete slow_ptr;

	return head;
}

// A utility function to print
// a given linked list
void printList(struct Node* ptr)
{
	while (ptr != NULL) {
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << "NULL\n";
}

// Utility function to create a new node.
Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
    cout<<"Deeksha Dewangan"<<endl;
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

	cout << "Given Linked List\n";
	printList(head);

	head = deleteMid(head);
    head = removeFirstNode(head);
     head = removeLastNode(head);
	cout << "Linked List after deletion of middle\n";
	printList(head);

	return 0;
}
