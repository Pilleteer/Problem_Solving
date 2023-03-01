
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int MAXN = 200010;    
int n,q;
int edges[MAXN][2];
int weight[MAXN];
//pair<int,int> sorted_edges[MAXN];
int parent[MAXN];

// void read_input(){   
//     cin >> n >> q;
//     char cs;
//     for(int i=0;i<q;i++){
//         int a,b;
//         cin >> a >> b >> cs;
//         edges[i][0]=a-1;
//         edges[i][1]=b-1;
//         sorted_edges[i].first=weight[i];
//         sorted_edges[i].second=i;
//     }
// }

// bool compare_pairs(const pair<int, int>& a, const pair<int, int>& b) {
//   return a.first < b.first;
// }

// void sort_edges() {
//   sort(sorted_edges, sorted_edges + m, compare_pairs);
// }
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void union_set(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px!=py){
        parent[px]=py;
    }
}

void init(){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // sort_edges();
    cin >> n >> q;
    init();
    char cs;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> cs >> a >> b;
        a--;
        b--;
        switch(cs){
        case 'q':
            if(find(a)!=find(b)){
                cout << "no" << '\n';
            }else{
                cout << "yes" << '\n';
            }
            break;
        case 'c':
            if(find(a)!=find(b)){
                union_set(a,b);
            }
        default:
            break;
        }
        // int a=edges[sorted_edges[i].second][0];
        // int b=edges[sorted_edges[i].second][1];
        // if(find(a)!=find(b)){
        //     union_set(a,b);
        //     sum+=sorted_edges[i].first;
        // }
    }
    return 0;
}