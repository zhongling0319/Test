#include<iostream>
#include<string>
using namespace std;

//手机类
class Phone
{
public:
	virtual void make() = 0;
};

class MiPhone : public Phone
{
public:
	MiPhone()
	{
		this->make();
	}
	virtual void make()
	{
		cout << "XiaoMi Phone maked" << endl;
	}
};

class IPhone : public Phone
{
public:
	IPhone()
	{
		this->make();
	}
	virtual void make()
	{
		cout << "IPhone maked" << endl;
	}
};

//PC类
class PC
{
public:
	virtual void make() = 0;
};

class MiPC : public PC
{
public:
	MiPC()
	{
		this->make();
	}
	virtual void make()
	{
		cout << "XiaoMi PC maked" << endl;
	}
};

class MAC : public PC
{
public:
	MAC()
	{
		this->make();
	}
	virtual void make()
	{
		cout << "MAC maked" << endl;
	}
};

//抽象工厂类
class AbstractFactory
{
public:
	virtual Phone* CreatePhone() = 0;
	virtual PC* CreatePC() = 0;
};

class XiaoMiFactory : public AbstractFactory
{
public:
	virtual Phone* CreatePhone()
	{
		return new MiPhone();
	}
	virtual PC* CreatePC()
	{
		return new MiPC();
	}
};

class AppleFactory : public AbstractFactory
{
public:
	virtual Phone* CreatePhone()
	{
		return new IPhone();
	}
	virtual PC* CreatePC()
	{
		return new MAC();
	}
};

int main()
{
	AbstractFactory* miFactory = new XiaoMiFactory();
	AbstractFactory* appleFactory = new AppleFactory();
	miFactory->CreatePhone();		//XiaoMi Phone maked
	miFactory->CreatePC();			//XiaoMi PC maked
	appleFactory->CreatePhone();	//IPhone maked
	appleFactory->CreatePC();		//MAC maked
}