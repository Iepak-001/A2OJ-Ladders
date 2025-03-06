#include <bits/stdc++.h>
using namespace std;

int f(int left, int right, vector<int>&heights, int baseHeight){
    if(left>right) return 0;

    
    int mindx=left;
    for(int i=left;i<=right;i++){
        if(heights[i]<heights[mindx]) mindx=i;
    }

    int horStrokes=heights[mindx]-baseHeight;

    int leftStrokes=f(left,mindx-1,heights,heights[mindx]);
    int rightStrokes=f(mindx+1,right,heights,heights[mindx]);

    return min(horStrokes+leftStrokes+rightStrokes, right-left+1);
}

int main()
{
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    int ans=f(0,n-1,heights,0);
    
    cout<<ans;
    return 0;
}