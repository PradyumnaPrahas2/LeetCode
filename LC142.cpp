class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*temp1=head;
        ListNode*temp2=head;
        while(temp1!=NULL){
            temp1=temp1->next;
            if(temp1!=NULL){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if(temp1==temp2){
                temp2=head;
                while(temp1!=temp2){
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
                return temp2;
            }
        }
        return NULL;
    }
};
