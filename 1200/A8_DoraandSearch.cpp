
#include <bits/stdc++.h>
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
        set<long long> s;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
        }

        int l = 0;
        int r = n-1;
        bool found = false;

        while(l<r)
        {
            if((a[l] == *s.begin()) || (a[l] == *s.rbegin()))
            {
                s.erase(a[l]);
                l++;
            }
            else if(a[r] == *s.begin() || a[r] == *s.rbegin())
            {
                s.erase(a[r]);
                r--;
            }
            else
            {
                found = true;
                break;
            }
        }

        if(found)
        {
            cout<<l+1<<" "<<r+1<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }

    }

}