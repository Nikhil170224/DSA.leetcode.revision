/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp2 = headB;
//        while(temp2 != NULL){
//         ListNode* temp1 = headA;
//         while(temp1 != NULL){
//             if(temp2 == temp1){
//                 return temp1;
//             }
//             else{
//                 temp1=temp1->next;
//             }

//         }
//         temp2=temp2->next;
//        }
//        return NULL; 
//     }
// };
class Solution {
public:
    long getLen(ListNode* &head){
        ListNode* temp = head;
        long len = 1;
        while(temp != NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        long lenA = getLen(headA);
        long lenB = getLen(headB);
        
        // Advance the pointer of the longer list
        while(lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while(lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        // Move both pointers together
        while(headA != nullptr && headB != nullptr) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};
