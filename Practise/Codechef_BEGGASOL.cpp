#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        int f_i[N];
        for(int j=0;j<N;j++)
        cin>>f_i[j];
        int csum[N];
        int stoppingIndex = -1;
        for(int j=0;j<N;j++)
        {
            if(j<1)
            {
                csum[j]=f_i[j];
                if(csum[j] <= j)
                {
                    stoppingIndex = j;
                    break;
                }
            }
            else
            {
                csum[j]=csum[j-1]+f_i[j];
                if(csum[j] <= j)
                {
                    stoppingIndex = j;
                    break;
                }
            }
        }
        if(stoppingIndex == -1)//No breakage there 
        cout<<csum[N-1]<<endl;//Print last element cumulative csum
        else
        {
            cout<<stoppingIndex<<endl;
        }
    }
    return 0;
}