
#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> ans;

        if(isPrime(n))
        {
            cout<<"NO"<<endl;
            continue;
        }

        int dummy_n = n;
    
            for (int i = 2; i*i <= dummy_n; i++)
            {
                if (i > dummy_n)
                {
                    break;
                }

                if (dummy_n % i == 0)
                {
                    ans.push_back(i);
                    dummy_n = dummy_n/i;
                    if (ans.size() == 2)
                    {
                        break;
                    }
                }
            }
          
            
        

       if(ans.size() < 2 || dummy_n == ans[0] || dummy_n == ans[1] || dummy_n == 1)
       {
           cout<<"NO"<<endl;
       }
       else{
           cout<<"YES"<<endl;
           cout<<ans[0]<<" "<<ans[1]<<" "<<dummy_n<<endl;
       }
    }
}
