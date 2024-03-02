class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=list1;
        ListNode*i;
        for(i=list2;i!=NULL;i=i->next){
            ListNode *temp=new ListNode;
            temp->val=i->val;
            temp->next=head;
            head=temp;
        }
        ListNode *temp2=head;
        ListNode *j;
        int tar;
        for(i=temp2;i!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(i->val>j->val){
                    tar=i->val;
                    i->val=j->val;
                    j->val=tar;
                }
            }
        }
        return head;
    }
};
