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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;
        int carry = 0;

        while(t1!=NULL && t2!=NULL){
            int sum = t1->val+t2->val+carry;
            ListNode* n = new ListNode(sum%10);
            carry = sum/10;
            temp->next = n;
            temp = temp->next;
            t1=t1->next;
            t2=t2->next;
        }

        while(t1!=NULL){
            int sum = t1->val+carry;
            ListNode* n = new ListNode(sum%10);
            carry = sum/10;
            temp->next = n;
            temp = n;
            t1 = t1->next;
        }

        while(t2!=NULL){
            int sum = t2->val+carry;
            ListNode* n = new ListNode(sum%10);
            carry = sum/10;
            temp->next = n;
            temp = n;
            t2 = t2->next;
        }

        if(carry > 0){
            ListNode* n = new ListNode(carry);
            temp->next = n;
            temp = n;
        }

        return newhead->next;



        
    }
};