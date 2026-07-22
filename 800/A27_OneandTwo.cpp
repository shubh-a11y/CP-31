
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

        int count2 = 0;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];

            if(v[i] == 2)
            {
                count2++;
            }
        }

        if(count2%2 != 0)
        {
            cout<<-1<<endl;
        }
        else{
            int curr = 0;
            for(int i=0;i<n;i++)
            {
                if(v[i] == 2)
                {
                    curr++;
                }
                if(curr == count2/2)
                {
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }
}

