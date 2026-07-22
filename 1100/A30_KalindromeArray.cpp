
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

        int start = 0;
        int end = n-1;

        bool answered = false;

        while(start < end)
        {
            if(a[start] != a[end])
            {
                int ignore1 = a[start];
                int ignore2 = a[end];

                bool flag1 = true;
                bool flag2 = true;

                int dummy_start = start+1;
                int dummy_end = end;

                while(dummy_start < dummy_end)
                {
                    if(a[dummy_start] != a[dummy_end])
                    {
                        if(a[dummy_start] == ignore1)
                        {
                            dummy_start++;
                        }
                        else if(a[dummy_end] == ignore1)
                        {
                            dummy_end--;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        dummy_start++;
                        dummy_end--;
                    }
                }

                if(dummy_start < dummy_end)
                {
                    flag1 = false;
                }

                dummy_start = start;
                dummy_end = end-1;

                while(dummy_start < dummy_end)
                {
                    if(a[dummy_start] != a[dummy_end])
                    {
                        if(a[dummy_start] == ignore2)
                        {
                            dummy_start++;
                        }
                        else if(a[dummy_end] == ignore2)
                        {
                            dummy_end--;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        dummy_start++;
                        dummy_end--;
                    }
                }

                if(dummy_start < dummy_end)
                {
                    flag2 = false;
                }

                if(flag1 || flag2)
                {
                    cout<<"YES"<<endl;
                    answered = true;
                    break;
                }
                else
                {
                    cout<<"NO"<<endl;
                    answered = true;
                    break;
                }


            }
            else{
                start++;
                end--;
            }
        }

        if(!answered)
        {
            cout<<"YES"<<endl;
        }
    }
}