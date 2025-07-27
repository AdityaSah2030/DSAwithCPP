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

// This solution uses the two-pointer technique to find the middle of the list,
// reverses the second half of the list, and then compares it with the first half.
class Solution {
public:
    // Helper function to reverse a linked list.
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // An empty or single-node list is always a palindrome.
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // 1. Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half of the list.
        // `slow->next` is the head of the second half.
        ListNode* secondHalf = reverseList(slow->next);

        // 3. Compare the first half and the reversed second half.
        ListNode* firstHalf = head;
        ListNode* reversedSecondHalf = secondHalf; // Use a new pointer for comparison
        bool isPalindrome = true;
        while (reversedSecondHalf != nullptr) {
            if (firstHalf->val != reversedSecondHalf->val) {
                isPalindrome = false;
                break; // Mismatch found, no need to continue.
            }
            firstHalf = firstHalf->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        // 4. (Optional but good practice) Restore the original list by reversing the second half back.
        slow->next = reverseList(secondHalf);

        return isPalindrome;
    }
};