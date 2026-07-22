
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        string s;
        cin>>s;
        
        unordered_set<char> st1,st2;
        vector<int> a(n);

        for(int i=0;i<n;i++)
        {
            st1.insert(s[i]);
            a[i] = st1.size();
        }

        vector<int> b(n);
        for(int i=n-1;i>=0;i--)
        {
            st2.insert(s[i]);
            b[i] = st2.size();
        }

        long long ans = 0;
        for(int i=0;i<n-1;i++)
        {
            ans = max(ans, (long long)a[i]+b[i+1]);
        }

        cout<<ans<<endl;


    }
}
