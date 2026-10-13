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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            // Step 1: Find the kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            // Fewer than k nodes remain
            if (kth == nullptr)
                break;

            // Save the node after this group
            ListNode* groupNext = kth->next;

            // Step 2: Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;

                curr->next = prev;

                prev = curr;
                curr = nextNode;
            }

            // Step 3: Connect the reversed group
            ListNode* oldGroupHead = groupPrev->next;

            groupPrev->next = kth;

            // Prepare for the next group
            groupPrev = oldGroupHead;
        }

        return dummy.next;
    }
}; 



/*

Original:
1 → 2 → 3 → 4 → 5

Groups:
[1 → 2] [3 → 4] [5]

Reverse each complete group:
[2 → 1] [4 → 3] [5]

Final:
2 → 1 → 4 → 3 → 5

so we do the following:
1. check whether a compelete group of k nodes exist
2. reverse that group
3. move to the next group.

*/