
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int l = 1;
        int r = 1000;

        int ans = 0;

        while(l < r)
        {
            int mid1 = l + (r-l)/3;
            int mid2 = r - (r-l)/3;

            int area;
            cout<<"? "<<mid1<<" "<<mid2<<endl;
            cin>>area;

            if(area == mid1*mid2)
            {
                l = mid2+1;
            }
            else if(area == mid1*(mid2+1))
            {
                r = mid2;
                l = mid1+1;
            }
            else if(area == ((mid1+1)*(mid2+1)))
            {
                // if(mid1 == mid2)
                // {
                //     ans = mid1;
                // }

                r = mid1;
            }

        }

        if(ans == 0)
        {
            ans = l;
        }
        cout<<"! "<<ans<<endl;
    }
}