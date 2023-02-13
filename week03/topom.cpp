#include <vector>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;
vector<int> adj[100001];
vector<int> output;
int indeg[100001];
int outdeg[100001];
int topo = 1;

void topo_order(int n)
{
    cout << "a\n";
  list<int> s;


  for(int u=0; u<n; u++)
    if(indeg[u] == 0)
      s.push_back(u);
  
  for(int i=0; i<n; i++) {
    int u = s.front();
    cout << s.size() << "\n";
    s.pop_front();
    output.push_back(u);

    for(int d=0; d < outdeg[u]; d++) {
      int v = adj[u][d];
      if(indeg[v]==0){
        topo = 0;
        return;
      }
      indeg[v]--;
      if(indeg[v] == 0) {
        s.push_back(v);
      } 
    }
  }
}
int main(){
    int n,m;
    cin>>n>>m;
    
    fill(indeg,indeg+n,0);
    fill(outdeg,outdeg+n,0);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--;v--;
        indeg[v]++;
        outdeg[u]++;
        adj[u].push_back(v);
    }
    for (int i=0;i<n;i++) {
        cout << indeg[i] << "\n";
    }
    topo_order(n);
    if(topo){
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<"\n";
        }
    }
    else
        cout<<"no"<<"\n";

}