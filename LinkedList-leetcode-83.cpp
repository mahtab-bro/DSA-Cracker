LeetCode 83: Remove Duplicates from Sorted List
Problem Statement
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

#include <iostream>

using namespace std;

// Definition for singly-linked list node provided by LeetCode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Edge case: If the list is empty or has only one node, no duplicates can exist
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Initialize a pointer to traverse the list starting from the head
        ListNode* current = head;
        
        // Loop runs until we reach the last node
        while (current != nullptr && current->next != nullptr) {
            // If the current node's value is equal to the next node's value
            if (current->val == current->next->val) {
                // Save the duplicate node to delete it from memory later
                ListNode* nodeToDelete = current->next;
                
                // Skip the duplicate node by linking to the node after it
                current->next = current->next->next;
                
                // Free the memory of the duplicated node to prevent leaks
                delete nodeToDelete;
            } else {
                // If they are not duplicates, safely move to the next node
                current = current->next;
            }
        }
        
        // Return the modified original head of the linked list
        return head;
    }
};
