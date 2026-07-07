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
    bool isPalindrome(ListNode* head) {
         if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode*temp=head;
        int count =0;
        while(temp)
        {
            count++;
            temp=temp->next;

        }
        int len=count;
        count/=2;
        
        ListNode*curr=head , *prev=NULL;
        
        while(count--)
        {
            prev=curr;
            curr=curr->next;

        }
        if(len % 2 != 0)
        {
            curr = curr->next;
        }


        prev->next=NULL;
        ListNode*front=NULL;
        ListNode* rev = NULL;
        while(curr){
            front=curr->next;
            curr->next=rev;
            rev=curr;
            curr=front;
        }
       
    
        ListNode*head1=head,*head2=rev;
        while(head1 && head2){
            if(head1->val != head2->val){
                return false;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }

        }
        return true;
        
    }
};