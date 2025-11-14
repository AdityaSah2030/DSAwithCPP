#include <cmath>
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
        // 1. Calculate lengths of both lists.
        int lenA = 0, lenB = 0;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (ptrA != nullptr) {
            lenA++;
            ptrA = ptrA->next;
        }
        while (ptrB != nullptr) {
            lenB++;
            ptrB = ptrB->next;
        }

        // Reset pointers to the heads.
        ptrA = headA;
        ptrB = headB;
        
        // 2. Align the starting point of the longer list's pointer.
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                ptrA = ptrA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                ptrB = ptrB->next;
            }
        }

        // 3. Traverse together until pointers meet.
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        // 4. Return the meeting point (or nullptr if they don't meet).
        return ptrA;
    }
};