
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);

        unordered_map<long long, long long> mp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }

        vector<long long> freq;
        for(auto& it: mp)
        {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end(), greater<long long>());

        long long candi = freq[0];

        long long idx = 0;
        long long result = 0;

        while(idx < freq.size() && candi > 0)
        {
            result += min(candi, freq[idx]);
            int curr = min(candi, freq[idx]);
            candi = curr - 1;
            idx++;
        }

        cout<<result<<endl;
    }
}