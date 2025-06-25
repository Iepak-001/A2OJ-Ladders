#include <bits/stdc++.h>
using namespace std;
int findMSB(int n){
    int result=0;
    while(n>1){
        n=n>>1;
        result++;
    }
    return result;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>arr(n),counter(32,0);

        for(int i=0;i<n;i++) cin>>arr[i];

        // max bit count can be 32
        for(int i=0;i<n;i++){
            int msb=findMSB(arr[i]);
            counter[msb]++;
        }
        long long ans=0;
        for(int i=0;i<32;i++){
            ans+=(counter[i]*(counter[i]-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}