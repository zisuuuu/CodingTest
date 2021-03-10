// https://leetcode.com/problems/add-two-numbers/submissions/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* prev = result;
        int up = 0;
        
        while(l1 || l2)
        {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            int sum = v1 + v2 + up;
            
            if(sum / 10 != 0)
            {
                up = sum/10;
                sum = sum%10;
            }
            else
            {
                up = 0;
            }
            
            //cout<<sum<<endl;
            ListNode* curr = new ListNode(sum);
            if(prev == nullptr)
            {
                result = curr;
            }
            else
            {
                prev->next = curr;
            }
            prev = curr;
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        if(up != 0)
        {
            //cout<<up<<endl;
            ListNode* curr = new ListNode(up);
            prev->next = curr;
        }
        
        return result;
    }
};