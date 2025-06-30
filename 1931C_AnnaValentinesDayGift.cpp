#include <bits/stdc++.h>
using namespace std;
int calculateZeros(int n){
    int count=0;
    while(n%10==0){
        count++;
        n/=10;
    }
    return count;
}

int digits(int n){
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i].second;
            arr[i].first=calculateZeros(arr[i].second);
        }

        sort(arr.begin(), arr.end());

        vector<int>noOfDigits(n);
        for(int i=0;i<n;i++) noOfDigits[i]=digits(arr[i].second);

        int right=n-1;
        int ans=0;
        while(right>=0){
            //Anna chance
            
            ans+=(noOfDigits[right]-arr[right].first);
            right--;

            //Sasha Chance
            if(right>=0) ans+=noOfDigits[right];
            right--;
        }

        if(ans>k) cout<<"Sasha";
        else cout<<"Anna";

        cout<<endl;
    }
    return 0;
}