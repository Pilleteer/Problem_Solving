#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
vector<int> adj[100010];
vector<int> toporder,oper;
int passed[100010];
int outdeg[100010];
int indeg[100010];
void init(int n){
    for(int i=0;i<n;i++){
        passed[i]=0;
        outdeg[i]=0;
    }
}
bool inord(int s){
    int temp;
    for(int i=0;i<oper.size();i++){
        temp=oper[i];
        if(s==temp){
            return true;
        }
    }
    return false;
}
bool dfs(int s){
    bool fstpass=false;
    if(!passed[s]){
        fstpass=true;
    }
    passed[s] = true;
    oper.push_back(s);
    bool iscycle=false;
    for(int i=0; i<outdeg[s]; i++) {
        int v = adj[s][i];
        if(!passed[v]) {
            iscycle=dfs(v);
        }else if(inord(v)){
            iscycle=true;
            break;
        }
    }
    if(fstpass){
        toporder.push_back(s);
    }
    oper.pop_back();
    return iscycle;
}
int main(){
    int n,m,a,b;
    bool istop=true;
    cin >> n >> m;
    init(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        outdeg[a]+=1;
        indeg[b]+=1;
    }
    for(int i=0;i<n;i++){
        oper.clear();
        istop=!dfs(i);
        if(!istop){
            break;
        }
    }
    if(istop){
        for(int i=toporder.size()-1;i>=0;i--){
            cout << toporder[i]+1 << '\n';
        }
    }else{
        cout << "no";
    }
}