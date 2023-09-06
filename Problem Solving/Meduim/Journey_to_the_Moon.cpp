#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    long long int result = 0;
    int i, j, k;
    vector<vector<int>> countries;
    
    int IDs = 0;  // number of IDs pushed in countries
    int found;    // number of found elments of each pair could be 0 or 1 or 2
    int order;    // order of found element could be 0 or 1
    int index[2]; // index of the found elments of each pair
    
    /* Fill each country with its astronauts */
    for(i=0; i<int(astronaut.size()); i++)
    {
        found = 0;

        for(j=0; j<int(countries.size()); j++)
        {
            for(k=0; k<int(countries.at(j).size()); k++)
            {
                if(astronaut.at(i).at(0) == countries.at(j).at(k)){
                    found++;
                    index[0] = j;
                    order = 0;
                }
                else if(astronaut.at(i).at(1) == countries.at(j).at(k)){
                    found++;
                    index[1] = j;
                    order = 1;
                }
                if(found == 2)
                    break;
            }
            if(found == 2)
                break;
        }

        if(found == 0)
        {
            vector<int> pair = {astronaut.at(i).at(0), astronaut.at(i).at(1)};
            countries.push_back(pair);
            IDs += 2;
        }
        else if(found == 1)
        {
            if(order == 0)
                countries.at(index[0]).push_back(astronaut.at(i).at(1));
            else
                countries.at(index[1]).push_back(astronaut.at(i).at(0));
            IDs++;
        }
        else
        {
            if(index[0] != index[1])
            {
                // Merge the two countries
                for(j=0; j<countries.at(index[0]).size(); j++)
                    countries.at(index[1]).push_back(countries.at(index[0]).at(j));
                countries.erase(countries.begin() + index[0]);
            }
        }

    }
    
    /* Array for number of astronauts in each country */
    vector<int> arr(countries.size());
    for(i=0; i<countries.size(); i++)
        arr.at(i) = countries.at(i).size();
    
    /* Calculate the number of possibilities */
    for(i=0; i<int(arr.size()); i++)
    {
        for(j=i+1; j<int(arr.size()); j++)
            result += (arr.at(i) * arr.at(j));
        result += (arr.at(i) * (n-IDs));
    }
    long long int temp = n - IDs - 1;
    if(temp != 0){
        if(temp % 2 == 0)
            result += ((temp+1)*(temp/2));
        else
            result += ((temp+1)*(temp/2)+((temp+1)/2));
    }
    return result;                             
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

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
