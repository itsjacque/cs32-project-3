//
//  maze.cpp
//  cs 32 hw 3
//
//  Created by Jacqueline Nguyen on 2/13/23.
//

class Coord{
public:
    Coord(int r, int c) : m_row(r), m_col(c) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    Coord startPoint(sr,sc);
    int r = startPoint.r();
    int c = startPoint.c();
    if (sr == er && sc == ec)
        return true;
    maze[sr][sc] = '*';
    if (maze[r - 1][c] == '.' &&
        pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
        return true;
    if (maze[r][c + 1] == '.' &&
        pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
        return true;
    if (maze[r + 1][c] == '.' &&
        pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
        return true;
    if (maze[r][c - 1] == '.' &&
        pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
        return true;
    return false;
}
