
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

        stack<int> st1;
        stack<int> st2;

        st1.push(INT_MAX);
        st2.push(INT_MAX);

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            int ele = a[i];
            int ele1 = st1.top();
            int ele2 = st2.top();

            if(ele1 <= ele2)
            {
                if(ele > ele2)
                {
                    st1.push(ele);
                    ans++;
                }
                else
                {
                    if(ele <= ele1)
                    {
                        st1.push(ele);
                    }
                    else
                    {
                        st2.push(ele);
        
                    }
                }

            }
            else
            {
                if(ele > ele1)
                {
                    st2.push(ele);
                    ans++;
                }
                else
                {
                    if(ele <= ele2)
                    {
                        st2.push(ele);
                    }
                    else
                    {
                        st1.push(ele);
                    }
                }
                
            }
        }

        cout<<ans<<endl;

    }
}

