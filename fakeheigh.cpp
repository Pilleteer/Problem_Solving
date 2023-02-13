#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<vector>
using namespace std;
long long int heigh[100010];
long long int hdif[100009];
int main(){
    long long int n,temp,mx=0,mxindex=0,ls,lsindex,cs=2;
    long long int lsdiff=1000000000000000,sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> heigh[i];
        if(i>0){
            hdif[i-1]=abs(heigh[i]-heigh[i-1]);
            sum+=hdif[i-1];
        }
    }
    for(int i=0;i<n-2;i++){
        temp=hdif[i]+hdif[i+1];
        if(temp>mx&&heigh[i+1]!=(heigh[i]+heigh[i+2])/2){
            mx=temp;
            mxindex=i+1;
        }
    }
    ls=(heigh[mxindex-1]+heigh[mxindex+1])/2;
    if(mxindex==1){
        if(abs(heigh[0]-heigh[2])>ls){
            if(hdif[0]>hdif[1]){
                mxindex=0;
                ls=heigh[1];
                cs=1;
            }
        }
    }else if(mxindex==n-2){
        if(abs(heigh[n-3]-heigh[n-1])>ls){
            if(hdif[n-2]>hdif[n-3]){
                mxindex=n-1;
                ls=heigh[n-2];
                cs=3;
            }
        }
    }else if(n==1){
        cs=4;
    }
    for(int i=0;i<n;i++){
        if(abs(i-mxindex)==1){
            continue;
        }
        if(abs(ls-heigh[i])<lsdiff){
            lsdiff=abs(ls-heigh[i]);
            lsindex=i;
        }
    }
    switch(cs){
        case 4:
            cout << 0 << '\n';
            break;
        case 3:
            cout << sum-(hdif[n-2]-abs(heigh[n-2]-heigh[lsindex])) << '\n';
            break;
        case 2:
            cout << sum-(hdif[mxindex-1]-abs(heigh[mxindex-1]-heigh[lsindex]))-(hdif[mxindex]-abs(heigh[mxindex+1]-heigh[lsindex])) << '\n';
            break;
        case 1:
            cout << sum-(hdif[0]-abs(heigh[1]-heigh[lsindex])) << '\n';
            break;
        default:
            break;
    }
    
}
/*
4
1 20 19 5
4
1 60 2 9
*/