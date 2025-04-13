#include <bits/stdc++.h>
using namespace std;

int  main()
{
    long long  n,m;
    cin>>n>>m;
    vector<long long >a(n),b(m);
    for(long long  i=0;i<n;i++) cin>>a[i];
    for(long long  i=0;i<m;i++) cin>>b[i];

    vector<long long >preA(n+1,0),preB(m+1,0);

    for(long long  i=1;i<=n;i++) preA[i]=preA[i-1]+a[i];
    for(long long  i=1;i<=m;i++) preB[i]=preB[i-1]+b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // ya toh sabko max ke krabar banao
    // ya phir max wale array ko km kro

    // YA ANSwer SPACE ME BINARY SEARCH

    long long  lo=0;
    long long  hi=INT_MAX;
    long long  minSteps=INT_MAX;

    while(lo<=hi){
        long long  mid=lo+(hi-lo)/2;

        long long  steps=0;
        for(long long  i=0;i<n;i++){
            steps+=abs(a[i]-mid);
        }

        for(long long  i=0;i<m;i++){
            steps+=abs(b[i]-mid);
        }

        if(steps<minSteps){
            minSteps=steps;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }

    }

    cout<<minSteps;

    return 0;
}