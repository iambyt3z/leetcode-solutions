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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> nums;
        ListNode* curr = head;

        while(curr != nullptr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int n = nums.size();

        for(int i=0; i<n; i+=k) {
            int elementsLeft = n-i;
            if(elementsLeft < k) break;
            reverse(nums.begin()+i, nums.begin()+i+k);
        }

        curr = head;
        int i = 0;

        while(i<n) {
            curr->val = nums[i];
            curr = curr->next;
            i++;
        }

        return head;
    }
};