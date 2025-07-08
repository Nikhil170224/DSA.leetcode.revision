/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value from the next node
        node->val = node->next->val;
        
        // Step 2: Save the pointer to the next node
        ListNode* temp = node->next;
        
        // Step 3: Point current node's next to the next of next node
        node->next = node->next->next;
        
        // Step 4: Delete the next node (now redundant)
        delete temp;
    }
};
