#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& matrix) {
        int n = matrix.size();
        const int INF = 1e9;

        // Convert -1 (no edge) to INF
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = INF;

                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        matrix[i][j] = min(matrix[i][j],
                                           matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INF)
                    matrix[i][j] = -1;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {-1, 0, 1, 8},
        {-1, -1, 0, 2},
        {-1, -1, -1, 0}
    };

    Solution obj;
    obj.floydWarshall(matrix);

    cout << "Shortest Distance Matrix:\n";
    for (auto &row : matrix) {
        for (auto &x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}