class Solution {
    private:
    void BFS(vector<int>edges,vector<int>&ans,int s){
        vector<bool> visited;
        visited.resize(edges.size(),false);
        visited[s]==true;
        queue<int> q;
        q.push(s);
        vector<int> clone;
        bool target=false;
        while(!q.empty()){
            int x=q.front();
            cout<<x<<" ";
            clone.push_back(x);
            q.pop();
            int val=edges[x];
            if(val>=0){
            if(val==s){
                cout<<val<<" ";
                target=true;
                break;
            }
            else if(visited[val]==false){
                visited[val]=true;
                q.push(val);
            }
            }
        }
        cout<<endl;
        if(target==true){
            ans.push_back(clone.size());
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<int> ans;
        for(int x=0;x<edges.size();x++){
            BFS(edges,ans,x);
        }
        // cout<<ans.size()<<endl;
        if(ans.size()==0){
            return -1;
        }
        return *max_element(ans.begin(),ans.end());
    }
};
