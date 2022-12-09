// complete link list with insertion deletion and display function
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

void deleteAtHead(node* &head){

    node* toDelete = head;

    if(head == NULL){
        cout << "Nothing To delete" << endl;
        return;
    }

    if(head->next == NULL){
        head = NULL;
        delete toDelete;
        return;
    }
    head = head->next;
    delete toDelete;
}

void deletion(node* &head, int val){

    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;

    if(temp->data == val){
        deleteAtHead(head);
        return;
    }

    while(temp->next->data != val){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

int main(){

    node* head = NULL;
    // display(head);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);  
    display(head);
    deletion(head, 1);
    display(head);
    deletion(head, 4);
    display(head);
    deletion(head, 2);
    display(head);
    deletion(head,3);
    display(head);


    return 0;
}
