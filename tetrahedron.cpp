#include <bits/stdc++.h>
using namespace std;
#define ll long long


int mod=1000000007;
// int f(int i,int n){
//     if(n==0 && i==0) return 1;
//     if(n==0) return 0;

//     if(n<0) return 0;

//     if(dp[i][n]!=-1) return dp[i][n];

//     int ans=0;
//     ans=(ans%mod +f((i+1)%4,n-1)%mod)%mod;
//     ans=(ans%mod +f((i+2)%4,n-1)%mod)%mod;
//     ans=(ans%mod +f((i+3)%4,n-1)%mod)%mod;

    
//     return dp[i][n]=ans%mod;
// }
int main()

{
    // Recursive solution not working due to
    // very large recursive stack

    // it is maths question

    // therefore tabulation also not working

    int n;
    cin>>n;

    ll atTop=1; // ways to be at Top of tetrahedron
    ll atOther=0; // other 3 vertices

    for(int i=0;i<n; i++){

        ll newAtTop=(3*atOther)%mod; // ways to reach at top vertex
        ll newAtOther=(2*atOther + atTop)%mod; //2ways each from Other3vertex and 1 way from top ==>> FOR EACH VERTEX

        atTop=newAtTop;
        atOther=newAtOther;
    }
    cout<<atTop%mod;

}