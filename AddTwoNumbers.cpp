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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL, *tail, *newNode;
        int sum, carry = 0;
        while(l1||l2||carry){
            if(l1&&l2)
                sum=l1->val+l2->val+carry;
            else if(l1)
                sum=l1->val+carry;
            else if(l2)
                sum=l2->val+carry;
            else
                sum=carry;
            carry=sum/10;
            sum%=10;
            newNode=(ListNode*)malloc(sizeof(ListNode));
            newNode->val=sum;
            newNode->next=NULL;
            if(head)
                tail->next=newNode;
            else
                head=newNode;
            tail=newNode;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        return head;
    }
};