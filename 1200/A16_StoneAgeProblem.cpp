
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    long long sum = 0;
    vector<vector<long long>> a;
    for(int i=0;i<n;i++)    {
        int val;
        cin>>val;
        a.push_back({val,0}); // Value, Timestamp
        sum += val;
    }

    int globalTime = 0;
    int globalUpdateTime = -1;
    int globalUpdateValue = 0;

    
    while(q--)
    {
        globalTime++;
        int t;
        cin>>t;
        if(t == 1)
        {
            int idx,val;
            cin>>idx>>val;
            idx--;
            int timestamp = a[idx][1];
            if(timestamp > globalUpdateTime)
            {
                sum = sum - a[idx][0] + val;
            }
            else{
                sum = sum - globalUpdateValue + val;
            }
            a[idx][0] = val;
            a[idx][1] = globalTime;
            cout<<sum<<endl;
        }
        else{
            long long val;
            cin>>val;
            sum = val*n;
            cout<<sum<<endl;
            globalUpdateTime = globalTime;
            globalUpdateValue = val;
        }
    }

}