#include<iostream>
#include<list>
using namespace std;

typedef struct necklace{
    int num;
    necklace *next;
    necklace *prev;
}nl;
nl **init(int n){
    nl **temp=(nl **)malloc(sizeof(nl *)*n);
    for(int i=0;i<n;i++){
        temp[i]=(nl *)malloc(sizeof(nl));
        temp[i]->num=i+1;
        temp[i]->next=NULL;
        temp[i]->prev=NULL;
    }
    return temp;
}
int main() {
    int n,a,b;
    nl **soy;
    nl *temp;
    nl *pos1;
    cin >> n;
    soy=init(n);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        a--;
        b--;
        if(soy[b]->next==NULL){
            soy[b]->next=soy[a];
            soy[a]->prev=soy[b];
        }else{
            temp=soy[b]->next;
            soy[b]->next=soy[a];
            soy[a]->prev=soy[b];
            pos1=soy[b];
            while(pos1->next!=NULL){
                pos1=pos1->next;
            }
            pos1->next=temp;
            temp->prev=pos1;
        }
    }
    nl *pos2=soy[b];
    while (pos2->prev!=NULL){
        pos2=pos2->prev;
    }
    while (pos2!=NULL){
        cout << pos2->num << ' ';
        pos2=pos2->next;
    }
    return 0;
}
/*
8
7 4
3 5
5 4
8 1
2 8
1 6
4 1 
*/