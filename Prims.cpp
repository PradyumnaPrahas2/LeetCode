#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
#include<climits>
using namespace std;
class Graph{
    private:
    vector<vector<int>> graph;
    vector<vector<int>> weights;
    vector<vector<int>>ans;
    vector<vector<int>>visited;
    vector<int>vertex;
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
        graph[x].push_back(y);
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
    void prims(int source,int size){
        for(int v:graph[source]){
            ans.push_back({source,v});
        }
        int index;
        int source1,source2;
        int count=0,answer=0;
        int cond=0;
        while(cond==0){
            int min=INT_MAX;
            for(int i=0;i<ans.size();i++){
                if(visited[ans[i][0]][ans[i][1]]==false && visited[ans[i][1]][ans[i][0]]==false && weights[ans[i][0]][ans[i][1]]<min && (vertex[ans[i][0]]==false || vertex[ans[i][1]]==false)){
                    min=weights[ans[i][0]][ans[i][1]];
                    source1=ans[i][0];
                    source2=ans[i][1];
                    index=i;
                }
            }
            ans.erase(ans.begin()+index);
            cout<<answer<<" was before ";
            count++;
            answer=answer+min;
            visited[source1][source2]=true;
            visited[source2][source1]=true;
            vertex[source1]=true;
            vertex[source2]=true;
            cout<<" after adding "<<min<<" answer is "<<answer<<endl;
            for(int v:graph[source2]){
            ans.push_back({source2,v});
            }
            int  h=0;
            for(bool m:vertex){
                if(m==true){
                    h++;
                }
            }
            if(h==size){
                cond=1;
            }
        }
        cout<<answer<<endl;
    }
};
int main(){
    int size;
    cout<<"Enter no of vertices of the graph:-";
    cin>>size;
    Graph g(size);
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
    g.addedge(6,7,1);
    g.addedge(6,5,2);
    g.addedge(3,4,9);
    g.addedge(3,5,14);
    g.addedge(4,5,10);
    g.prims(0,size);
}
