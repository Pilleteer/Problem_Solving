#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
vector<vector<char> > map;
vector<int> tree[30];
int passed[30][30];
int layer[30][30];
bool chcktwo(int posn,int posm,int n,int m){
    if(map[posn][posm]=='.'&&map[posn][posm+1]=='.'){
        return true;
    }else{
        return false;
    }
}
bool chckbox(int posn,int posm,int n,int m){
    if(chcktwo(posn,posm,n,m)==true&&chcktwo(posn+1,posm,n,m)==true){
        return true;
    }else{
        return false;
    }
}
bool bfs(int posn,int posm){
    list<int> n;
    list<int> m;
    n.push_back(posn);
    m.push_back(posm);
    passed[posn][posm] = 1;
    layer[posn][posm] = 1;
    while(!n.empty()) {
        int u = n.front();
        int v = m.front();
        n.pop_front();
        m.pop_front();
        for(int d=0; d<4; d++) {
            int tempn=u;
            int tempm=v;
            switch(d){
                case 0:
                    tempn-=1;
                    break;
                case 1:
                    tempm+=1;
                    break;
                case 2:
                    tempn+=1;
                    break;
                case 3:
                    tempm-=1;
                    break;
                default:
                    break;
            }
            if(tempn<0||tempn>=map.size()||tempm<0||tempm>=map[0].size()-1){
                continue;
            }
            if(passed[tempn][tempm]!=1&&chckbox(tempn,tempm,map.size(),map[0].size())){
                if(tempn+1==map.size()-1){
                    return true;
                }
	            n.push_back(tempn);
                m.push_back(tempm);
	            passed[tempn][tempm] = 1;
	            layer[tempn][tempm] = layer[u][v] + 1;
            }
        }
    }
    return false;
}
void boxpath(int n,int m){ // find startpoint
    bool a;
    for(int i=0;i<m;i++){
        if(chckbox(0,i,n,m)==true){
            a=bfs(0,i);
            //cout << a << endl;
            if(a){
                break;
            }
        }
    }
    //cout << a;
    if(a){
        cout << "yes";
    }else{
        cout << "no";
    }
}
int main(){
    int n,m,o;
    char a;
    bool boxcan=true;
    cin >> n >> m;
    for(int i=0;i<n;i++){ // convert into graph,change path format
        vector<char> temp;
        for(int j=0;j<m;j++){
            cin >> a;
            temp.push_back(a);
            layer[i][j]=-1;
            passed[i][j]=0;
        }
        map.push_back(temp);
        temp.clear();
    }
    boxpath(n,m);
}
/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.
*/