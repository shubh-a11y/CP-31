
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int negatives = 0;
        long long sum = 0;
        long long mini = LLONG_MAX;

        for(int i=0;i<n;i++)
        {
            if(a[i] < 0)
            {
                negatives++;
            }
            sum += abs(a[i]);
            mini = min(mini,abs(a[i]));
        }

        if(negatives%2 == 0)
        {
            cout<<sum<<endl;
        }
        else{
            cout<<sum - 2*mini<<endl;   
        }
    }

}