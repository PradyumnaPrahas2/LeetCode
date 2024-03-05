class Solution {
    private:
    int size(ListNode*head){
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
    int no_of_rows(int x){
        int count=0;
        for(int i=1;i<=x;i++){
            if((i*(i+1)/2)<x){
                count++;
            }
            else if((i*(i+1)/2)>=x){
                count++;
                break;
            }
        }
        return count;
    }
    void traversal(ListNode*head,vector<vector<int>>&l,int tot){
        int c=1;
        int latest=1;
        while(head!=NULL){
            while(c<=latest*(latest+1)/2 && head!=NULL){
                l[latest-1].push_back(head->val);
                head=head->next;
                c++;
            }
            latest++;
        }
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<vector<int>>l;
        int x=size(head);
        int y=no_of_rows(x);
        cout<<x<<endl;
        cout<<"No of rows: "<<y<<endl;
        l.resize(y);
        traversal(head,l,y);
        ListNode*temp=head;
        for(vector<int>&c:l){
            if(c.size()%2==0){
                reverse(c.begin(),c.end());
            }
            for(int value:c){
                temp->val=value;
                temp=temp->next;
            }
        }
        return head;
    }
};
