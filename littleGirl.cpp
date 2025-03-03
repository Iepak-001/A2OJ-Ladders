#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int>freq(2*10e5+1,0);

    for(int i=0;i<q;i++){

        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++) freq[j]++;
    }

    sort(arr.begin(),arr.end());
    
    sort(freq.begin(),freq.end());

    for(int i=0;i<=2*10e5;i++){

    }

    return 0;
}