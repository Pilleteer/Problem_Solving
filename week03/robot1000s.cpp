#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<string>
using namespace std;
int main(){    
    int point[4]={0,0,0,0};
    int cnt;
    string walk;
    cin >> walk >> cnt;
    int delmin=cnt;
    for(int i=0;i<walk.length();i++){
        switch(walk[i]){
        case 'N':
            point[0]+=1;
            break;
        case 'S':
            point[1]+=1;
            break;
        case 'W':
            point[2]+=1;
            break;
        case 'E':
            point[3]+=1;
            break;
        case 'Z':
            for(int i=0;i<4;i++){
                point[i]=0;
            }
            break;
        default:
            break;
        }
    }
    int temp=0;
    int i=0,j=2;//i=='N',j=='W'
    if(point[i]>point[i+1]){
        i+=1;
    }
    if(point[j]>point[j+1]){
        j+=1;
    }
    if(point[i]<delmin){
        delmin-=point[i];
        point[i]=0;
        i=(i+1)%2;
        if(point[j]<delmin){
            delmin-=point[j];
            point[j]=0;
            j=2+(j+1)%2;
            if(point[i]<delmin){
                delmin-=point[i];
                point[i]=0;
                point[j]-=delmin;
            }else{
                point[i]-=delmin;
            }
        }else{
            point[j]-=delmin;
        }
    }else{
        point[i]-=delmin;
    }
    int x=abs(point[0]-point[1]);
    int y=abs(point[2]-point[3]);
    pair<int,int> pos=make_pair(x,y);
    temp=x+y;
    cout << temp*2;
    return 0;
}