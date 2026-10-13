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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // step 1: Detect the cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // both pointers meet: cycle exists
            if (slow == fast) {

                // step 2: Move slow back to head
                slow = head;

                // step 3: Find the cycle's starting node
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // no cycle exists
        return nullptr;
    }
};

/*
Imagine:

A = distance from the head to the cycle's starting node.
B = distance from the cycle's starting node to the first meeting point.
C = remaining distance around the cycle from the meeting point back to the cycle's start.

The cycle's total length is B + C.

When the pointers meet:

slow has travelled A + B steps.
fast has travelled twice as far: 2(A + B) steps.

Because fast travels twice as far, the extra distance it travels is a whole number of cycle lengths.

Therefore:

2(A + B) - (A + B) = A + B

A + B = k × (B + C)

Rearranging gives:

A = k × (B + C) - B

Since travelling a complete cycle brings you back to the same node, this means:

The distance from the head to the cycle's start equals the distance from the meeting point to the cycle's start, modulo the cycle length.

So when we reset slow to head and move both pointers one step at a time, they meet at the cycle's starting node.

Remember these three steps
Move slow one step and fast two steps until they meet.
Reset slow to head.
Move both one step at a time. Their next meeting point is the cycle's start.

The key insight: The first meeting detects the cycle. The second meeting finds its starting node.


*/