#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    vector<vector<int>> a;

    Matrix& operator+(Matrix& x){
        Matrix result;
        int rows = (int)x.a.size();
        int columns = (int)x.a[0].size();
        vector<int> row(columns);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
                row[j] = this->a[i][j] + x.a[i][j];
            result.a.push_back(row);
        }
        return result;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Matrix x, y, result;

        int n, m;
        cin >> n >> m;

        vector<int> row(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cin >> row[j];
            x.a.push_back(row);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cin >> row[j];
            y.a.push_back(row);
        }

        result = x + y;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << result.a[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}
