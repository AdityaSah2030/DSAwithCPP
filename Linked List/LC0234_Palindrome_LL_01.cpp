#include <stack>
using namespace std;

// Definition for singly-linked list (as provided by LeetCode)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This solution uses a stack to check if the linked list is a palindrome.
// The stack allows us to easily compare the first half of the list with the reversed second half
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Create a stack to store the values of the list.
        stack<int> s;

        // 1. First Pass: Push all list values onto the stack.
        // We use a temporary pointer `current` to traverse the list.
        ListNode* current = head;
        while (current != nullptr) {
            s.push(current->val);
            current = current->next;
        }

        // 2. Second Pass: Compare the list with the popped stack values.
        // Reset `current` to the head to start traversal from the beginning.
        current = head;
        while (current != nullptr) {
            // Get the top element from the stack (which corresponds to the last element of the list).
            int topVal = s.top();
            s.pop();

            // 3. If the current node's value doesn't match the stack's top value, it's not a palindrome.
            if (current->val != topVal) {
                return false;
            }
            // Move to the next node in the list.
            current = current->next;
        }

        // 4. If we finish the loop, it means every element matched. It is a palindrome.
        return true;
    }
};