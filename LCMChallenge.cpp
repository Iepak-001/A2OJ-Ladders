#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

ll lcm3(ll a, ll b, ll c) {
    return lcm(lcm(a, b), c);
}

int main()
{
    long long n;
    cin>>n;

    if(n==1) {
        cout<<1;
        return 0;
    }
    if(n==2) {
        cout<<2;
        return 0;
    }
    if(n%2==1){
        cout<<n*(n-1)*(n-2);
    }
    else{
        cout<<max(lcm3(n,n-1,n-3),lcm3(n-1,n-2,n-3));
    }
    return 0;
}