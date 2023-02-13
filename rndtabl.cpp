#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;

int cntord[200010];
void init(int n){
    for(int i=0;i<n;i++){
        cntord[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,fi,st,cnt=0,mx=0;
    cin >> n;
    init(n);
    for(int i=0;i<n;i++){
        cin >> fi;
        fi--;
        st=i-fi;
        if(st<0){
            st=n+st;
        }
        cntord[st]+=1;
        if(cntord[st]>mx){
            mx=cntord[st];
        }
    }
    cout << mx << '\n';
}


/*
5
4 5 2 3 1
*/