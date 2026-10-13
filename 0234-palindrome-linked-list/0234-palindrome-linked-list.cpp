/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };*/
 
class Solution {
public:
ListNode* reverseList(ListNode* head) {
ListNode* prev = nullptr;
ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr &&
           fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; //finding middle of the whole linked lsit using slow and fast
    }

    // now we have got mid point
    // and so we will reer teh list fromm the mid point to forward i.e. from slow till the end .
    ListNode* secondHalf = reverseList(slow->next);

    ListNode* first = head;
    ListNode* second = secondHalf;

    while (second != nullptr) {
        if (first->val != second->val) {
            return false;
        }

        first = first->next;
        second = second->next;
    }

    return true;
}

};



 /*

Find the middle using slow and fast pointers.
Reverse the second half.
Compare the first half with the reversed second half.

if both match then palindrome
*/