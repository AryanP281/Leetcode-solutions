
#include<bits/stdc++.h>

using namespace std;

int countCollisions(string directions);

int main()
{
    string dir = "LLRR";
    cout << countCollisions(dir);

    getchar();
    return 0;
}

int countCollisions(string directions) 
{
    stack<char> prevCars;

    int collisions = 0;
    for(int i = 0; i < directions.size(); ++i)
    {
        char curr = directions[i];
        while(prevCars.size())
        {
            char top = prevCars.top();
            prevCars.pop();
            if(top == 'R' && curr == 'L')
            {
                collisions += 2;
                curr = 'S';
            }
            else if((top == 'S' && curr == 'L') || (top == 'R' && curr == 'S'))
            {
                collisions++;
                curr = 'S';
            }
            else
            {
                prevCars.push(top);
                break;
            }
        }
        
        prevCars.push(curr);
    }

    return collisions;
}