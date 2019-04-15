/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		// lambda sort根据start进行排序
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {return a.start < b.start;});
        vector<Interval> res;
        int len = intervals.size();
        int len1 = 0;
		
		for(int i = 0; i < len; i++)
		{
			if(len1 == 0)
			{
				res.emplace_back(intervals[0]);
				len1++;
			}
			else{
				// 最小的比最大的大
				int j = len1-1;
				if(intervals[i].start > res[j].end)
				{
					res.emplace_back(intervals[i]);
					len1++;
				}
				// 最大比最小的小
				else if(intervals[i].end < res[j].start)
				{
					res.emplace_back(intervals[i]);
					len1++;
				}
				// 合并
				else{
					res[j].start = res[j].start <= intervals[i].start ? res[j].start : intervals[i].start;
					res[j].end = res[j].end >= intervals[i].end ? res[j].end : intervals[i].end;
				}
			}
		}
        return res;
    }
};