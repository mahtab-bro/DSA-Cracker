LeetCode 21: Merge Two Sorted Lists
Problem Statement
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the safe starting anchor of the new list
        ListNode dummy(0);
        
        // This pointer will always track the last node in our merged list
        ListNode* tail = &dummy;
        
        // Loop runs as long as both lists have elements left to compare
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // Link the smaller node from list1 to our merged list
                tail->next = list1;
                // Move list1 pointer forward
                list1 = list1->next;
            } else {
                // Link the smaller node from list2 to our merged list
                tail->next = list2;
                // Move list2 pointer forward
                list2 = list2->next;
            }
            // Move our tail tracker forward to the newly added node
            tail = tail->next;
        }
        
        // If one of the lists is not empty yet, append the rest of it to the end
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // The real merged list starts from the node right after the dummy node
        return dummy.next;
    }
};
