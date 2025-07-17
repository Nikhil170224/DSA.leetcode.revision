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
    ListNode* reverse(ListNode* &head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fowd =NULL;
       
        int count = 0;
        // First, check if there are at least k nodes
        ListNode* temp = head;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) return head; // Do not reverse if nodes are fewer than k
       for(int i = 0; curr != NULL && i< k ; i++){
        fowd=curr->next;
        curr->next = prev;
        prev=curr;
        curr=fowd;
        
       }
       if(fowd != NULL){
        head->next = reverse(fowd,k);
        
       }
        return prev;
       

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL || k == 1){
            return head;
        }
        // function call to reverse successive groups which returns 
        return reverse(head,k);
    }
};