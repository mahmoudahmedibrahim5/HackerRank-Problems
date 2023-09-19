#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    /* 1- Remove Spaces */
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int length = s.size();
    
    /* 2- Calculate Row and column */
    int row, column;
    column = ceil(sqrt(length));
    row = ceil((double)length/(double)column);
    
    /* 3- Split the unspaced string to grid(array of strings) */
    string lines[row];
    for(int i = 0; i < length; i++)
        lines[i/column].push_back(s[i]);

    /* 4- Encryption */
    int lenOfLastString = lines[row-1].size();
    string result;    
    for(int i = 0; i < column; i++){
        if(i == lenOfLastString)
            row--;
        for(int j = 0; j < row; j++)
            result.push_back(lines[j][i]);
        result.push_back(' ');
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
