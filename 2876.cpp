class Solution {
    private:
    int BFS(vector<int>edges,int s,int n){
        int count = 0;
        queue<int> q;
        q.push(s);  
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current >= 0 && current < edges.size() && edges[current] >= 0) {
                count++;             
                int next = edges[current];
                edges[current] = -1;  
                q.push(next);        
            }
        }
        return count; 
        // vector<bool> visited;
        // visited.resize(n,false);
        // stack<int> stack;
        // stack.push(s);
        // int count=0;
        // visited[s]=true;
        // int x;
        // while(!stack.empty()){
        //     x=stack.top();
        //     stack.pop();
        //     if(!visited[graph[x]]){
        //         visited[graph[x]]=true;
        //         stack.push(graph[x]);
        //         count++;
        //     }
        //     else{
        //         count++;
        //         break;
        //         }
        // }
        // return count;
    }
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (edges[i] >= 0) {
                result.push_back(BFS(edges, i,n));
            } else {
                result.push_back(0); 
            }
        }
        return result;
    }
};
