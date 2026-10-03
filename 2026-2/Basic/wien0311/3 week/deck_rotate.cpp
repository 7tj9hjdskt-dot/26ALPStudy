#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    deque<int> d;
    int n, m, idx1, idx2, k;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        d.insert(d.begin()+i, i+1);
    }

    for(int i=0; i<m; i++) { //찾아야 하는 원소의 수만큼 반복
        cin>>k;
        auto it = find(d.begin(), d.end(), k);
        idx1 = it - d.begin(); //[0]에서 부터
        idx2 = d.end() - it; //끝에서 부터
        
        if(idx1 < idx2) {
            //d.begin()을 뒤로 보내야 함
        }
    }


    return 0;
}//d.push_front(d.back())