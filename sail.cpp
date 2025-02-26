#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;

    string s;
    cin>>s;

    map<char,int>dir;

    long long int dx=ex-sx;
    long long int dy=ey-sy;


    if(dx>0) dir['E']=dx;
    if(dx<0) dir['W']=-dx;

    if(dy>0) dir['N']=dy;
    if(dy<0) dir['S']=-dy;



    int time=0;

    for(long long int i=0; i<s.size(); i++){
        time++;
        if(dir.find(s[i])!=dir.end() && dir[s[i]]>0){
            dir[s[i]]--;
            if(dir[s[i]]==0) dir.erase(s[i]);
        }

        if(dir.size()==0){
            cout<<time;
            return 0;
        }
        
    }
    
    
    cout<<-1;
}