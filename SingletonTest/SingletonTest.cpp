//使用模板包装的单例类Singleton实现将任意一个类做成单例模式

#include "Singleton.hpp"
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        m_a = 1;
    }
    void func()
    {
        cout << "Class A: m_a = " << m_a << endl;
    }
private:
    int m_a;
};

class B
{
public:
    B()
    {
        m_b = 2;
    }
    void func()
    {
        cout << "Class B: m_b = " << m_b << endl;
    }
private:
    int m_b;
};

int main()
{
    Singleton<A>::getInstance().func();
    Singleton<B>::getInstance().func();
    return 0;
}


