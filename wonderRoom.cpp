#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,b;
    cin>>n>>a>>b;


    long long reqArea=6*n;

    if(a*b >=reqArea){
        cout<<a*b<<"\n";
        cout<<a<<" "<<b;
        return 0;
    
    }
    long long tempa=a,tempb=b;

    if(b<a) swap(a,b);

    long long newB=b;
    long long newA=a;

    long long minA=a,minB=b,minArea=LLONG_MAX;
    
    for(newA=a; newA*newA<=reqArea*2;newA++){
        
        newB=(reqArea+newA-1)/newA; // To make cieling value
        
        if (newB < b) continue; // We cannot decrease any value

        if(newB*newA<minArea && newA*newB>=reqArea){
            minArea=newA*newB;
            minA=newA;
            minB=newB;
            if(newA*newB==reqArea) break;
        }
    }
    if(tempa>tempb) swap(minA,minB);
    cout<<minA*minB<<"\n";
    cout<<minA<<" "<<minB;
    return 0;
}