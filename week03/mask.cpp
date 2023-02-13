#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
int kon[1201];
int findmax(int n,int rnd){
    int fnd=0,fndindex;
    for(int i=n*(rnd-1);i<n+n*(rnd-1);i++){
        if(kon[i]>fnd){
            fnd=kon[i];
            fndindex=i;
        }
    }
    return fndindex;
}
int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<4*n;i++){
        cin >> m;
        kon[i]=m;
    }
    int prize[4],saiA,saiB;
    if(kon[findmax(n,1)]>kon[findmax(n,2)]){
        prize[2]=findmax(n,2);
        saiA=findmax(n,1);
    }else{
        prize[2]=findmax(n,1);
        saiA=findmax(n,2);
    }
    if(kon[findmax(n,3)]>kon[findmax(n,4)]){
        prize[3]=findmax(n,4);
        saiB=findmax(n,3);
    }else{
        prize[3]=findmax(n,3);
        saiB=findmax(n,4);
    }
    if(kon[saiA]>kon[saiB]){
        prize[1]=saiB;
        prize[0]=saiA;
    }else{
        prize[0]=saiB;
        prize[1]=saiA;
    }
    for(int i=0;i<4;i++){
        cout << prize[i]+1 << ' ';
    }
}