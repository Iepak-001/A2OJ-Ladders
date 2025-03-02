#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());

    int lo=0;
    int hi=(n+1)/2; //handling for odd case by adding 1

    int count=0;
    while(hi<n){
        if(arr[hi]>=2*arr[lo]){
            count++;
            hi++;
            lo++;
        }
        else hi++;
    }
    cout<<n-count;
    return 0;
}