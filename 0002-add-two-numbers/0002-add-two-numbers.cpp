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

    int length(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int length1 = length(l1);
        int length2 = length(l2);

        int carry = 0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;

        if(length1 >= length2){

            while(temp2 != NULL){
                prev = temp1;
                int sum = temp1->val + temp2->val + carry;
                temp1->val = sum % 10;
                carry = sum / 10;

                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            while(temp1 != NULL){
                prev = temp1;
                int sum = temp1->val + carry;
                temp1->val = sum % 10;
                carry = sum / 10;

                temp1 = temp1->next;
            }

            if(carry){
                prev->next = new ListNode(carry);
            }

            return l1;
        }

        else{

            while(temp1 != NULL){
                prev = temp2;
                int sum = temp1->val + temp2->val + carry;
                temp2->val = sum % 10;
                carry = sum / 10;

                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            while(temp2 != NULL){
                prev = temp2;
                int sum = temp2->val + carry;
                temp2->val = sum % 10;
                carry = sum / 10;

                temp2 = temp2->next;
            }

            if(carry){
                prev->next = new ListNode(carry);
            }

            return l2;
        }
    }
};