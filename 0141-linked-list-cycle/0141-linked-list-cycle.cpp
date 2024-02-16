class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;

            if(slow==fast){
                return true;
                break;
            }

        } 

        return false;
    }
};