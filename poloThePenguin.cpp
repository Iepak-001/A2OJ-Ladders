#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,d;
    cin>>n>>m>>d;

    vector<int>arr(n*m);
    for(int i=0; i<n*m; i++){
        cin>>arr[i];
    }
    // kaun element sabse paas hai dekhna hoga
    // median of all elements

    int rem=arr[0]%d;
    for(int i=1;i<arr.size();i++){
        if(arr[i]%d !=rem){
            cout<<-1;
            return 0;
        }
    }

    sort(arr.begin(),arr.end());
    int target=arr[arr.size()/2];

    int moves=0;
    for(int i=0;i<arr.size();i++){
        moves+=abs(arr[i]-target)/d;
    }

    cout<<moves;

    
    return 0;
}