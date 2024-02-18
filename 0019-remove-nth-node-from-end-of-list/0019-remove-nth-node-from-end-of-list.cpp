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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* temp =  head;
        int trav = 0;
        while(temp!=NULL){
            trav++;
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int m = trav - n;

        while(curr!=NULL && m!=0){
            next = curr->next;
            prev= curr;
            curr = next;
            m--;
        }

        if(curr == head && head!=NULL){
            head = head->next;
        }

        if(curr -> next == NULL && prev!=NULL){
            prev->next = NULL;
        }

        if(prev!=NULL && curr!=NULL){
            prev->next = curr->next;
        }
        

        return head; 
    }
};