#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//原型模式
class cloneable
{
    public:
        virtual cloneable* clone() = 0;
};

class myVector: public cloneable
{
    public:
        int* arr;
        int _size;
        myVector(size_t _size)
        {
            this->_size = _size;
            arr = new int[_size];
            
        }
        ~myVector()
        {
            delete[] arr;
        }
        myVector(const myVector& a)
        {
            this->arr = new int[a._size];
            this->_size = a._size;
            memcpy(this->arr, a.arr, sizeof(int) * a._size);
        }
        cloneable* clone()
        {
            return new myVector(*this);
        }
        void print()
        {
            for(int i = 0; i < _size; i++)
            {
                printf("%d", arr[i]);
                if(i) putchar(' ');
            }
            putchar('\n');
        }
};
int main()
{
    myVector a(3);
    a.print();
    myVector* b = (myVector*)a.clone();
    b->print();
    delete b;

}