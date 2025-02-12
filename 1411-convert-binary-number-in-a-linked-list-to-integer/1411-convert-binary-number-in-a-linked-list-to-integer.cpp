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
    void solve(ListNode* curr, int &mult, int &res) {
        if(curr == nullptr)
            return ;

        solve(curr->next, mult, res);

        res += mult*curr->val;
        mult *= 2;
    }

    int getDecimalValue(ListNode* head) {
        int res = 0, mult = 1;
        solve(head, mult, res);
        return res;
    }
};