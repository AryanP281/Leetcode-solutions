
#include<bits/stdc++.h>

using namespace std;

int numDistinct(string s, string t);

int main()
{
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";

    cout << numDistinct(s, t);

    getchar();

    return 0;
}

int numDistinct(string s, string t) 
{
    double** dp = new double*[s.size()+1];
    for(int i = 0; i < s.size()+1; ++i)
    {
        dp[i] = new double[t.size()+1]();
        dp[i][t.size()] = 1;
    }

    for(int r = s.size()-1; r >= 0; --r)
    {
        for(int c = t.size()-1; c >= 0; --c)
        {

            dp[r][c] = dp[r+1][c] + ((double)(s[r] == t[c]))*dp[r+1][c+1];
        }
    }

    int subsequenceCount = (int)dp[0][0];

    for(int r = 0; r <= s.size(); ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return subsequenceCount;
}
