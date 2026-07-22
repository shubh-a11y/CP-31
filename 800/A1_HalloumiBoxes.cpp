#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
    int n;
    int k;
    cin>>n;
    cin>>k;

    vector<int> v(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    bool sorted = true;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            sorted = false;
            break;
        }
    }

    if(sorted)
    {
        cout<<"YES"<<endl;
        continue;
    }

    if(k == 1)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

}
