/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

    bool check(vector<ListNode*>& visited, ListNode* curr)
    {
        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i] == curr)
            {
                return true;
            }
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode* curr = head;
        vector<ListNode*> visited;

        while(curr)
        {
            if(check(visited, curr))
            {
                return curr;
            }

            visited.push_back(curr);
            curr = curr->next;
        }

        return NULL;
    }
};