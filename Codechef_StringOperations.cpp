#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int n = s.size();
        set<tuple<int,int,int>> eq;
        for(int i = 0;i<n;i++)
        {
            int cnt = 0, even = 0, odd = 0;
            for(int j = i;j<n;j++)
            {
                if(s[j] == '1')
                {
                    cnt++;
                }
                else
                {
                    if(cnt%2 == 0)
                    even++;
                    else
                    {
                        odd++;
                    } 
                }
                int len = j - i + 1;
                eq.insert(make_tuple(len, even, odd));
            }
        }
        cout<<eq.size()<<endl;
    }
}