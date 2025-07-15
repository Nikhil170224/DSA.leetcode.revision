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
    ListNode* merge(ListNode* head, ListNode* newHead){
        ListNode dummy;
        ListNode* temp = &dummy;
        while(head != NULL && newHead != NULL){
            if(head->val <= newHead->val){
                temp->next = head;
                head=head->next;
            }
            else{
                temp->next= newHead;
                newHead = newHead->next;
            }
            temp=temp->next;
        }
        if(head != NULL){
            temp->next = head;
        }
        else{
            temp->next = newHead;
        }
        return dummy.next;
}
    ListNode* sortList(ListNode* head) {
        //Base case
        if(head== NULL){
            return head;
        }
        else if(head->next == NULL){
            return head;
        }

        // Break from middles
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL){
            fast= fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* newhead = slow->next;
        slow->next = NULL;
        ListNode* head1=sortList(newhead);
        ListNode* head2=sortList(head);
        

        return merge(head1,head2);
    }
};