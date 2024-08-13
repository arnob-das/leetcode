/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (map.find(key) == map.end())
        {
            return "";
        }
        int l = 0;
        int h = map[key].size() - 1;

        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (map[key][mid].first < timestamp)
            {
                l = mid + 1;
            }
            else if (map[key][mid].first > timestamp)
            {
                h = mid - 1;
            }
            else
            {
                return map[key][mid].second;
            }
        }
        if (h >= 0)
        {
            return map[key][h].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
