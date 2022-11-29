#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }

};

void insertAtHead(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void insertAtMiddle(node* &head, int val, int val1, int val2){

    node* n = new node(val);
    node* temp = head;

    while(temp->data != val1){
        temp = temp->next;
    }
     n->next = temp->next;
    temp->next = n;


}

void insertAtTail(node* &head, int val){

    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = n;
}

void display(node* head){

    if(head == NULL){
        cout << "head -> NULL" << endl;
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}



int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,0);
    display(head);
    insertAtMiddle(head,69,2,3);    
    display(head);

    return 0;
}
