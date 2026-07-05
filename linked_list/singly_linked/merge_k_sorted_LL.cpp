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

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* dummpy = new ListNode(-1);
        ListNode* head = dummpy;
        int size = lists.size();
        for (int i = 0; i < size; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();

            if (tmp->next) {
                pq.push(tmp->next);
            }

            head->next = tmp;
            head = head->next;
        }
        return dummpy->next;
    }
};