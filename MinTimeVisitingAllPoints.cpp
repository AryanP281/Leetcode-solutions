/*#include<iostream>
#include<math.h>
#include <vector>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points);
vector<float> getDirVec(vector<int>& start, vector<int>& end);
float getDistance(vector<int>& pt1, vector<int>& pt2);

void main()
{
    vector<vector<int>> points;
    points.push_back(vector<int>());
    points[0].push_back(1);
    points[0].push_back(1);
    points.push_back(vector<int>());
    points[1].push_back(3);
    points[1].push_back(4);
    points.push_back(vector<int>());
    points[2].push_back(-1);
    points[2].push_back(0);

    cout << minTimeToVisitAllPoints(points);
}

int minTimeToVisitAllPoints(vector<vector<int>>& points)
{
    vector<float>* stdDirVecs = new vector<float>[4];
    stdDirVecs[0].push_back(1.0f);
    stdDirVecs[0].push_back(0.0f);
    stdDirVecs[1].push_back(0.0f);
    stdDirVecs[1].push_back(1.0f);
    stdDirVecs[2].push_back(1.0f);
    stdDirVecs[2].push_back(1.0f);
    stdDirVecs[3].push_back(0.0f);
    stdDirVecs[3].push_back(0.0f);

    vector<int> currentPos = points[0];
    int nextPosIndex = 1;
    int time = 0;

    while (true)
    {
        vector<float>dirVec = getDirVec(currentPos, points[nextPosIndex]);

        if (dirVec == stdDirVecs[3])
        {
            if (nextPosIndex == points.size() - 1) break;
            ++nextPosIndex;
            continue;
        }
        else if (abs(dirVec[0]) == stdDirVecs[0][0] && abs(dirVec[1]) == stdDirVecs[0][1])
        {
            float distance = getDistance(currentPos, points[nextPosIndex]);
            time += floor(distance);
            currentPos = points[nextPosIndex];
            continue;
        }
        else if (abs(dirVec[0]) == stdDirVecs[1][0] && abs(dirVec[1]) == stdDirVecs[1][1])
        {
            float distance = getDistance(currentPos, points[nextPosIndex]);
            time += floor(distance);
            currentPos = points[nextPosIndex];
            continue;
        }
        else if (abs(dirVec[0]) == stdDirVecs[2][0] && abs(dirVec[1]) == stdDirVecs[2][1])
        {
            float distance = getDistance(currentPos, points[nextPosIndex]);
            time += floor(distance) / sqrt(2);
            currentPos = points[nextPosIndex];
            continue;
        }
        else
        {
            currentPos[0] += pow(-1, dirVec[0] < 0);
            currentPos[1] += pow(-1, dirVec[1] < 0);
        }
        time++;
    }
    delete[] stdDirVecs;

    return time;
}

vector<float> getDirVec(vector<int>& start, vector<int>& end)
{
    vector<float> dirVec;
    dirVec.push_back(end[0] - start[0]);
    dirVec.push_back(end[1] - start[1]);

    float mag = sqrt(pow(dirVec[0], 2) + pow(dirVec[1], 2));

    if (mag != 0)
    {
        dirVec[0] /= mag;
        dirVec[1] /= mag;
    }

    return dirVec;
}

float getDistance(vector<int>& pt1, vector<int>& pt2)
{
    float distance = sqrt(pow(pt2[0] - pt1[0], 2) + pow(pt2[1] - pt1[1], 2));
    return distance;
}*/