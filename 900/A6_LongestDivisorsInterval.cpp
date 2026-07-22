
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

        long long res = 1;

        while(n%res == 0)
        {
            res++;
        }

        cout<<res-1<<endl;
    }
}