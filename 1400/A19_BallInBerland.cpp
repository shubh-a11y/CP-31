
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long A,B,k;
        cin>>A>>B>>k;

        vector<long long> a(k), b(k);
        for(int i=0;i<k;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<k;i++)
        {
            cin>>b[i];
        }

        long long total = k*(k-1)/2;

        vector<long long> countA(A+1,0), countB(B+1,0);

        for(int i=0;i<k;i++)
        {
            countA[a[i]]++;
            countB[b[i]]++;
        }

        long long pairs = 0;
        for(int i=1;i<=A;i++)
        {
            if(countA[i] > 1)
            {
                pairs += (countA[i]*(countA[i]-1))/2;
            }
        }

        for(int i=1;i<=B;i++)
        {
            if(countB[i] > 1)
            {
                pairs += (countB[i]*(countB[i]-1))/2;
            }
        }

        cout<<total-pairs<<endl;


    }
}