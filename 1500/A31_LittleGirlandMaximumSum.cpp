
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    long long q;
    cin>>q;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<long long> prefixSum(n+1,0);

    for(int i=0;i<q;i++)
    {
        long long l,r;
        cin>>l>>r;

        prefixSum[l-1]++;
        prefixSum[r]--;
    }

    priority_queue<long long> pq;
    pq.push(prefixSum[0]);
    for(int i=1;i<n;i++)
    {
        prefixSum[i] += prefixSum[i-1];
        if(prefixSum[i] > 0)
        {
            pq.push(prefixSum[i]);
        }
    }

    sort(a.begin(), a.end(),greater<long long>());

    int idx = 0;
    long long ans = 0;
    while(!pq.empty())
    {
        long long curr = pq.top();
        pq.pop();

        ans += curr*a[idx];
        idx++;
    }

    cout<<ans<<endl;
}