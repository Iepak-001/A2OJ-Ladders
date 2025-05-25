#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll totalSum=accumulate(arr.begin(),arr.end(),(ll)0);

        ll minimalBeauty=(totalSum+(x-1))/x;

        ll maximalBeauty=0;
        for(int i=0;i<n;i++){
            maximalBeauty+=(arr[i]+x-1)/x;
        }

        cout<<minimalBeauty<<" "<<maximalBeauty<<endl;
    }
    return 0;
}