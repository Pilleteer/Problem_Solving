#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,y,start;//y for case t=2,start for case t=1
    int *point;
    cin >> n >> t;
    point=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin >> point[i];
    }
    switch (t){
    case 2:
        for(int i=1;i<n;i++){
            y=point[i]-point[i-1];
            if(y>point[i-1]){
                y=point[i]-(2*point[i-1]);
            }
            point[i]=y;
        }
    case 1:
        if(point[0]<n){
            cout << 0;
        }else{
            cout << 1;
        }
        cout << '\n';
        for(int i=1;i<n;i++){
            if(point[i-1]<point[i]){
                cout << 1;
            }else{
                cout << 0;
            }
            cout << "\n";
        }
        break;
    default:
        break;
    }
    return 0;
}
/*
10 1
9
10
9
8
9
8
9
10
9
10

10 2
9
28
19
17
25
17
25
28
19
28
*/