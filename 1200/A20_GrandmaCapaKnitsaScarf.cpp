
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
        string s;
        cin>>s;

        int start = 0;
        int end = n-1;

        int ans = 0;
        int ans1 = 1;
        int ans2 = 1;
        char chosen = '0';

        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;

        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else{
                flag3 = false;

                chosen = s[start];
                ans1 = 1;
                int start2 = start;
                int end2 = end;
                start2++;
                while(start2<end2)
                {
                    if(s[start2] == s[end2])
                    {
                        start2++;
                        end2--;
                    }
                    else if(s[start2] == chosen)
                    {
                        start2++;
                        ans1++;
                    }
                    else if(s[end2] == chosen)
                    {
                        end2--;
                        ans1++;
                    }
                    else{
                        flag1 = false;
                        break;
                    }
                }

                

                ans2 = 1;
                chosen = s[end];
                int start3 = start;
                int end3 = end-1;
                while(start3 < end3)
                {
                    if(s[start3] == s[end3])
                    {
                        start3++;
                        end3--;
                    }
                    else if(s[start3] == chosen)
                    {
                        start3++;
                        ans2++;
                    }
                    else if(s[end3] == chosen)
                    {
                        end3--;
                        ans2++;
                    }
                    else{
                        flag2 = false;
                        break;
                    }
                }

                break;

                

            }
        }

        if(flag3)
        {
            cout<<0<<endl;
        }
        else if(flag1 && flag2)
        {
            cout<<min(ans1,ans2)<<endl;
        }
        else if(flag1)
        {
            cout<<ans1<<endl;
        }
        else if(flag2)
        {
            cout<<ans2<<endl;
        }
        else{
            cout<<-1<<endl;
        }


    }
}