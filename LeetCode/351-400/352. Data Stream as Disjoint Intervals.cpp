class SummaryRanges 
{
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    vector<Interval>res;
    void addNum(int val)
    {
        Interval cur(val, val);
        int pos = 0;
        vector<Interval>r;
        for (auto it : res)
        {
            if (it.end + 1 < cur.start)
            {
                pos++;
                r.push_back(it);
            }
            else if (cur.end + 1 < it.start)
            {
                r.push_back(it);
            }
            else if (it.end + 1 == cur.start)
            {
                cur.start = min(cur.start, it.start);
            }
            else if (cur.end + 1 == it.start)
            {
                cur.end = max(cur.end, it.end);
            }
            else
            {
                cur.start = min(cur.start, it.start);
                cur.end = max(cur.end, it.end);
            }
        }
        r.insert(r.begin() + pos, cur);
        res = r;
    }

    vector<Interval> getIntervals() 
    {
        return res;
    }
};