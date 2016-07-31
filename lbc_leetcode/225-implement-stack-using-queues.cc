/*
题目大意：
要求用队列实现栈。

解题思路：
假设当前的队列中的元素就是已经按照栈的要求排列了。
然后新来元素的时候，将其全部倒入另一个队列中，将该元素放进去，然后再将刚才的元素
倒回来。

遇到的问题：
一次通过。
不过不知道有没有复杂度第一点的实现方案？

再次阅读：
我还以为会有一些效率好点的方案呢。
结果看了DISCUSS，也没有找到一种比这更好的方案。
不过有一个只使用了一个queue的方案还是挺好的：
class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};
*/
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }else{
            queue<int> tmp;
            while(!q.empty()){
                tmp.push(q.front());
                q.pop();
            }
            q.push(x);
            while(!tmp.empty()){
                q.push(tmp.front());
                tmp.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
/*
第二次做：
虽然思路上没有什么大的改变，不过这次的代码的确是不如之前的了。
尤其是DISCUSS中的这种代码，值得借鉴。
*/
class Stack {
private:
    bool first = true;
    queue<int> q1, q2;

public:
    // Push element x onto stack.
    void push(int x) {
        if (first) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (first) {
            while (q1.size() > 1) {
                q2.push(q1.front()); q1.pop();
            }
            int ret = q1.front(); q1.pop();
            first = false;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front()); q2.pop();
            }
            int ret = q2.front(); q2.pop();
            first = true;
        }
    }

    // Get the top element.
    int top() {
        if (first) {
            while (q1.size() > 1) {
                q2.push(q1.front()); q1.pop();
            }
            int ret = q1.front(); q1.pop();
            q2.push(ret);
            first = false;
            return ret;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front()); q2.pop();
            }
            int ret = q2.front(); q2.pop();
            q1.push(ret);
            first = true;
            return ret;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};
/*
 * bad question.
 */
class Stack {
private:
    queue<int> s1, s2;

public:
    // Push element x onto stack.
    void push(int x) {
        if (s2.size() == 0) s1.push(x);
        else s2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (s1.size() > 0) {
            while (s1.size() > 1) {
                s2.push(s1.front());
                s1.pop();
            }
            s1.pop();
        } else {
            while (s2.size() > 1) {
                s1.push(s2.front());
                s2.pop();
            }
            s2.pop();
        }
    }

    // Get the top element.
    int top() {
        if (s1.size() > 0) {
            while (s1.size() > 1) {
                s2.push(s1.front());
                s1.pop();
            }
            int val = s1.front();
            s2.push(s1.front());
            s1.pop();
            return val;
        } else {
            while (s2.size() > 1) {
                s1.push(s2.front());
                s2.pop();
            }
            int val = s2.front();
            s1.push(val);
            s2.pop();
            return val;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return s1.size() == 0 && s2.size() == 0;
    }
};
