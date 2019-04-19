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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;
        ListNode* b = head;
        while(n){
            a = a -> next; 
            n--;
        }
        if(a == NULL)
            return head->next;
        while(a -> next != NULL)
        {
            a = a -> next;
            b = b -> next;
        }

        b -> next = (b -> next) -> next;
        return head;
    }
};