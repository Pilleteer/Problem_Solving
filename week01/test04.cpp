#include<iostream>
using namespace std;

int main(){
    int a,point,n;
    point=0;
    int *b;
    b=(int *)malloc(sizeof(int)*301);
    for(int i=0;i<301;i++){
        b[i]=0;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        b[a]+=1;
        if(point<b[a]){
            point=b[a];
        }
    }
    cout << point << "\n";
    return 0;
}
