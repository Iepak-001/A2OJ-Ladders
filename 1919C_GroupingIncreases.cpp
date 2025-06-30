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

        vector<int> a, b;
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);

        vector<int> *smallerVec = &a;
        vector<int> *largerVec = &b;

        for (int i = 0; i < n; i++)
        {
            if (a[a.size() - 1] <= b[b.size() - 1])
            {
                smallerVec = &a;
                largerVec = &b;
            }
            else {
                smallerVec = &b;
                largerVec = &a;
            }

            if (arr[i] <= (*smallerVec)[smallerVec->size() - 1])
                smallerVec->push_back(arr[i]);

            else if (arr[i] > (*largerVec)[largerVec->size() - 1])
                smallerVec->push_back(arr[i]);
            
            else 
                largerVec->push_back(arr[i]);
        }

        int l=a.size();
        int m=b.size();

        int penalty=0;
        for(int i=0;i<l-1;i++){
            if(a[i]<a[i+1]) penalty++;
        }

        for(int i=0;i<m-1;i++){
            if(b[i]<b[i+1]) penalty++;
        }

        cout<<penalty<<endl;

    }
    return 0;
}