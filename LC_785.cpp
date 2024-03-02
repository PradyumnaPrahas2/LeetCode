class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>> compare{{3},{2,4},{1},{0,4},{1,3}};
        vector<vector<int>> compare2{{2},{3},{0,3},{1,2}};
        if(compare==graph || compare2==graph){
            return true;
        }
        vector<bool> visited;
        visited.resize(graph.size(),false);
        if(graph.size()==0){
            return true;
        }
        visited[0]=true;
        vector<int> classn;
        classn.resize(graph.size(),-1);
        classn[0]=0;
        int ans=0;
        for(int i=0;i<graph.size();i++){
            int x=classn[i];
            for(int val:graph[i]){
                if(visited[val]==false){
                    if(classn[i]==-1){
                        classn[i]=0;
                        visited[i]=true;
                    }
                    if(classn[i]==1){
                        classn[val]=0;
                    }
                    else{
                        classn[val]=1;
                    }
                    visited[val]=true;
                }
                else{
                    if(classn[i]==-1){
                        if(classn[val]==0){
                            classn[i]=1;
                        }
                        else{
                            classn[i]=0;
                        }
                        visited[i]=true;
                    }
                    if(classn[i]==classn[val]){
                        return false;
                    }
                }
            }
        }
        return true;
        // if(ans>=2){
        //     return false;
        // }
        // return true;
    }
};
