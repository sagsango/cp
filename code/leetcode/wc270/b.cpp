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
    ListNode* deleteMiddle(ListNode* head) {
        if( head && head->next ){
            ListNode *slow_ptr = head, *fast_ptr = head->next->next;
            while( fast_ptr && fast_ptr->next ){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
            }
            slow_ptr->next = slow_ptr->next->next;
            return head;
        }
        return NULL;
        
    }
};
