//
// Created by Sean on 4/17/2019.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

using namespace std;

template<typename T>

class Stack {
    T *A{};
    unsigned int capacity;
    unsigned int len;

    // doubles the capacity of the array
    void grow() {
        capacity *= 2;
        T *newA = new T[capacity];
        
        // After creating a new array ^ copied the old array over
        for (unsigned int i = 0; i < len; i++) {
            newA[i] = A[i];
        }
        
        // Zeros out the values after length
        for (unsigned int i = len; i < capacity; i++) {
            newA[i] = {};
        }
        
        // Zeros out the old array
        for (unsigned int i = 0; i < len; i++) {
            A[i] = {};
        }
        
        // Deletes the old memory on the heap
        delete[] A;
        A = newA;
    };

public:
    Stack() : A(new T[1]), capacity(1), len(0) {};

    // Copy contructor
    Stack(const Stack &stack) {
        capacity = stack.capacity;
        A = new T[capacity];
        len = stack.len;
        for (unsigned int i = 0; i < len; i++) {
            A[i] = stack.A[i];
        }
    }

    // Destructor
    ~Stack() {
        // Zeros out array
        for (unsigned int i = 0; i < capacity; i++) {
            A[i] = {};
        }
        delete[] A;
        
        // Resets capacity and length
        capacity = 0;
        len = 0;
    };

    // Overloads the equals operator
    Stack &operator=(const Stack stack) {
        capacity = stack.capacity;
        len = stack.len;
        T *newA = new T[capacity];
        for (unsigned int i = 0; i < len; i++) {
            newA[i] = A[i];
        }
        for (unsigned int i = len; i < capacity; i++) {
            newA[i] = {};
        }
        for (unsigned int i = 0; i < len; i++) {
            A[i] = {};
        }
        delete[] A;
        A = newA;
        for (unsigned int i = 0; i < len; i++) {
            A[i] = stack.A[i];
        }
        return *this;
    }

    // pop gets the top value on the stack and removes it
    T pop() {
        T val = A[--len];
        A[len] = {};
        return val;
    };

    // returns the length of the array (not capacity)
    int size() {
        return len;
    }

    // push places new value on top of stack
    T push(T val) {
        if (len == capacity) {
            grow();
        }
        A[len++] = val;
    }

    // Returns the value on top of the stack
    T peek() {
        return A[len - 1];
    }

    // Clears out the stack...
    void clear() {
        for (int i = 0; i < len; i++) {
            A[i] = {};
        }
        len = 0;
    }

    // Returns true if the stack has no elements
    bool isEmpty() {
        if (len == 0) {
            return true;
        }
        return false;
    }

    // Iterates through stack and returns true if val is contained within
    bool contains(T val) {
        for (int i = 0; i < len; i++) {
            if (A[i] == val) {
                return true;
            }
        }
        return false;
    }

};

#endif //STACK_STACK_H
