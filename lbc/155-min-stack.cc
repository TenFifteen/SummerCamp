/*
题目大意：
实现一个具有求最小值的栈。

解题思路：
用两个栈，一个用来存放原来的数，一个用来存放最小值。

遇到的问题：
一次通过。

再次阅读：
虽然之前做的没啥问题，不过第二个栈的空间可以用的更少一些的：
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);       
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};

另外，竟然找到了一个人用的是一个栈就解决了。实在是太厉害了。
解决方法就是栈里面存放的是最小值和真实值之间的差值，然后在每次push和pop的时候更新min值。
public class MinStack {
    long min;
    Stack<Long> stack;

    public MinStack(){
        stack=new Stack<>();
    }

    public void push(int x) {
        if (stack.isEmpty()){
            stack.push(0L);
            min=x;
        }else{
            stack.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    public void pop() {
        if (stack.isEmpty()) return;

        long pop=stack.pop();

        if (pop<0)  min=min-pop;//If negative, increase the min value

    }

    public int top() {
        long top=stack.peek();
        if (top>0){
            return (int)(top+min);
        }else{
           return (int)(min);
        }
    }

    public int getMin() {
        return (int)min;
    }
}
*/
class MinStack {
private:
    stack<int> a,b;
public:
    void push(int x) {
        a.push(x);
        if(b.empty()){
            b.push(x);
        }else{
            b.push(min(x, b.top()));
        }
    }

    void pop() {
        a.pop();
        b.pop();
    }

    int top() {
        return a.top();
    }

    int getMin() {
        return b.top();
    }
};