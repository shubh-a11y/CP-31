
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int partitions = 0;
        long long sum = 0;

        for(int i=0;i<n;i++)
        {
            if(v[i] == 0)
            {
                if(sum != 0)
                {
                    partitions++;
                    sum = 0;
                }
            }
            else
            {
                sum += v[i];
            }
        }

        if(sum != 0)
        {
            partitions++;
        }

        cout<<min(partitions,2)<<endl;
    }
}