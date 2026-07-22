
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k,a,b;
        cin>>n>>k>>a>>b;

        long long mini_cost_a_major = LLONG_MAX;
        long long mini_cost_b_major = LLONG_MAX;
        vector<pair<long long,long long>> points(n);

        for(int i=0;i<n;i++)
        {
            long long x1,y1;
            cin>>x1>>y1;
            points[i] = {x1, y1};
        }

        long long a_x = points[a-1].first;
        long long a_y = points[a-1].second;
        long long b_x = points[b-1].first;
        long long b_y = points[b-1].second;

        long long ans = abs(b_y-a_y) + abs(b_x-a_x);

        if(k == 0)
        {
            cout<<ans<<endl;
            continue;
        }

        for(int i=0;i<k;i++)
        {
            mini_cost_a_major = min(mini_cost_a_major, abs(points[i].first - a_x) + abs(points[i].second - a_y));
            mini_cost_b_major = min(mini_cost_b_major, abs(points[i].first - b_x) + abs(points[i].second - b_y));
        }



        ans = min(ans, mini_cost_a_major + mini_cost_b_major);

        cout<<ans<<endl;

    }
}