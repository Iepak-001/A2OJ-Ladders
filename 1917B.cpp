#include <bits/stdc++.h>
using namespace std;
void f(string s, unordered_set<string> &st)
{
    if (s.size() == 0)
        return;

    st.insert(s);

    if (s.size() >= 2)
    {
        char x=s[0];
        s.erase(0, 1);
        st.insert(s);
        f(s, st);

        s.insert(0,1,x);
        s.erase(1, 1);
        st.insert(s);
        f(s, st);
    }

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_set<string> st;

        f(s, st);
        cout << st.size() << endl;
        // for(auto x:st) cout<<x<<" ";
    }
    return 0;
}