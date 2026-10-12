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
    void deleteNode(ListNode* node) {

        node -> val  = node -> next -> val;
        node -> next = node -> next -> next;
        
    }
};


/*

Instead of deleting the given node directly:

Copy the next node's value into it.
Skip over the next node

*/