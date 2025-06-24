#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<pair<long long,long long>>arr(n);
        for(long long i=0;i<n;i++) {
            cin>>arr[i].first;
            arr[i].second=i;
        }

        sort(arr.begin(),arr.end());

        vector<long long>prefSum(n);

        prefSum[0]=arr[0].first;
        for(long long i=1;i<n;i++) prefSum[i]=prefSum[i-1]+arr[i].first;


        

        vector<long long>result(n,0);
        result[arr[n-1].second]=n-1;
        
        for(long long i=n-2;i>=0;i--){

            if(prefSum[i]>=arr[i+1].first){
                result[arr[i].second]=result[arr[i+1].second];

            } 
            else result[arr[i].second]=i;
                        
        }

        for(auto x:result) cout<<x<<" ";
        cout<<endl;
        
    }
    return 0;
}