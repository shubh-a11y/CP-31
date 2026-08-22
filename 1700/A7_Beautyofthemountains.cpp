
// Good Use of Bézout's Identity

// By Bézout’s Identity, an integer linear combination sigma(ai * xi) can produce an integer value D if and only if D is a multiple of the 
// Greatest Common Divisor (GCD) of all available ai values.

// n Bézout's Identity, there is a fundamental difference between the fixed building blocks and the variables you choose.
// In the linear equation:$$c_1 \Delta_1 + c_2 \Delta_2 + \dots + c_m \Delta_m = D$$$\Delta_i$ are the Fixed Constants: 
// These values are determined entirely by the grid. Each $k \times k$ submatrix has a fixed number of zeros and ones, meaning $\Delta_1, 
// \Delta_2, \dots, \Delta_m$ are rigid numbers given to you by the problem.$c_i$ are the Free Variables: You are allowed to choose any 
// integers for $c_1, c_2, \dots, c_m$ (positive, negative, or zero).


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,m,k;
        cin>>n>>m>>k;

        vector<vector<long long>> a(n+1,vector<long long>(m+1));

        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                
            }
        }

        vector<vector<long long>> prefix(n+1,vector<long long>(m+1));

        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                prefix[i][j+1] = s[j]-'0';

                if(prefix[i][j+1] == 1)
                {
                    sum1 += a[i][j+1];
                }
                else
                {
                    sum2 += a[i][j+1];
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                prefix[i][j] += prefix[i][j-1];
            }
        }

        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                prefix[i][j] += prefix[i-1][j];
            }
        }

        long long g = 0;
        long long diff = abs(sum1-sum2);

        if(diff == 0)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(int i=k;i<=n;i++)
        {
            for(int j=k;j<=m;j++)
            {
                long long ones = prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k];
                int zeros = k*k - ones;
                 
                g = __gcd(g,abs(ones-zeros));

            }
        }

        if(g != 0 && diff%g == 0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

        


    }
}


