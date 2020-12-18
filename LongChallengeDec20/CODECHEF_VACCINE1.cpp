#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D1,V1,D2,V2,P;
    cin>>D1>>V1>>D2>>V2>>P;
    int currentDay = min(D1,D2);
    while(true)
    {
        if(D1 <= currentDay)//Vaccine 1 production started
        P-=V1;
        if(D2 <= currentDay)
        P-=V2;
        if(P<=0)
        break;
    }
    cout<<currentDay;
}