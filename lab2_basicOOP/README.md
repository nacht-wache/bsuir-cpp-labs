Лабораторная работа №2

Тема работы: Создание базовых объектов.



Цель работы: Создание консольной программы включающей объекты и реализующей члены объектов c использованием спецификаторов доступа, конструкторы и деструктор, статические члены классов, особую инициализацию членов класса, дружественные функции и классы.



Общие требования к выполнению работы

1.    Рассмотреть теоретические сведения по теме лабораторной работы.

2.    Создать проект консольной программы.

3.    Создать базовый класс согласно заданию. Все данные класса описать в закрытой секции, все методы класса реализовать как открытые. Создать конструктор по умолчанию и конструктор инициализации. Создать деструктор.

4.    Вне класса должна быть создана дружественная функция, предназначенная для вывода данных объекта на экран.

5.    Для задания значений уникальных номеров использовать или статические члены класса или особую инициализацию членов класса.

6.    Установка значений переменных должна иметь проверку на реальный диапазон значений.

7.    В головной функции создать несколько одиночных экземпляров базового класса. Обработать все экземпляры базового класса с помощью заданного метода дружественного класса. Вывести содержимое переменных экземпляров классов на экран до и после этой обработки.

8.    В головной функции создать массив экземпляров базового класса. Обработать все элементы массива с помощью заданного метода дружественного класса. Вывести содержимое переменных элементов массива на экран до и после этой обработки.

9.    Отладить и выполнить полученную программу.

Вариант задания № 6

6.    Создать класс «Задание» со следующими данными: id – уникальный номер, name – название, result – процент выполнения. Создать дружественный класс «Проверяющий», в котором реализовать метод установки процента выполнения задания.