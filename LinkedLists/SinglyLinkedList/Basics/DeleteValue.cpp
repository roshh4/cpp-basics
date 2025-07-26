#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int x, ListNode* nxt): data(x), next(nxt) {}
    ListNode(int x): data(x), next(nullptr) {}
};

ListNode* CreateLL(vector<int> &v) {
    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;
    for(int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head;
}

void traverse(ListNode* head) {
    ListNode *temp = head;
    while(temp) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* deleteHead(ListNode* head) {
    if(!head) return nullptr;
    ListNode* temp = head;
    head = temp->next;
    delete temp;
    return head;
}

ListNode* deleteTail(ListNode* head) {
    if(!head || !head->next) return nullptr;
    ListNode* temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

ListNode* deleteValue(ListNode* head, int val) {
    if(val == head->data) return deleteHead(head);
    if(!head) return head;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp->next) {
        if(temp->data == val) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector <int> v = {1,2,3,4,5};
    ListNode* head = CreateLL(v);
    traverse(head);
    head = deleteValue(head, 3);
    traverse(head);
}