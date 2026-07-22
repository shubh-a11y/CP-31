
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
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[a[i] - i]++;
        }

        long long count = 0;
        for(auto it: freq)
        {
            long long f = it.second;
            count += f*(f-1)/2;
        }

        cout<<count<<endl;
    }

}
