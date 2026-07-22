
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {

    long long n,x,y;
    cin>>n>>x>>y;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // EVEN = 0, ODD = 1;
    if(y%2 == 0)
    {
        y = 0;
    }
    else{
        y = 1;
    }

    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2 != 0)
        {
            curr = 1 - curr;
        }
    }

    if((curr^y) == 0) // Both curr and y are even or both are odd
    {
        // Even wins;
        if(x%2 == 0)
        {
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    else{
        // Odd wins
        if(x%2 == 1)
        {
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }

}


}

