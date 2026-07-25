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
    ListNode* partition(ListNode* head, int x) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* leftTemp = left;
        ListNode* rightTemp = right;
        for (int num : nums) {
            if (num < x) {
                ListNode* node = new ListNode(num);
                leftTemp->next = node;
                leftTemp = leftTemp->next;
            } else {
                ListNode* node = new ListNode(num);
                rightTemp->next = node;
                rightTemp = rightTemp->next;
            }
        }

        leftTemp->next = right->next;
        return left->next;
    }
};