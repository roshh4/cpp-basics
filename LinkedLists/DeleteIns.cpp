#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x): data(x), next(nullptr) {}
    Node(int x, Node* Nxt): data(x), next(Nxt) {}
};

Node *createLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(Node* head)
{
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* headRemoval(Node* head) {
    if(!head) return head;
    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}

Node* tailRemoval(Node* head) {
    if(!head || !head->next) return nullptr;
    Node* temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = nullptr;
    return head;
} 

int main() {
    vector <int> v = {2,5,3,8,1,1,2,3,4,5,6,9};
    Node* head = createLL(v);
    head = headRemoval(head);
    head = tailRemoval(head);
    traverse(head);
}