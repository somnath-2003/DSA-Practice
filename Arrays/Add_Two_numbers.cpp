// LeetCode Problem: 2
// 2. Add Two Numbers 
// Difficulty: Medium
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        int carry=0, sum = 0;
        ListNode *temp1, *temp2, *dummy;
        temp1 = l1;
        temp2 = l2;
        dummy = result;
        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            sum = carry;
            if (temp1 != NULL)
                sum += temp1->val;
            if (temp2 != NULL)
                sum += temp2->val;

            result->val = sum % 10;
            carry = sum / 10;

            // ✅ FIRST: advance temp1 and temp2
            if (temp1 != NULL)
                temp1 = temp1->next;
            if (temp2 != NULL)
                temp2 = temp2->next;

            // ✅ THEN: decide if you still need a new node
            if (temp1 != NULL || temp2 != NULL || carry != 0) {
                result->next = new ListNode();
                result = result->next;
            }
        }
        return dummy;
    }
};