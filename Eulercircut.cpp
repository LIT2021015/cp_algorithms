
void findpath(vector<vector<int>> &graph, int n, vector<ll> &v1)
{
    vector<int> numofadj;

  
    for (int i = 0; i < n; i++)
        numofadj.push_back(accumulate(graph[i].begin(),
                                      graph[i].end(), 0));

    int startpoint = 0, numofodd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (numofadj[i] % 2 == 1)
        {
            numofodd++;
            startpoint = i;
        }
    }

    stack<int> stack;
    vector<int> path;
    int cur = startpoint;

 
    while (!stack.empty() or
           accumulate(graph[cur].begin(),
                      graph[cur].end(), 0) != 0)
    {
     
        if (accumulate(graph[cur].begin(),
                       graph[cur].end(), 0) == 0)
        {
            path.push_back(cur);
            cur = stack.top();
            stack.pop();
        }

      
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (graph[cur][i] == 1)
                {
                    stack.push(cur);
                    graph[cur][i] = 0;
                    graph[i][cur] = 0;
                    cur = i;
                    break;
                }
            }
        }
    }

    for (auto ele : path)
        v1.pb(ele);
            v1.pb(cur);
}