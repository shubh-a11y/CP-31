#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a,long long b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

void build(vector<long long> &tree, vector<long long> &diff, int start, int end, int node)
{
    if(start == end)
    {
        tree[node] = diff[start];
        return;
    }

    int mid = start + (end - start) / 2;

    int left = 2 * node;
    int right = 2 * node + 1;

    build(tree,diff,start,mid,left);
    build(tree,diff,mid+1,end,right);

    tree[node] = GCD(tree[left],tree[right]);
}

long long query(vector<long long> &tree, vector<long long> &diff, int start, int end, int l, int r,int node)
{
    if(l > end || r < start)
    {
        return 0;
    }

    if(start >= l && end <= r)
    {
        return tree[node];
    }

    int mid = start + (end - start) / 2;

    int left = 2 * node;
    int right = 2 * node + 1;

    long long leftGCD = query(tree,diff,start,mid,l,r,left);
    long long rightGCD = query(tree,diff,mid+1,end,l,r,right);

    return GCD(leftGCD,rightGCD);
    
    


}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,q;
        cin>>n>>q;

        

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(n==1)
        {
            for(int i=0;i<q;i++)
            {
                int l,r;
                cin>>l>>r;
                cout<<"0 ";
            }
            cout<<endl;
            continue;
        }

        vector<long long> diff(n,0);

        for(int i=1;i<n;i++)
        {
            diff[i]=abs(a[i-1]-a[i]);
        }

        vector<long long> tree(4*n);

        build(tree,diff,1,n-1,1);

        vector<long long> ans;
        while(q--)
        {
            long long l,r;
            cin>>l>>r;
            ans.push_back(query(tree,diff,1,n-1,l,r-1,1));
        }

        for(long long x : ans)
        {
            cout<<x<<" ";

        }
        cout<<endl;


    }
}
