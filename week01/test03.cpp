#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int point=0,rnd,n,data;//rnd=round of runing,n=number of runner
    long long int less=1000000000;
    int *res;//calculated second
    res=(int *)malloc(sizeof(int)*(n+1));
    cin >> n >> rnd;
    for(int i=1;i<=n;i++){
        cin >> data;
        res[i]=data*rnd;
        if(res[i]<less){
            less=res[i];
        }
    }
    for(int i=1;i<=n;i++){
        //cout << less << " " << res[i] << " " << rnd << " " << point << "\n";
        if((res[i]-less)<res[i]/rnd){
            point+=1;
        }
    }
    cout << point << "\n";
    return 0;
}
/*
5 3
6
7
15
9
11
*/