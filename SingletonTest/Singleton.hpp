#pragma once
template<typename T>
class Singleton
{
public:
	static T& getInstance()
	{
		//��̬�ֲ�������ֻ֤��ʼ��һ�Σ������̰߳�ȫ
		static T value_;	
		return value_;
	}
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
};

