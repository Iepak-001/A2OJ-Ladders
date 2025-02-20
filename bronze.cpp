// #include<bits/stdc++.h>
// using namespace std;

// int main(){
    
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    string ans="";
    for(int i=0;i<s.size(); i++){
        if(s[i]=='.'){
            ans.push_back('0');
        }
        else if(s[i]=='-'){
            if(s[i+1]=='.'){
                ans.push_back('1');
            }
            else ans.push_back('2');
            i++;
        }
    }
    cout<<ans;
}