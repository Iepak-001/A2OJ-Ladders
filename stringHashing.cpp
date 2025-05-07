#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod=1e9+7;
    int m,n;
    cin>>m>>n;
    vector<string>s(m),t(n);

    for(int i=0;i<m;i++){
        string temp;
        cin>>temp;
        s[i]=temp;
    }

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        t[i]=temp;
    }

    set<long long>st;



    vector<long long>powers(3e6+5);
    long long p=53;
    powers[0]=1;
    for(int i=1;i<powers.size();i++){
        powers[i]=(powers[i-1]*p)%mod;
    }



    for(int i=0;i<m;i++){
        long long hashVal=0;
        string curr=s[i];
        for(int j=0;j<s[i].size();j++){
            hashVal=(hashVal+ (curr[j]-'a'+1)*powers[j])%mod;
        }
        st.insert(hashVal);
    }



    vector<long long>hash(n);

    for(int i=0;i<n;i++){
        long long hashVal=0;
        string curr=t[i];
        for(int j=0;j<curr.size();j++){
            hashVal=(hashVal+ (curr[j]-'a'+1)*powers[j])%mod;
        }
        hash[i]=hashVal;
        
    }

    for(int i=0;i<n;i++){

        string curr=t[i];
        bool flag=false;
        for(int j=0;j<curr.size();j++){
            int hasVal2=(hash[i]+ mod  +('a' -'a'+1)*powers[j] - (curr[j]-'a'+1)*powers[j])%mod;
            int hasVal3=(hash[i]+mod+ ('b'-'a'+1)*powers[j] - (curr[j]-'a'+1)*powers[j])%mod;
            int hasVal4=(hash[i] +mod+ ('c' -'a'+1)*powers[j] - (curr[j]-'a'+1)*powers[j])%mod;

            if(st.find(hasVal2)!=st.end() || st.find(hasVal3)!=st.end() || st.find(hasVal4)!=st.end()){
                flag=true;
                break;
            }
        }
        if(flag==false){
            cout<<"NO";
        }
        else cout<<"YES";

        cout<<endl;
    }

    return 0;
}