#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main() {
   int M;
   cin>>M;
   char com;
   list<int>  platform[100001];
   for(int k=0;k<M;k++){
        cin>>com;
        switch (com)
        {
        case 'N':
            int x,idx;
            cin>>x>>idx;
            platform[idx].push_back(x);
            break;
        case 'M':
            int i,j;
            cin>>i>>j;
            if(i==j) break;
            platform[j].splice(platform[j].end(),platform[i]);
            platform[i].clear();
            break;
        default:
            break;
        }
   }
   for (int i = 0; i < 100001; i++)
   {
        if(platform[i].empty())
            continue;
        list<int>::iterator it;
        for(it = platform[i].begin();it != platform[i].end();it++)
            cout<<*it<<"\n";        
   }
   
}