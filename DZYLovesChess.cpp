#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int i,int j, vector<vector<char>>&arr, vector<vector<char>>&vis, bool flag){
    int n=arr.size();
    int m=arr[0].size();
    for(int k=0; k<4; k++){
        int nrow=i+dir[k][0];
        int ncol=j+dir[k][1];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]=='.' && vis[nrow][ncol]=='-'){
            if(flag==0) vis[nrow][ncol]='B';
            else vis[nrow][ncol]='W';
            dfs(nrow,ncol,arr,vis,!flag);
        }
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n; i++){
        for(int j=0;j<m; j++) cin>>arr[i][j];
    }

    vector<vector<char>>vis(n,vector<char>(m,'-'));

    for(int i=0;i<n; i++){
        for(int j=0;j<m; j++) {
            //dfs call lagao
            // agar visited nhi hai toh
            if(arr[i][j]=='.' && vis[i][j]=='-'){
                vis[i][j]='W';
                dfs(i,j,arr,vis,0);
            }
        }
    }

    for(int i=0;i<n; i++){
        for(int j=0;j<m; j++) cout<<vis[i][j];
        cout<<"\n";
    }
    
}