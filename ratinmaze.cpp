#include <iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>>& mat, int r, int c,
            string path, vector<string>& ans,
            vector<vector<bool>>& vis) {

    int n = mat.size();

    if (r < 0 || c < 0 || r >= n || c >= n ||
        mat[r][c] == 0 || vis[r][c] == true) {
        return;
    }

    if (r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;

    helper(mat, r+1, c, path+"D", ans, vis); // Down
    helper(mat, r-1, c, path+"U", ans, vis); // Up
    helper(mat, r, c-1, path+"L", ans, vis); // Left
    helper(mat, r, c+1, path+"R", ans, vis); // Right

    vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();

    vector<string> ans;

    if (n == 0 || mat[0][0] == 0 || mat[n-1][n-1] == 0) {
        return ans;
    }

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(mat, 0, 0, "", ans, vis);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<string> ans = findPath(mat);

    if (ans.empty()) {
        cout << "No path";
    } else {
        for (string path : ans) {
            cout << path << " ";
        }
    }

    return 0;
}
