#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,X;
        cin>>N>>X;
        vector<long long int> arr(N);
        for(long long int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        long long int i = 0;//Initial choice of i
        while(i<N-1)
        {
            while(arr[i]!=0)//A single selection step
            {
                int p = (int)(log2(arr[i]));
                long long int num = (long long int)(pow(2,p));
                arr[i] = arr[i] ^ num;
                long long int j = i+1;
                while(j<N)
                {
                    if((arr[j] ^ num) < arr[j])
                    break;
                    j++;
                }

                //Take last element if none of the values reduces with this selection
                if(j == N)
                j = N-1;

                arr[j] = arr[j] ^ num;
                X -= 1;
                if(X==0)
                break;
            }
            if(X == 0)
            break;
            i++;
        }
        
        if(N <= 2)
        {
            //We have achieved best sequence by now by Greedy approach
            //2 Cases remn steps even or odd
            if(X % 2 != 0 && X > 0)
            {
                arr[N-2] = arr[N-2] ^ 1;
                arr[N-1] = arr[N-1] ^ 1;
            }    
        }
        
        for(long long int i=0;i<N;i++)
        {
            if(i!=N-1)
            cout<<arr[i]<<" ";
            else
            {
                cout<<arr[i];
            }
        }
        cout<<endl;
    } 
}