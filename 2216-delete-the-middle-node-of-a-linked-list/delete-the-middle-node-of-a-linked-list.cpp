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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* middle = NULL;
        while(fast->next != NULL){
            fast= fast->next;
            if(fast->next != NULL){
                fast= fast->next;
                slow= slow->next;

            }
        }
        middle = slow->next;
        slow->next = middle->next;
        middle->next = NULL;
        delete middle;
        return head;
    }
};