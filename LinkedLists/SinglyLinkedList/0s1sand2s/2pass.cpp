#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x): data(x), next(nullptr) {}
    Node(int x, Node* nxt): data(x), next(nxt) {}
};

void traverse(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* arrangeNodes(Node* head){
    Node* temp = head;
    int c0 = 0, c1 = 0, c2 = 0;
    while(temp){
        if(temp->data == 0) c0++;
        else if(temp->data == 1) c1++;
        else c2++;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(c0){
            temp->data = 0;
            c0--;
        } 
        else if(c1){
            temp->data = 1;
            c1--;
        } 
        else if(c2){
            temp->data = 2;
            c2--;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1, new Node(0, new Node(1, new Node(2, new Node(0, new Node(2, new Node(1)))))));
    head = arrangeNodes(head);
    traverse(head);
}