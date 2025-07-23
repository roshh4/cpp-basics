#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x, Node* ptr): data(x), next(ptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

Node* CreateList(vector <int>& v){
    Node *head = new Node(v[0]);
    Node *mover = head;
    for(int i = 1; i < v.size(); i++) {
        Node* temp = new Node (v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void Traverse(Node* head){
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int AddWithCarry(Node* head) {
    if(!head) return 1;
    int carry = AddWithCarry(head->next);
    int sum = head->data + carry;
    head->data = sum%10;
    return sum/10;
}

Node* AddOne(Node* head){
    int i = AddWithCarry(head);
    if(i) {
        Node* newHead = new Node(1, head);
        return newHead;
    }
    return head;
}

int main() {
    vector <int> v = {9,9,9,9};
    Node * head = CreateList(v);
    head = AddOne(head);
    Traverse(head);
}