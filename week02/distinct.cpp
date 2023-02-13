#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n,m,cntj,cntl,cost;
    set<int> dist;
    vector<int> price;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cost;
        price.push_back(cost);
    }
    for(int i=0;i<price.size();i++){
        dist.insert(price[i]);
        for(int j=0;j<i;j++){
            price[j]+=price[i];
            dist.insert(price[j]);
        }
    }
    cout << dist.size() << '\n';
}