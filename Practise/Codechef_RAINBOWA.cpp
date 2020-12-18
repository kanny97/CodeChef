#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        int l = 0,r = N-1;
        bool isRainbow = false;
        int num = 1;//Base value of the 
        
        while(A[l]==A[r] && A[l] == num && l < r)
        {
            l++;
            r--;
            if(A[l] == A[l-1] + 1)//Increment of value by 1 but still value between 1 to 7
            num++;
            else if(A[l] == A[l-1])//Same value would be encountered again
            continue;
            else//Needs to increase in steps 
            {
                isRainbow = false;
                break;
            }
            if(num == 7)
            {
                bool only7 = true;
                for(int i = l;i<=r;i++)
                    if(A[i] != 7)
                    {
                       only7 = false; 
                       break;
                    }
                if(only7)
                isRainbow = true;
                break;
            }
        }
        if(isRainbow)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;   
    }
    return 0;
}