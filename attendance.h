#pragma once
#define _CRT_SECURE_NO_WARNINGS

// для простоты использования сортировки
#define SURNAME 0
// для простоты использования сортировки
#define COUNT 1

#include <iostream>
#include <fstream>
#include <ctime>

class person {

public:
	person(); // Конструктор по умолчанию
	person(const char* surname, const char* group); // Копирующий конструктор
	~person(); // Деструктор
	void add_date(time_t date); // Метод для добавления даты и времени посещения
	bool was_between(time_t, time_t) const; // Метод для проверки был студент на паре в заданном интервале или нет
	const char* get_surname() const; // Метод для получения фамилии
	const char* get_group() const; // Метод для получения группы
	void save(std::ofstream& out) const; // Метод для сохранения в бинарный файл
	void load(std::ifstream& in); // Метод для загрузки из бинарного файла
	void print() const; // Метод для вывода студента в консоль

	person& operator=(const person& other); // Копирующее присваивание
	bool smaller_surname(const person& other) const; // Метод для сравнения с другим студентом по фамилии
	bool bigger_surname(const person& other) const; // Метод для сравнения с другим студентом по фамилии
	bool smaller_count(const person& other) const; // Метод для сравнения с другим студентом по кол-ву посещений
	bool bigger_count(const person& other) const; // Метод для сравнения с другим студентом по кол-ву посещений

private:
	void resize(); // Метод для увеличения кол-ва выделенных ячеек в массиве для дат посещения 

	char* _surname; // Фамилия
	char* _group; // Группа
	time_t* _attendance; // Динамический массива в котором хранятся времена начала пары, на которых присутствовал этот человек
	size_t _att_count; // Число посещений (кол-во элементов в массиве)
	size_t _att_capacity; // Кол-во выделенных ячеек в масииве посещений
	const static size_t _init_att_count; // Начальное кол-во выделенных ячеек в массиве
};