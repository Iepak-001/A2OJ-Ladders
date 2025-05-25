#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int maxDiff=max(arr[0],2*(x-arr[n-1]));
        for(int i=1;i<n;i++){
            maxDiff=max(maxDiff,arr[i]-arr[i-1]);
        }
        cout<<maxDiff<<endl;
    }
    return 0;
}