#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }

    int r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    r1-=1,c1-=1,c2-=1,r2-=1;

    // IF Start and End coincide

    if(r1==r2 && c1==c2){

        for(int i=0;i<4;i++){
            int nrow=r1+dir[i].first;
            int ncol=c1+dir[i].second;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]=='.'){
                cout<<"YES"<<endl;
                return 0;
            }
            
        }
        cout<<"NO";
        return 0;
    }

    // If Start and End are neighbors

    if(abs(r1-r2)+abs(c1-c2) ==1){

        if(arr[r2][c2]=='X'){
            cout<<"YES"<<endl;
            return 0;
        }
        else if(arr[r2][c2]=='.'){

            for(int i=0;i<4;i++){
                int nrow=r2+dir[i].first;
                int ncol=c2+dir[i].second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]=='.'){
                    cout<<"YES"<<endl;
                    return 0;
                }
                
            }
            cout<<"NO";
                return 0;
        }
    }

    // Start and end NOt special case

    set<pair<int,int>>vis;

    stack<pair<int,int>>st;

    st.push({r1,c1});
    vis.insert({r1,c1});

    while(!st.empty()){
        auto x=st.top();
        st.pop();
        

        for(int i=0;i<4;i++){

            int nrow=x.first + dir[i].first;
            int ncol=x.second + dir[i].second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis.find({nrow,ncol})==vis.end() && (arr[nrow][ncol]=='.' || (nrow==r2 && ncol==c2))){
                st.push({nrow,ncol});
                vis.insert({nrow,ncol});
            }
        }
    }

    // End unreachable

    if(vis.find({r2,c2})==vis.end()){
        cout<<"NO";
        return 0;
    }

    // End is X => only one sturdy neighbor needed
    
    if(arr[r2][c2]=='X'){

        for(int i=0;i<4;i++){
            int nrow=r2+dir[i].first;
            int ncol=c2+dir[i].second;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]=='.'){
                cout<<"YES"<<endl;
                return 0;
            }
            
        }
        cout<<"NO";
        return 0;
    }

    if(arr[r2][c2]=='.'){
        int count=0;
        for(int i=0;i<4;i++){
            int nrow=r2+dir[i].first;
            int ncol=c2+dir[i].second;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]=='.'){
                count++;
            }
            
        }
        if(count>=2){
            cout<<"YES"<<endl;
            return 0;
        }
        cout<<"NO";
        return 0;
    }


    cout<<"NO";
    return 0;
}