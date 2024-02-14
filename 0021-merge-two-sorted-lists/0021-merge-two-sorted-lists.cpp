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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* h1 = ans;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1!=NULL && t2!=NULL){
            if(t1->val <= t2->val){
                ListNode* n = new ListNode(t1->val);
                t1 = t1->next;
                h1->next = n;
                h1 = h1->next;
            }
            else{
                ListNode* n = new ListNode(t2->val);
                t2 = t2->next;
                h1->next = n;
                h1 = h1->next;

            }
        }

        while(t1!=NULL){
            ListNode* n = new ListNode(t1->val);
                t1 = t1->next;
                h1->next = n;
                h1 = h1->next;
        }

        while(t2!=NULL){
            ListNode* n = new ListNode(t2->val);
                t2 = t2->next;
                h1->next = n;
                h1 = h1->next;
        }

        return ans->next;

    }
};