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
    ListNode* middle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* rev(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* forw;

        while (cur != NULL) {
            forw = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* mid = middle(head);
        ListNode* nhead = mid->next;
        mid->next = NULL;
        nhead = rev(nhead);

        bool res = true;
        ListNode* a = head;
        ListNode* b = nhead;

        while (b != NULL) {
            if (a->val != b->val) {
                res = false;
            }
            a = a->next;
            b = b->next;
        }
        nhead = rev(nhead);
        mid->next = nhead;
        return res;
    }
};