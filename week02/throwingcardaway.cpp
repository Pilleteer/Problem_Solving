#include<iostream>
#include<list>
using namespace std;
void printodd(int n){
    if(n>1){
        cout << " 1";
    }
    for(int i=3;i<=n;i+=2){
        cout << ", " << i;
    }
}
void geteven(list<int> *a,int n){
    for(int i=4;i<=n;i+=2){
        a->push_back(i);
    }
    if(n>=2&&n%2==1){
        a->push_back(2);
    }else if(n>=2){
        a->push_front(2);
    }
        
}
void discardeven(list<int> *a){
    int temp;
    //list<int>::iterator rem=a->begin();
    while(a->size()>1){
        cout << ", " << a->front();
        a->pop_front();
        temp=a->front();
        a->pop_front();
        a->push_back(temp);
    }
}
void printlist(list<int> *a){
    list<int>::iterator show;
    cout << '\n';
    for(show=a->begin();show!=a->end();++show){
        cout << *show << ' ';
    }
    cout << '\n';
}
int main() {
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        list<int> deck;
        cout << "Discarded cards:";
        printodd(n);
        geteven(&deck,n);
        //printlist(&deck);
        //cout << '\n' << deck.size() << '\n';
        discardeven(&deck);
        cout << '\n' << "Remaining card: ";
        if(n==1){
            cout << '1' << '\n';
        } else{
            cout << deck.front() << '\n';
        }
    }
    //cout << '\n';
    return 0;
}
/*
7
19
10
6
0
*/