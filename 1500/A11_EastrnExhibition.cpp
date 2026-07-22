
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<long long> xs(n);
        vector<long long> ys(n);

        for(int i=0;i<n;i++)
        {
            cin>>xs[i]>>ys[i];
        }

        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());

        if(n%2 == 1)
        {
            cout<<1<<endl;
        }
        else
        {
            long long x_diff = xs[n/2] - xs[(n/2)-1] + 1;
            long long y_diff = ys[n/2] - ys[(n/2)-1] + 1;
            cout<<x_diff*y_diff<<endl;
        }
    }
}