#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define ll long long

int main()
{
    int n,k;
    cin>>n>>k;
    
    queue<int>levelQueues[n];

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        levelQueues[a].push(i);
    }

    if(levelQueues[0].size()!=1 || levelQueues[1].size()>k) {
        cout<<-1;
        return 0;
    }

    for(int level=1;level<n-1;level++){
        ll parents=levelQueues[level].size();
        ll childrens=levelQueues[level+1].size();

        if(childrens>parents*(k-1)){
            cout<<-1;
            return 0;
        }
    }


    queue<pp>bfsQueue; // {Node,dist}
    bfsQueue.push({levelQueues[0].front(),0});

    vector<pp>edgeList;

    while(!bfsQueue.empty()){

        int currNode=bfsQueue.front().first;
        int currLevel=bfsQueue.front().second;
        bfsQueue.pop();

        int degreeLimit=(currLevel==0)?k:k-1;

        while(currLevel<n-1 && !levelQueues[currLevel+1].empty() && degreeLimit>0){
            int childNode=levelQueues[currLevel+1].front();
            levelQueues[currLevel+1].pop();

            edgeList.push_back({currNode,childNode});

            bfsQueue.push({childNode,currLevel+1});
            degreeLimit--;
        }
    }

    cout<<edgeList.size()<<"\n";
    for (auto [u, v] : edgeList) {
        cout<<u<<" "<<v<<"\n";
    }


    
    return 0;
}