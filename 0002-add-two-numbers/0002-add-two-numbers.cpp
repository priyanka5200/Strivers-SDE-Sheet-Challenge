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
        ListNode* node = new ListNode(-1);
        ListNode* ptr = node;
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;

        while (a != NULL || b != NULL || carry != 0) {
            int sum = 0;
            if (a != NULL) {
                sum += a->val;
                a = a->next;
            }
            if (b != NULL) {
                sum += b->val;
                b = b->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            ptr->next = temp;
            ptr =ptr->next;
        }
        return node->next;
    }
};