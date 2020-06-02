// DecratorTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 实现简单的装饰器模式

#include <iostream>
#include <string>
using namespace std;

class Cake
{
public:
    virtual void showCake() = 0;
    string m_name;
};

class ConcreteCake : public Cake
{
public:
    ConcreteCake()
    {
        m_name = "原始蛋糕";
    }

    virtual void showCake()
    {
        cout << m_name << endl;
    }
};

class CakeDecrator : public Cake
{
protected:
    //维护一个Cake对象，为其添加装饰
    Cake* m_pCake;
public:
    virtual void showCake() = 0;
};

class CakeDecratorCholate : public CakeDecrator
{
public:
    CakeDecratorCholate(Cake* pCake)
    {
        this->m_pCake = pCake;
    }

    void showCake()
    {
        this->m_name = m_pCake->m_name + "，加巧克力";
        cout << this->m_name << endl;
    }
};

class CakeDecratorCream : public CakeDecrator
{
public:
    CakeDecratorCream(Cake* pCake)
    {
        this->m_pCake = pCake;
    }

    void showCake()
    {
        this->m_name = m_pCake->m_name + "，加奶油";
        cout << this->m_name << endl;
    }
};

int main()
{
    //创建原始蛋糕
    ConcreteCake* pConCake = new ConcreteCake();
    pConCake->showCake();
    //在原始蛋糕上添加装饰
    CakeDecratorCream* pDecCre = new CakeDecratorCream(pConCake);
    pDecCre->showCake();
    //在上一步装饰后继续添加装饰
    CakeDecratorCholate* pDecCho = new CakeDecratorCholate(pDecCre);
    pDecCho->showCake();

    delete pConCake;
    delete pDecCho;
    delete pDecCre;
}

