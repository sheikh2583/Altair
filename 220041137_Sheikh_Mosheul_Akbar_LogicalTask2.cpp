#include <bits/stdc++.h>

using namespace std;

int visited[26] = {0};
int matrix[26][26];
int c = 0;

void dfs(int u) {
    visited[u] = 1;
    dbg(u);
    c++;
    for(int i=0; i<26; i++) {
        int v = matrix[u][i];
        if(v == 1) { // Connection exists
            if(visited[i] == 0) {
                dfs(i);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(matrix, 0, sizeof matrix); 
    string a, b;
    while(cin >> a >> b) {
        int offA = (int)(a[0]-'a'), offB = (int)(b[0]-'a');
        dbg(a[0], b[0],offA, offB);
        matrix[a[0]-'a'][b[0]-'a'] = 1;
    }

    for(char i='a'; i<='z'; i++) {
        for(char j='a'; j<='z'; j++) {
            cout << matrix[i-'a'][j-'a'] << " ";
        }
        cout << endl;
    }

    int mx = -1;
    for(int i=0; i<26; i++) {
        c = 0;
        memset(visited, 0, sizeof visited);
        dfs(i);
        mx = max(mx, c);
    }

    bool isPossible = (mx >= n);
    cout << isPossible << endl;

    return 0;
}
