// ObserverTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// Observer模式的简单实现

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;

class Observer
{
public:
    Observer(Subject* pSubject, string name)
    {
        m_pSubject = pSubject;
        m_name = name;
    }
    virtual void update() = 0;
protected:
    Subject* m_pSubject;
    string m_name;
};

class Subject
{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
    virtual int GetState() = 0;
    virtual void SetState(int) = 0;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject* pSubject, string name) : Observer(pSubject, name)
    {
    }
    
    virtual void update()
    {
        m_ObserverState = m_pSubject->GetState();
        cout << m_name << " recived the notify, state is " << m_ObserverState << endl;
    }
private:
    int m_ObserverState;
};


class ConcreteSubject : public Subject
{
public:
    virtual void Attach(Observer* pObserver)
    {
        m_ObserverList.push_back(pObserver);
    }

    virtual void Detach(Observer* pObserver)
    {
        m_ObserverList.remove(pObserver);
    }

    virtual void Notify()
    {
        for (auto it = m_ObserverList.begin(); it != m_ObserverList.end(); it++) {
            (*it)->update();
        }
    }

    void SetState(int state)
    {
        m_SubjectState = state;
    }

    int GetState()
    {
        return m_SubjectState;
    }

private:
    int m_SubjectState;
    list<Observer*> m_ObserverList;
};

int main()
{
    //实例化目标和观察者
    Subject* pSubject = new ConcreteSubject();
    Observer* pObserver01 = new ConcreteObserver(pSubject, "observer01");
    Observer* pObserver02 = new ConcreteObserver(pSubject, "observer02");
    //建立联系
    pSubject->Attach(pObserver01);
    pSubject->Attach(pObserver02);
    //设置目标状态并通知
    pSubject->SetState(1);
    pSubject->Notify();
    //解除一个observer的联系
    pSubject->Detach(pObserver01);
    //再次设置目标状态并通知
    pSubject->SetState(2);
    pSubject->Notify();

    delete pSubject;
    delete pObserver01;
    delete pObserver02;
}

