#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<long long int>arr(n);
    map<long long int,long long int>mp;
    for(long long int i=0; i<n; i++) {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    long long int mini=*min_element(arr.begin(), arr.end());
    long long int maxi=*max_element(arr.begin(),arr.end());

    long long int k=maxi-mini;

    long long int ways=0;
    for(long long int i=0; i<n; i++){
        mp[arr[i]]--;
        if(mp[arr[i]]==0) mp.erase(arr[i]);
        long long int rem1=arr[i]-k;
        long long int rem2=k+arr[i];
        if(mp.find(rem1)!=mp.end()){
            ways+=mp[rem1];
        }

        if(k!=0 && mp.find(rem2)!=mp.end()){
            ways+=mp[rem2];
        }
    }
    cout<<k<<" "<<ways;
}