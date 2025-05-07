#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s;

    cin >> k>>s;
    

    int n=s.size();

    
    if(k==0){
        long long count0=0;
        long long ans=0;
        
        for(int i=0;i<n;i++){
            // calculate zeros on left and right of 1
            if(s[i]=='0')  count0++;
            
            else if(s[i]=='1'){
                ans+=(count0*(count0+1))/2;
                count0=0;
            }
        }
        if(count0!=0) ans+=(count0*(count0+1))/2;
        cout<<ans;
        return 0;
    }

    vector<int>left(n,0),right(n,0);

    int count0=0;
    int count1=0;
    int prev=-1,curr=0;

    for(int i=0;i<n;i++){
        // calculate zeros on left and right of 1
        if(s[i]=='0')  count0++;
        
        else{
            left[i]=count0;
            if(prev!=-1) right[prev]=count0;
            count0=0;
            prev=i;
        }
    }
    if(count0!=0 && prev!=-1) right[prev]=count0;

    

    // for(int i=0;i<n;i++){
    //     cout<<left[i]<<" "<<right[i]<<endl;
    // }

    // //Make an array of positions of 1
    vector<int>pos1;
    for(int i=0;i<n;i++){
        if(s[i]=='1') pos1.push_back(i);
    }


    int lo=0;
    int hi=k-1;

    long long result=0;

    while(hi<pos1.size()){
        result+=(long long)((long long)(1+left[pos1[lo]])*(long long)(right[pos1[hi]]+1));
        lo++,hi++;
    }

    cout<<result<<endl;


    return 0;
}