#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    string val;
    cin >> val;

    int k;
    cin >> k;

    // set<string> st;

    // vector<vector<int>> kval(n+1, vector<int>(n+1, 0));


    // for (int length = 1; length <= n; length++)
    // {

    //     for (int i = 0; i +(length-1) < n; i++)
    //     {
    //         // subStr from i==>j
            
    //         if (length==1){
            
    //             if (val [s[i]-'a'] == '0') kval[i][length] = 1;
                    
    //             else kval[i][length] = 0;
                
                
    //             if (kval[i][length] <= k) st.insert(s.substr(i, length));
                
    //             // cout<<s.substr(i, length)<<" "<<kval[i][length]<<endl;

    //             continue;
    //         }
            
    //         kval[i][length] = kval[i][length/2] + kval[i + length/2][length-length/2];

    //         // cout<<s.substr(i, length)<<" "<<kval[i][length]<<endl;

    //         if (kval[i][length] <= k) st.insert(s.substr(i, length));  
    //     }
    // }

    unordered_set<string> st;
    vector<int> bad(n + 1, 0);  // Prefix sum array for bad character count

    // Compute prefix sum of 'bad' character counts
    for (int i = 0; i < n; i++) {
        bad[i + 1] = bad[i] + (val[s[i] - 'a'] == '0');
    }

    // Iterate over all substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (bad[j + 1] - bad[i] <= k) {  // Count of 'bad' chars in substring s[i:j]
                st.insert(s.substr(i, j - i + 1));
            }
        }
    }

    // for (auto x : st) cout << x << " ";
    cout<<st.size();
        
    return 0;
}