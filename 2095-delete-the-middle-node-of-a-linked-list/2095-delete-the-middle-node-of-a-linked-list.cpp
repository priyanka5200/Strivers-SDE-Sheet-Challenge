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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        int len = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            cur = cur->next;
            len++;
        }
        cur = head;
        for (int i = 1; i < len / 2 && cur->next != NULL; i++) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = temp->next;
        delete (temp);
        return head;
    }
};