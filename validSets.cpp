#include <bits/stdc++.h>
using namespace std;
vector<list<int>>graph;

void addEdge(int n1,int n2){
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
}
int main()
{
    int d,n;
    cin>>d>>n;

    vector<int>val(n);
    for(int i=0;i<n;i++) cin>>val[i];

    graph.resize(n,{});

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
    }

    // Graph is fully connected
    // max  n x n possibilities
    // Subarray jaisa kuch bna rha
    // base khojo aur sub-array nikalo

    // jo single time aa rha usko base bna lo
    // NOPE YE TARIKA KAAM NHI KREGA ||| TREE HAI YAHA

    // khi se bhi start maaro 
    // then all possibilities daalo
    
    return 0;
}