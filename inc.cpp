#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int score[100010];
int best_length[100010];
int max_length=0;
int max_index=0;
vector<int> seq[100010];

void init(int n){
    for(int i=0;i<n;i++){
        best_length[i]=0;
    }
}
//A[i]=P[i]+max(A[i-3]),A[2]=P[2]
void find_fndmax(int n){
    int tmp;
    for(int i=0;i<n;i++){
        tmp=1;
        for(int j=i-1;j>=0;j--){
            if(score[i]>score[j]){
                tmp+=best_length[j];
                seq[i]=seq[j];
                seq[i].push_back(score[i]);
                break;
            }
        }
        best_length[i]=tmp;
        if(tmp==1){
            seq[i].push_back(score[i]);
        }
        if(tmp>max_length){
            max_length=tmp;
            max_index=i;
        }
    }
    cout << max_length << " " << max_index << "\n";
    for(int k=0;k<seq[max_index].size();k++){
        cout << seq[max_index][k] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    init(n);
    for(int i=0;i<n;i++){
        cin >> score[i];
    }
    find_fndmax(n);
}