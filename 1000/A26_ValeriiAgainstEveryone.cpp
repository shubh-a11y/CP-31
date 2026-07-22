
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
        vector<int> a(n);
        unordered_map<int,int> freq;
        bool flag = false;
        for(int i=0;i<n;i++)        {
            cin>>a[i];
            freq[a[i]]++;
            if(freq[a[i]] > 1)
            {
                freq[a[i]] = 2;
                flag = true;
            }
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }
}