#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int _val) {
        data = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp->data);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        temp = head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node* dummy = new Node(0);
        Node* newHead = dummy;
        while(temp){
            dummy->next = temp->next;
            temp->next = temp->next->next;
            dummy = dummy->next;
            temp = temp->next;
        }

        return newHead->next;
    }

};

// Helper to print a list (val + random)
void printList(Node* head) {
    while (head) {
        cout << "Node: " << head->data;
        if (head->random)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

// Sample main
int main() {
    // Creating the list: 1 -> 2 -> 3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;

    // Setting random pointers
    node1->random = node3;  // 1 -> 3
    node2->random = node1;  // 2 -> 1
    node3->random = node2;  // 3 -> 2

    cout << "Original List:\n";
    printList(node1);

    Solution sol;
    Node* copied = sol.copyRandomList(node1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
