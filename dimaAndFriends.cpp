#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int sum=accumulate(arr.begin(), arr.end(),0)-1;
    
    int ans=0;

    for(int i=1;i<=5; i++){
        if((sum+i)%(n+1) !=0) ans++;
    }
    cout<<ans;

}