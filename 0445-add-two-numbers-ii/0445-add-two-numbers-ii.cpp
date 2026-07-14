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
        ListNode*curr1=l1,*curr2=l2;
        vector<int>arr1;
        vector<int>arr2;
        vector<int>ans;

        while(curr1)
        {
            arr1.push_back(curr1->val);
            curr1=curr1->next;
        }
        while(curr2){
            arr2.push_back(curr2->val);
            curr2=curr2->next;
        }
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        int sum=0,car=0,digit=0,i=0,j=0;
        while(i < arr1.size() || j < arr2.size() || car)
        {
            int sum = car;

            if(i < arr1.size())
                sum += arr1[i++];

            if(j < arr2.size())
                sum += arr2[j++];

            ans.push_back(sum % 10);
            car = sum / 10;
        }
        reverse(ans.begin(),ans.end());

    if(ans.size() == 0)
        return NULL;

    ListNode* head = new ListNode(ans[0]);
    ListNode* temp = head;

    for(int i = 1; i < ans.size(); i++)
    {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }

    return head;

    }
};