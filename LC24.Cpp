class Solution {
    private :
    void swap(ListNode *&one,ListNode *&two){
        ListNode* temp=one;
        one=two;
        two=temp;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *i,*temp=head;
        int tempo;
        while(temp!=NULL && temp->next!=NULL){
            // swap(temp,temp->next);
            tempo=temp->val;
            temp->val=temp->next->val;
            temp->next->val=tempo;
            temp=temp->next->next;
        }
        return head;
    }
};
