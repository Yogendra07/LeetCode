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
    ListNode* middleNode(ListNode* head) 
    {
        int counter = 0;
        
        ListNode* temp = head;
        

        while(temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        
        
    
            counter = counter / 2;
            
            temp = head;
            
            
            while(counter != 0)
            {
                temp = temp->next;
                counter--;
            }
            
            return temp;
  
        
        
        return NULL;
        
    }
};