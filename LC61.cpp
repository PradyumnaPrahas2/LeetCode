class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        head=temp;   
        
        return head;
    }
};
