#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x): data(x), next(nullptr) {}
};

Node* createLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void traverse(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insertTail(Node* head, int x) {
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(x);
    return head;
}

Node* insertValue(Node* head, int val, int pos) {
    if(pos == head->data) return insertHead(head, val);
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        if(pos == temp->data) {
            Node* newEl = new Node(val);
            prev->next = newEl;
            newEl->next = temp;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector <int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* head = createLL(v);
    traverse(head);
    cout <<"enter value to be inserted before: " ;
    int x;
    cin >> x;
    cout << "enter value to be inserted: ";
    int y;
    cin >> y;
    head = insertValue(head, y, x);
    traverse(head);
}