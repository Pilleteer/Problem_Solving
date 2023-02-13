#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
vector<int> adj[100010];
int passed[100010];
int deg[100010];
int layer[100010];
vector<int> conf;
pair<int,int> xy=make_pair(-1,-1);

void clearlayer(int n){
    for(int i=0;i<n;i++){
        passed[i]=0;
        layer[i]=0;
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        passed[i]=0;
        deg[i]=0;
        layer[i]=0;
    }
}
bool bfs(int s){
    list<int> u;
    u.push_back(s);
    passed[s]=1;
    layer[s]=0;
    while(!u.empty()){
        int v=u.front();
        u.pop_front();
        for(int i=0;i<deg[v];i++){
            if(xy.first!=-1&&xy.second!=-1){
                if((adj[v][i]==xy.first&&v==xy.second)||(adj[v][i]==xy.second&&v==xy.first)){
                    continue;
                }
            }
            if(passed[adj[v][i]]==0){
                u.push_back(adj[v][i]);
                passed[adj[v][i]]=1;
                layer[adj[v][i]]=(layer[v]+1)%2;
            }else{
                if(layer[adj[v][i]]==layer[v]){
                    xy=make_pair(v,adj[v][i]);
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int n,m,a,b;
    cin >> n >> m;
    init(n);
    for(int l=0;l<m;l++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        deg[a-1]++;
        deg[b-1]++;
    }    
    int temp1,temp2;
    while(1){
        if(bfs(0)){
            break;
        }
        clearlayer(n);
    }
    cout << xy.first+1 << " " << xy.second+1 << '\n';
}