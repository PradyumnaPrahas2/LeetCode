class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*temp1=head;
        ListNode*temp2=head;
        while(temp1){
            if(temp1->next==NULL || temp1->next->next==NULL){
                return false;
            }
            temp1=temp1->next->next;
            if(temp1->next==NULL || temp1->next->next==NULL){
                return false;
            }
            temp2=temp2->next;
            if(temp1==temp2){
                return true;
            }
        }
        return false;
    }
};
