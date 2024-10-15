#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

vector<pair<int, int>> possibleToGo(const vector<vector<bool>>& matriz, int i, int j) {
    vector<pair<int, int>> possibleMoves;
    if (i + 1 < matriz.size() && matriz[i + 1][j]) {
        possibleMoves.emplace_back(i + 1, j);
    }
    if (i - 1 >= 0 && matriz[i - 1][j]) {
        possibleMoves.emplace_back(i - 1, j);
    }
    if (j + 1 < matriz[0].size() && matriz[i][j + 1]) {
        possibleMoves.emplace_back(i, j + 1);
    }
    if (j + 1 == matriz[0].size() && matriz[i][0]) {
        possibleMoves.emplace_back(i, 0);
    }
    if (j - 1 >= 0 && matriz[i][j - 1]) {
        possibleMoves.emplace_back(i, j - 1);
    }
    if (j - 1 == -1 && matriz[i].back()) {
        possibleMoves.emplace_back(i, matriz[0].size() - 1);
    }
    return possibleMoves;
}

pair<set<pair<int, int>>, int> bfs(const vector<vector<bool>>& matriz, int i, int j) {
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.emplace(i, j);
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        visited.insert(node);
        
        auto possibleMoves = possibleToGo(matriz, node.first, node.second);
        for (const auto& move : possibleMoves) {
            if (visited.find(move) == visited.end()) {
                q.push(move);
            }
        }
    }
    return {visited, visited.size()};
}

int main() {
    try {
        while (true) {
            int n, m;
            cin >> n >> m;
            vector<vector<bool>> land(n);
            set<pair<int, int>> visited;
            int biggest = 0;

            for (int i = 0; i < n; ++i) {
                string line;
                cin >> line;
                land[i].resize(line.size());
                for (int j = 0; j < line.size(); ++j) {
                    land[i][j] = (line[j] == line[0]); // Change this logic if needed
                }
            }

            int landI, landJ;
            cin >> landI >> landJ;
            char landMark = land[landI][landJ]; // Change logic accordingly if necessary

            auto mainLand = bfs(land, landI, landJ);
            visited.insert(mainLand.first.begin(), mainLand.first.end());

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < land[i].size(); ++j) {
                    if (visited.find({i, j}) == visited.end() && land[i][j]) {
                        auto newVisited = bfs(land, i, j);
                        visited.insert(newVisited.first.begin(), newVisited.first.end());
                        biggest = max(biggest, (int)newVisited.second);
                    }
                }
            }
            cout << biggest << endl;
        }
    } catch (...) {
        // Handle any exception if necessary
    }
    return 0;
}
