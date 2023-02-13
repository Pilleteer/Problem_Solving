#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int point=1,n,k,t,detector;
    cin >> n >> k >> t;
    detector=0;
    for(point;point<=n;point++){
        //cout << point*k << endl;
        detector+=k;
        if(detector>=n){
            detector-=n;
        }
        if(detector==0||detector==t-1){
            if(detector==t-1){
                point+=1;
            }
            break;
        }
    }
    //ถ้าkหารด้วยnลงตัว+เทียบกะn+t
    cout << point << "\n";
    return 0;
}