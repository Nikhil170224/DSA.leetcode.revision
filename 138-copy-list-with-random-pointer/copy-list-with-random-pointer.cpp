/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head == NULL){
//             return NULL;
//         }
//         unordered_map<Node*,Node*>mpp;
//         Node* temp = head;
//         while(temp != NULL){
//             mpp[temp]= new Node(temp->val);
//             temp=temp->next;

//         }
//         temp = head;
//         while(temp != NULL){
//             mpp[temp]->next = mpp[temp->next];
//             if(temp->random != NULL){
//                 mpp[temp]->random = mpp[temp->random];
//             }
//             temp= temp->next;
//         }
//         temp = head;
//         return mpp[temp];
//     }
// };

class Solution {
public:
    void addCopy(Node* &head){
        Node* temp1 = head;
        if(temp1 == NULL){
            return;
        }
        // ek case khud solve kardo
        Node* temp2 = temp1->next;
        temp1->next = new Node(temp1->val);
        temp1= temp1->next;
        temp1->next = temp2;
        addCopy(temp2);
    }
    void seperationOfCopy(Node* temp1, Node* temp2){
        if(temp1 == NULL){
            return;
        }
        //ek case khud solve kardo
        temp1->next = temp2->next;
        temp1 = temp1->next;
        if(temp1 != NULL){
        temp2->next = temp1->next;
        temp2 = temp2->next;
        }
        seperationOfCopy(temp1,temp2);

    }
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        // this function will add copy nodes in next to each original node.
        addCopy(head);

        // copying the random nodes of original lists to the copyed list corresponding nodes 
        // As original node ->next => copyed node
        Node* temp = head;
        while(temp != NULL){
            if(temp->random != NULL){
            temp->next->random = temp->random->next;
            }
            temp= temp->next;
            temp= temp->next;
        }
       // recursive call to break the link of Original and Copyed nodes to seperate them
       Node* copyHead = head->next;
       seperationOfCopy(head,copyHead);
       return copyHead; 


    }
};