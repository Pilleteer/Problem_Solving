#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
vector<vector<char> > map;
int passed[31][31];
int layer[31][31];
bool bfs(int posn,int posm){
    list<int> n;
    list<int> m;
    n.push_back(posn);
    m.push_back(posm);
    passed[posn][posm] = 1;
    layer[posn][posm] = 0;
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
            if(passed[tempn][tempm]!=1){
	            n.push_back(tempn);
                m.push_back(tempm);
	            passed[tempn][tempm] = 1;
	            if(map[tempn][tempm]!=map[u][v]){
                    layer[tempn][tempm] = layer[u][v]+1;
                }else{
                    layer[tempn][tempm] = layer[u][v];
                }
            }else{
                if(map[tempn][tempm]!=map[u][v]&&layer[tempn][tempm]>layer[u][v]+1){
                    layer[tempn][tempm] = layer[u][v]+1;
                }else if(map[tempn][tempm]==map[u][v]&&layer[tempn][tempm]>layer[u][v]){
                    layer[tempn][tempm] = layer[u][v];
                }
            }
        }
    }
}
void printlayer(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << layer[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int n,m,st1,st2,x,y;
    int a;
    cin >> n >> m >> st1 >> st2 >> x >> y;
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
    bfs(st1-1,st2-1);
    cout << layer[x-1][y-1] << endl;
    printlayer(n,m);
}