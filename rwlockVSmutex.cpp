//#include <stdio.h>
//#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <pthread.h>
using namespace std;
using namespace chrono;

//ȫ�ֱ���
int g_var = 0;

pthread_mutex_t mutex;
pthread_rwlock_t rwlock;

//ʹ�û��������̺߳���
void thfunc1()
{
	volatile int a;
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);	//����
		a = g_var;	//ֻ��ȫ�ֱ���
		pthread_mutex_unlock(&mutex);	//����
	}
	return;
}

//ʹ�ö�д�����̺߳���
void thfunc2()
{
	volatile int b;
	for (int i = 0; i < 10000000; i++)
	{
		pthread_rwlock_rdlock(&rwlock);	//����
		b = g_var;	//ֻ��ȫ�ֱ���
		pthread_rwlock_unlock(&rwlock);	//����
	}
	return;
}

//���������Ժ���
int mutexTest()
{
	thread threads[5];
	pthread_mutex_init(&mutex, NULL);	//��ʼ��������

	//��ʱ
	auto start = system_clock::now();
	//ִ���̺߳���
	for (int i = 0; i < 5; i++)
	{
		threads[i] = thread(thfunc1);
	}
	//�ȴ�ÿ���߳̽���
	for (auto& t : threads)
	{
		t.join();
	}
	//������ʱ
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Total mutex time is " << (double)duration.count() / 1000.0 << "ms" << endl;
	
	pthread_mutex_destroy(&mutex);	//���ٻ�����
	
	return 0;
}

//��д�����Ժ���
int rwlockTest()
{
	thread threads[5];
	pthread_rwlock_init(&rwlock, NULL);	//��ʼ��������

	//��ʱ
	auto start = system_clock::now();
	//ִ���̺߳���
	for (int i = 0; i < 5; i++)
	{
		threads[i] = thread(thfunc2);
	}
	//�ȴ�ÿ���߳̽���
	for (auto& t : threads)
	{
		t.join();
	}
	//������ʱ
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Total rwlock time is " << (double)duration.count() / 1000.0 << "ms" << endl;

	pthread_rwlock_destroy(&rwlock);	//���ٶ�д��

	return 0;
}

int main()
{
	//���ò��Ժ���
	mutexTest();
	rwlockTest();

	return 0;
}