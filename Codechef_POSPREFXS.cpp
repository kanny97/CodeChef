#include <bits/stdc++.h>
using namespace std;

/*
Logic of the problem Create array such as -1,2,-3,4,-5,6 and so on initially 
In the above array there are exactly k prefixes with sum > 0 upto i = (2*k) If N >= 2*k we can attribute -ve to all other indices beyond this point
If K > N / 2, then from the end move backwards to multiply -1 with alternate elements  
*/

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N, K;
        cin>>N>>K;
        vector<int> arr(N+1);
        arr[0]=0;//Dummy element
        for(int i = 1;i<=N;i++)
        {
            if(i%2 == 0)
            arr[i] = i;
            else
            arr[i] = -i;
        }
        //Arr with every even element +ve
        if(N >= (2*K))
        {
            for(int i = 2*K + 1;i<=N;i++)
            {
                arr[i] = -i;
            }
        }
        else
        {
            //Every alternate element from back multiply by -1
            int iterations = K - (N/2);
            int idx = (N%2 == 0?N-1:N);//Last -ve element of the array
            while(iterations--)
            {
                arr[idx]*=-1;
                idx-=2;
                if(idx<1)
                break;
            }
        }
        for(int i = 1;i<=N;i++)
        {
            if(i < N)
            cout<<arr[i]<<" ";
            else//i == N
            cout<<arr[i];
        }
        if(i!=T-1)//Not the last test case
        cout<<endl;
    }
}