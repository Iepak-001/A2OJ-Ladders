#include <bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
int main()
{
    int n;
    cin>>n;
    graph.resize(n);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
    }

    
    vector<int>minInversions(n,INT_MAX);
    vector<vector<bool>>vis(n,vector<bool>(n,false));

    for(int i=0;i<n;i++){
        int src=i;
        
        queue<int>qu;
        qu.push(src);
        vis[i][src]=true;

        while(!qu.empty()){
            int currNode=qu.front();
            qu.pop();

            for(auto neighbor:graph[currNode]){
                if(!vis[i][neighbor]){
                    qu.push(neighbor);
                    vis[i][neighbor]=true;
                }
            }
        }

        int visCount=0;
        for(int j=0;j<n;j++){
            if(vis[i][j]==false) visCount++;
        }
        minInversions[i]=visCount;
    }

    int miniInversionCount=*min_element(minInversions.begin(), minInversions.end());

    cout<<miniInversionCount<<"\n"; 

    for(int i=0;i<n;i++){
        if(minInversions[i]==miniInversionCount) cout<<i+1<<" ";
    }
    
    return 0;
}