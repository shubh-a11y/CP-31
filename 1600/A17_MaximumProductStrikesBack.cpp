
#include <bits/stdc++.h>
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

        int l = 0;
        int r = -1;

        int maxTwos = 0;

        int twos = 0;
        int negatives = 0;
        int len = 0;

        for(int i=0;i<n;i++)
        {
            if(abs(a[i]) == 2)
            {
                twos++;
            }
            
            if(a[i] < 0)
            {
                negatives++;
            }

            if(a[i] == 0)
            {

                if (twos > maxTwos)
                {
                    if(negatives % 2 == 0)
                    {
                        maxTwos = twos;
                        l = i - len;
                        r = i - 1;
                    }
                    else
                    {
                        int l1 = i-len;
                        int r1 = i-1;
                        int two1 = twos;

                        while(l1 <= r1 && a[l1] > 0)
                        {
                            if(a[l1] == 2)
                            {
                                two1--;
                            }
                            l1++;
                        }

                        if(a[l1] == -1)
                        {
                            l1++;
                        }
                        else if(a[l1] == -2)
                        {
                            two1--;
                            l1++;
                        }

                        int l2 = i-len;
                        int r2 = i-1;
                        int two2 = twos;

                        while(l2 <= r2 && a[r2] > 0)
                        {
                            if(a[r2] == 2)
                            {
                                two2--;
                            }
                            r2--;
                        }

                        if(a[r2] == -1)
                        {
                            r2--;
                        }
                        else if(a[r2] == -2)
                        {
                            two2--;
                            r2--;
                        }

                        if((two1 >= two2) && (two1 > maxTwos))
                        {
                            maxTwos = two1;
                            l = l1;
                            r = i-1;
                        }
                        else if(two2 > maxTwos)
                        {
                            maxTwos = two2;
                            l = i-len;
                            r = r2;
                        }

                    }
                }
                len = 0;
                twos = 0;
                negatives = 0;
            }
            else
            {
                len++;
            }

        }

        if (twos > maxTwos)
        {
            if (negatives % 2 == 0)
            {
                maxTwos = twos;
                l = n - len;
                r = n - 1;
            }
            else
            {
                int l1 = n - len;
                int r1 = n - 1;
                int two1 = twos;

                while (l1 <= r1 && a[l1] > 0)
                {
                    if(a[l1] == 2)
                    {
                        two1--;
                    }
                    l1++;
                }

                if (a[l1] == -1)
                {
                    l1++;
                }
                else if (a[l1] == -2)
                {
                    two1--;
                    l1++;
                }

                int l2 = n - len;
                int r2 = n - 1;
                int two2 = twos;

                while (l2 <= r2 && a[r2] > 0)
                {
                    if(a[r2] == 2)
                    {
                        two2--;
                    }
                    r2--;
                }

                if (a[r2] == -1)
                {
                    r2--;
                }
                else if (a[r2] == -2)
                {
                    two2--;
                    r2--;
                }

                if ((two1 >= two2) && (two1 > maxTwos))
                {
                    maxTwos = two1;
                    l = l1;
                    r = n - 1;
                }
                else if (two2 > maxTwos)
                {
                    maxTwos = two2;
                    l = n - len;
                    r = r2;
                }
            }
        }

        cout<<l<<" "<<n-r-1<<"\n";
    }
}