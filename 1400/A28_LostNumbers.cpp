#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a(6);

    vector<int> nums = {4, 8, 15, 16, 23, 42};
    vector<bool> used(6, false);
    
    cout<<"? 1 2"<<endl;
    int x1;
    cin>>x1;
    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++)
        {
            if(nums[i]*nums[j] == x1)
            {
                a[0] = nums[i];
                a[1] = nums[j];
                used[i] = used[j] = true;
                break;
            }
        }
    }

    cout << "? 2 3" << endl;
    int x2;
    cin >> x2;
    if ((x2 % a[0] == 0) && (find(nums.begin(), nums.end(), x2 / a[0]) != nums.end()) && (x2 / a[0] != a[0]))
    {
        swap(a[0], a[1]);
    }

    x2 /= a[1];
    
    for(int i=0; i<6; i++)
    {
        if(used[i]) continue;
        if(nums[i] == x2)
        {
            a[2] = nums[i];
            used[i] = true;
            break;
        }
    }

    cout<<"? 3 4"<<endl;
    int x3;
    cin>>x3;
    x3 = x3/ a[2];
    for(int i=0; i<6; i++)
    {
        if(used[i]) continue;
        if(nums[i] == x3)
        {
            a[3] = nums[i];
            used[i] = true;
            break;
        }
    }

    cout<<"? 4 5"<<endl;
    int x4;
    cin>>x4;
    x4 = x4/ a[3];
    for(int i=0; i<6; i++)
    {
        if(used[i]) continue;
        if(nums[i] == x4)
        {
            a[4] = nums[i];
            used[i] = true;
            break;
        }
    }

    for(int i=0;i<6;i++)
    {
        if(used[i]) continue;
        a[5] = nums[i];
        break;
    }

    cout<<"! ";
    for(int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    
    


}