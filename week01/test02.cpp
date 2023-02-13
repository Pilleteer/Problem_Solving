#include<iostream>
using namespace std;

int main() {
    int a,b,point,n;
    point=0;
    b=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a>b){
            point+=a;
        }
    }
    cout << point << "\n";
    return 0;
}