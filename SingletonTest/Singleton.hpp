#pragma once
template<typename T>
class Singleton
{
public:
	static T& getInstance()
	{
		//静态局部变量保证只初始化一次，并且线程安全
		static T value_;	
		return value_;
	}
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
};

