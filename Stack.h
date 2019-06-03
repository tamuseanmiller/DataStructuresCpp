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

    void grow() {
        capacity *= 2;
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
    };

public:
    Stack() : A(new T[1]), capacity(1), len(0) {};

    Stack(const Stack &stack) {
        capacity = stack.capacity;
        A = new T[capacity];
        len = stack.len;
        for (unsigned int i = 0; i < len; i++) {
            A[i] = stack.A[i];
        }
    }

    ~Stack() {
        for (unsigned int i = 0; i < capacity; i++) {
            A[i] = {};
        }
        delete[] A;
        capacity = 0;
        len = 0;
    };

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

    T pop() {
        T val = A[--len];
        A[len] = {};
        return val;
    };

    int size() {
        return len;
    }

    T push(T val) {
        if (len == capacity) {
            grow();
        }
        A[len++] = val;
    }

    T peek() {
        return A[len - 1];
    }

    void clear() {
        for (int i = 0; i < len; i++) {
            A[i] = {};
        }
        len = 0;
    }

    bool isEmpty() {
        if (len == 0) {
            return true;
        }
        return false;
    }

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
