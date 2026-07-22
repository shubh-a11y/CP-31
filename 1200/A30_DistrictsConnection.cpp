
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

    long long val1 = 0;
    long long val2 = 0;

    vector<pair<long long,long long>> v;
    for(int i=1;i<n;i++)
    {
        if(a[i] != a[val1])
        {
            v.push_back({val1,i});
            val2 = i;
        }
    }

    if(val2 == 0)
    {
        cout<<"NO"<<endl;
        continue;
    }
    else{
        for(int i=1;i<n;i++)
        {
            if(a[i] == a[val1])
            {
                v.push_back({val2,i});
            }
        }
    }

    cout<<"YES"<<endl;
    for(auto it: v)
    {
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }

}
}