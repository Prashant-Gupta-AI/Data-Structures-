// Complete Program for Insertion in a Linked List in C++
#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
};

void insertAtBeginning(Node** head, int val){
    
    // dynamically create memory for this newNode
    Node* newNode = new Node();
    
    newNode->val = val;
    newNode->next = *head;

    *head = newNode;
    
    cout << newNode->val << " inserted" << endl; 
} 

void insertAtLast(Node** head, int val){ 
    Node* newNode = new Node(); 
    newNode->val = val;
    // Last node always pointst to NULL
    newNode->next = NULL;

    // If Linked List was empty
    if(*head==NULL){
        *head = newNode;
        cout << newNode->val << " inserted" << endl; 
        return; 
    } 

    Node* tempNode = *head; 
    // reach to the last node of Linked List 
    while(tempNode->next!=NULL)
        tempNode = tempNode->next;
    
    // assign last node's next to this newNode
    tempNode->next = newNode;
    cout << newNode->val << " inserted" << endl; 
} 
// required for insertAfterNthNode 
int getCurrSize(Node* node){ 
    int size=0; 
    while(node!=NULL){ 
        node = node->next;
        size++;
    }
    return size;
}

void insertAfterNthNode(int n, int val, Node** head)
{
    int size = getCurrSize(*head);

    // Negative Position Insertions not possible
    // Can't insert if position to insert is greater than size of Linked List
    if(n < 0 || n > size) 
        cout << "Invalid position to insert"; 

    if(n == 0){ 
        insertAtBeginning(head, val); 
    } 

    else { 
        Node* newNode = new Node(); 
        newNode->val = val;
        newNode->next = NULL;        
        
        // tempNode used to traverse the Linked List
        Node* tempNode = *head; 
        
        // traverse till the nth node
        while(--n)
            tempNode = tempNode->next;
        
        // assign newNode's next to nth node's next
        newNode->next= tempNode->next;
        // assign nth node's next to this new node
        tempNode->next = newNode;
        // newNode inserted 
        
        cout << newNode->val << " inserted" << endl;
    }
}

void display(Node* node){
    cout << "\n";
    
    // as linked list will end when Node is Null
    while(node!=NULL){
        cout << node->val << " "; node = node->next;
    }
    cout << "\n" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtBeginning(&head,12);
    insertAtBeginning(&head,11);
    insertAtBeginning(&head,10);
    
    display(head); 
    
    insertAtLast(&head,13);
    insertAtLast(&head,14);
    insertAtLast(&head,16);

    display(head);

    //Inserts data: 15 after 5th node
    insertAfterNthNode(5, 15,&head);
    insertAfterNthNode(0, 9,&head);
    
    display(head); 
    
    return 0; 
}