#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
    if(n == 0 || n == 1)
        return grid;
    else if(n%2 == 0)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i = 0; i < columns; i++)
            grid[0][i] = 'O';
        for(int i = 1; i < rows; i++)
            grid[i] = grid[0];
        return grid;
    }
    else
    {
        int rows = grid.size();
        int columns = grid[0].size();
        
        vector<string> result(rows);
        for (int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < columns; j++)
            {
                if(  grid[i][j] == 'O' 
                || ( (i > 0) && (grid[i - 1][j] == 'O') ) 
                || ( (i < rows - 1) && (grid[i + 1][j] == 'O') ) 
                || ( (j > 0) && (grid[i][j - 1] == 'O') )
                || ( (j < columns - 1) && (grid[i][j + 1] == 'O') )
                )
                    result[i].push_back('.');
                else
                    result[i].push_back('O');
            }
        }
        
        if((n-1)%4==0)
        {
            for (int i = 0; i < rows; i++) 
            {
                for(int j = 0; j < columns; j++)
                {
                    if(  result[i][j] == 'O' 
                    || ( (i > 0) && (result[i - 1][j] == 'O') ) 
                    || ( (i < rows - 1) && (result[i + 1][j] == 'O') ) 
                    || ( (j > 0) && (result[i][j - 1] == 'O') )
                    || ( (j < columns - 1) && (result[i][j + 1] == 'O') )
                    )
                        grid[i][j] = '.';
                    else
                        grid[i][j] = 'O';
                }
            }
            return grid;
        }
        else
            return result;
    }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
