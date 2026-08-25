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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddNode = new ListNode(-1);
        ListNode* odd = oddNode;
        ListNode* evenNode = new ListNode(-1);
        ListNode* even = evenNode;
        ListNode* cur = head;

        while (cur != NULL) {
            odd->next = cur;
            odd = odd->next;
            cur = cur->next;
            if (cur == nullptr) {
                break;
            }
            even->next = cur;
            even = even->next;
            cur = cur->next;
        }
        odd->next = evenNode->next;
        even->next = NULL;
        return oddNode->next;
    }
};