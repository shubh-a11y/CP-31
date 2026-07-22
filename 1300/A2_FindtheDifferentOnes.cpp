
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
        vector<long long> a(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> lastChanged(n);
        lastChanged[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] == a[i+1])
            {
                lastChanged[i] = lastChanged[i+1];
            } 
            else{
                lastChanged[i] = i;
            }
        }

        long long q;
        cin>>q;
        while(q--)
        {
            long long l,r;
            cin>>l>>r;

            if(lastChanged[l-1] >= r-1)
            {
                cout<<-1<<" "<<-1<<endl;
            }
            else{
                cout<<lastChanged[l-1]+1<<" "<<lastChanged[l-1]+2<<endl;
            }
        }
        cout<<endl;

    }
}