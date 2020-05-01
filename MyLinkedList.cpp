#include<iostream>
using namespace std;



class MyLinkedList {
private:
    struct ListNode {
        int val;  //当前结点的值
        ListNode* next;  //指向下一个结点的指针
        ListNode(int x) : val(x), next(NULL) {}  //初始化当前结点值为x,指针为空
    };

    ListNode* head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() :head(nullptr) {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* p = head;
        int i = 0;
        while (p && i < index) {
            p = p->next;
            ++i;
        }
        if (p) 
            return p->val;
        else return -1;

    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* p = new ListNode(val);
        if (head == nullptr) {
            head = p;
            return;
        }
        ListNode* q = head;
        while (q->next) {
            q = q->next;
        }
        q->next = p;

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val);
        if (index <= 0) {
            node->next = head;
             head=node;
            return;
        }
        ListNode* p = head;
        int i = 0;
        while (p && i < index - 1) {
            p = p->next;
            ++i;
        }
        if (p) {
            node->next = p->next;
            p->next = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) {
            ListNode* del = head;
            head = head->next;
            delete(del);
            return;
        }
        ListNode* p = head;
        int i = 0;
        while (p && i < index - 1) {
            p = p->next;
            ++i;
        }
        if (!p) return;
        if (p->next) {
            ListNode* del = p->next;
            p->next = del->next;
            delete(del);
        }
    }
};

int main() {
    MyLinkedList mylist;
    mylist.addAtIndex(0, 10);
    mylist.addAtIndex(0, 20);
    mylist.addAtIndex(1, 10);
    int a = mylist.get(0);
    cout << a << endl;

}