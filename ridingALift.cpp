#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[5005][5005];
int mod=1e9+7;
ll f(int n, int currLevel, int restrictedLevel, int tripsLeft){
    if(currLevel<=0 || currLevel>n) return 0;
    if(tripsLeft==0) return 1;

    if(dp[currLevel][tripsLeft]!=-1) return dp[currLevel][tripsLeft];

    int levelDiff=abs(currLevel-restrictedLevel);
    if(levelDiff<=1) return 0;

    ll ans=0;
    
    ll bothSum=0;
    for(int i=1;i<levelDiff;i++){
        ll left=f(n,currLevel+i,restrictedLevel,tripsLeft-1);
        ll right=f(n,currLevel-i,restrictedLevel,tripsLeft-1);
        bothSum+=(left+right);
    }
    ans=((ans%mod )+ (bothSum%mod))%mod;
    return dp[currLevel][tripsLeft]=ans;
}
int main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    memset(dp,-1,sizeof(dp));
    ll ans=f(n,a,b,k);
    cout<<ans%mod;

    return 0;
}
