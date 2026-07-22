
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

        vector<int> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        vector<int> min_left(n);
        vector<int> min_right(n);

        min_left[0] = 0;
        int min_so_far = v[0];

        for(int i=1;i<n;i++)
        {
            if(v[i] < min_so_far)
            {
                min_so_far = v[i];
                min_left[i] = i;
            }
            else
            {
                min_left[i] = min_left[i-1];
            }
        }

        min_right[n-1] = n-1;
        min_so_far = v[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(v[i] < min_so_far)
            {
                min_so_far = v[i];
                min_right[i] = i;
            }
            else
            {
                min_right[i] = min_right[i+1];
            }
        }

        bool flag = true;
        for(int i=1;i<n-1;i++)
        {
            if(v[i] > v[min_left[i]] && v[i] > v[min_right[i]])
            {
                cout<<"YES"<<endl;
                cout<<min_left[i]+1<<" "<<i+1<<" "<<min_right[i]+1<<endl;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"NO"<<endl;
        }

            
        

    }
}