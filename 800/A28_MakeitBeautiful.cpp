
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

        int maxi = 0;
        int secondMaxi = 0;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];

            if(v[i] > maxi)
            {
                secondMaxi = maxi;
                maxi = v[i];
            }
            else if((v[i] > secondMaxi) && (v[i] < maxi))
            {
                secondMaxi = v[i];
            }
        }

        if(secondMaxi == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else{
            sort(v.begin(),v.end());

            vector<int> res(n,0);

            for(int i=0;i<n;i++)
            {
                res[i] = v[n-i-1];

                if(res[i] == secondMaxi)
                {
                    swap(res[i],res[1]);
                }
            }

            cout<<"YES"<<endl;

            for(int i=0;i<n;i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
                
        }
    }
}