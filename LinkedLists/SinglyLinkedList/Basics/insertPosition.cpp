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

int sizeOfList(Node* head) {
    Node* temp = head;
    int x = 0;
    while(temp != nullptr) {
        x++;
        temp = temp->next;
    }
    return x;
}

Node* headInsert(int val, Node* head) {
    return new Node(val, head);
}

Node* tailInsert(int val, Node* head) {
    if(!head) return new Node(val, head);
    Node * temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    Node * newNode = new Node(val, nullptr);
    temp->next = newNode;
    return head;
} 

Node* positionInsert(int k, int x, Node* head) {
    if(k == 1) return headInsert(k, head);
    if(k == sizeOfList(head) + 1) return tailInsert(k, head);
    Node* temp = head;
    int count = 0; 
    Node* prev = nullptr;
    while(temp) {
        count++;
        if(count == k) {
            Node* place = new Node(x);
            prev->next = place;
            place->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector <int> v = {1,2,3,4,5,6,7,8};
    Node* head = createLL(v);
    int x;
    cout << "enter value: ";
    cin >> x;
    int y;
    cout << "enter position: ";
    cin >> y;
    traverse(positionInsert(y, x, head));
}