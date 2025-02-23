#include<bits/stdc++.h>
using namespace std;

// Each letter frequency is to be stored
// Now how can we check if a palindrome can be formed from freq arr
// if oddFreqCount==0 => Frst will win
// if odd freq=1 => first will remove one char and win
// If oddCount is odd => first will win
// else Second will win

int main(){
    string s;
    cin>>s;

    vector<int>freq(26,0);
    for(auto x: s) freq[x-'a']++;

    int n=s.size();
    int count=0;
    for(int i=0;i<26;i++){
        if(freq[i]%2==1) count++;   
    }

    if(count==0 || count%2==1) cout<<"First";
    else cout<<"Second";
}