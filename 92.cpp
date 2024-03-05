class Solution {
    private:
    void traversal(ListNode*head,vector<int>&l){
        while(head){
            l.push_back(head->val);
            head=head->next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>l;
        traversal(head,l);
        reverse(l.begin()+left-1,l.end()-l.size()+right);
        ListNode*temp=head;
        for(int val:l){
            cout<<val<<" ";
            temp->val=val;
            temp=temp->next;
        }
        return head;
    }
};
