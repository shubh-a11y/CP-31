
#include<bits/stdc++.h>
using namespace std;

double res;

bool valid(double mid,vector<long long> a,vector<long long> t)
{
    long long n = a.size();

    double l = double(INT_MIN); 
    double r = double(INT_MAX);

    for(int i=0;i<n;i++)
    {
        double time = mid - t[i];
        if(time < 0)
        {
            return false;
        }

        l = max(l,double((double)a[i] - time));
        r = min(r,double((double)a[i] + time));

        if(l > r)
        {
            return false;
        }
    }

    res = l;
    return true;

}


int main()
{

    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        long long mini_x = LLONG_MAX;
        long long max_x = LLONG_MIN;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mini_x = min(mini_x,a[i]);
            max_x = max(max_x,a[i]);
        }

        vector<long long> t2(n);
        long long max_t = LLONG_MIN;

        for(int i=0;i<n;i++)
        {
            cin>>t2[i];
            max_t = max(max_t,t2[i]);
        }

        double r = 2e9;;
        double l = 0;

        while(r-l > 1e-7)
        {
            double mid = l + (r-l)/2.0;

            if(valid(mid,a,t2))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        cout<<fixed<<setprecision(10)<<res<<"\n";   
        
    }
}
