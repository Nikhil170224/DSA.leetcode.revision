/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Recursive function to reverse the list and return new head
    ListNode* reverse(ListNode* prev, ListNode* curr) {
        if (curr == NULL) return prev;
        ListNode* nextNode = curr->next;
        curr->next = prev;
        return reverse(curr, nextNode);
    }

    // Function to find middle node
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Get middle of the list
        ListNode* mid = getMid(head);

        // Step 2: Reverse second half of the list
        mid->next = reverse(NULL, mid->next);  // reverse starting from mid->next

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = mid->next;

        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
