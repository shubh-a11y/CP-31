
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    vector<long long> a(n);
    long long largest = 0;
    long long largestidx = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] > largest)
        {
            largest = a[i];
            largestidx = i;
        }
    }

    vector<vector<long long>> indices(1e6+1);
    for(int i=0;i<n;i++)
    {
        if(i == largestidx)
        {
            continue;
        }
        indices[a[i]].push_back(i);
    }

    sort(a.begin(),a.end());
    vector<long long> prefix(n,0);
    prefix[0] = a[0];
    for(int i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1]+a[i];
    }

    long long ans = 0;

    vector<long long> idxs;

long long target = prefix[n-2] - a[n-1];
    
    // Check if target is perfectly within valid array bounds!
    if(target >= 0 && target <= 1000000)
    {
        if(indices[target].size() > 0)
        {
            ans += indices[target].size();
            for(int i = 0; i < indices[target].size(); i++)
            {
                idxs.push_back(indices[target][i]);
            }
        }
    }



    if((n-3 >= 0) && (prefix[n-3] == a[n-2]))
    {
        ans++;
        idxs.push_back(largestidx);
    } 

    cout<<ans<<endl;
    for(int i=0;i<idxs.size();i++)
    {
        cout<<idxs[i]+1<<" ";
    }

}