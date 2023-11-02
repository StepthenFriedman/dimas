int hasPath(char** matrix, int rows, int cols, char *str) {
    for (int i = 0; i < rows; i ++ )
        for (int j = 0; j < cols; j ++ )
            if (dfs(matrix, str, 0, i, j, rows, cols))
                return 1;
    return 0;
}

int dfs(char **matrix, char *str, int u, int x, int y, int rows, int cols) {
    if (matrix[x][y] != str[u]) return 0;
    if (str[u+1] == '\0') return 1;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char t = matrix[x][y];
    matrix[x][y] = '*';
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < rows && b >= 0 && b < cols) {
            if (dfs(matrix, str, u + 1, a, b, rows, cols)) return true;
        }
    }
    matrix[x][y] = t;
    return 0;
}

