// example_21222_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
void sayHello()
{
	std::cout << "Hello World!\n";
}
int main()
{
	/*std::cout << std::this_thread::get_id() << "\n";
	std::thread threadOne(sayHello);
	std::cout << threadOne.get_id() << "\n";
	threadOne.join();//.detach();
	std::cout << threadOne.get_id() << "\n";*/
	auto count { 0ull };
	std::mutex mtx;
	std::recursive_mutex rmtx;
	std::timed_mutex tmtx;
	std::recursive_timed_mutex rtmtx;
	//std::atomic<unsigned long long> count{ 0 };
	std::thread th1([&]() {
		//mtx.lock();
		std::lock_guard<std::mutex> lg(mtx);
		for (int i = 0; i < 1e6; i++)
			++count;//count.fetch_add(1);
		//mtx.unlock();
		});
	std::thread th2([&]() {
		//mtx.lock();
		std::lock_guard<std::mutex> lg(mtx);
		for (int i = 0; i < 1e6; i++)
			++count;//count.fetch_add(1);
		//mtx.unlock();
		});
	std::cout << th1.get_id() << "\n";
	std::cout << th2.get_id() << "\n";
	auto start = std::chrono::steady_clock::now();
	th1.join();
	th2.join();	
	auto finish = std::chrono::steady_clock::now();
	std::cout << "time="<<std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << "\n";
	std::cout << "count=" << count << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
