class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x,y;
        vector<vector<int>> l;
        l.resize(edges.size()+1);
        for(int i=0;i<edges.size();i++){
            x=edges[i].front();
            y=edges[i].back();
            l[x-1].push_back(1);
            l[y-1].push_back(1);
        }
        for(int i=0;i<l.size();i++){
            if(edges.size()==l[i].size()){
                return i+1;
            }
            cout<<endl;
        }
        return 0;
    }
};
