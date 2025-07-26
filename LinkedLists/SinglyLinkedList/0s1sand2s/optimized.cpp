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
    Node* zeroDummy = new Node(-1);
    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);

    Node* zero  = zeroDummy;
    Node* one = oneDummy;
    Node* two = twoDummy;

    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr; 

    return zeroDummy->next;
}

int main() {
    Node* head = new Node(1, new Node(0, new Node(1, new Node(2, new Node(0, new Node(2, new Node(1)))))));
    head = arrangeNodes(head);
    traverse(head);
}