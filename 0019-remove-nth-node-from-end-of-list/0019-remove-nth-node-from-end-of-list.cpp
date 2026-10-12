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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast ahead by n nodes
        for(int i =0; i < n; i++){  // i < n so, in deletion slow->next
            

            if (fast == NULL){
                return dummy.next; //edge case
            }

            fast = fast -> next;
        }
        

        // fast is having lead of n nodes from start so when fast reaches the end slow reaches n-1 node as then both moving at same speed. 

        // Move both pointers until fast reaches last node
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }



        // removing nth node from end
        ListNode* node_to_delete = slow -> next;
        slow->next = node_to_delete->next;

        delete node_to_delete;

        return dummy.next; 
    }
};

// edge case head = 1 -> null, n=1, so we must delete the only node, the dummy node makes this easy , dummy -> 1 -> null so after deletion dummy -> null, returning dummy.next correctly return NULL