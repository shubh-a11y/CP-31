
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

        long long x;
        cin>>x;

        vector<long long> v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }

        long long mini = 0;
        long long maxi = 0;
        long long sum = 0;


        for(int i=0;i<n;i++)
        {
            sum += v[i];
            
            if(v[i] % x == 0)
            {
                maxi += v[i]/x;
            }
            else{
                maxi += v[i]/x + 1;
            }
        }

        if(sum % x == 0)
        {
            mini = sum/x;
        }
        else
        {
            mini = sum/x + 1;
        }

        cout<<mini<<" "<<maxi<<endl;
    }
}