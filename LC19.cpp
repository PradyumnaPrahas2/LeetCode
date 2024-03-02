class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int x=0;
        while(temp!=NULL){
            x++;
            temp=temp->next;
        }
        ListNode *temp2=head;
        int y=x-n;
        cout<<x<<" "<<y<<" "<<n<<endl;
        int y2=1;
        ListNode *temp3=NULL;
        if(x==1){
            return temp3;
        }
        while(y2<y){
            temp3=temp2;
            temp2=temp2->next;
            y2++;
        }
        temp3->next=temp2->next;
        return temp3;
    }
};
