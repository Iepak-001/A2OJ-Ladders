#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        map<pair<int,int>,int>mp;

        long long ans=0;

        for(int i=0;i<n;i++){
            //Look in hash map for prevously inserted values
            int needX=(x-arr[i]%x)%x;
            int needY=arr[i]%y;

            if(mp.find({needX,needY})!=mp.end()) ans+=(long long) mp[{needX,needY}];

            mp[{arr[i]%x,arr[i]%y}]++;
        }
        cout<<ans<<endl;

    }
    return 0;
}