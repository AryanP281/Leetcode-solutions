
#include<bits/stdc++.h>

using namespace std;

string validIPAddress(string queryIP);
int charFreq(string& str, char ch);
bool checkValidIp4Format(string& str);
bool checkValidIp6Format(string& str);

int main()
{
    string queryIp = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    cout << validIPAddress(queryIp);

    getchar();
    return 0;
}

string validIPAddress(string queryIP) 
{
    int v4Ct = charFreq(queryIP, '.');
    if(v4Ct > 0)
    {
        if(v4Ct != 3 || !checkValidIp4Format(queryIP))
            return "Neither";
        return "IPv4";
    }
    else
    {
        int v6Ct = charFreq(queryIP, ':');
        if(v6Ct != 7 || !checkValidIp6Format(queryIP))
            return "Neither";
        return "IPv6";
    }
}

int charFreq(string& str, char ch)
{
    int freq = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ch)
            freq++;
    }

    return freq;
}

bool checkValidIp4Format(string& str)
{
    str.push_back('.');
    int l = -1;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '.' && i-l >= 2 && i-l <= 4)
        {
            if(str[l+1] == '0' && (i-l) > 2)
                return false;
            int octet = stoi(str.substr(l+1,i-l-1));
            if(octet > 255)
                return false;
            l = i;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            continue;
        }
        else
            return false;
    }
    
    str.pop_back();
    return true;
}

bool checkValidIp6Format(string& str)
{
    str.push_back(':');
    int l = -1;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ':' && i-l >= 2 && i-l <= 5)
        {
            l = i;
        }
        else if((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9'))
        {
            continue;
        }
        else
            return false;
    }
    
    str.pop_back();
    return true;
}