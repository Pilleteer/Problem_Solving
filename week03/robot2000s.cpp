#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<string>
using namespace std;
char rotate(char st){
    if(st=='N'){
        return 'E';
    }else if(st=='E'){
        return 'S';
    }else if(st=='S'){
        return 'W';
    }else if(st=='W'){
        return 'N';
    }
    return st;
}
int main(){    
    vector<char> newcomd;
    char stance='N';
    string walk;
    cin >> walk;
    for(int i=0;i<walk.length();i++){
        if(walk[i]=='Z'){
            stance='N';
            newcomd.push_back('Z');   
        }else{
            while(stance!=walk[i]){
                newcomd.push_back('R');
                stance=rotate(stance);
            }
            newcomd.push_back('F');
        }
    }
    for(auto i=newcomd.begin();i!=newcomd.end();i++){
        cout << *i;
    }
    return 0;
}