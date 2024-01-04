#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kingdomDivision' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY roads
 */
 int length;
long long recursive(vector<vector<int>> connections, vector<bool> red){
    if(red.size() == length)
    {
        bool fail;
        for(int i = 0; i < length; i++)
        {
            fail = true;
            for(int j = 0; j < (int)connections[i].size(); j++){
                if(red[connections[i][j]-1] == red[i]){
                    fail = false;
                    break;
                }
            }
            if(fail)
                return 0;
        }
        // cout << "Passed at red[] = ";
        // for(int i = 0; i < length; i++)
        //     cout << red[i] << " ";
        // cout << endl;
        return 1;
    }
    else
    {
        vector<bool>addBlue = red;
        addBlue.push_back(false);
        vector<bool>addRed = red;
        addRed.push_back(true);
        
        return recursive(connections, addRed) + recursive(connections, addBlue);
    } 
}

int kingdomDivision(int n, vector<vector<int>> roads) {
    vector<bool> red;
    length = n;
    vector<vector<int>> connections(n);
    for(int i = 0; i < n; i++)
    {
        vector<int> c;
        for(int j = 0; j < (int)roads.size(); j++)
        {
            if(roads[j][0] == i + 1)
                c.push_back(roads[j][1]);
            else if(roads[j][1] == i + 1)
                c.push_back(roads[j][0]);
        }
        connections[i] = c;
    }
    // for(int i = 0; i < (int)connections.size(); i++){
    //     cout << "connections of " << i + 1 << " are = ";
    //     for(int j = 0; j < connections[i].size(); j++)
    //         cout << connections[i][j] << " ";
    //     cout << endl;
    // }
    long long result = 0;
    result = recursive(connections, red);
    int r = result%1000000007;
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> roads(n - 1);

    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(2);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int result = kingdomDivision(n, roads);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
