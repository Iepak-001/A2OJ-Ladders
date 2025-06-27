#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 1; i < n; i += 2)
            arr[i] *= -1;

        
        map<long long, int> mp;
        
        mp[0]++;

        // Make alternating sum
        long long sum=0;

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            sum+=(long long)arr[i];
            if (mp.count(sum))
            {
                flag = true;
                break;
            }
            mp[sum]++;
        }

        if (flag == false)
            cout << "NO";
        else
            cout << "YES";

        cout << "\n";
    }
    return 0;
}