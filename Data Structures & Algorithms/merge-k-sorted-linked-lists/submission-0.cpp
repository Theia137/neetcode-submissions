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
        int size = lists.size();
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while(true){
            int min = 1001;
            int idx = 0;
            bool check = true;
            for(int i=0; i<size; i++){
                if(lists[i] != nullptr){
                    check = false;
                }
                if(lists[i] != nullptr && lists[i]->val < min){
                    min = lists[i]->val;
                    idx = i;
                }
            }
            if(check){
                break;
            }
            ans->next = new ListNode(lists[idx]->val);
            ans = ans->next;
            lists[idx] = lists[idx]->next;
        }
        return head->next;
    }
};
