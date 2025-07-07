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

int sizeOfList(Node* head) {
    Node* temp = head;
    int x = 0;
    while(temp != nullptr) {
        x++;
        temp = temp->next;
    }
    return x;
}

int main() {
    vector <int> v = {1,2,3,4,5,6,7};
    Node * head = CreateList(v);
    Traverse(head);
    int s = sizeOfList(head);
    cout << endl << "size is: " << s;
}