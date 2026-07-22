
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {

    long long n,k;
    cin>>n>>k;
    priority_queue<pair<long long, long long>> pq;

    for(long long i=0;i<n;i++)    
    {
        long long x;
        cin>>x;
        if(x%k == 0)
        {
            x = k;
        }
        else{
            x = x%k;
        }
        pq.push({x,n-i});
    }

    while(pq.empty() == false)
    {
        auto it = pq.top();
        pq.pop();

        long long health = it.first;
        long long index = it.second;

        if(health > k)
        {
            health -= k;
            pq.push({health, index});
        }
        else{
            cout<<n-index+1<<" ";
        }

    }
    cout<<endl;

}




}

