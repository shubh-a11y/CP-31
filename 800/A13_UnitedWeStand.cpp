
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

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        vector<int> b;
        vector<int> c;

        sort(v.begin(),v.end());

        for(int i=n-1;i>=0;i--)
        {
            c.push_back(v[i]);
            
            if((i != 0) && (v[i] != v[i-1]))
            {
                v.pop_back();
                break;
            }
            v.pop_back();
        }

        if(c.size() == n)
        {
            cout<<-1<<endl;
        }
        else
        {
            b = v;
            cout<<b.size()<<" "<<c.size()<<endl;
            for(int i=0;i<b.size();i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<c.size();i++)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;
        }

    }


}