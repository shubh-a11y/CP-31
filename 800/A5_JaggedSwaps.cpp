
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

        if(v[0] > v[1])
        {
            cout<<"NO"<<endl;
            continue;
        }


        if(is_sorted(v.begin(),v.end()))
        {
            cout<<"YES"<<endl;
            continue;
        }


        bool swapped = true;

        while(swapped)
        {
            swapped = false;
            for(int i=1;i<n-1;i++)
            {
                if((v[i-1] < v[i]) && (v[i] > v[i+1]))
                {
                    swap(v[i],v[i+1]);
                    swapped = true;
                }
            }
        }

        if(is_sorted(v.begin(),v.end()))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

        
    }
}