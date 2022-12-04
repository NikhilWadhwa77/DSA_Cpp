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
    temp -> next = n;
}

node* reverse(node* &head){

    node* prev = NULL;
    node* current = head;
    node* nxt;

    while(current != NULL){

        nxt = current -> next;
        current->next = prev;
        prev = current;
        current = nxt;

    }
    head = prev;
    return prev;
}

void print(node* head){

    node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    // insertAtTail(head, 5);
    print(head);

    node* newhead = reverse(head);
    print(newhead);

    print(head);

    

    return 0;
}
