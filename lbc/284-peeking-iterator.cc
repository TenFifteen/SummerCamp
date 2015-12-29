/*
题目大意：
要求是实现一个迭代器，支持peek操作。

解题思路：
见代码

遇到的问题：
有点水啊。
*/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    vector<int>::const_iterator ci, eci; 
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    ci = nums.cbegin();
	    eci = nums.cend();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *ci;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return *ci++;
	}

	bool hasNext() const {
	    return ci != eci;
	}
};