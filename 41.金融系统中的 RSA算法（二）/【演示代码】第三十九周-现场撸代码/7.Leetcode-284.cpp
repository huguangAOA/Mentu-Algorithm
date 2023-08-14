/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int cur;
    int end_flag;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        end_flag = false;
        if (Iterator::hasNext()) {
            cur = Iterator::next();
        } else {
            end_flag = true;
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (end_flag) {
            return -1;
        }
        int ret = cur;
        if (Iterator::hasNext()) {
            cur = Iterator::next();
        } else {
            end_flag = true;
        }
        return ret;
	}
	
	bool hasNext() const {
	    return !end_flag;
	}
};