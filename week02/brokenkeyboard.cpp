#include<iostream>
#include<string>
#include<list>
using namespace std;
void getprint(list<char> a){
    auto show=a.begin();
    for(show;show!=a.end();++show){
        cout << *show;
    }
}
int main() {
    int a,point,n;
    int cs;//case select
    list<char> txt,temptxt,stxt;//text,temp to first text,first text
    string x;
    while(getline(cin , x)){
        cs=1;
        for(a=0;a<x.size();a++){
            if(x[a]=='['){
                cs=2;
                stxt.splice(stxt.begin(),temptxt);
                temptxt.clear();
                //cout << '2' << txt.size() << '\n';
                continue;
            }
            if(x[a]==']'){
                cs=1;
                stxt.splice(stxt.begin(),temptxt);
                temptxt.clear();
                //cout << '1' << txt.size() << '\n';
                continue;
            }
            switch(cs){
                case 1:
                    txt.push_back(x[a]);
                    break;
                case 2:
                    temptxt.push_back(x[a]);
                    break;
            }
        }
        if(!temptxt.empty()){
            stxt.splice(stxt.begin(),temptxt);
            temptxt.clear();
        }
        getprint(stxt);
        getprint(txt);
        cout << '\n';
        txt.clear();
        stxt.clear();
    }
    return 0;
}
/*
*/