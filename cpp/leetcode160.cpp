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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *headA1 = headA;
        ListNode *headB1 = headB;
        int len_A = 0;
        int len_B = 0;
        while(headA1 != NULL) {
            len_A++;
            headA1 = headA1 -> next;
        }
        while(headB1 != NULL) {
            len_B++;
            headB1 = headB1 -> next;
        }
        int gap = abs(len_A - len_B);
        ListNode *temp = len_A > len_B ? headA : headB;
        ListNode *temp1 = len_A > len_B ? headB: headA;
        for(int i = 0; i < gap; i++) {
            temp = temp -> next;
        }
        while(temp != NULL) {
            if(temp == temp1) 
                return temp;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        return NULL;
    }
};