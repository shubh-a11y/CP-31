
#include <bits/stdc++.h>
using namespace std;

int find(int a, vector<long long>& parent, vector<long long>& size)
{
    if(parent[a] != a)
    {
        parent[a] = find(parent[a], parent, size); // Path compression
    }

    return parent[a];
}

void join(int a, int b, vector<long long>& parent, vector<long long>& size)
{
    int roota = find(a,parent,size);
    int rootb = find(b,parent,size);


    if(roota == rootb)
    {
        return; // They are already in the same set
    }

    if(size[roota] < size[rootb])
    {
        swap(roota,rootb);
    }

    parent[rootb] = roota;
    size[roota] += size[rootb];
}

int main()
{
    long long n,m;
    cin>>n>>m;

    vector<long long> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }

    vector<long long> size(n,1);

    for(int i=0;i<m;i++)
    {
        long long k;
        cin>>k;

        if(k > 0)
        {
            long long first;
            cin>>first;
            first--;

            for(int i=1;i<k;i++)
            {
                long long a;
                cin>>a;

                a--;

                join(first,a,parent,size);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<size[find(i,parent,size)]<<" ";
    }
    cout<<endl;



}