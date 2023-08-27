#include "common.hpp"

// TODO: how to avoid using new and delete during running? it is dangerous!
char memoryPool[10000];

template<typename T>
class Vector {
public:
  explicit Vector(uint64_t s=0):size(s) {
    while (size > capacity) {
      capacity *= 2;
    }
    array = new T[capacity];
  }
  ~Vector() {
    delete[] array;
  }
  Vector(Vector & other) {
    Vector temp(other);
    *this = temp;
  }
  Vector & operator=(const Vector & other) {
    Vector temp(other);
    *this = temp;
  }
  void push_back(const T & data) {
    if (size < capacity) {
      array[size++] = data;
    } else {
      capacity *= 2;
      T * tmp = new T[capacity];
      for (auto i = 0; i < size; i++) {
        tmp[i] = array[i];
      }
      tmp[size++] = data;
      delete[] array;
      array = tmp;
    }
  }
  void print() {
    cout << size << endl;
    for (auto i = 0; i < size; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  }

private:
  T * array;
  uint64_t size;
  uint64_t capacity = 4;
  // T memoryPool[10000];
};

int main(int argc, char **argv)
{
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.print();
  return 0;
}