#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10); 
            curr = curr->next;
        }

        return dummy->next; 
    }
};

// Hàm in danh sách liên kết
void printList(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    // Tạo l1: 2 -> 4 -> 3 (tức số 342)
    ListNode* l1 = nullptr;
    l1 = new ListNode(3, l1);
    l1 = new ListNode(4, l1);
    l1 = new ListNode(2, l1);
    printList(l1);

    // Tạo l2: 5 -> 6 -> 4 (tức số 465)
    ListNode* l2 = nullptr;
    l2 = new ListNode(4, l2);
    l2 = new ListNode(6, l2);
    l2 = new ListNode(5, l2);
    printList(l2);

    ListNode* l3 = Solution().addTwoNumbers(l1, l2);

    printList(l3); // Kết quả: 7 0 8 (tức số 807)

    return 0;
}