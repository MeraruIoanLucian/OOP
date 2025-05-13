#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

using namespace std;

namespace ArrayExceptions {

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Indexul este inafara domeniului!";
        }
    };

    class InvalidCapacityException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Capacitate invalida!";
        }
    };

    class EmptyArrayException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Lista este goala!";
        }
    };
}

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    T** List;
    int Current;
    int Size;
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {}
    
    ArrayIterator(T** list, int current, int size) : 
        List(list), Current(current), Size(size) {}
    
    ArrayIterator& operator++() {
        if (Current < Size)
            Current++;
        return *this;
    }
    
    ArrayIterator& operator--() {
        if (Current > 0)
            Current--;
        return *this;
    }
    
    bool operator=(ArrayIterator<T>& other) {
        List = other.List;
        Current = other.Current;
        Size = other.Size;
        return true;
    }
    
    bool operator!=(ArrayIterator<T>& other) {
        return (Current != other.Current) || (List != other.List);
    }
    
    T* GetElement() {
        if (Current < Size && Current >= 0)
            return List[Current];
        return nullptr;
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void Resize(int newCapacity) {
        T** newList = new T*[newCapacity];
        int copyItems = (newCapacity < Size) ? newCapacity : Size;
        
        for(int i = 0; i < copyItems; i++) {
            newList[i] = List[i];
        }
        
        delete[] List;
        List = newList;
        Capacity = newCapacity;
        if (Size > Capacity)
            Size = Capacity;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}
    ~Array() {
        for(int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }
    Array(int capacity) {
        if(capacity <= 0) {
            throw ArrayExceptions::InvalidCapacityException();
        }
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
    }
    Array(const Array<T> &otherArray) {
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T*[Capacity];
        
        for(int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
    }
    T& operator[] (int index) {
        if(index < 0 || index >= Size) {
            throw ArrayExceptions::OutOfBoundsException();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T &newElem) {
        if(Size == Capacity) {
            int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
            Resize(newCapacity);
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T &newElem) {
        if(index < 0 || index > Size) {
            throw ArrayExceptions::OutOfBoundsException();
        }
        if(Size == Capacity) {
            Resize(Capacity * 2);
        }
        for(int i = Size; i > index; i--) {
            List[i] = List[i-1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if(index < 0 || index > Size) {
            throw ArrayExceptions::OutOfBoundsException();
        }
        
        int newSize = Size + otherArray.Size;
        if(newSize > Capacity) {
            Resize(newSize);
        }
        
        for(int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        
        for(int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size = newSize;
        return *this;
    }
    
    const Array<T>& Delete(int index) {
        if(index < 0 || index >= Size) {
            throw ArrayExceptions::OutOfBoundsException();
        }
        
        delete List[index];
        
        for(int i = index; i < Size - 1; i++) {
            List[i] = List[i+1];
        }
        
        Size--;
        return *this;
    }

    bool operator=(const Array<T> &otherArray) {
        if(this == &otherArray) return true;
        for(int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T*[Capacity];
        
        for(int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
        
        return true;
    }
    void Sort() {
        if (Size <= 1) return;

        for(int i = 0; i < Size - 1; i++) {
            for(int j = 0; j < Size - i - 1; j++) {
                if(*List[j] > *List[j+1]) {
                    T* temp = List[j];
                    List[j] = List[j+1];
                    List[j+1] = temp;
                }
            }
        }
    }
    
    void Sort(int(*compare)(const T&, const T&)) {
        if (Size <= 1) return;
        
        for(int i = 0; i < Size - 1; i++) {
            for(int j = 0; j < Size - i - 1; j++) {
                if(compare(*List[j], *List[j+1]) > 0) {
                    T* temp = List[j];
                    List[j] = List[j+1];
                    List[j+1] = temp;
                }
            }
        }
    }
    
    void Sort(Compare *comparator) {
        if (Size <= 1) return;
        
        for(int i = 0; i < Size - 1; i++) {
            for(int j = 0; j < Size - i - 1; j++) {
                if(comparator->CompareElements(List[j], List[j+1]) > 0) {
                    T* temp = List[j];
                    List[j] = List[j+1];
                    List[j+1] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        if (Size == 0) {
            throw ArrayExceptions::EmptyArrayException();
        }
        
        int left = 0;
        int right = Size - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (*List[mid] == elem)
                return mid;
                
            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        if (Size == 0) {
            throw ArrayExceptions::EmptyArrayException();
        }
        
        int left = 0;
        int right = Size - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = compare(*List[mid], elem);
            
            if (result == 0)
                return mid;
                
            if (result < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
    int BinarySearch(const T& elem, Compare *comparator) {
        if (Size == 0) {
            throw ArrayExceptions::EmptyArrayException();
        }
        
        int left = 0;
        int right = Size - 1;
        T elemCopy = elem;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = comparator->CompareElements(List[mid], &elemCopy);
            
            if (result == 0)
                return mid;
                
            if (result < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }

    int Find(const T& elem) {
        for(int i = 0; i < Size; i++) {
            if(*List[i] == elem)
                return i;
        }
        return -1;
    }
    
    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for(int i = 0; i < Size; i++) {
            if(compare(*List[i], elem) == 0)
                return i;
        }
        return -1;
    }
    
    int Find(const T& elem, Compare *comparator) {
        T elemCopy = elem;
        for(int i = 0; i < Size; i++) {
            if(comparator->CompareElements(List[i], &elemCopy) == 0)
                return i;
        }
        return -1;
    }

};

#endif // ARRAY_H