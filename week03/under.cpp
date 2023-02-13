#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
int l[301];
void init(int n){
    for(int i=0;i<n;i++){
        l[i]=0;
    }
}
int main(){
    int cnt=0;
    int n,m,a,b;
    cin >> n >> m;
    init(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        for(int j=a;j<=b-1;j++){
            l[j]+=1;
            if(l[j]>cnt){
                cnt=l[j];
            }
        }
    }
    cout << cnt;
    return 0;
}