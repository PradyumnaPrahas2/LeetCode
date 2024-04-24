#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class Graph{
    private:
    vector<vector<int>>clone_graph;
    map<int,vector<vector<int>>> hash_map;
    vector<vector<int>> graph;
    vector<vector<int>> weights;
    vector<vector<bool>> visited;
    vector<bool>vertex;
    public:
    Graph(int size){
        graph.resize(size);
        weights.resize(size);
        visited.resize(size);
        vertex.resize(size);
        for(int i=0;i<size;i++){
            weights[i].resize(size,-1);
            visited[i].resize(size,false);
        }
    }
    void addedge(int x,int y,int z){
        graph[x].push_back(y);// BI-Directed Graph;
        graph[y].push_back(x);
        weights[x][y]=z;
        weights[y][x]=z;
    }
    bool cycle(vector<vector<int>>clone_graph,int i,vector<bool>&visited2){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(visited2[x]==true){
                return true;
            }
            visited2[x]=true;
            for(int v:clone_graph[x]){
                if(visited2[v]==false){
                    q.push(v);
                }
            }
        }
        return false;
    }
    bool check(vector<vector<int>>clone_graph,int s,int d){
        clone_graph[s].push_back(d);
        clone_graph[d].push_back(s);
        vector<bool>visited2;
        visited2.resize(clone_graph.size(),false);
        for(int i=0;i<clone_graph.size();i++){
            if(!visited2[i] && cycle(clone_graph,i,visited2)){
                cout<<"Cycle exists";
                return true;
            }
        }
        return false;
    }
    void prims(int size){
        // vector<vector<int>> clone_graph;
        clone_graph.resize(size);
        int ans=0;
        for(const auto& h:hash_map){
            cout<<h.first<<"->";
            for(vector<int>m:h.second){
                cout<<visited[m[0]][m[1]]<<" "<<visited[m[1]][m[0]]<<", ";
                if(visited[m[0]][m[1]]==false && visited[m[1]][m[0]]==false ){
                    cout<<"inside"<< " .";
                    if(check(clone_graph,m[0],m[1])==false){
                        cout<<"{"<<m[0]<<","<<m[1]<<"}"<<endl;
                        ans+=h.first;
                        clone_graph[m[0]].push_back(m[1]);
                        clone_graph[m[1]].push_back(m[0]);
                        //vertex[m[0]]=true;
                    }
                    else{
                        cout<<true<<" ";
                    }
                }
                visited[m[0]][m[1]]=true;
                visited[m[1]][m[0]]=true;
            }
            cout<<endl;
        }
        cout<<"ANSWER IS:-"<<ans<<endl;
    }
    void buildhash(){
        for(int i=0;i<weights.size();i++){
            for(int j=0;j<weights.size();j++){
                if(weights[i][j]!=-1){
                    hash_map[weights[i][j]].push_back({i,j});
                }
            }
        }
        // for(const auto& pair:hash_map){
        //     cout<<pair.first<<"->";
        //     for(vector<int>m:pair.second){
        //         cout<<"{";
        //         for(int n:m){
        //             cout<<n<<" ";
        //         }
        //         cout<<"}";
        //     }
        //     cout<<endl;
        // }
    }
    void path(){
        vector<bool>v;
        v.resize(clone_graph.size(),false);
        queue<int>qt;
        qt.push(0);
        while(!qt.empty()){
            int x=qt.front();
            cout<<x<<"->";
            qt.pop();
            for(int y:clone_graph[x]){
                if(v[y]==false){
                    qt.push(y);
                    v[y]=true;
                }
            }
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    Graph g(9);//Bi- Directed graph
    g.addedge(0,1,4);
    g.addedge(0,7,8);
    g.addedge(1,2,8);
    g.addedge(1,7,11);
    g.addedge(2,8,2);
    g.addedge(2,3,7);
    g.addedge(2,5,4);
    g.addedge(7,8,7);
    g.addedge(6,7,7);
    g.addedge(6,8,6);
    g.addedge(6,7,7);
    g.addedge(6,5,2);
    g.addedge(3,4,9);
    g.addedge(3,5,14);
    g.addedge(4,5,10);
    g.buildhash();
    g.prims(9);
    g.path();
}