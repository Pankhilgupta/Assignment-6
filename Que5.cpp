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
void detect() {
    bool circular=false;
    if (head == NULL) {
        cout << "Empty list";
        return;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == head) {
        cout << "This is a circular list";
    }
    else {
        cout << "This is not a circular list";
    }

}
int main(){
    insert(10,2,0);
    insert(20,2,0);
    insert(30,2,0);
    insert(40,2,0);
    detect();
    return 0;
}
