#include <iostream>
#include <locale>
#include "VisitContainer.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    VisitContainer container;
    container.loadFromFile("data.json");

    std::cout << "Количество записей после чтения файла: " << container.getSize() << std::endl;

    int choice;
    do
    {
        std::cout << "Меню:\n1. Вывести все записи\n2. Найти пациента с самой поздней датой\n"
                  << "3. Показать количество пациентов врача\n 4. пример добавления \n5. Выход\nВыберите опцию: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            container.displayAll();
            break;
        case 2:
        {
            Visit *lastVisit = container.findLastVisit();
            if (lastVisit)
            {
                std::cout << "Пациент с самой поздней датой обращения:\n";
                lastVisit->display();
            }
            else
            {
                std::cout << "Нет записей в контейнере.\n";
            }
            break;
        }
        case 3:
        {
            std::string doctor;
            std::cout << "Введите имя врача: ";
            std::cin >> doctor;
            container.DoctorPatients(doctor);
            break;
        }
        case 4:
        {
            Visit newVisit;
            std::cout << "Введите данные визита: " << std::endl;
            std::cin >> newVisit;  // Ввод данных через перегруженный оператор >>
            container += newVisit; // Добавление в контейнер
            std::cout << "Визит добавлен.\n";
            break;
        }
        case 5:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    container.saveToFile("data.json");
    return 0;
}
// main.cpp