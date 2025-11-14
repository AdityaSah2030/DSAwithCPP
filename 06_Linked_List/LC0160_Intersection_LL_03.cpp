using namespace std;

// LeetCode's definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // The loop continues until the pointers are equal.
        // This will be either the intersection node or nullptr.
        while (ptrA != ptrB) {
            // When a pointer reaches the end of its list, switch it to the other list's head.
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        return ptrA;
    }
};