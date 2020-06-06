# Test
一些练习用的小程序

## EndianTest

两种方式实现大小端字节序的判断。

1. 用char指针指向int变量获取int中低地址的内容
2. 用包含int和char的联合体，通过char来读取int中低地址上的内容

## RwlockVSMutex

实现简单的读写锁与互斥锁性能比较。

5个线程同时对一个全局变量进行多次读操作，分别使用互斥锁和读写锁对读操作上锁，比较两种情况下的用时。

![读写锁与互斥锁比较](https://image-1301378304.cos.ap-nanjing.myqcloud.com/%E4%BA%92%E6%96%A5%E9%94%81%E4%B8%8E%E8%AF%BB%E5%86%99%E9%94%81%E9%80%9F%E5%BA%A6%E6%AF%94%E8%BE%83.PNG)

可以看出，即使都在读的情况下，读写锁依然比互斥锁速度慢。

> 读写锁比互斥锁适用性更高，并行性也更高，但读写锁更复杂，系统开销更大，因此读写锁速度并不一定比互斥锁快。

## EditText

基于Qt实现的一个简单txt文本编辑器。

实现功能：打开已有txt文件，读取到编辑器中显示；编辑器中进行编辑；保存编辑器中的内容。

![文本编辑器界面](https://image-1301378304.cos.ap-nanjing.myqcloud.com/EditText%E7%95%8C%E9%9D%A2.png)

## SingletonTest

实现简单的单例模式。

利用C++11中局部静态变量只初始化一次且线程安全的特性，并用模板包装单例类

## AbstractFactoryTest

实现简单的抽象工厂模式

![抽象工厂模式](https://image-1301378304.cos.ap-nanjing.myqcloud.com/%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F.png)

## ObserverTest

实现简单的观察者模式

## DecratorTest

实现简单的装饰器模式