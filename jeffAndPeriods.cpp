#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int>st;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        st.insert(arr[i]);
    }
        
    map<int, int> mp;

    int maxEl=*max_element(arr.begin(),arr.end());

    //index, diff store krega
    vector<pair<int,int>>vis(maxEl+1,{-1,0});
    
    for (int i = 0; i < n; i++){
        // cout<<i<<" ";
        int curr=arr[i];
        if(vis[curr].first==INT_MAX){
            continue;
        }

        if(vis[curr].first==-1){
            // pehli baar entry ho rha
            vis[curr]={i,0};
            continue;
        }

        //Pehle se stored hai
        int diff=i-vis[curr].first;
        if(vis[curr].second==0){
            vis[curr]={i,diff};
        }
        else{

            if(diff==vis[curr].second){
                vis[curr].first=i;
            }
            else {
                vis[curr].first=INT_MAX;
                st.erase(curr);
            }
        }
    }

    for(auto x: st){
        if(vis[x].first==INT_MAX) st.erase(x);
    }
    cout<<st.size()<<"\n";
    for(auto x: st){
        if(vis[x].first==INT_MAX) continue;
        else{
            cout<<x<<" "<<vis[x].second;
            cout<<"\n";
        }
    }

}