
#include<bits/stdc++.h>

using namespace std;

int calPoints(vector<string>& ops);

int main()
{
    vector<string> ops = {"1"};
    cout << calPoints(ops);

    getchar();
    return 0;
}

int calPoints(vector<string>& ops) 
{
    stack<int> records;

    for(int a = 0; a < ops.size(); ++a)
    {
        if(isdigit(ops[a][0]) || ops[a][0] == '-')
            records.push(stoi(ops[a]));
        else
        {
            if(ops[a][0] == '+')
            {
                int last = records.top();
                records.pop();
                int secondLast = records.top();
                records.pop();
                int newRecord = last + secondLast;

                records.push(secondLast);
                records.push(last);
                records.push(newRecord);
            }
            else if(ops[a][0] == 'C')
                records.pop();
            else
                records.push(records.top()*2);
        }
    }

    int score = 0;
    while(!records.empty())
    {
        score += records.top();
        records.pop();
    }

    return score;
}