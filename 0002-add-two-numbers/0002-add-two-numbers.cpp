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
        ListNode* nhead = new ListNode(-1);
        ListNode* ptr = nhead;
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int carry = 0;
        while(cur1 != NULL || cur2 != NULL || carry != 0)
        {
            int sum = 0;
            if(cur1 != NULL)
            {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if(cur2 != NULL)
            {
                sum += cur2->val;
                cur2 = cur2->next;
            }
            sum += carry;
            carry = sum/10;

            ListNode* temp = new ListNode(sum%10);
            ptr->next = temp;
            ptr = ptr->next;
        }
        return nhead->next;
    }
};