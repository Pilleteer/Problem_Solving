#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
vector<int> node[100010];
int passed[100010];
int layer[100010];
int n,m,cnt=0;
void init(){
    for(int i=0;i<n;i++){
        passed[i]=0;
        layer[i]=-1;
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
        for(auto i=node[v].begin();i!=node[v].end();i++){
            if(passed[*i]==0){
                u.push_back(*i);
                passed[*i]=1;
                layer[*i]=layer[v]+1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    int a,b;
    for(int j=0;j<m;j++){
        cin >> a >> b;
        node[a-1].push_back(b-1);
        node[b-1].push_back(a-1);
    }
    init();
    for(int i=0;i<n;i++){
        if(passed[i]){
            continue;
        }else{
            bfs(i);
            cnt+=1;
        }
    }
    cout << cnt;
    return 0;
}