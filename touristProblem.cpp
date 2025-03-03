#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);


    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    ll totalSum=0;
    totalSum=accumulate(arr.begin(),arr.end(),0ll);

    ll prefixSum=0;
    ll bwDistance=0;

    for(int i=0;i<n;i++){
        bwDistance+=i*arr[i]-prefixSum;
        prefixSum+=arr[i]; 
    }


    ll numerator=totalSum+2*bwDistance;
    ll denominator=n;
    ll divisor=__gcd(numerator,denominator);


    numerator/=divisor;
    denominator/=divisor;


    cout<<numerator<<" "<<denominator;

    return 0;
}