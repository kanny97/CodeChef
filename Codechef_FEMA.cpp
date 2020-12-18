#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        string S;
        cin>>S;//The string to be considered
        string new_S="";
        //For each sheet add an extra position of sheet to reduce attraction by one
        for(int i = 0;i<N;i++)
        {
            if(S[i]==':')
            {
                new_S+=S[i];
            }
            new_S+=S[i];
        }
        queue<int> q_m;
        queue<int> q_i;
        int ans = 0;
        for(int i =0;i<new_S.size();i++)
        {
            //If an iron element is encountered
           if(new_S[i] == 'I')
           {
               while(!q_m.empty() && K + 1 <= i - q_m.front())//While there is an unmatched magnet at this index
               {
                   q_m.pop();
               }
               if(!q_m.empty())//If there is a magnet with attraction for this iron
               {
                   ans++;
                   q_m.pop();//Remove this magnet because its matched
               }
               else
               {
                   q_i.push(i);
               }   
           }
           else if(new_S[i] == 'M')
           {
               while(!q_i.empty() && K + 1 <= i - q_i.front())//While there is an unmatched magnet at this index
               {
                   q_i.pop();
               }
               if(!q_i.empty())//If there is an iron with attraction for this magnet
               {
                   ans++;
                   q_i.pop();//Remove this iron because its matched
               }
               else
               {
                   q_m.push(i);
               }   
           }
           else if(new_S[i] == 'X')
           {
               //If this is blocked remove all indices by now
               while(!q_i.empty())
               {
                   q_i.pop();
               }
               while(!q_m.empty())
               {
                   q_m.pop();
               }
           } 
        }
        cout<<ans<<endl;
    }
    return 0;
}