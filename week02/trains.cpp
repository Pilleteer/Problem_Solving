#include<iostream>
#include<list>
using namespace std;
list<long long int> trn[100010];//train station
int main() {
    int n,c;
    char a;
    long long int b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        switch(a){
            case 'N':
                trn[c].push_back(b);
                break;
            case 'M':
                if(b==c) break;
                trn[c].splice(trn[c].end(),trn[b]);
                break;
        }
    }
    for(int i=0;i<100010;i++){
        if(trn[i].empty()){
            continue;
        }
        else{
            auto show=trn[i].begin();
            for(show;show!=trn[i].end();show++){
                cout << *show << '\n';
            }
        }
    }
    return 0;
}
/*
7
N 1 1
N 2 1
N 3 2
M 1 2
N 4 1
N 5 3
M 3 1
*/