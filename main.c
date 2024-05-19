#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include "locale.h"
//методы с закрытой структурой Triangle 
//int main()
//{
//    setlocale(LC_ALL, "rus");
 //   Triangle* triangle  = CreateTriangle(22, 16,12);
 //   PrintTriangle(triangle);
 //   printf("%f\n", Perimeter(triangle));
 //   printf("%f", Area(triangle));
 //   float alpha, beta, gamma;
 //   FindAngles(triangle, &alpha, &beta, &gamma);
 //   PrintTriangleAngles(alpha, beta, gamma);
 //   free(triangle);
 //   return 0;
//}
int main()
{
    setlocale(LC_ALL, "rus");
    TriangleDatabase* db = CreateDatabase(10);
    if (!db) {
        printf("Не удалось создать базу данных\n");
        return 1;
    }
    while (1) {
        int choice;
        printf("\nМеню:\n");
        printf("1. Добавить треугольник\n");
        printf("2. Удалить треугольники по стороне\n");
        printf("3. Найти треугольники по стороне\n");
        printf("4. Отсортировать базу данных по стороне\n");
        printf("5. Показать все треугольники\n");
        printf("6. Выход\n");
        printf("Введите номер команды: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            AddTriangleFromConsole(db);
            break;
        case 2:
            DeleteTriangleFromConsole(db);
            break;
        case 3:
            FindTriangleFromConsole(db);
            break;
        case 4:
            SortDatabaseFromConsole(db);
            break;
        case 5:
            PrintDatabase(db);
            break;
        case 6:
            free(db->triangles);
            free(db);
            return 0;
        default:
            printf("Неверная команда. Пожалуйста, попробуйте снова.\n");
        }
    }
    return 0;
}
