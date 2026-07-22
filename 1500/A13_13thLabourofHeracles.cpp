
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
      long long n;
      cin>>n;
      vector<long long> w(n);

      long long sum = 0;

      for(int i=0;i<n;i++)
      {
        cin>>w[i];
        sum += w[i];
      }

      vector<long long> degree(n+1);

      for(int i=0;i<n-1;i++)
      {
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
      }

      priority_queue<long long> pq;

      for(int i=0;i<n;i++)
      {
        while(degree[i+1] > 1)
        {
            pq.push(w[i]);
            degree[i+1]--;
        }
      }

      vector<long long> res;

      res.push_back(sum);

      for(int i=1;i<n-1;i++)
      {
        if(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        res.push_back(sum);
      }


      for(int i=0;i<n-1;i++)
      {
        cout<<res[i]<<" ";
      }
      cout<<endl;

   }
}
