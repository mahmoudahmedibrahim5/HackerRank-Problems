#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene) {
    int n = gene.size();
    int count[4] = {0, 0, 0, 0};
    for(int i = 0; i < n; i++)
    {
        if(gene[i] == 'A')
            count[0]++;
        else if(gene[i] == 'C')
            count[1]++;
        else if(gene[i] == 'G')
            count[2]++;
        else if(gene[i] == 'T')
            count[3]++;
    }
    
    int requiredLen = 0;
    for(int i = 0; i < 4; i++){
        
        if(count[i] > (n / 4))
            count[i] -= (n / 4);
        else
            count[i] = 0;
        requiredLen += count[i];
    }
    
    bool pass = false;
    while (requiredLen <= n) 
    {
        int subCount[4] = {0, 0, 0, 0};
        for(int i = 0; i < requiredLen; i++)
        {
            if(gene[i] == 'A')
                subCount[0]++;
            else if(gene[i] == 'C')
                subCount[1]++;
            else if(gene[i] == 'G')
                subCount[2]++;
            else if(gene[i] == 'T')
                subCount[3]++;
        }
        pass = true;
        for(int j = 0; j < 4; j++)
        {
            if(subCount[j] < count[j]){
                pass = false;
                break;
            }
        }
        if(pass)
            return requiredLen;
        
        for (int i = requiredLen; i < n; i++) 
        {
            if(gene[i - requiredLen] == gene[i])
                continue;
            if(gene[i - requiredLen] == 'A')
                subCount[0]--;
            else if(gene[i - requiredLen] == 'C')
                subCount[1]--;
            else if(gene[i - requiredLen] == 'G')
                subCount[2]--;
            else if(gene[i - requiredLen] == 'T')
                subCount[3]--;   
                
            if(gene[i] == 'A')
                subCount[0]++;
            else if(gene[i] == 'C')
                subCount[1]++;
            else if(gene[i] == 'G')
                subCount[2]++;
            else if(gene[i] == 'T')
                subCount[3]++;
            
            pass = true;
            for(int j = 0; j < 4; j++)
            {
                if(subCount[j] < count[j]){
                    pass = false;
                    break;
                }
            }
            if(pass)
                return requiredLen;
        }
        requiredLen++;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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
