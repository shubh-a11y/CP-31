
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
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int> a1(n);
        for(int i=0;i<n;i++)
        {
            cin>>a1[i];
        }

        int left = 0;
        int right = n-1;

        for(int i=0;i<n;i++)
        {
            if(a[i] != a1[i])
            {
                left = i;
                break;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(a[i] != a1[i])
            {
                right = i;
                break;
            }
        }

        while(left > 0 && a1[left] >= a1[left-1])
        {
            left--;
        }

        while(right < n-1 && a1[right] <= a1[right+1])
        {
            right++;
        }

        cout<<left+1<<" "<<right+1<<endl;


    }
}
