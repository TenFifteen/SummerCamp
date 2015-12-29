/*
题目大意：
给定一个整数，然后将其转化为罗马数字表示。

解题思路：
罗马数字是由1、5、10、50、100、500、1000这些字符组成的。然后表示规则就是：
对于1-3：用三个连着的1
对于4：用5-1
对于5：5
对于5-8：用5+。。。
对于9：用10-1
然后从前往后的处理每个数字就可以了。

遇到的问题：
本来这个题目原来是不会的。结果今天查了一下百度。感觉应该就是这样贪心下来的。就试了一下，结果
竟然对了。

再次阅读：
这个题目已经做过两次了。也该记住了。
虽然之前感觉自己做的有些麻烦，不知道怎么改进代码。
看了DISCUSS里面，有一种解法是用空间来换时间，见下面代码（java）：
String[] romanPieces={"","I","II","III","IV","V","VI","VII","VIII",
"IX", "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC", "","C",
"CC","CCC","CD","D","DC","DCC","DCCC","CM", "","M","MM","MMM","MMMM"}; 
return romanPieces[num/1000+30]+
romanPieces[(num/100)%10+20] +
romanPieces[(num/10)%10+10]+
romanPieces[num%10];
*/
class Solution {
public:
    string intToRoman(int num) {
        map<int,char> table;
        table[1] = 'I';
        table[5] = 'V';
        table[10] = 'X';
        table[50] = 'L';
        table[100] = 'C';
        table[500] = 'D';
        table[1000] = 'M';
        string ans;
        int len = 0;
        int tmp = num;
        while(tmp){
            len++;
            tmp /= 10;
        }
        tmp = 1;
        for(int i = 1; i < len; ++i){
            tmp *= 10;
        }
        for(int i = 0; i < len; ++i){
            int cur = num / tmp;
            if(cur == 9){
                ans.push_back(table[tmp]);
                ans.push_back(table[tmp*10]);
            }else if(cur >= 5){
                ans.push_back(table[tmp*5]);
                for(int j = 0; j < cur-5; ++j){
                    ans.push_back(table[tmp]);
                }
            }else if(cur == 4){
                ans.push_back(table[tmp]);
                ans.push_back(table[tmp*5]);
            }else{
                for(int j = 0; j < cur; j++){
                    ans.push_back(table[tmp]);
                }
            }
            num %= tmp;
            tmp /= 10;
        }
        return ans;
    }
};