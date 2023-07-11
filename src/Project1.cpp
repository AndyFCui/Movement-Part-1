#include "Project1.h"
#include <chrono>
#include <math.h>
#include <queue>
using namespace std;
int visited[10001][10001];
int valF[10001][10001];
int path[10001][10001][2]; 
vector<pos> path1;
int xmax, ymax;

priority_queue<Node> que;
int Straightline(int x, int y, int x1, int y1, const vector<vector<char>> inputMap) {
        
    int xsums = 0,ysums=0;
    int xm = x < x1 ? x : x1;
    int xa = x > x1 ? x : x1;
    int ym = y < y1 ? y : y1;
    int ya = y > y1 ? y : y1;
    for (int i = xm;i <= xa;i++) {
        if (inputMap[i][ya] == 'X')xsums+= 1;
        else xsums += inputMap[i][ya] - '0';
    }
        for (int j =ym;j <= ya;j++) {
            if (inputMap[xm][j] == 'X')ysums += 1;
            else ysums += inputMap[xm][j] - '0';
        }
    return int(sqrt(pow(xsums, 2) + pow(ysums, 2)));
}
int ManhattanDis(int x, int y, int x1, int y1, const vector<vector<char>> inputMap) {

    int sums = 0;
    int xm = x < x1 ? x : x1;
    int xa = x > x1 ? x : x1;
    int ym = y < y1 ? y : y1;
    int ya = y > y1 ? y : y1;
    for (int i = xm;i <= xa;i++) {
        if (inputMap[i][y] == 'X')sums += 1;
        else sums += inputMap[i][y] - '0';
    }
    for (int j = ym;j <= ya;j++) {
        if (inputMap[xa][j] == 'X')sums += 1;
        else sums += inputMap[xa][j] - '0';
    }
    return sums;
}
bool NodeIsLegal(int x, int y, int xx, int yy,vector<vector<char>> inputMap) {
    if (x < 0 || x >= xmax || y < 0 || y >= ymax) return false; // find boundary
    if (inputMap[x][y] == 'X')return false;

    if (x != xx && y != yy && (inputMap[x][yy] == 'X' || inputMap[xx][y] == 'X')) return false;
    return true;
}
void A_algorithm(int x0, int y0, int x1, int y1, const vector<vector<char>> inputMap,
                 eMode mode, eHeuristic heuristic) {

    Node node(x0, y0);
    node.G = 0;
    if (heuristic == StraightLine)node.H = Straightline(x0, y0, x1, y1, inputMap);
    else node.H = ManhattanDis(x0, y0, x1, y1, inputMap);

    node.F = node.G + node.H;
    valF[x0][y0] = node.F;
    que.push(node);
    while (!que.empty()) {
        Node node_top = que.top(); que.pop();
        visited[node_top.x][node_top.y] = 1; 
        if (node_top.x == x1 && node_top.y == y1)
            break;
        for (int i = node_top.x - 1;i <= node_top.x + 1;i++)
            for (int j = node_top.y - 1;j <= node_top.y + 1;j++) {
                if (!NodeIsLegal(i, j, node_top.x, node_top.y, inputMap) ||
                (i == node_top.x) && (j == node_top.y) || visited[i][j])
                    continue;
                Node node_next(i, j); 
                if (heuristic == StraightLine) {
                    
                    node_next.G = node_top.G + int(sqrt(pow(inputMap[node_top.x][node_top.y]
                            - inputMap[node_top.x][node_next.y], 2)
                                    + pow(inputMap[node_top.x][node_top.y]
                                    - inputMap[node_next.x][node_top.y], 2)));
                    
                    node_next.H = Straightline(node_next.x, node_next.y, x1, y1, inputMap);
                }
                else {
                    
                    node_next.G = node_top.G + abs(inputMap[node_top.x][node_top.y]
                            - inputMap[node_top.x][node_next.y])
                                    + abs(inputMap[node_top.x][node_top.y]
                                    - inputMap[node_next.x][node_top.y]);
                
                    node_next.H = ManhattanDis(node_next.x, node_next.y, x1, y1, inputMap);
                }
                
                node_next.F = node_next.G + node_next.H;
                // node_next.F < valF[node_next.x][node_next.y] find optimal path and update
                // valF[node_next.x][node_next.y] == 0 update list
                if (node_next.F < valF[node_next.x][node_next.y] || valF[node_next.x][node_next.y] == 0) {
                    
                    path[node_next.x][node_next.y][0] = node_top.x;
                    path[node_next.x][node_next.y][1] = node_top.y;
                    valF[node_next.x][node_next.y] = node_next.F; // change valF
                    que.push(node_next); // append open list
                }
            }
    }
}
void print_path(int x0, int y0, int x1, int y1,vector<vector<char>>& outputMap,eMode mode) {
        if (path[x1][y1][0] == -1 || path[x1][y1][1] == -1) { //no path
            cout << "No solution!" << endl;
            return;
        }
        int x = x1, y = y1;
        int a, b;
        cout << "path:";
        while (x != -1 || y != -1) {

            outputMap[x][y] = '+'; // '+' for other nodes along the path
            a = path[x][y][0];
            b = path[x][y][1];
            path1.push_back({ b,a });
            x = a;
            y = b;
        }
        outputMap[x0][y0] = 's';
        outputMap[x1][y1] = 'd';
        x = x0;
        y = y0;
        for (int i = path1.size() - 2;i >= 0;i--) {
            cout << '(' << path1[i].x << ',' << path1[i].y << ')' <<" ";
        }
        if (mode != Standard) {
            while (!que.empty()) {
                Node a = que.top();
                que.pop();
                if(outputMap[a.x][a.y] != '+'&&outputMap[a.x][a.y] != 's'&&outputMap[a.x][a.y] != 'd')
                outputMap[a.x][a.y] = 'e';
            }
        }
        if (mode == All) {
            for (int i = 0;i < xmax;i++)
                for (int j = 0;j < ymax;j++)
                    if (visited[i][j]&&outputMap[i][j]!='+'&&outputMap[i][j] != 'd'&&outputMap[i][j] != 's')
                        outputMap[i][j] = 't';
        }
    }
void PlanPath(const vector<vector<char>>& inputMap, int start[2],
              int destination[2], eMode mode, eHeuristic heuristic) {
        // Start the timer
        using namespace chrono;
        steady_clock::time_point clock_begin = steady_clock::now();
        ymax = inputMap[0].size();
        xmax = inputMap.size();
        int xx= xmax-1 - start[1];
        start[1] = start[0];
        start[0] =xx;
        xx= xmax-1 - destination[1];
        destination[1] = destination[0];
        destination[0] = xx;
        for (int i = 0;i <= xmax;i++) {
            for (int j = 0; j <= ymax; j++) {
                path[i][j][0] = -1;
                path[i][j][1] = -1;
            }
        }
        for (int i = 0;i <= xmax;i++) {
            for (int j = 0; j <= ymax; j++) {
                visited[i][j] = 0;
                valF[i][j] = 0;
            }
        }
        A_algorithm(start[0], start[1], destination[0], destination[1], inputMap, mode, heuristic);
        // Stop the timer
        steady_clock::time_point clock_end = steady_clock::now();
        steady_clock::duration time_span = clock_end - clock_begin;
        double seconds = double(time_span.count()) * steady_clock::period::num / steady_clock::period::den;

        cout << endl;
        cout << "It took " << seconds << " seconds.";
        cout << endl;
        // Annotate & print the output map
        vector<vector<char>> outputMap = inputMap;
        print_path(start[0],start[1],destination[0], destination[1],outputMap, mode);
        cout << endl;
        cout << "the output map is:";
        cout << endl;
        PrintMap(outputMap);
    }

int main()
{
    vector<vector<char>> inputMap;
    string loc;
    string modeType, heuristicType;
    int start[2], end[2];

    cout << "Enter the location of the file:";
    cin >> loc;
    readMap(loc, inputMap);

    cout << endl;
    cout << "the input map is:\n";
    PrintMap(inputMap);

    cout << endl;
    cout << "Enter the mode:";
    cin >> modeType;
    eMode mode = convertMode(modeType);

    cout << endl;
    cout << "Enter the heuristic:";
    cin >> heuristicType;
    eHeuristic heuristic = convertHeuristic(heuristicType);

    cout << endl;
    cout << "Start x coordinate:";
    cin >> start[0];
    cout << "Start y coordinate:";
    cin >> start[1];

    cout << endl;
    cout << "End x coordinate:";
    cin >> end[0];
    cout << "End y coordinate:";
    cin >> end[1];
    PlanPath(inputMap, start, end, mode, heuristic);
}
