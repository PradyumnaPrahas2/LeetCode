class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        for(int i=0;i<lists.size();i++){
            ListNode *temp=new ListNode;
            temp=lists[i];
           
            if(head==NULL){
                head=temp;
            }
            else{
                vector<int> ans;
                while(temp){
                    ans.push_back(temp->val);
                    temp=temp->next;
                }
                for(int j=0;j<ans.size();j++){
                    ListNode*fin=new ListNode;
                    fin->val=ans[j];
                    fin->next=head;
                    head=fin;
                }
                // temp->next=head;
                // head=temp;
            }
        }
        ListNode* answer=head;
        ListNode *i,*j;
        int temp;
        for(i=answer;i!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(j->val<i->val){
                    temp=i->val;
                    i->val=j->val;
                    j->val=temp;
                }
            }
        }
        return head;
    }
};
