#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int point=0,rnd,n;//rnd=round of running,n=number of runner
    long long int less=1000000000,data;
    cin >> n >> rnd;
    long long int *res;
    res=(long long int *)malloc(sizeof(long long int)*(n+1));
    for(int i=1;i<=n;i++){
        cin >> data;
        res[i]=data;
        if(res[i]<less){
            less=res[i];
        }
    }
    for(int i=1;i<=n;i++){
        //cout << less << " " << res[i] << " " << rnd << " " << point << "\n";
        if((res[i]-less)*rnd<res[i]){
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