// Applications of circular linked lists:
//     Multiplayer games use this to give each player a chance to play.
//     A circular linked list can be used to organize multiple running applications on an operating system. 
//     These applications are iterated over by the OS.

// Why circular linked list?
//     A node always points to another node, so NULL assignment is not necessary.
//     Any node can be set as the starting point.
//     Nodes are traversed quickly from the first to the last.

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
        n->next = n;
        return;
    }

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;    
    }
    temp->next = n;
    n->next = head;
    head = n;

}

void insertAtTail(node* &head, int val){

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;

}

void deleteAtHead(node* &head){

    if(head->next == head){

        node* toDelete = head;
        head = NULL;
        delete toDelete;
        return;
    }

    node* temp = head;
    
    while(temp->next != head){
        temp = temp-> next;
    }

    node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
    

}

void deletion(node* &head, int pos){

    if(head->next == head){
        deleteAtHead(head);
        return;
    }

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

void print(node* head){

    if(head == NULL){
        cout << "empty i.e head->NULL" << endl;
        return;
    }

    node* temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;

    }
    while(temp != head);

    cout << endl;
}

int main(){

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    print(head);
    insertAtHead(head, 5);
    print(head);

    deletion(head, 3);
    print(head);

    deletion(head, 4);
    print(head);

    deletion(head, 1);
    print(head);

    deletion(head, 2);
    print(head);

    deletion(head, 1);
    print(head);
    print(head);

    insertAtHead(head, 44);
    print(head);

    insertAtHead(head, 55);
    print(head);

    insertAtHead(head, 66);
    print(head);
    

    return 0;
}
