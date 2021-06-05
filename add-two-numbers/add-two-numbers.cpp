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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int len1 = 0 , len2 = 0;
        
        ListNode *rev1 = l1;
        ListNode *rev2 = l2;
        
        while(rev1->next!=NULL)
        {
            rev1 = rev1->next;
        }
        while(rev2->next!=NULL)
        {
            rev2 = rev2->next;
        }
        while(t1!=NULL)
        {
            len1++;
            t1 = t1->next;
        }
        
        while(t2!=NULL)
        {
            len2++;
            t2 = t2->next;
        }
        
        if(len1<len2)
        {
            int diff = len2 - len1;
            while(diff--)
            {
                ListNode * N = new ListNode(0);
                rev1->next = N;
                rev1 = N;
            }
        }
        else
        {
            int diff = len1 - len2;
            while(diff--)
            {
                ListNode * N = new ListNode(0);
                rev2->next = N;
                rev2 = N;
            }
        }
    
        int carry = 0;
        while(temp1!=NULL and temp2!=NULL)
        {
            if(temp1->val + temp2->val + carry <= 9)
            {
                temp1->val = temp1->val + temp2->val + carry;
                carry = 0;
            }
            else
            {
                int ans = temp1->val + temp2->val + carry;
                int ans3= ans%10;
                int ans1= ans/10;
                
                temp1->val = ans3 ;
                carry = ans1;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(carry!=0)
        {
            ListNode *temp3 = l1;
            while(temp3->next!=NULL)
            {
                temp3 = temp3->next;
            }
            
            ListNode *n = new ListNode(carry);
            temp3->next = n;
        }
        
        return l1;
    }
};