/*
题目大意：
要求是实现一个迭代器，支持peek操作。

解题思路：
见代码

遇到的问题：
有点水啊。

再次阅读：
感觉自己的实现完全没有用到之前的Iterator类，所以应该是有点问题的。
感觉上应该是利用之前的next和hasNext方法，然后用一个变量来缓存peek出来的元素。
然而，看到DISCUSS中都是用的再造一个Iterator出来用：
class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};
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
/*
第二次做：
这次写的还可以。
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
    bool buf;
    int last;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    buf = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!buf) {
            buf = true;
            last = Iterator::next();
        }
        return last;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (buf) {
	        buf = false;
	        return last;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    return buf || Iterator::hasNext();
	}
};