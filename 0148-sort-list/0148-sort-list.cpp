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

    ListNode* findmid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(left == NULL)
            return right;

        if(right == NULL)
            return left;

        if(left->val <= right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head)
    {
        // Base Case
        if(head == NULL || head->next == NULL)
            return head;

        // Find Middle
        ListNode* mid = findmid(head);

        // Split List
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // Sort Left and Right
        left = sortList(left);
        right = sortList(right);

        // Merge
        return merge(left, right);
    }
};