#include<iostream>
#include<list>
using namespace std;
int main(){
    int n,mx=0,cnt=0;
    long long int a,b;
    list<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_front(b);
    }
    auto j=v.begin();
    for(j;j!=v.end();j++){
        //cout << *j << '\n';
        if(*j>mx){
            mx=*j;
            continue;
        }else{
            cnt+=1;
        }
    }
    cout << cnt << '\n';
}