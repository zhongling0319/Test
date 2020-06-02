//#include <stdio.h>
//#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <pthread.h>
using namespace std;
using namespace chrono;

//全局变量
int g_var = 0;

pthread_mutex_t mutex;
pthread_rwlock_t rwlock;

//使用互斥锁的线程函数
void thfunc1()
{
	volatile int a;
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);	//上锁
		a = g_var;	//只读全局变量
		pthread_mutex_unlock(&mutex);	//解锁
	}
	return;
}

//使用读写锁的线程函数
void thfunc2()
{
	volatile int b;
	for (int i = 0; i < 10000000; i++)
	{
		pthread_rwlock_rdlock(&rwlock);	//上锁
		b = g_var;	//只读全局变量
		pthread_rwlock_unlock(&rwlock);	//解锁
	}
	return;
}

//互斥锁测试函数
int mutexTest()
{
	thread threads[5];
	pthread_mutex_init(&mutex, NULL);	//初始化互斥锁

	//计时
	auto start = system_clock::now();
	//执行线程函数
	for (int i = 0; i < 5; i++)
	{
		threads[i] = thread(thfunc1);
	}
	//等待每个线程结束
	for (auto& t : threads)
	{
		t.join();
	}
	//结束计时
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Total mutex time is " << (double)duration.count() / 1000.0 << "ms" << endl;
	
	pthread_mutex_destroy(&mutex);	//销毁互斥锁
	
	return 0;
}

//读写锁测试函数
int rwlockTest()
{
	thread threads[5];
	pthread_rwlock_init(&rwlock, NULL);	//初始化互斥锁

	//计时
	auto start = system_clock::now();
	//执行线程函数
	for (int i = 0; i < 5; i++)
	{
		threads[i] = thread(thfunc2);
	}
	//等待每个线程结束
	for (auto& t : threads)
	{
		t.join();
	}
	//结束计时
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Total rwlock time is " << (double)duration.count() / 1000.0 << "ms" << endl;

	pthread_rwlock_destroy(&rwlock);	//销毁读写锁

	return 0;
}

int main()
{
	//调用测试函数
	mutexTest();
	rwlockTest();

	return 0;
}