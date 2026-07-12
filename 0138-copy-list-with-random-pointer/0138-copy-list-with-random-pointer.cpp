/*
 // Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        Node* headcopy = new Node(0);
        Node* tailcopy = headcopy;
        Node* temp = head;

        while (temp) {
            tailcopy->next = new Node(temp->val);
            tailcopy = tailcopy->next;
            temp = temp->next;
        }

        tailcopy = headcopy;
        headcopy = headcopy->next;
        delete tailcopy;

        Node* curr1 = head;
        Node* curr2 = headcopy;
        Node* front1, *front2;

        while (curr1) {
            front1 = curr1->next;
            front2 = curr2->next;

            curr1->next = curr2;
            curr2->next = front1;

            curr1 = front1;
            curr2 = front2;
        }

        curr1 = head;

        while (curr1) {
            curr2 = curr1->next;

            if (curr1->random)
                curr2->random = curr1->random->next;

            curr1 = curr2->next;
        }

        curr1 = head;
        curr2 = headcopy;

        while (curr1 && curr2) {
            curr1->next = curr2->next;
            curr1 = curr1->next;

            if (curr1) {
                curr2->next = curr1->next;
                curr2 = curr2->next;
            }
        }

        return headcopy;
    }
};