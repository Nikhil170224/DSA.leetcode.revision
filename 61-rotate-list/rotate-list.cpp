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
    int getLen(ListNode* &head){
        ListNode* temp = head;
        int length = 1;
        while(temp->next != NULL){
            temp= temp->next;
            length++;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head;

        // valid cases 
        int len = getLen(head);

        // making sure that k < lenght
        k = k % len;
       
        if(k == 0){
            return head;
        }
        // making the list circular

        ListNode* temp = head;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next = head;
        
        // steps needed to breaking point
        int count = len - k -1;
        ListNode* newHead = head;
        while(count){
            newHead = newHead->next;
            count--;
        }
        // Breaking the list 
        temp = newHead->next;
        newHead->next = NULL;
        return temp;
    }
};