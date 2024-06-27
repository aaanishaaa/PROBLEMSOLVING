#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the rustMurdered function below.
 */
vector<int> rustMurdered(int n, vector<vector<int>> roads, int s)
{
    vector<int> adjlist[n + 1];
    vector<int> newadj[n + 1];
    int m = roads.size();
    for (int i = 0; i < m; i++)
    {
        int a = roads[i][0];
        int b = roads[i][1];
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> DAT(n + 1);
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            int x = adjlist[i][j];
            DAT[x] = 1;
        }
        for (int k = 1; k <= n; k++)
        {
            if (DAT[k] == 0 && k != i)
            {
                newadj[i].push_back(k);
            }
        }
    }
    queue<int> Q;
    int visitedcount = 1;
    vector<int> status(n + 1, 0);
    Q.push(s);
    status[s] = 0;
    while (visitedcount != n)
    {
        int a = Q.front();
        Q.pop();
        vector<long> visited;
        vector<int> Newadj[n + 1];
        vector<int> dat(n + 1, 0);
        for (long j = 0; j < adjlist[a].size(); j++)
        {
            dat[adjlist[a][j]]++;
        }
        for (long k = 1; k <= n; k++)
        {
            if (dat[k] == 0 && k != a)
            {
                {
                    Newadj[a].push_back(k);
                }
            }
        }
        for (auto l : Newadj[a])
        {
            if (visited[l] == -1)
            {
                visited[l] = visited[a] + 1;
                Q.push(l);
                visitedcount++;
                if (visitedcount == n)
                    break;
            }
        }

        vector<int> ans;
        for (long k = 1; k <= n; k++)
        {
            if (visited[k] != 0)
            {
                ans.push_back(visited[k]);
            }
        }
        return ans;
    };

    int main()
    {
        ofstream fout(getenv("OUTPUT_PATH"));
        int s;
        int t;
        cin >> t;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int t_itr = 0; t_itr < t; t_itr++)
        {
            string nm_temp;
            getline(cin, nm_temp);

            vector<string> nm = split_string(nm_temp);

            int n = stoi(nm[0]);

            int m = stoi(nm[1]);

            vector<vector<int>> roads(m);
            for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++)
            {
                roads[roads_row_itr].resize(2);

                for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++)
                {
                    cin >> roads[roads_row_itr][roads_column_itr];
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int s;
            cin >> s;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            vector<int> result = rustMurdered(n, roads, s);

            for (int result_itr = 0; result_itr < result.size(); result_itr++)
            {
                fout << result[result_itr];

                if (result_itr != result.size() - 1)
                {
                    fout << " ";
                }
            }

            fout << "\n";
        }

        fout.close();

        return 0;
    }

    vector<string> split_string(string input_string)
    {
        string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                          { return x == y and x == ' '; });

        input_string.erase(new_end, input_string.end());

        while (input_string[input_string.length() - 1] == ' ')
        {
            input_string.pop_back();
        }

        vector<string> splits;
        char delimiter = ' ';

        size_t i = 0;
        size_t pos = input_string.find(delimiter);

        while (pos != string::npos)
        {
            splits.push_back(input_string.substr(i, pos - i));

            i = pos + 1;
            pos = input_string.find(delimiter, i);
        }

        splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

        return splits;
    }
