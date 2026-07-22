
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

        vector<int> arr(n);
    
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        int res = 0;

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1] == 0)
            {
                res = -1;
                break;
            }

            while(arr[i] >= arr[i+1])
            {
                arr[i] = arr[i]/2;
                res++;
            }
        }

        cout<<res<<endl;

    }
}