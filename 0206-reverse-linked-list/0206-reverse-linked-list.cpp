class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // Store next node
            curr->next = prev;           // Reverse link
            prev = curr;                 // Move prev
            curr = next;                 // Move curr
        }

        return prev;
    }
};