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
        Node*headcopy=new Node(0);
        Node*tailcopy=headcopy;
        Node*temp=head;
         while(temp)
         {
            tailcopy->next=new Node(temp->val);
            tailcopy=tailcopy->next;
            temp=temp->next;
         }
         tailcopy=headcopy;
         headcopy=headcopy->next;
         delete tailcopy;

         tailcopy=headcopy;
         temp=head;
         unordered_map<Node*,Node*>m;

         while(temp){
            m[temp]=tailcopy;
            tailcopy=tailcopy->next;
            temp=temp->next;
            

         }
         tailcopy=headcopy;
            temp=head;
         while(temp){
            tailcopy->random=m[temp->random];
            tailcopy=tailcopy->next;
            temp=temp->next;
            
         }
         return headcopy;

        
    }
};