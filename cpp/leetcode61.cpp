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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0)
            return head;
        ListNode* b = head;
        int len = 0;
        ListNode* tail = head;
        while(b){
            if(b ->next == NULL)
                tail = b;
            b = b -> next;
            len++;
        }   
        if(len == 0)
            return head;
        k = k % len;
        b = head;
        for(int i = 0; i < len - k - 1; i++)
        {
            b = b -> next;
        }
        ListNode *res = b -> next;
        if(res == NULL)
            return head;
        b -> next = NULL;
        tail -> next = head;
        return res;
    }
};