class Solution {
    private:
    void traversal(TreeNode* node,vector<int> &l){
        if(node==NULL){
            return;
        }
        l.push_back(node->val);
        traversal(node->left,l);
        traversal(node->right,l);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> l;
        traversal(root,l);
        int ans=-1,ref,final_ans;
        for(int i=0;i<l.size();i++){
            ref=count(l.begin(),l.end(),l[i]);
            if(ref>ans){
                ans=ref;
            }        
        }
        vector<int> a;
        for(int i=0;i<l.size();i++){
            if(count(l.begin(),l.end(),l[i])==ans){
                a.push_back(l[i]);
            }
        }
        set<int> s(a.begin(),a.end());
        a.assign(s.begin(),s.end());
        return a;
    }
};
