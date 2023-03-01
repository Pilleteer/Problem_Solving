#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int banana_score[100010];
int kept_score[100010];
int best_score[100010];

void init(int n){
    for(int i=0;i<n;i++){
        kept_score[i]=0;
        best_score[i]=0;
    }
}
//A[i]=P[i]+max(A[i-3]),A[2]=P[2]
void find_fndmax(int n){
    int tmp=0;
    for(int i=2;i<n;i++){
        tmp=banana_score[i];
        tmp+=best_score[i-3];
        if(tmp>best_score[i-1]){
            best_score[i]=tmp;
        }else{
            best_score[i]=best_score[i-1];
        }
        kept_score[i]=tmp;
    }
    cout << best_score[n-1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    init(n);
    for(int i=0;i<n;i++){
        cin >> banana_score[i];
    }
    find_fndmax(n);
}