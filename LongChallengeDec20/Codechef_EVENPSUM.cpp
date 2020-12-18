#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int A, B;
        cin>>A>>B;
        int even_A, odd_A, even_B, odd_B;
        if(A%2 == 0)
        {
            even_A = A/2;
            odd_A = A/2;
        }
        else
        {
            even_A = A/2;
            odd_A = A - even_A;
        }
        if(B%2 == 0)
        {
            even_B = B/2;
            odd_B = B/2;
        }
        else
        {
            even_B = B/2;
            odd_B = B - even_B;
        }
        int result = even_A * even_B + odd_A * odd_B;
        cout<<result<<endl;
    }
}