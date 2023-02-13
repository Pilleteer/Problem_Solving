#include<iostream>
#include<list>
#include<string>
using namespace std;

void cansort(int *n,int m){
    int i=0,cnt=1;
    list<int> stk;
    while(i<m){
        if(cnt==n[i]){
            cnt++;
            i++;
        }else{
            if(stk.front()==n[i]){
                i++;
                stk.pop_front();
            }else{
                stk.push_front(cnt);
                cnt++;
                if(cnt-m>2){
                    break;
                }
            }
        }
    }
    if(cnt>=m&&stk.empty()){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
int main(){
    int cnt,m;
    int *n;
    while(1){
        cnt=0;
        cin >> m;
        if(m==0){
            break;
        }
        n=(int *)malloc(sizeof(int)*m);
        while(1){   
            switch(cnt) {
                case 0:
                case 1:
                    for(int i=0;i<m;i++){
                        cin >> n[i];
                        if(n[i]==0&&i==0){
                            cnt+=1;
                            cout << '\n';
                            break;
                        }
                    }
                    break;
            }
            if(cnt==1){
                break;
            }
            cnt=0;
            cansort(n,m);
            cout << '\n';
        }
        free(n);  
    }
}