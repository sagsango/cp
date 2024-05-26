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
    ListNode * reverse( ListNode * head){
        ListNode * prev = NULL, *curr = head;
        while( curr ){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head){
        
        ListNode * slow = head, *fast = head->next;
        while( fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * twin_a = head, *twin_b = reverse(slow->next);
        
        int twin_sum = 0;
        while( twin_a != NULL && twin_b != NULL ){
            twin_sum = max( twin_sum, twin_a->val + twin_b->val);
            twin_a = twin_a->next;
            twin_b = twin_b->next;
        }
        return twin_sum;
    }
};
