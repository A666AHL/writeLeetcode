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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prefix = new ListNode(-1);
        ListNode* suffix = new ListNode(-1);
        ListNode* prefix1 = prefix;
        ListNode* suffix1 = suffix;
        while(head != NULL) {
            int temp = head -> val;
            if(temp < x) {
                prefix -> next = new ListNode(temp);
                prefix = prefix -> next;
            }
            else {
                suffix -> next = new ListNode(temp);
                suffix = suffix -> next;
            }
            head = head -> next;
        }
        
        // 两个链表进行连接
        prefix -> next = suffix1 -> next;
        ListNode* res = prefix1 -> next;
        return res;
    }
};