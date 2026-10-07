
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;

        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        } 

        int count = 0;
        bool flag = true;

        sort(a.begin(),a.end());

        if(n%2 == 0)
        {
            for(int i=1;i<n;i+=2)
            {
                if(a[i]-a[i-1] > d)
                {
                    flag = false;
                    break;
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
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;)
                {
                    if((j == i))
                    {
                        j++;
                        continue;

                    }
                    else if(i == j+1)
                    {
                        if(i < n-1 && abs(a[i+1]-a[i-1]) > d)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            j = i+2;
                        }
                    }
                    else
                    {
                        if(abs(a[j]-a[j+1]) > d)
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            j+=2;
                        }
                    }
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
}