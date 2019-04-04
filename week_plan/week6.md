## week6_question

leetcode40~45

## week6_exercise

leetcode周赛130

## week6_shared

这周分享一道题leetcode44，我暂时没看其他的做法，还不知道自己的做法多傻逼ヾ(｡ꏿ﹏ꏿ)ﾉﾞ，一大波代码来袭:fist_oncoming:

```c++
class Solution {
public:
    // 得到next数组
    void getNext(string ss, int *next)
    {
        int j = 0, k = -1;
        next[0] = -1;
        while(j < ss.size() - 1) {
            if(k == -1 || ss[j] == ss[k] || ss[k] == '?') {	// 注意这里问号也是满足要求的
                j++;
                k++;
                next[j] = k;
            }
            else{
                k = next[k];
            }
        }
    }
    // kmp算法，注意这是返回s中第一次出现ss的index，因为下面有需要的是s中最后一次出现ss的index
    int kmp(string s, string ss)	
    {
        int len_s = s.size();
        int len_ss = ss.size();
        int i = 0, j = 0;
        int *next = new int[len_ss];
        getNext(ss, next);
        while(i < len_s) {
            if(j == -1 || s[i] == ss[j] ||ss[j] == '?') {	// 同样注意这里问号也满足匹配要求的
                i++;
                j++;
            }
            else {
                j = next[j];	
            }
            if (j == len_ss)
                return i - len_ss;
        }
        return -1;
    }
    // 好了，正文开始ヽ(￣▽￣)و
    bool isMatch(string s, string p) {
        if(p == "*")
            return true; 
        int len_p = p.size();
        set<int> s_p {};
        for(int i = 0; i < len_p - 1; i++)
        {
            if(p[i] == '*')
                s_p.insert(i);
            if(p[i] == '*'&& p[i+1] == '*')
            {
                p.erase(i, 1);
                i--;
                len_p--;	
            }	
        } 
        if(p[len_p-1] == '*')
            s_p.insert(len_p-1);
        auto iter1 = s_p.begin();
        auto iter2 = s_p.end();
        int count = 0; // count *
        for(auto p = iter1; p != iter2; p++)
        {
            count++;
        }
        if(count == 0) {
            if(s == ""&& p =="")
                return true;
            else if(s == ""|| p == "")
                return false;
            else if(s.size() != p.size() || kmp(s, p) != 0) {
                return false;
            }
            else{
                return true;
            }
        }
        int len_s = s.size();
        int len_x = len_s - (len_p - count);	// * 代表的总长度 
        if(len_x < 0)
            return false;
        else{
            // 集合中*的index放入数组中
            int *index = new int [count]; 
            int i = 0; 
            for(auto p = iter1; p != iter2; p++)
            {
                index[i] = *p;
                i++;
            } 
            // 以 * 将 p 串分割为 不同的 子串 s1, s2, s3…… 
            // 如果首尾都有 *
            if(count > 1&& index[0] == 0&& index[count-1] == len_p-1)
            {
                if(count == 2)
                {
                    p = p.erase(0, 1);
                    p = p.erase(p.size() - 1, 1);
                    if(kmp(s, p) != -1)
                        return true;
                    else
                        return false;
                }
                string str {};
                str = p.substr(1, index[1] - 1);
                int index_sub = kmp(s, str);
                if(index_sub == -1)
                    return false;
                else{
                    p = p.erase(0, index[1]);
                    s = s.erase(0, index_sub + str.size());
                    return isMatch(s, p);
                }
            } 
            // 如果首有 *，尾没有 * 
            if(index[0] == 0&& index[count-1] != len_p-1) {
                if(count == 1)
                {
                    string s1{s.rbegin(), s.rend()};
                    p = p.erase(0, 1);
                    string p1{p.rbegin(), p.rend()};
                    if(kmp(s1, p1) == 0)
                        return true;
                    else
                        return false;
                }
                else{ // 至少有两个 * 
                    string temp = p.substr(index[count-1] + 1, len_p - 1 - index[count-1]);
					// 反转字符串，调用kmp函数，再用长度相减这就获得了s中最后一次出现ss的位置
                    string temp1(temp.rbegin(), temp.rend());	
                    string s1(s.rbegin(), s.rend());

                    int index_last = s.size() - 1 - (kmp(s1, temp1) + temp1.size() - 1);
                    if(index_last == -1|| index_last + temp.size() != s.size())
                    {
                        return false;
                    }
                    else{
                        s = s.erase(index_last, temp.size());
                        p = p.erase(index[count-1] + 1, temp.size());
                        return isMatch(s, p);
                    }
                }
            }
            // 如果尾有 *，首没有 * 
            if(index[0] != 0&& index[count-1] == len_p-1) {
                if(count == 1)
                {
                    if(kmp(s, p.erase(index[count-1], 1)) == 0)
                        return true;
                    else
                        return false;
                }
                else {
                    string temp = p.substr(0, index[0]);
                    int index_first = kmp(s, temp);
                    if(index_first == -1|| index_first != 0)
                    {
                        return false;
                    }
                    else{
                        s = s.erase(0, temp.size());
                        p = p.erase(0, temp.size());
                        return isMatch(s, p);  
                    }
                }
            }
            // 如果首尾都没有 *
            if(index[0] != 0&& index[count-1] != len_p-1)
            {
                string temp1 = p.substr(0, index[0]);
                int index_first = kmp(s, temp1);
                string temp2 = p.substr(index[count-1] + 1, len_p - 1 - index[count-1]);

                string temp3(temp2.rbegin(), temp2.rend()); 
                string s1(s.rbegin(), s.rend());

                int index_last = s.size() - 1 - (kmp(s1, temp3) + temp3.size() - 1);	 
                if(index_last == -1|| index_first == -1|| index_first != 0|| index_last + temp2.size() != s.size())
                {
                    return false;
                }
                s = s.erase(0, temp1.size());
                p = p.erase(0, temp1.size());
                s = s.erase(index_last - temp1.size(), temp2.size());
                p = p.erase(index[count-1] + 1 - temp1.size(), temp2.size());
                return isMatch(s, p);
            }
        } 
        return true;
    }
};
```

其实不建议大家读这又臭又长的代码，但是这周分享的也就这些了。

I should do better next week and share something have good quality.