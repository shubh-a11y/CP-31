
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<vector<long long>> a(n,vector<long long>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        if(n == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }   

        vector<vector<long long>> a_180_rotated(n,vector<long long>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a_180_rotated[i][j] = a[n-1-i][n-1-j];
            }
        }

        long long changes = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j] != a_180_rotated[i][j])
                {
                    changes++;
                }
            }
        }

        changes /= 2; 



        if(changes > k)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(n%2 == 1) // if n is odd, then these is a center element which can be changed without affecting the symmetry, so we can always achieve the pattern if changes <= k
            {
                cout<<"YES"<<endl;
                continue;
            }   
            else
            { 
                if((k-changes)%2 == 0)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}