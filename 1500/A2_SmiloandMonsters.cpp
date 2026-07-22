
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

        sort(a.begin(),a.end());
        long long counter = 0;
        long long attacks = 0;

        long long left = 0;
        long long right = n-1;

        while(left < right)
        {
            long long needed = a[right] - counter;

            if(needed >= a[left])
            {
                counter += a[left];
                attacks += a[left];
                left++;
            }
            else
            {
                a[left] -= needed;
                attacks += needed;
                attacks++;
                right--;
                counter = 0;
            }
        }

        if(a[left] == 0)
        {
            cout<<attacks<<endl;
        }
        else if(counter == a[left])
        {
            attacks ++;
            cout<<attacks<<endl;
        }
        else if(counter < a[left])
        {
            long long R = a[left];
            long long C = counter;

            long long diff = R - C;

            if(R == 1)
            {
                attacks++;
                cout<<attacks<<endl;
            }
            else if(diff%2 == 0)
            {
                attacks += (diff/2)+1;
                cout<<attacks<<endl;
            }
            else if(diff%2 == 1)
            {
                attacks += (diff/2)+2;
                cout<<attacks<<endl;
            }

        }


    }
}