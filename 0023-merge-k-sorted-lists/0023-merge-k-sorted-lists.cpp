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
     ListNode* mergeSort(ListNode* l1, ListNode* l2)
     {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* ptr = dummyHead;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if(l1 != NULL)
        {
            ptr->next = l1;
        }
        else
        {
            ptr->next = l2;
        }
        return dummyHead->next;
     }
    ListNode* divide(vector<ListNode*>& lists,int si, int ei)
    {
       if(si > ei)return NULL;
       if(si == ei)return lists[si]; 
        int mid = (si + ei)/2;

        ListNode* l1 = divide(lists, si, mid);
        ListNode* l2 = divide(lists, mid+1, ei);

        return mergeSort(l1, l2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;

        return divide(lists, 0, lists.size()-1);
        
    }
};