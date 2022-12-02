#include <iostream>
using namespace std;

class node{

    public:

    int data;
    node* next;
    node* prev;

    node(int value){

        data = value;
        next = NULL;
        prev = NULL;

    }
};

void insertAtHead(node* &head, int val){

    node* n = new node(val);

    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    
    head = n;

}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void print(node* head){

    node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

void deletion(node* &head, int pos){

    node* temp = head;
    int count = 1;

    if(pos == 1){

        node* toDelete = temp;
        head = temp->next;
        temp->next->prev = NULL;
        delete toDelete;
        return;
        
    }

    while(count != pos){
        temp = temp->next;
        count++;
    }

    node* toDelete = temp;

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    
    

    temp->prev->next = temp->next;

    delete toDelete;
}


int main(){

    node* head = NULL; 
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    print(head);
    insertAtHead(head,5);

    print(head);

    deletion(head, 1);
    print(head);
    deletion(head, 4);
    print(head);
    deletion(head, 2);
    print(head);

    return 0;
}
