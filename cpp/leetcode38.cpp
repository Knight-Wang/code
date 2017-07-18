class Solution 
{
public:
    string countAndSay(int n) 
    {
        string x = "1", y = "";
        int index = 0, cnt = 1;
        for (int j = 1; j < n; j++)
        {
            int index = 0, cnt = 0;
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] != x[index])
                {
                    char tmp[100]; sprintf(tmp, "%d", cnt); cnt = 1;
                    string str = string(tmp);
                    y.append(str);
                    y += x[index];
                    index = i;
                }
                else cnt++;
            }
            if (cnt)
            {
                char tmp[100]; sprintf(tmp, "%d", cnt); cnt = 0;
                string str = string(tmp);
                y.append(str);
                y += x[index];
            }
            x = y;
            y = "";
        }
        return x;
    }
};