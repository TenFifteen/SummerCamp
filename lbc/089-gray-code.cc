/*
题目大意：
给出格雷码的一个顺序。

解题思路：
格雷码的变换规则是，当前变化最后一位，下一次变换最后一个1左边的一位。

遇到的问题：
这个变化规则不知道啊。最后还是看别人的思路才知道格雷码的变换规则是这样的。

再次阅读：
这次依然是没有想出来变化规则，但是看了之后，感觉以后就记住了。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<bool> cur(n, false);
        bool tail = true;
        int now = 0;
        ans.push_back(now);
        for(int i = 0; i < (1 << n)-1; ++i){
            if(tail){
                cur[n-1] = !cur[n-1];
                if(cur[n-1]){
                    now += 1;
                }else{
                    now -= 1;
                }
                tail = false;
            }else{
                int index = n-1;
                while(index >= 0){
                    if(cur[index]){
                        break;
                    }
                    index--;
                }
                cur[index-1] = !cur[index-1];
                if(cur[index-1]){
                    now += 1 << (n-index);
                }else{
                    now -= 1 << (n-index);
                }
                tail = true;
            }
            ans.push_back(now);
        }
        return ans;
    }
};
/*
第二次做：
虽然比较简单，但是做的过程中还是出现了一些小问题。
好处就是这次用的位操作比较多，效率应该是不错的。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        
        int cur = 0;
        for (int i = 0; i < (1 << n); ++i) {
            ans[i] = cur;
            if (i & 0x1) {
                int add = cur - (cur&(cur-1));
                cur ^= (add << 1);
            } else {
                if (cur & 0x1) {
                    cur &= 0xfffffffe;
                } else {
                    cur |= 0x1;
                }
            }
        }
        
        return ans;
    }
};