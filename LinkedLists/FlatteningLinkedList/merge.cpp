#include<iostream>

struct Node{
    int data;
    Node* next;
    Node* child;

    Node(int val): data(val), next(nullptr), child(nullptr){}
};

Node* mergeTwoLists(Node* l1, Node* l2){
    Node* merged = new Node(0);
    Node* head = merged;
    while(l1 && l2){
        if(l1->data < l2->data){
            merged->child = l1;
            l1 = l1->child;
        }
        else {
            merged->child = l2;
            l2 = l2->child;
        }
        merged = merged->child;
    }
    while(l1){
        merged->child = l1;
        l1 = l1->child;
        merged = merged->child;
    }
    while(l2){
        merged->child = l2;
        l2 = l2->child;
        merged = merged->child;
    }
    return head->child;
}

Node* Flatten (Node* head){
    if(!head || !head->next) return head;
    Node* list = Flatten(head->next);
    return mergeTwoLists(head, list);
    
}

void traversal(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->child;
    }
    std::cout << std::endl;
}

int main() {
    // Sample list creation
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    Node* flattened = Flatten(head);
    traversal(flattened);
    return 0;
}