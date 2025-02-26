#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int f(vector<int>&temp, vector<vector<int>>&arr , vector<bool>&vis){
    if(temp.size()==5){
        return arr[temp[0]][temp[1]] + arr[temp[1]][temp[0]] +
                2*arr[temp[2]][temp[3]] + 2*arr[temp[3]][temp[2]] + 
                2*arr[temp[3]][temp[4]] + 2*arr[temp[4]][temp[3]] +
                arr[temp[1]][temp[2]] + arr[temp[2]][temp[1]];
    }
    int ans=0;
    for(int i=0;i<5; i++){
        if(vis[i]==1) continue;

        vis[i]=1;
        temp.push_back(i);
        ans=max( ans, f(temp,arr,vis));
        temp.pop_back();
        vis[i]=0;
    }
    return ans;
}
int main()
{
    vector<vector<int>>arr(5,vector<int>(5));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) cin>>arr[i][j];
    }

    int ans=0;
    vector<bool>vis(5,0);

    vector<int>temp;
    cout<<f(temp,arr,vis);


    return 0;
}