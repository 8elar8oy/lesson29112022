#include <SFML/Graphics.hpp>

using namespace sf;
const float SC_WIDTH = 800.f;
const float SC_HEIGHT = 600.f;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SC_WIDTH, SC_HEIGHT), "SFML Works!");
	float radius1 = 200.f;
	float radius2 = 180.f;
	float radius3 = 160.f;
	float radius4 = 140.f;
	float radius5 = 120.f;
	CircleShape c1(radius1);
	CircleShape c2(radius2);
	CircleShape c3(radius3);
	CircleShape c4(radius4);
	CircleShape c5(radius5);
	c1.setFillColor(Color(25, 28, 20));
	c1.move((SC_WIDTH - 2 * radius1) / 2, (SC_HEIGHT - 2 * radius1) / 2);
	
	c2.setFillColor(Color(55, 55, 55));
	c2.move((SC_WIDTH - 2 * radius2) / 2, (SC_HEIGHT - 2 * radius2) / 2);

	c3.setFillColor(Color(25, 28, 16));
	c3.move((SC_WIDTH - 2 * radius3) / 2, (SC_HEIGHT - 2 * radius3) / 2);
	
	c4.setFillColor(Color(25, 22, 13));
	c4.move((SC_WIDTH - 2 * radius4) / 2, (SC_HEIGHT - 2 * radius4) / 2);

	c5.setFillColor(Color(65, 22, 13));
	c5.move((SC_WIDTH - 2 * radius5) / 2, (SC_HEIGHT - 2 * radius5) / 2);

	const int size = 5;
	float dx = 100.f;
	RectangleShape arr_rect[8];
	RectangleShape arr_rect1[8];
	RectangleShape arr_rect2[8];
	RectangleShape arr_rect3[8];
	for (int i = 0; i < 8; i++)
	{
		arr_rect[i].setSize(Vector2f(50.f, 50.f));
		arr_rect[i].move(dx * i, 0);
		arr_rect[i].setFillColor(Color{ (Uint8)(50 * i),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });

	}
	for (int i = 0; i < 8; i++)
	{
		arr_rect1[i].setSize(Vector2f(50.f, 50.f));
		arr_rect1[i].move(0,dx * i);
		arr_rect1[i].setFillColor(Color{ (Uint8)(50 * i),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	}
	for (int i = 0; i < 8; i++)
	{
		arr_rect2[i].setSize(Vector2f(50.f, 50.f));
		arr_rect2[i].move(SC_WIDTH-50.f, dx * i);
		arr_rect2[i].setFillColor(Color{ (Uint8)(50 * i),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	}
	for (int i = 0; i < 8; i++)
	{
		arr_rect3[i].setSize(Vector2f(50.f, 50.f));
		arr_rect3[i].move(dx * i, SC_HEIGHT-50.f);
		arr_rect3[i].setFillColor(Color{ (Uint8)(50 * i),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	}
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//Обновление обьектов
		
		// Отрисовка обьектов и обновление окна
		window.clear();
		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.draw(c4);
		window.draw(c5);
		for (int i = 0; i < 8; i++)
		{
			window.draw(arr_rect[i]);
		}
		for (int i = 0; i < 8; i++)
		{
			window.draw(arr_rect1[i]);
		}
		for (int i = 0; i < 8; i++)
		{
			window.draw(arr_rect2[i]);
		}
		for (int i = 0; i < 8; i++)
		{
			window.draw(arr_rect3[i]);
		}


		
		
		window.display();
	}

	return 0;
}