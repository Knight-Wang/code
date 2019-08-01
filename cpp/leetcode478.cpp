class Solution
{
public:
    double _radius, _x_center, _y_center;
    Solution(double radius, double x_center, double y_center)
    {
        _radius = radius; _x_center = x_center; _y_center = y_center;
    }
    vector<double> randPoint()
    {
        double x, y;
        do
        {
            x = rand() / double(RAND_MAX);
            y = rand() / double(RAND_MAX);
        } while (x * x + y * y > 1);
        if (rand() % 2) x = -x;
        if (rand() % 2) y = -y;
        x *= _radius; y *= _radius;
        x += _x_center; y += _y_center;
        vector<double> res; res.push_back(x); res.push_back(y);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */