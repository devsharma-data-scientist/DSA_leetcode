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
    int length(ListNode* head) {
        int cnt = 0;

        while (head != NULL) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int d = abs(l1-l2);
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if(l1 > l2){
            while(d--){
                temp1 = temp1->next;
            }

            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2) return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else if(l2 > l1){
            while(d--){
                temp2 = temp2->next;
            }

            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2) return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else{
            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2) return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return NULL;
    }
};