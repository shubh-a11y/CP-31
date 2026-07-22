
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,x,y;
        cin>>n>>x>>y;

        long long gcd_xy = __gcd(x,y);
        long long lcm_xy = ((x/gcd_xy) * y);
        
        long long common = n / lcm_xy;
        long long only_x = (n / x) - common;
        long long only_y = (n / y) - common;

        long long SumOnlyX = (n * (n + 1)) / 2 - ((n - only_x) * (n - only_x + 1)) / 2;
        long long SumOnlyY = (only_y * (only_y + 1)) / 2;

        cout<<(SumOnlyX - SumOnlyY)<<endl;




    }
}