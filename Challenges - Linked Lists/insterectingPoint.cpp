#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
Node *intersectionOfTwoLinkedLists(Node *list1, Node *list2)
{
	if(list1 == NULL or list2 == NULL){
		return NULL;
	}

    int count1 = 0, count2 = 0;
	Node*len1 = list1;
	Node*len2 = list2;

 	while(len1!=NULL){
 		len1 = len1->next;
 		count1++;
 	}

 	while(len2!=NULL){
 		len2 = len2->next;
 		count2++;
 	}

 	int diff = abs(count1-count2);

 	if(count1>count2){
 		while(list1!=NULL and diff){
 			list1 = list1->next;
 			diff--;
 		}
 	}else{
 		while(list2!= NULL and diff){
 			list2 = list2->next;
 			diff--;
 		}
 	}

 	while(list1!=NULL and list2!= NULL){
 		if(list1==list2){
 			return list1;
 		}
 		list1 = list1->next;
 		list2 = list2->next;
 	}

 	return NULL;
}



/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}