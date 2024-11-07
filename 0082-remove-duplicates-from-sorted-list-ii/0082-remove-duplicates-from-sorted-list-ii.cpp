class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = head;
        
        while(fast){
            bool dup = false;
            do{
                dup = false;
                while(fast && fast->next && fast->val == fast->next->val){
                    fast = fast->next;
                    dup = true;
                }
                
                if(dup)
                    fast = fast->next;
            }while(dup);
            
            slow->next = fast;
            slow = slow->next;
            if(fast)
                fast = fast->next;
        }
        
        return dummy->next;
    }
};