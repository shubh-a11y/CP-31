
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    long long fact = 2;
    vector<long long> factorials;

    for(int i=3;i<=14;i++) // 12 factorials as 15! is greater than 1e12
    {
        fact = fact*i;
        factorials.push_back(fact);
    }

    while(t--)
    {
        long long n;
        cin>>n;

        long long factorialSum = 0;
        long long ans = LLONG_MAX;
        // Now as any number can be represented as sum of powers of two,
        // and number of powers of two is equal to number of 1's in it's binary representation,

        // Therefore now to consider which factorials to include out of these 12
        // we create all possible masks of size 12 where 1 implies that we include that factorial and 0 implies that we don't include that factorial

        // Now for 12 factorials we have 2^12 masks which is 4096 which is very less and we can easily iterate over all these masks and calculate the sum of factorials for each mask and add it to the factorialSum
        for(int i=0;i<4096;i++)
        {
            long long sum = 0;
            for(int j=0;j<12;j++)
            {
                if(i & (1<<j))
                {
                    sum += factorials[j];

                    if(sum > n)
                    {
                        break;
                    }
                }
            }

            if(sum > n)
            {
                continue;
            }
            else
            {
                long long remaining = n-sum;
                long long count = __builtin_popcountll(i); // number of 1's in the binary representation of i which is the number of factorials we have included
                count += __builtin_popcountll(remaining); // number of 1's in the binary representation of remaining which is the number of powers of two we need to include to make the sum equal to n

                ans = min(ans,count);
            }

        }

        cout<<ans<<endl;
    }
}