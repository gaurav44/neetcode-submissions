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
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* res = list1->val < list2->val ? new ListNode(list1->val) : new ListNode(list2->val);
        auto curr = res;

        list1->val < list2->val ? list1 = list1->next : list2 = list2->next;

        while(list1 && list2) {
            // cout << list1->val << " " << list2->val << "\n";
            // cout << curr->val << "\n";
            // cout << "********************************************************\n";
            if(list1->val <= list2->val)
            {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1) curr->next = new ListNode(list1->val, list1->next);
        if(list2) curr->next = new ListNode(list2->val, list2->next);
        return res;
    }
};
