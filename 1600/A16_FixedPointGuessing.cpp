
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

        int l = 1;
        int r = n;

        while(l < r)
        {
            if( l == r)
            {
                break;
            }
            int mid = l + (r-l)/2;
            
            cout<<"? "<<l<<" "<<mid<<endl;
            int len = mid-l+1;
            int cnt = 0;

            for(int i=0;i<len;i++)
            {
                int x;
                cin>>x;

                if((x >= l) && (x <= mid))
                {
                    cnt++;
                }
            }

            if(cnt%2 == 0)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }

        cout<<"! "<<l<<endl;

    }
}