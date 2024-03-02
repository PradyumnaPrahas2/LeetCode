class Solution {
    private:
    bool DFS(vector<vector<int>>k,int s,int d){
        vector<bool> visited;
        visited.resize(k.size()+1,false);
        list<int>stack;
        stack.push_back(s);
        while(stack.size()!=0){
            int x=stack.back();
            if(x==d){
                return true;
            }
            stack.pop_back();
            for(int val:k[x]){
                if(visited[val]==false){
                    visited[val]=true;
                    stack.push_back(val);
                }
            }
        }
        return false;
    }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<vector<int>> l(n+1,vector<int>(n+1,0));
        vector<vector<int>> k;
        k.resize(n+1);
        for(int i=0;i<=n;i++){
            k[i].push_back(i);
        }
        for(int i=threshold+1;i<=n;i++){
            for(vector<int> m:queries){
                if(m[0]%i==0 && m[1]%i==0){
                    // l[m[0]][m[1]]=1;
                    k[m[0]].push_back(m[1]);
                    k[m[1]].push_back(m[0]);
                }
            }
        }
        vector<bool> ans;
        for(vector<int> j:queries){
            if(DFS(k,j[0],j[1])==true){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        // for(vector<int> j:queries){
        //     if(l[j[0]][j[1]]==0){
        //         ans.push_back(false);
        //     }
        //     else{
        //         ans.push_back(true);
        //     }
        // }
        return ans;
    }
};
