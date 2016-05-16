/*
题目大意：
又是实现工厂模式

解题思路：
见代码

遇到的问题：
没有。
*/
/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Square : public Shape {
    // Write your code here
public:
    virtual void draw() const {
        cout << " ----" << endl;
        cout << "|    |" << endl;
        cout << "|    |" << endl;
        cout << " ----" << endl;
    }
};

class Rectangle: public Shape {
    // Write your code here
public:
    virtual void draw() const {
        cout << " ----" << endl;
        cout << "|    |" << endl;
        cout << " ----" << endl;
    }
};

class Triangle: public Shape {
    // Write your code here
public:
    virtual void draw() const {
        cout << "  /\\" << endl;
        cout << " /  \\" << endl;
        cout << "/____\\" << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        // Write your code here
        if (shapeType == "Square") {
            return new Square();
        } else if (shapeType == "Triangle") {
            return new Triangle();
        } else if (shapeType == "Rectangle") {
            return new Rectangle();
        } else {
            return NULL;
        }
    }
};

