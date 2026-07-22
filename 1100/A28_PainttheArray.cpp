
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
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> even;
        vector<long long> odd;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                even.push_back(a[i]);
            }
            else
            {
                odd.push_back(a[i]);
            }
        }

        long long even_gcd = 0;
        for(int i=0;i<even.size();i++)
        {
            even_gcd = __gcd(even_gcd, even[i]);
        }
        long long odd_gcd = 0;
        for(int i=0;i<odd.size();i++)
        {
            odd_gcd = __gcd(odd_gcd, odd[i]);
        }

        if((even_gcd == 1)  && (odd_gcd == 1))
        {
            cout<<0<<endl;
        }
        else
        {
            bool flag1 = true;
            for(int i=0;i<even.size();i++)
            {
                if(even[i]%odd_gcd == 0)
                {
                    flag1 = false;
                    break;
                }
            }

            bool flag2 = true;
            for(int i=0;i<odd.size();i++)
            {
                if(odd[i]%even_gcd == 0)
                {
                    flag2 = false;
                    break;
                }
            }

            if(flag1 && flag2)
            {
                cout<<min(even_gcd, odd_gcd)<<endl;
            }
            else if(flag1)
            {
                cout<<odd_gcd<<endl;
            }
            else if(flag2)
            {
                cout<<even_gcd<<endl;
            }
            else
            {
                cout<<0<<endl;
            }

        }


    }
}