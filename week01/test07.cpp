#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int point=0,n;//rnd=round of running,n=number of penguin
    float half;
    float *angle;
    cin >> n;
    half=n/2;
    angle=(float *)malloc(sizeof(float)*n+1);
    //ดูเลขที่เก็บ case:มากกว่าครึ่ง เจอน้อยกว่าครึ่งข้าม เจอมากกว่าตัวเอง+1
    //case:น้อยกว่าครึ่ง เจอมากกว่าตัวเอง+1
    for(int i=1;i<=n;i++){
        cin >> angle[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(angle[i]>half&&angle[j]>angle[i]){
                point+=1;
            }else if(angle[i]<=half&&angle[j]>angle[i]){
                point+=1;
            }
        }
    }
    cout << point << "\n";
    return 0;
}