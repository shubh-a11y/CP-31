
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
        unordered_map<long long, long long> freq;
        vector<vector<long long>> a(n);
        long long idx = 0;
        for(int m=0;m<n;m++)
        {
            long long num;
            cin>>num;
            for(int i=0;i<num;i++)
            {
                long long x;
                cin>>x;
                a[idx].push_back(x);
                freq[x]++;
            } 
            idx++;
        }

        bool flag = true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(freq[a[i][j]] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout<<"YES"<<endl;
                break;
            }
            else
            {
                if(i != n-1)
                {
                    flag = true;
                }
            }
        }

        if(flag)
        {
            continue;
        }
        else{
            cout<<"NO"<<endl;
        }



    }
}