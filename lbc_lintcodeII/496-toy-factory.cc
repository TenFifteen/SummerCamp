/*
题目大意：
实现工厂模式

解题思路：
见代码

遇到的问题：
本来对纯虚函数理解是没有问题的。结果只是因为子类少了一个const，
导致我的代码一直编译不过去。
最后发现是有const和没有const是两个不同的函数签名。

所以纯虚函数和虚函数的区别就是：
纯虚函数在基类中是一定没有实现的。而虚函数是有实现的，而且是必须要有实现的。
*/
/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
public:
    virtual void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    // Write your code here
public:
    virtual void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if (type == "Dog") {
            return new Dog();
        } else if (type == "Cat") {
            return new Cat();
        } else {
            return NULL;
        }
    }
};
