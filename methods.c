#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "methods.h"
#define M_PI 3.14159265358979323846

Triangle* CreateTriangle(float side_1, float side_2, float side_3) 
{
    Triangle* triangle = malloc(sizeof(Triangle));
    if (!triangle) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    triangle->side_1 = side_1;
    triangle->side_2 = side_2;
    triangle->side_3 = side_3;
    if (triangle->side_1 + triangle->side_2 > triangle->side_3 &&
        triangle->side_1 + triangle->side_3 > triangle->side_2 &&
        triangle->side_2 + triangle->side_3 > triangle->side_1)
    {
        return triangle;
    }
    else 
    {
        printf("Не является треугольником\n");
        free(triangle);
        return NULL;
    }
}

void PrintTriangle(const Triangle* triangle) 
{
    printf("Стороны треугольника: %f %f %f\n", triangle->side_1, triangle->side_2, triangle->side_3);
}

float Perimeter(const Triangle* triangle)
{
    return triangle->side_1 + triangle->side_2 + triangle->side_3;
}

float Area(const Triangle* triangle) 
{
    float s = (triangle->side_1 + triangle->side_2 + triangle->side_3) / 2;
    return sqrt(s * (s - triangle->side_1) * (s - triangle->side_2) * (s - triangle->side_3));
}

void FindAngles(const Triangle* triangle, float* alpha, float* beta, float* gamma) 
{
    float a = triangle->side_1;
    float b = triangle->side_2;
    float c = triangle->side_3;
    float cos_alpha = (b * b + c * c - a * a) / (2 * b * c);
    float cos_beta = (a * a + c * c - b * b) / (2 * a * c);
    float cos_gamma = (a * a + b * b - c * c) / (2 * a * b);
    *alpha = acos(cos_alpha) * 180 / M_PI;
    *beta = acos(cos_beta) * 180 / M_PI;
    *gamma = acos(cos_gamma) * 180 / M_PI;
}

void PrintTriangleAngles(float alpha, float beta, float gamma)
{
    printf("Угол альфа: %.2f градусов\n", alpha);
    printf("Угол бетта: %.2f градусов\n", beta);
    printf("Угол гамма: %.2f градусов\n", gamma);
}

TriangleDatabase* CreateDatabase(size_t initial_capacity)
{
    TriangleDatabase* db = malloc(sizeof(TriangleDatabase));
    if (!db)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    db->triangles = malloc(initial_capacity * sizeof(Triangle));
    if (!db->triangles) {
        free(db);
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    db->size = 0;
    db->capacity = initial_capacity;
    return db;
}


void FindTrianglesBySide(const TriangleDatabase* db, int side_choice, float side_value) 
{
    int found = 0;
    for (size_t i = 0; i < db->size; i++) 
    {
        switch (side_choice) {
        case 1:
            if (db->triangles[i].side_1 == side_value) 
            {
                found = 1;
                PrintTriangle(&db->triangles[i]);
            }
            break;
        case 2:
            if (db->triangles[i].side_2 == side_value)
            {
                found = 1;
                PrintTriangle(&db->triangles[i]);
            }
            break;
        case 3:
            if (db->triangles[i].side_3 == side_value) 
            {
                found = 1;
                PrintTriangle(&db->triangles[i]);
            }
            break;
        default:
            printf("Неправильный выбор стороны для поиска.\n");
            return;
        }
    }
    if (!found) 
    {
        printf("Треугольники с указанным значением стороны не найдены.\n");
    }
}

void DeleteTrianglesBySide(TriangleDatabase* db, int side_choice, float side_value) 
{
    size_t new_size = 0;
    for (size_t i = 0; i < db->size; i++) {
        int delete_flag = 0;
        switch (side_choice) {
        case 1:
            if (db->triangles[i].side_1 == side_value) 
            {
                delete_flag = 1;
            }
            break;
        case 2:
            if (db->triangles[i].side_2 == side_value)
            {
                delete_flag = 1;
            }
            break;
        case 3:
            if (db->triangles[i].side_3 == side_value) 
            {
                delete_flag = 1;
            }
            break;
        default:
            printf("Неправильный выбор стороны для удаления.\n");
            return;
        }
        if (!delete_flag)
        {
            db->triangles[new_size++] = db->triangles[i];
        }
    }
    db->size = new_size;
}

void SortDatabaseBySide(TriangleDatabase* db, int side_choice) 
{
    if (side_choice < 1 || side_choice > 3) 
    {
        printf("Неправильный выбор стороны для сортировки.\n");
        return;
    }

    for (size_t i = 0; i < db->size - 1; i++)
    {
        for (size_t j = i + 1; j < db->size; j++) 
        {
            float side_i, side_j;
            switch (side_choice) 
            {
            case 1:
                side_i = db->triangles[i].side_1;
                side_j = db->triangles[j].side_1;
                break;
            case 2:
                side_i = db->triangles[i].side_2;
                side_j = db->triangles[j].side_2;
                break;
            case 3:
                side_i = db->triangles[i].side_3;
                side_j = db->triangles[j].side_3;
                break;
            default:
                printf("Неправильный выбор стороны для сортировки.\n");
                return;
            }
            if (side_i > side_j)
            {
                Triangle temp = db->triangles[i];
                db->triangles[i] = db->triangles[j];
                db->triangles[j] = temp;
            }
        }
    }
}



void AddTriangle(TriangleDatabase* db, Triangle triangle) 
{
    if (db->size >= db->capacity) 
    {
        db->capacity *= 2;
        db->triangles = realloc(db->triangles, db->capacity * sizeof(Triangle));
        if (!db->triangles)
        {
            printf("Ошибка выделения памяти\n");
            return;
        }
    }

    db->triangles[db->size++] = triangle;
}

void PrintDatabase(const TriangleDatabase* db)
{
    for (size_t i = 0; i < db->size; i++) 
    {
        PrintTriangle(&db->triangles[i]);
    }
}

void AddTriangleFromConsole(TriangleDatabase* db)
{
    float side_1, side_2, side_3;
    printf("Введите стороны треугольника: ");
    scanf_s("%f %f %f", &side_1, &side_2, &side_3);

    Triangle* triangle = CreateTriangle(side_1, side_2, side_3);
    if (triangle)
    {
        AddTriangle(db, *triangle);
        free(triangle);
    }
}

void DeleteTriangleFromConsole(TriangleDatabase* db) 
{
    int side_choice;
    printf("Выберите сторону треугольника для удаления (1 - side_1, 2 - side_2, 3 - side_3): ");
    scanf_s("%d", &side_choice);

    float side_value;
    printf("Введите значение стороны треугольника для удаления: ");
    scanf_s("%f", &side_value);
    DeleteTrianglesBySide(db, side_choice, side_value);
}

void FindTriangleFromConsole(const TriangleDatabase* db)
{
    int side_choice;
    printf("Выберите сторону треугольника для поиска (1 - side_1, 2 - side_2, 3 - side_3): ");
    scanf_s("%d", &side_choice);
    float side_value;
    printf("Введите значение стороны треугольника для поиска: ");
    scanf_s("%f", &side_value);
    FindTrianglesBySide(db, side_choice, side_value);
}

void SortDatabaseFromConsole(TriangleDatabase* db)
{
    int side_choice;
    printf("Выберите сторону для сортировки (1 - side_1, 2 - side_2, 3 - side_3): ");
    scanf_s("%d", &side_choice);
    SortDatabaseBySide(db, side_choice);
    printf("База данных отсортирована.\n");
}
