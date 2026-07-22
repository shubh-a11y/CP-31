#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        bool ten_present = false;
        for(int i=0;i<n;i++)
        {
            if((a[i]%10 == 5) || (a[i]%10 == 0))
            {
                ten_present = true;
                a[i] = a[i] + (a[i]%10);
            }
            else{
                while(a[i]%10 != 8)
                {
                    a[i] = a[i] + (a[i]%10);
                }
            }
        }

        if(ten_present)
        {
            bool all_equal = true;
            for(int i=1;i<n;i++)
            {
                if(a[i] != a[0])
                {
                    all_equal = false;
                    break;
                }
            }
            if(all_equal)
            {
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            bool all_mod_equal = true;
            for(int i=1;i<n;i++)
            {
                if((a[i]%20) != (a[0]%20))
                {
                    all_mod_equal = false;
                    break;
                }
            }
            if(all_mod_equal)
            {
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
}