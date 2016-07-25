#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Problem: Given two words(begin word and end word), and a dictionary's word list, find
 *          the length of shortest transformation sequence from begin word to end word.
 * Solve: BFS/bi-BFS, we can construct the edge by iterator the word length and 26 character(which is
 *        26|W|, because hash set is O(1)) other than iterator the other words and see if the two words are neighbour.
 * Tips: bi-bfs is faster, from 292ms -> 72ms
 */
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
    int len = beginWord.size();
    queue<string> words;
    words.push(beginWord);

    int dis = 1;
    while (!words.empty()) {
        dis++;

        queue<string> next;
        while (!words.empty()) {
            string now = words.front();
            words.pop();
            for (int i = 0; i < len; ++i) {
                char letter = now[i];
                for (int c = 'a'; c <= 'z'; ++c) {
                    now[i] = c;
                    if (wordList.find(now) != wordList.end()) {
                        if (now == endWord) return dis;
                        wordList.erase(now);
                        next.push(now);
                    }
                }
                now[i] = letter;
            }
        }
        words = next;
    }

    return 0;
}

int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordList)
{
    int len = beginWord.size();
    unordered_set<string> head, tail, *phead, *ptail;
    head.insert(beginWord);
    tail.insert(endWord);

    int dis = 1;
    while (!head.empty() && !tail.empty()) {
        if (head.size() > tail.size()) {
            phead = &tail;
            ptail = &head;
        } else {
            phead = &head;
            ptail = &tail;
        }
        dis++;

        unordered_set<string> next;
        for (auto iter = phead->begin(); iter != phead->end(); ++iter) {
            string now = *iter;
            for (int i = 0; i < len; ++i) {
                char letter = now[i];
                for (int c = 'a'; c <= 'z'; ++c) {
                    now[i] = c;
                    if (wordList.find(now) != wordList.end()) {
                        if (ptail->find(now) != ptail->end()) return dis;
                        wordList.erase(now);
                        next.insert(now);
                    }
                }
                now[i] = letter;
            }
        }
        swap(next, *phead);
    }

    return 0;
}
int main()
{

}

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            bool find = false;
            int step = 1;

            queue<string> q;
            q.push(beginWord);

            while (!q.empty() && !find) {
                queue<string> next;

                vector<string> used;
                while (!q.empty()) {
                    string now = q.front();

                    for (int i = 0; i < now.size() && !find; ++i) {
                        char tmp = now[i];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            now[i] = ch;
                            if (now == endWord) {
                                find = true;
                                break;
                            }

                            if (wordList.find(now) != wordList.end()) {
                                next.push(now);
                                used.push_back(now);
                            }
                        }
                        now[i] = tmp;
                    }
                    q.pop();
                }

                for (string s : used) wordList.erase(s);
                ++step;
                q = next;
            }

            return find ? step : 0;
        }
};
