#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    string result = s;
    int length = 0;
    bool finished = false;
    for(int i = 0; i < s.size()/2; i++)
    {
        finished = true;
        length = result.size();
        for(int j = 0; j < length - 1; j++)
        {
            if(result[j] == result[j+1]){
                result.erase(j, 2);
                finished = false;
                length -= 2;
            }
        }
        if (finished)
            break;
    }
    
    if(result.size() == 0)
        result = "Empty String";
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
