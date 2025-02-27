#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>upper(n),lower(n);
    int upperSum=0,lowerSum=0;
    for(int i=0;i<n;i++){
        cin>>upper[i]>>lower[i];
        lowerSum+=lower[i];
        upperSum+=upper[i];
    }

    if((upperSum+lowerSum)%2==1){
        cout<<-1;
        return 0;
    }

    if(upperSum%2==0 && lowerSum%2==0){
        cout<<0;
        return 0;
    }

    // ya toh dono sum odd hoga 
    // => ek odd no ko even se exchange

    // ya dono sum even => return 0

    for(int i=0;i<n;i++){
        if((upper[i]+lower[i])%2==1){
            cout<<1;
            return 0;
        }
    }

    cout<<-1;

    return 0;
}