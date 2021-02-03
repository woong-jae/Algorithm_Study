#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string str1, str2;
int cache[1001][1001];

int lcs(int index1, int index2) {
    if(index1 == str1.size() || index2 == str2.size()) return 0;
    int&ret = cache[index1][index2];
    if(ret != -1) return ret;
    
    ret = 0;
    if(str1[index1] == str2[index2]) {
        ret = max(ret, lcs(index1 + 1, index2 + 1) + 1);
    } else {
        ret = max(lcs(index1 + 1, index2), lcs(index1, index2 + 1));
    }
    
    return ret;
}

int main() {
    cin >> str1 >> str2;
    memset(cache, -1, sizeof(cache));
    
    cout << lcs(0, 0) << '\n';
}

