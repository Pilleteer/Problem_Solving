#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int point=0,n,cur=1,cnt=0;//a=passto data,n=rnd,point=max cnt,cur = current position,cnt tell rnd that success
    int *passto,*cycle;//lessrndบอกรอบที่น้อยสุด,cycle tell cycle of that num
    cin >> n;
    passto=(int *)malloc(sizeof(int)*(n+1));
    cycle=(int *)malloc(sizeof(int)*(n+1));
    for(int i=1;i<n+1;i++){
        cin >> passto[i];
        cycle[i]=n+1;
    }
    for(int i=1;i<=n;i++){//i=number that want to run
        cur=passto[i];
        if(cycle[cur]==n+1){
            cycle[cur]=i;
        }
        cnt=1;
        while(cur!=i&&cycle[i]>=i){
            cur=passto[cur];
            cycle[cur]=i;
            cnt+=1;
            //cout << cur << " " << i << "\n";
        }
        if(cnt>point){
            point=cnt;
        }
    }
    cout << point;
    return 0;
}
/*
6
2
6
5
4
3
1
*/