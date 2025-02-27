#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;

int main()
{
    long long x,y,n;
    cin>>x>>y>>n;

    if(n%12==0) n=12;
    else n=n%12;

    if(n==1 || n==2){
        if(n==1) cout<<(x%mod +mod)%mod;
        else cout<<(y%mod +mod)%mod;
        return 0;
    }
    long long z=y-x;

    for(int i=3;i<n;i++){
        x=y;
        y=z;
        z=y-x;
    }
    cout<<(z%mod +mod )%mod;
    return 0;
}