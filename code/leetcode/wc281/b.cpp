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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * _head = NULL, * tail = NULL;
        while(head != NULL)
        {
            head = head->next;
            int sum = 0;
            while(head && head->val != 0 ){
                sum += head->val;
                head = head->next;
            }
            if (sum)
            {
                if(tail){
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }else{
                    _head = tail = new ListNode(sum);
                }
            }
            
        }
        return _head;
        
    }
};
