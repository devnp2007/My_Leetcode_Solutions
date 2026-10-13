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
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr){ // to find middle point in linked list
            slow = slow->next;
            fast = fast->next->next;
        }

        // list in two halves 1st and 2nd
        ListNode* second = slow -> next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* prev = nullptr;

        while(second != nullptr){
            ListNode* newNode = second -> next;
            second->next = prev;
            prev = second;
            second = newNode;
        }

        second = prev;

        // step 4: merge both halves alternatively
        ListNode* first = head;
        
        while(second != nullptr){
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first ->next = second;
            second ->next = nextFirst;

            first = nextFirst;
            second = nextSecond;

        }
        
    }
};


/*
find middle using slow and fast pointers

reverse the second half of linked from mid to end as done in Leetcode no. 206

and then merge the two linked list, inplace by taking one node from each alternatively

TC : O(n)
SC : O(1l
)


*/