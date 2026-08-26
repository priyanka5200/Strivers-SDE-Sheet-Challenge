/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first = headA;
        unordered_set<ListNode*>st;

        while(first != NULL)
        {
            st.insert(first);
            first = first->next;
        }
        ListNode* second = headB;
        while(second != NULL)
        {
            if(st.find(second) != st.end())
            {
                return second;
            }
            second = second->next;
        }
        return NULL;
        
    }
};