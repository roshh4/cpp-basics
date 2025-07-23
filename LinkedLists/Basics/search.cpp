#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next): data(data), next(next) {}
    Node(int data): data(data), next(nullptr) {}
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

void searchInList(Node* head, int x) {
    Node* temp = head;
    int c = 0;
    while(temp != nullptr) {
        c++;
        if(temp->data == x){
            cout << x << " was found at position " << c;
            return;
        }
        temp = temp->next;
    }
    cout << "value not found";
}

int main() {
    vector <int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* head = CreateList(v);
    cout << "enter a value to check" << endl;
    int x;
    cin >> x;
    searchInList(head, x);
}