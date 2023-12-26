#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    int n = (int)s1.size();

    int** table = new int*[n];
    table[0] = new int[n];
    
    /* Fill the first row of the table */
    bool found = false;
    for(int j = 0; j < n; j++)
    {
        if(s1[0] == s2[j] || found){
            table[0][j] = 1;
            found = true;
        }
        else
            table[0][j] = 0;
    }
    
    /* Fill the first column of the table */
    found = false;
    for(int i = 1; i < n; i++)
    {
        table[i] = new int[n];
        if(s1[i] == s2[0] || found){
            table[i][0] = 1;
            found = true;
        }
        else
            table[i][0] = 0;
    }
    
    /* Fill the rest of the table */
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {   
            if(s1[i] == s2[j]){
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else{
                if(table[i - 1][j] > table[i][j - 1])
                    table[i][j] = table[i - 1][j];
                else
                    table[i][j] = table[i][j - 1];
            }
        }
    }
    int result = table[n - 1][n - 1];
    
    /* Free the allocated memory */
    for(int i = 0; i < n; i++)
        delete[] table[i];
    delete[] table;
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
