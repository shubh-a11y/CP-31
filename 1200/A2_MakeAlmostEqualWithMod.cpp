
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long k = 1;

        for(int i=1;i<=60;i++)
        {
            k = k*2;
            unordered_set<long long> s;
            for(int j=0;j<n;j++)
            {
                s.insert(a[j]%k);
            }
            if(s.size() == 2)
            {
                cout<<k<<endl;
                break;
            }
        }

    }
}