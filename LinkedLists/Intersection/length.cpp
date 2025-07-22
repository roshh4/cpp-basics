#include<iostream>
using namespace std;

struct Node {
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

Node* intersection(Node* small, Node* big, int diff) {
    while(diff--) {
        big = big->next;
    }

    while(small && big && small != big) {
        small = small->next;
        big = big->next;
    }

    return small;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* l1 = headA;
    Node* l2 = headB;

    int s1 = 0, s2 = 0;

    while(l1) {
        s1++;
        l1 = l1->next;
    }

    while(l2) {
        s2++;
        l2 = l2->next;
    }

    if(s1 < s2)
        return intersection(headA, headB, s2 - s1); 
    else
        return intersection(headB, headA, s1 - s2); 
}

int main() {
    // Shared tail: 8 -> 4 -> 5
    Node* intersect = new Node(8, new Node(4, new Node(5)));

    // List A: 4 -> 1 -> [8 -> 4 -> 5]
    Node* headA = new Node(4, new Node(1, intersect));

    // List B: 5 -> 6 -> 1 -> [8 -> 4 -> 5]
    Node* headB = new Node(5, new Node(6, new Node(1, intersect)));

    Node* result = getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersection at node with value: " << result->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
