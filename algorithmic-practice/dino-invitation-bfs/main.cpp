#include <queue>
#include <iostream>
#include <vector>
#include <utility>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> office(n, std::vector<char>(m));
    std::vector<std::vector<int>> time(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> office[i][j];

            if (office[i][j] == 'D') {
                q.push({i, j});
                time[i][j] = 0;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (office[nx][ny] == 'S' && time[nx][ny] == -1) {
                time[nx][ny] = time[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] == 'S') {
                if (time[i][j] == -1) {
                    std::cout << -1 << "\n";
                    return 0;
                }

                if (time[i][j] > answer) {
                    answer = time[i][j];
                }
            }
        }
    }

    std::cout << answer << "\n";
}
