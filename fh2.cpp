#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<vector>
using namespace std;
long long int heigh[100010];
long long int hdif[100009];
int main(){
    int n,temp,mx=0,mxindex=0,ls,lsindex=0;
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
        if(temp>mx){
            mx=temp;
            mxindex=i+1;
        }
    }
    ls=(heigh[mxindex-1]+heigh[mxindex+1])/2;
    lsindex=mxindex;
    for(int i=0;i<n;i++){
        if(abs(i-mxindex)==1){
            continue;
        }
        if(abs(ls-heigh[i])<lsdiff){
            lsdiff=abs(ls-heigh[i]);
            lsindex=i;
        }
    }
    cout << sum-(hdif[mxindex-1]-abs(heigh[mxindex-1]-heigh[lsindex]))-(hdif[mxindex]-abs(heigh[mxindex+1]-heigh[lsindex])) << endl;
}
/*
4
1 20 19 5
*/