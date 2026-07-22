
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n+1,0);
        vector<int> child_count(n+1,0); // To count the number of children of each node
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            child_count[a[i]]++;

        }

        string s;
        cin>>s;


        

        vector<pair<int,int>> count(n+1,{0,0}); // To cunt the number of black and white nodes
        queue<int> q; // For topological sorting(From leaf to root)

        for(int i=1;i<=n;i++)
        {
            if(child_count[i] == 0)
            {
                q.push(i);
            }
        }

        while(q.empty() == false)
        {
            int curr = q.front();
            q.pop();

            if(s[curr-1] ==  'B')
            {
                count[curr].first++;
            } 
            else{
                count[curr].second++;
            }

            if(curr == 1)
            {
                continue;
            }

            int parent = a[curr];

            count[parent].first += count[curr].first;
            count[parent].second += count[curr].second;

            child_count[parent]--;

            if(child_count[parent] == 0)
            {
                q.push(parent);
            }


        }

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(count[i].first == count[i].second)
            {
                ans++;
            }
        }

        // cout<<"Testing"<<endl;
        // cout<<count[1].first<<" "<<count[1].second<<endl;

        cout<<ans<<endl;
    }


        
}