// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/


#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: empty list or single node
        }
        
        ListNode* newHead = reverseList(head->next); // Recursively reverse the rest of the list
        head->next->next = head; // Make the next node point to the current node
        head->next = nullptr; // Set the next of the current node to null
        
        return newHead; // Return the new head of the reversed list
    }
};