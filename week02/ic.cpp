#include<iostream>
#include<list>
using namespace std;

int main() {
    int a,temp,n;
    string s;
    list<int> ans;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        //cout << "\n" << s << "\n";
        if(s.length()!=2){
            continue;
        }
        switch(s[0]){
            case 'l':
                switch(s[1]){
                    case 'i':
                        cin >> a;
                        ans.push_front(a);
                        break;
                    case 'r':
                        if(ans.begin()==ans.end()){
                            continue;
                        }
                        temp=ans.front();
                        ans.pop_front();
                        ans.push_back(temp);
                        break;
                }
            break;
            case 'r':
                switch(s[1]){
                    case 'i':
                        cin >> a;
                        ans.push_back(a);
                        break;
                    case 'r':
                        if(ans.begin()==ans.end()){
                            continue;
                        }
                        temp=ans.back();
                        ans.pop_back();
                        ans.push_front(temp);
                        break;
                }
        }
    }
    list<int>::iterator show;
    for(show=ans.begin();show!=ans.end();show++){
        cout << *show << "\n";
    }
    return 0;
}