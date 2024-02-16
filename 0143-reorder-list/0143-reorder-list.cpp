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

    void reorderList(ListNode* head) {

        int l = 0;
        ListNode* temp = head;
        vector<int> ans;
        while(temp!=NULL){
            l++;
            ans.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        int i = ans.size()-1;

        while(temp!=NULL && i>l/2){
            
            ListNode* t = new ListNode(ans[i--]);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }

        if(l%2 ==0 && temp!=NULL){
            temp = temp->next;
            temp->next= NULL;
        }
        else if(l%2 == 1 && temp!=NULL){
            temp->next = NULL;
        }

        
    }
};