#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int indx(int target, vector<int>&v){
    int lo = 0, hi = v.size(); // hi is v.size(), not v.size()-1
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] <= target)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo; // lo equals the number of elements ≤ target
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int m;
    cin>>m;
    vector<int>brr(m);
    for(int i=0;i<m;i++) cin>>brr[i];

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

    
    unordered_set<int>st;
    st.insert(0);
    for(int i=0;i<n;i++)st.insert(arr[i]);
    for(int i=0;i<m;i++) st.insert(brr[i]);


    int maxDiff=INT_MIN;
    int maxA=0,maxB=0;
    for(auto target: st){
        //crr[i]+1 && crr[i-1] par chalao
        int tempT=target;
        int indxA=indx(target,arr);
        int indxB=indx(target,brr);

        int pointA=0,pointB=0;

        pointA=2*(indxA)+ 3*(n-indxA);
        pointB=2*(indxB) + 3*(m-indxB);

        if(maxDiff<=pointA-pointB){
            if(maxDiff==pointA-pointB){
                if(pointA>maxA){
                    maxA=pointA;
                    maxB=pointB;
                }
            }
            else{
                maxDiff=pointA-pointB;
                maxA=pointA;
                maxB=pointB;
            }
        }

        target=tempT+1;
        indxA=indx(target,arr);
        indxB=indx(target,brr);

         pointA=2*indxA + 3*(n-indxA);
         pointB=2*indxB + 3*(m-indxB);

        if(maxDiff<=pointA-pointB){
            if(maxDiff==pointA-pointB){
                if(pointA>maxA){
                    maxA=pointA;
                    maxB=pointB;
                }
            }
            else{
                maxDiff=pointA-pointB;
                maxA=pointA;
                maxB=pointB;
            }
        }

         target=tempT-1;
         indxA=indx(target,arr);
         indxB=indx(target,brr);

         pointA=2*indxA + 3*(n-indxA);
         pointB=2*indxB + 3*(m-indxB);

        if(maxDiff<=pointA-pointB){
            if(maxDiff==pointA-pointB){
                if(pointA>maxA){
                    maxA=pointA;
                    maxB=pointB;
                }
            }
            else{
                maxDiff=pointA-pointB;
                maxA=pointA;
                maxB=pointB;
            }
        }

    }
    cout<<maxA<<":"<<maxB;
    return 0;
}