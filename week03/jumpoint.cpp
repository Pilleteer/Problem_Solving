#include<iostream>
#include<utility>
#include<list>
#include<vector>
#include<math.h>
using namespace std;
vector<int> adj[1010];
vector<pair<int,int>> node;
int passed[1010];
int layer[1010];
void init(int n){
    for(int i=0;i<n;i++){
        passed[i]=0;
        layer[i]=-1;
    }
}
int distcal(pair<int,int> x,pair<int,int> y){
    int a,b,c;
    a=pow(y.first-x.first,2);
    b=pow(y.second-x.second,2);
    c=a+b;
    return c;
}
void get_edge(int n,int dist){
    pair<int,int> a,b;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            a=node[i],b=node[j];
            int d=distcal(node[i],node[j]);
            if(d<=pow(dist,2)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}
void bfs(int s){
    list<int> u;
    u.push_back(s);
    passed[s]=1;
    layer[s]=0;
    while(!u.empty()){
        int v=u.front();
        u.pop_front();
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            if(passed[*i]==0){
                u.push_back(*i);
                passed[*i]=1;
                layer[*i]=layer[v]+1;
            }
        }
    }
}
int main(){
    int n,dist,a,b;
    cin >> n >> dist;
    node.push_back(make_pair(0,0));
    for(int i=0;i<n;i++){
        cin >> a >> b;
        node.push_back(make_pair(a,b));
    }
    n+=2;
    node.push_back(make_pair(100,100));
    init(n);
    get_edge(n,dist);
    bfs(0);
    cout << layer[n-1];
}