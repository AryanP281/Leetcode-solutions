
#include<bits/stdc++.h>

using namespace std;

struct Robot
{
    int id;
    int pos;
    int health;
    char dir;

    Robot(int id, int pos, int health, char dir)
    {
        this->id = id;
        this->pos = pos;
        this->health = health;
        this->dir = dir;
    }
};

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions);

int main()
{

    vector<int> pos = {1,2,5,6};
    vector<int> healths = {10,10,11,11};
    string dir = "RLRL";

    survivedRobotsHealths(pos, healths, dir);

    getchar();

    return 0;
}

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
{
    vector<struct Robot*> robots;
    map<int,struct Robot*> aliveRobots;
    for(int i = 0; i < positions.size(); ++i)
    {
        Robot* robot = new Robot(i, positions[i], healths[i], directions[i]);
        robots.push_back(robot);
        aliveRobots[i] = robot;
    }

    sort(robots.begin(), robots.end(), [](Robot* r1, Robot* r2) -> bool {
        return r1->pos < r2->pos;
    });

    stack<struct Robot*> rightMovers;
    for(int i = 0; i < robots.size(); ++i)
    {
        if(robots[i]->dir == 'R')
            rightMovers.push(robots[i]);
        else
        {
            while(!rightMovers.empty() && robots[i]->health)
            {
                if(rightMovers.top()->health < robots[i]->health)
                {
                    aliveRobots.erase(rightMovers.top()->id);
                    rightMovers.pop();
                    robots[i]->health--;
                }
                else if(rightMovers.top()->health == robots[i]->health)
                {
                    rightMovers.top()->health = 0;
                    robots[i]->health = 0;
                }
                else
                {
                    rightMovers.top()->health--;
                    robots[i]->health = 0;
                }
            }

            if(robots[i]->health <= 0)
                aliveRobots.erase(robots[i]->id);
            if(!rightMovers.empty() && rightMovers.top()->health <= 0)
            {
                aliveRobots.erase(rightMovers.top()->id);
                rightMovers.pop();
            }
        }
    }

    vector<int> result;
    for(map<int,struct Robot*>::iterator itr = aliveRobots.begin(); itr != aliveRobots.end(); itr++)
    {
        result.push_back(itr->second->health);
    }

    for(int i = 0; i < robots.size(); ++i)
    {
        delete robots[i];
    }

    return result;
}