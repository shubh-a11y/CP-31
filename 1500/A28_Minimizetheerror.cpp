
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k1,k2;
    cin>>n>>k1>>k2;

    vector<long long> a(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<long long> b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    priority_queue<long long> pq;
    vector<long long> diff(n,0);
    for(int i=0;i<n;i++)
    {
        diff[i] = abs(a[i]-b[i]);
        pq.push(diff[i]);
    }




    long long k = k1+k2;
    long long ans = 0;
    
    while((k > 0) && (!pq.empty()) && (pq.top() > 0))
    {
        long long tp = pq.top();
        pq.pop();
        k--;
        tp--;
        pq.push(tp);
    }

    while(!pq.empty())
    {
        long long tp = pq.top();
        pq.pop();
        ans += (tp*tp);
    }
        
    if(k > 0)
    {
        if(k%2 == 0)
        {
            ans += 0;
        }
        else
        {
            ans += 1;
        }
    }

    

    cout<<ans<<endl;



}