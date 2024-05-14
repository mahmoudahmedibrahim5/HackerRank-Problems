#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'maxPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skillLevel
 *  2. INTEGER minDiff
 */

int maxPairs(vector<int> skillLevel, int minDiff) {
    int n = skillLevel.size();
    sort(skillLevel.begin(), skillLevel.end());
    
    int last = -1, i, j;
    for(i = 0; i < n; i++)
    {
        if((skillLevel[n - 1] - skillLevel[i]) < minDiff){
            last = i;
            break;
        }
    }
    int pairs = 0;
    i = last;
    j = n - 1;
    
    while(i >= 0)
    {
        if((skillLevel[j] - skillLevel[i]) >= minDiff){
            pairs++;
            j--;
            i--;
        }
        else{
            i--;
        }
    }
    if(pairs > n/2)
        pairs = n / 2;
    
    return pairs;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string skillLevel_count_temp;
    getline(cin, skillLevel_count_temp);

    int skillLevel_count = stoi(ltrim(rtrim(skillLevel_count_temp)));

    vector<int> skillLevel(skillLevel_count);

    for (int i = 0; i < skillLevel_count; i++) {
        string skillLevel_item_temp;
        getline(cin, skillLevel_item_temp);

        int skillLevel_item = stoi(ltrim(rtrim(skillLevel_item_temp)));

        skillLevel[i] = skillLevel_item;
    }

    string minDiff_temp;
    getline(cin, minDiff_temp);

    int minDiff = stoi(ltrim(rtrim(minDiff_temp)));

    int result = maxPairs(skillLevel, minDiff);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
