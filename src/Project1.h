#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
typedef struct pos {
    int x, y;
}pos;
class Node
{
public:
    int x, y;
    int F, G, H;
                 // F = G + H 
    Node(int a, int b) :x(a), y(b) {}

    bool operator < (const Node &a) const
    {
        return F > a.F;
    }
};
void static readMap(const std::string& filename, std::vector<std::vector<char>> &PathMap)
{

    std::ifstream file(filename);
    std::vector<char> row;
    std::string input;
    while (file >> input) {
        row.clear();
        for (char i : input) {
            row.push_back(i);
        }
        PathMap.emplace_back(row);
        //PathMap.insert(PathMap.begin(), row);
    }

    //To check if there are equal number of values in each row.
    size_t length = PathMap[0].size();
    for (size_t i = 1; i < PathMap.size(); i++) {
        if (length != PathMap[i].size()) {
            printf("Error in input file.");
            PathMap.clear();
            return;
        }
    }
}

void static PrintMap(std::vector<std::vector<char>> PathMap) {
    for (std::vector<char> name : PathMap)
    {
        for (char c : name)
        {
            std::cout << c;
        }
        std::cout << endl;

    }
}

enum eMode { Standard, Expanded, All };
enum eHeuristic { StraightLine, Manhattan };

eMode convertMode(const std::string str)
{
    if (str == "Standard")
    {
        return Standard;
    }
    else if (str == "Expanded") {
        return Expanded;
    }

    else if (str == "All") {
        return All;
    }
    else throw("illegal value of mode");
}

eHeuristic convertHeuristic(const std::string str)
{
    if (str == "StraightLine")
    {
        return StraightLine;
    }
    else if (str == "Manhattan")
    {
        return Manhattan;
    }

    else throw("Illegal value of heuristic");
}