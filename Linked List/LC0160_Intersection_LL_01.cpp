#include <stack>
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
        // 1. Create two stacks to store the nodes.
        stack<ListNode*> s1, s2;

        // Traverse list A and push each node onto stack 1.
        ListNode* currentA = headA;
        while (currentA != nullptr) {
            s1.push(currentA);
            currentA = currentA->next;
        }

        // Traverse list B and push each node onto stack 2.
        ListNode* currentB = headB;
        while (currentB != nullptr) {
            s2.push(currentB);
            currentB = currentB->next;
        }

        // 2. Find the last common node.
        ListNode* intersectionNode = nullptr;

        // Pop from stacks as long as they are not empty and their top nodes are the same.
        while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
            // This node is part of the common tail, so update our potential answer.
            intersectionNode = s1.top();
            s1.pop();
            s2.pop();
        }

        // 3. Return the last common node found.
        return intersectionNode;
    }
};