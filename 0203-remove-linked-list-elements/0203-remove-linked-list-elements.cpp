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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;

        ListNode*curr=head;
        ListNode*temp=dummy;
        
        while(curr)
        {
            
            if(curr->val == val)
            {
                

                temp->next=curr->next;
                ListNode*del=curr;
                
                curr=curr->next;
                delete del;
            }
            else{
                temp=curr;
                curr=curr->next;
            }


        }
        return dummy->next;
        
    }
};