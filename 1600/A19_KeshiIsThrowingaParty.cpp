
#include<bits/stdc++.h>
using namespace std;


bool check(int mid,vector<int> &a,vector<int> &b)
{
    int c = 1;
    int n = a.size();

    for(int i=0;i<n;i++)
    {
        if((b[i] >= c-1) && (a[i] >= mid-c))
        {
            c++;
        }

        if(c > mid)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }

        int low = 0;
        int high = n;

        int res = 1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(check(mid,a,b))
            {
                res = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        cout<<res<<endl;
    }
}