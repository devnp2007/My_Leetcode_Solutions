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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0){
            return head;
        }


        // step 1 : find length and tail
        int length = 1;
        ListNode* tail = head;

        while(tail->next != nullptr){
            tail = tail ->next;
            length++;
            // calculating the length of linked list
        }

        // step 2 : remove unecessary rotations 
        k = k % length ;

        if (k == 0){
        return head;
        }

        //step 3: make the list circular 
        tail ->next = head;


        //step 4 : find the new tail
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;

        for(int i = 0 ; i< stepsToNewTail; i++ ){
            newTail = newTail -> next;

        }

        //step 5 : break the pivot
        ListNode* newHead = newTail -> next;
        newTail -> next = nullptr;

        return newHead;
           
    }
};


/* 

imagine circular linked list we make then we only need to find the pivot point

also rotating the list of 5 elements with 5 right places changes nothing so k % 5

so first find the length and last node
then temporarily connect the first node and last node to make it circular by ppointing tail to head rather than nullptr

find the pivot point mkae it tail and then cut all other rest elemnts forward





*/