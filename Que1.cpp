#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
Node* head = NULL;
void insert(int x, int mode, int val) {
    Node* temp = new Node;
    Node* last = NULL;
    Node* pre = NULL;
    
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        head->next = temp;
        return;
    }

    if (mode == 0) { // insert in beginning
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        temp->next = head;
        head = temp;
        last->next = temp;
    }
    else if (mode == 2) { // insert at end
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    else {
        Node* temp1 = head;
        while (temp1->next != head && temp1->data != val) {
            pre=temp1;
            temp1 = temp1->next;
        }
        if (mode == -1) { // insert before a data value
            if(head->data == val){   // special case: value is at head
            Node* last = head;
            while(last->next != head){
                last = last->next;
            }
            temp->next = head;
            head = temp;
            last->next = head;
            }
        else {
            pre->next = temp;
            temp->next = temp1;
        }
        }
        else if (mode == 1) { // insert after a data value
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
}
int deleteNode(int val) {
    if (head == NULL) {
        cout << "Empty list";
        return 0;
    }
    Node* prev = NULL;
    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }
        Node* temp1 = head;
        prev = NULL;
        while (temp1->next != head && temp1->data != val) {
            prev = temp1;
            temp1 = temp1->next;
        }

        if (temp1->data != val) {
            cout << "Value not found"<<endl;
            return 0;
        }
        if(temp1==head){
            head=head->next;
            last->next=head;
        }
        else{
        prev->next=temp1->next;
        delete temp1;
        }
        

    return 1;
}


void search(int val) {
    Node* temp = head;

    if (head == NULL) {
        cout << "Empty list";
        return;
    }

    while (temp->next != head && temp->data != val) {
        temp = temp->next;
    }

    if (temp->data == val || head->data == val) {
        cout << "Value found"<<endl;
    }
    else {
        cout << "Value not found"<<endl;
    }
}

int main(){
    insert(10,2,0);
    insert(20,2,0);
    insert(30,2,0);
    insert(40,2,0);
    deleteNode(10);
    search(30);
    search(10);
    return 0;
}
