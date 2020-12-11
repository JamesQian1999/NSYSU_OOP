#include "Trace.h"

template <class T>
class Vector
{
    T *v;
    int sz;
    static int count;
public:
    Vector();
    Vector(int i) : sz(i)
    {
        TRACE(dummy, "Vector<T>::Vector(int)");
        std::cout<<"  count = "<<++count<<endl;
        v = new T[sz];
    }
    ~Vector()
    {
        TRACE(dummy, "Vector<T>::~Vector");
        std::cout<<"  count = "<<count--<<endl;
    }
    T &elem(int i) { return v[i]; }
    T &operator[](int i) { return v[i]; }
};
template <class T>
int Vector<T>::count = 0;

template <>
class Vector<void *>
{
    void **p;
    int sz;
    static int count;
public:
    Vector();
    Vector(int i) : sz(i)
    {

        TRACE(dummy, "Vector<void*>::Vector(int)");
        std::cout<<"  count = "<<++count<<endl;
        p = new void *[sz];
    }
    ~Vector()
    {
        TRACE(dummy, "Vector<void*>::~Vector");
        std::cout<<"  count = "<<count--<<endl;
    }
    void *&elem(int i) { return p[i]; }
};
template <>
int Vector<void *>::count = 0;

template <class T>
class Vector<T *> : public Vector<void *>
{
public:
    typedef Vector<void *> Base;
    explicit Vector(int size) : Base(size)
    {
        TRACE(dummy, "Vector<T*>::Vector(int)");
    }
    ~Vector()
    {
        TRACE(dummy, "Vector<T*>::~Vector");
    }
    T *&operator[](int i)
    {
        static T *t = (T *)Base::elem(i);
        return t;
    }
    T *&elem(int i)
    {
        static T *t = (T *)Base::elem(i);
        return t;
    }
};
