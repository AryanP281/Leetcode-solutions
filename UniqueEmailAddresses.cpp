/*
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int numUniqueEmails(vector<string>& emails);

void main()
{
    string vals[2] = { "test.email+alex@leetcode.com", "test.email@leetcode.com" };

    vector<string> emails(vals, vals + 2);

    cout << numUniqueEmails(emails);
}

int numUniqueEmails(vector<string>& emails)
{
    unordered_set<string> distinctEmails;
    for (int a = 0; a < emails.size(); ++a)
    {
        string::iterator boundary = emails[a].begin() + emails[a].find('@');
        string localName(emails[a].begin(), boundary);
        string domainName(boundary, emails[a].end());

        string emailAddr = "";
        for (int b = 0; b < localName.size(); ++b)
        {
            if (localName[b] == '+') break;

            if (localName[b] != '.') emailAddr += localName[b];
        }

        emailAddr += domainName;
        distinctEmails.insert(emailAddr);
    }

    return distinctEmails.size();
}
*/