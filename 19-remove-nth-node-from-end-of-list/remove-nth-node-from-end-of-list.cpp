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
            temp=temp->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLen(head);
        if(length < n){
            return head;
        }
        int targetNode = length-n+1;
        ListNode* temp = head;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        while(targetNode != 0 && temp != NULL){
            if(targetNode == 1){
                head= temp->next;
                return head;
            }
            if(targetNode==2){
                prev = temp;
                curr = temp->next;
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                break;
            }
            temp= temp->next;
            targetNode--;
        }
        //Joining & deleting
        return head;
    }
};