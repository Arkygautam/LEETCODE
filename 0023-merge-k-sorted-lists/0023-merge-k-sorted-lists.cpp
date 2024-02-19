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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < lists.size(); i++) {
        ListNode* curr = lists[i];
        while (curr != nullptr) {
            pq.push(curr->val);
            curr = curr->next;
        }
    }

    ListNode* root = nullptr;
    ListNode* head = nullptr;

    if (!pq.empty()) {
        root = new ListNode(pq.top());
        head = root;
        pq.pop();
    }

    while (!pq.empty()) {
        ListNode* temp = new ListNode(pq.top());
        pq.pop();
        root->next = temp;
        root = temp;
    }

    return head;
}

};