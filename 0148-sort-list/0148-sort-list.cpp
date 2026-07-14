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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode*curr=head;
        if(head == NULL)
        return NULL;
        while(curr)
        {
            arr.push_back(curr->val);
            curr=curr->next;

        }
        sort(arr.begin(),arr.end());
        ListNode*newhead=new ListNode(arr[0]);
        ListNode*temp=newhead;
        for(int i =1;i<arr.size();i++)
        {
            temp->next=new ListNode(arr[i]);
            temp=temp->next;

        }
        return newhead;
        
        
        
    }
};