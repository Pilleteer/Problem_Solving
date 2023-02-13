#include<iostream>
#include<list>
using namespace std;

int main() {
    int a,n;
    char s;
    list<int> ans;
    cin >> n;
    list<int>::iterator temp;
    for(int i=0;i<n;i++){
        cin >> s >> a;
        //cout << s << " " << a;
        switch(s){
        case 'I':
            ans.push_front(a);
            break;
        case 'D':
            //cout << ans.size();
            if(a>ans.size()){
                continue;
            }
            temp=ans.begin();
            for(int j=1;j<a;j++){
                temp++;
            }
            ans.erase(temp);
        }
    }
    list<int>::iterator show;
    for(show=ans.begin();show!=ans.end();show++){
        cout << *show << "\n";
    }
    return 0;
}