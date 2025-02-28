#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
long long int  gap=0;
vector< vector<long long int>>dp;
long long int   f(long long int  i, vector<long long int >&pre,long long int  k){
    if(i>=pre.size() || k<=0 ) return 0;

    if(dp[i][k]!=-1) return dp[i][k];
    ll ans=0;
    // take
    if(i+gap<pre.size())
    ans=pre[i+gap]-pre[i] + f(i+gap,pre,k-1);

    //not take
    ans=max(ans,f(i+1,pre,k));

    return dp[i][k]=ans;
    
}
int  main()
{
    // array ko subarray of length m me divide krna hai
    // aisa K subarrays ka sum max krna hai
    long long int  n,m,k;
    cin>>n>>m>>k;

    gap=m;
    vector<long long int>pre(n+1,0);
    vector<long long int >arr(n+1);
    for(long long int  i=1;i<=n; i++){
        cin>>arr[i];
        pre[i]=pre[i-1]+arr[i];
    }

    if(m==1){
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        long long int  ans=0;
        for(long long int  i=0;i<k;i++){
            ans+=arr[i];
        }
        cout<<ans;
        return 0;
    }
    dp.resize(n+1,vector<ll>(k+1,-1));

    long long int  ans=f(0,pre,k);
    cout<<ans;
    return 0;
}