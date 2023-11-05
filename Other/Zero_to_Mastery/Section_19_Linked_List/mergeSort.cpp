// leetcode 21
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) {
    while (head) {
        std::cout << head->val << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

class Solution {
public:
     ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        
        ListNode* newHead = nullptr;
        if (a->val < b->val) {
            newHead = a;
            newHead->next = mergeTwoLists(a->next, b);
        } else {
            newHead = b;
            newHead->next = mergeTwoLists(a, b->next);
        }
        return newHead;
    }

     ListNode* mergeTwoLists1(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        
        ListNode* finalHead = nullptr;
        if (a->val < b->val) {
            finalHead = a;
            a = a->next;
        } else {
            finalHead = b;
            b = b->next;
        }

        ListNode* p = finalHead;
        while (a && b) {
            if (a->val < b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        p->next = (a ? a : b);
        return finalHead;
     }

    // lettcode 148
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        /// break list into two
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now pointing to the middle node
        ListNode *n = slow->next;
        slow->next = nullptr;
        
        ListNode* a = sortList(head);
        ListNode* b = sortList(n);
        
        return mergeTwoLists(a, b);
    }
};

int main() {
    Solution s;
    auto *head = new ListNode(3);
    head = new ListNode(1, head);
    head = new ListNode(2, head);
    head = new ListNode(4, head);

    print(head);
    head = s.sortList(head); 
    std::cout << "Answer is\n";
    print(head);
}

