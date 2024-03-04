class Solution {
    private:
    void traversal(TreeNode* node,vector<int> &l,int i){
        if(node==NULL){
            return;
        }
        l.push_back(i);
        traversal(node->left,l,i+1);
        traversal(node->right,l,i+1);
    }
    void traversal2(TreeNode*node,vector<vector<int>>&l,int i){
        if(node==NULL){
            return;
        }
        l[i].push_back(node->val);
        traversal2(node->left,l,i+1);
        traversal2(node->right,l,i+1);
    }
    void righttraversal(TreeNode*node,vector<int>&ans){
        if(node==NULL){
            return;
        }
        ans.push_back(node->val);
        righttraversal(node->right,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>l;
        traversal(root,l,0);
        vector<vector<int>>ll;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        int level=*max_element(l.begin(),l.end());
        ll.resize(level+1);
        traversal2(root,ll,0);
        righttraversal(root,ans);
        int a=ans.size();
        for(int i=a;i<ll.size();i++){
            ans.push_back(ll[i].back());
        }
        return ans;
    }
};
