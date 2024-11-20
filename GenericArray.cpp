#include <iostream>
#include <stdexcept>
#include <limits>


template <typename T>
class GenericArray {
private:
    T* data;
    int capacity;

public:

    GenericArray() : data(nullptr), capacity(0) {}


    ~GenericArray() {
        delete[] data;
    }


    void addElement(T param) {
        T* new_data = new T[capacity + 1];
        for (int i = 0; i < capacity; ++i) {
            new_data[i] = data[i];
        }
        new_data[capacity] = param;
        delete[] data;
        data = new_data;
        ++capacity;
    }


    T at(int index) {
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }


    int size() const {
        return capacity;
    }


    T sum() {
        T total = 0;
        for (int i = 0; i < capacity; ++i) {
            total += data[i];
        }
        return total;
    }


    T max() {
        if (capacity == 0) {
            throw std::runtime_error("Array is empty.");
        }
        T max_val = std::numeric_limits<T>::lowest();
        for (int i = 0; i < capacity; ++i) {
            if (data[i] > max_val) {
                max_val = data[i];
            }
        }
        return max_val;
    }


    T min() {
        if (capacity == 0) {
            throw std::runtime_error("Array is empty.");
        }
        T min_val = std::numeric_limits<T>::max();
        for (int i = 0; i < capacity; ++i) {
            if (data[i] < min_val) {
                min_val = data[i];
            }
        }
        return min_val;
    }


    T* slice(int begin, int end) {
        if (begin < 0 || end >= capacity || begin > end) {
            throw std::out_of_range("Invalid slice range.");
        }
        int slice_size = end - begin + 1;
        T* slice_array = new T[slice_size];
        for (int i = 0; i < slice_size; ++i) {
            slice_array[i] = data[begin + i];
        }
        return slice_array;
    }
};


int main() {
    GenericArray<int> int_array;


    int_array.addElement(10);
    int_array.addElement(20);
    int_array.addElement(30);
    int_array.addElement(40);
    int_array.addElement(50);


    std::cout << "Size of array: " << int_array.size() << std::endl;


    std::cout << "Sum of array: " << int_array.sum() << std::endl;


    std::cout << "Maximum value: " << int_array.max() << std::endl;
    std::cout << "Minimum value: " << int_array.min() << std::endl;


    std::cout << "Element at index 2: " << int_array.at(2) << std::endl;


    int* sliced_array = int_array.slice(1, 3);
    std::cout << "Sliced array: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << sliced_array[i] << " ";
    }
    std::cout << std::endl;


    delete[] sliced_array;

    return 0;
}

