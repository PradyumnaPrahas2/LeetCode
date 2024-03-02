#include<string>
class Solution {
    private:
    void traversal(TreeNode* node, vector<string>&l,string s){
        if(node==NULL){
            return;
        }
        s=s+to_string(node->val);
        if(node->left==NULL && node->right==NULL){
            cout<<s<<endl;
            l.push_back(s);
        }
        traversal(node->left,l,s);
        traversal(node->right,l,s);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> l;
        string s="";
        int ans=0;
        traversal(root,l,s);
        for(int i=0;i<l.size();i++){
            ans=ans+stoi(l[i]);
            cout<<stoi(l[i])<<endl;
        }
        return ans;
    }
};
