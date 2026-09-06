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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        for(auto head : lists)
        {
            if(head != NULL)
            pq.push({head->val, head});
        }

        while(!pq.empty())
        {
            auto minindex = pq.top().second;
            pq.pop();
            if(minindex->next != NULL){
                pq.push({minindex->next->val, minindex->next});
            }
            dummyTail->next = minindex;
            dummyTail= dummyTail->next;
        }
        return dummyHead->next;

       
    }
};