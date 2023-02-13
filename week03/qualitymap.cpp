#include<iostream>
#include<list>
#include<vector>
#include<utility>
using namespace std;
vector<vector<char> > map;
vector<int> tree[31];
int passed[31][31];
int layer[31][31];
bool isdirt(char a){
    if(a=='.'||a=='$'||a=='*'){
        return true;
    }else{
        return false;
    }
}
pair<int,int> bfs(int posn,int posm){
    list<int> n;
    list<int> m;
    
    int cnt=0,tier=1;
    bool checktier[2]={false,false};
    if(map[posn][posm]=='$'){
        checktier[0]=true;
        }
    if(map[posn][posm]=='*'){
        checktier[1]=true;
    }
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
            if(tempn<0||tempn>=map.size()||tempm<0||tempm>=map[0].size()){
                continue;
            }
            char pos=map[tempn][tempm];
            if(passed[tempn][tempm]!=1&&isdirt(pos)){
                if(pos=='$'){
                    checktier[0]=true;
                }
                if(pos=='*'){
                    checktier[1]=true;
                }
	            n.push_back(tempn);
                m.push_back(tempm);
	            passed[tempn][tempm] = 1;
	            layer[tempn][tempm] = layer[u][v] + 1;
            }
        }
        cnt+=1;
    }
    for(int i=0;i<=1;i++){
        if(checktier[i]==true){
            tier+=1;
        }
    }
    return  make_pair(tier,cnt);
}
void runmap(int n,int m){
    int lowrank=0,midrank=0,highrank=0;
    pair<int,int> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(passed[i][j]==1||map[i][j]=='#'){
                continue;
            }
            res=bfs(i,j);
            if(res.first==1){
                lowrank+=res.second;
            }else if(res.first==2){
                midrank+=res.second;
            }else if(res.first==3){
                highrank+=res.second;
            }
        }
    }
    cout << highrank << " " << midrank << '\n'; //<< ' ' << lowrank;
}
int main(){
    int n,m;
    char a;
    cin >> n >> m;
    for(int i=0;i<n;i++){
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
    runmap(n,m);
}
/*
7 8
.*..#...
....#...
.$.#..*#
..#..##.
.#.##...
#....###
..$.....
*/