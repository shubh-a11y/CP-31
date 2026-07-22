
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int> a(m);
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }

        vector<int> proficientIn(n+1,0);
        for(int i=0;i<m;i++)
        {
            proficientIn[a[i]]++;
        }

        long long ans = 2*(m);
        long long high = 2*m;
        long long low = 0;

        while(low <= high)
        {
            long long t = low + (high-low)/2;
            long long tasksCompleted = 0;
            for(int i=1;i<=n;i++)
            {
                tasksCompleted += min(t,proficientIn[i] + (t-proficientIn[i])/2);
            }

            if(tasksCompleted >= m)
            {
                ans = t;
                high = t-1;
            }
            else{
                low = t+1;
            }
        }
        cout<<ans<<endl;

    }
}

