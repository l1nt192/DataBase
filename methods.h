#include <stddef.h>
typedef struct
{
    float side_1;
    float side_2;
    float side_3;
} Triangle;

typedef struct 
{
    Triangle* triangles;
    size_t size;
    size_t capacity;
} TriangleDatabase;

/**
 * @brief Создание треугольника с заданными сторонами
 * @param side_1 Длина первой стороны треугольника
 * @param side_2 Длина второй стороны треугольника
 * @param side_3 Длина третьей стороны треугольника
 * @return Указатель на созданный треугольник, или NULL, если треугольник невозможно создать
 */
Triangle* CreateTriangle(float side_1, float side_2, float side_3);

/**
 * @brief Вывод информации о треугольнике
 * @param triangle Указатель на треугольник, информацию о котором нужно вывести
 */
void PrintTriangle(const Triangle* triangle);

/**
 * @brief Вычисление периметра треугольника
 * @param triangle Указатель на треугольник
 * @return Значение периметра треугольника
 */
float Perimeter(const Triangle* triangle);

/**
 * @brief Вычисление площади треугольника по формуле Герона
 * @param triangle Указатель на треугольник
 * @return Значение площади треугольника
 */
float Area(const Triangle* triangle);

/**
 * @brief Нахождение углов треугольника в градусах
 * @param triangle Указатель на треугольник
 * @param alpha Указатель на переменную, в которую будет записан угол альфа
 * @param beta Указатель на переменную, в которую будет записан угол бетта
 * @param gamma Указатель на переменную, в которую будет записан угол гамма
 */
void FindAngles(const Triangle* triangle, float* alpha, float* beta, float* gamma);

/**
 * @brief Вывод углов треугольника в градусах
 * @param alpha Угол альфа
 * @param beta Угол бетта
 * @param gamma Угол гамма
 */
void PrintTriangleAngles(float alpha, float beta, float gamma);

/**
 * @brief Поиск треугольников по длине стороны в базе данных и вывод информации о них
 * @param db Указатель на базу данных треугольников
 * @param side_choice Выбор стороны треугольника для поиска (1 - сторона 1, 2 - сторона 2, 3 - сторона 3)
 * @param side_value Значение длины стороны для поиска
 */
void FindTrianglesBySide(const TriangleDatabase* db, int side_choice, float side_value);

/**
 * @brief Удаление треугольников из базы данных по заданной длине стороны
 * @param db Указатель на базу данных треугольников
 * @param side_choice Выбор стороны треугольника для удаления (1 - сторона 1, 2 - сторона 2, 3 - сторона 3)
 * @param side_value Значение длины стороны для удаления
 */
void DeleteTrianglesBySide(TriangleDatabase* db, int side_choice, float side_value);

/**
 * @brief Сортировка базы данных треугольников по длине заданной стороны
 * @param db Указатель на базу данных треугольников
 * @param side_choice Выбор стороны треугольника для сортировки (1 - сторона 1, 2 - сторона 2, 3 - сторона 3)
 */
void SortDatabaseBySide(TriangleDatabase* db, int side_choice);

/**
 * @brief Создание базы данных треугольников с начальной емкостью
 * @param initial_capacity Начальная емкость базы данных
 * @return Указатель на созданную базу данных треугольников
 */
TriangleDatabase* CreateDatabase(size_t initial_capacity);

/**
 * @brief Добавление треугольника в базу данных
 * @param db Указатель на базу данных треугольников
 * @param triangle Треугольник для добавления
 */
void AddTriangle(TriangleDatabase* db, Triangle triangle);

/**
 * @brief Вывод содержимого базы данных треугольников
 * @param db Указатель на базу данных треугольников
 */
void PrintDatabase(const TriangleDatabase* db);

/**
 * @brief Добавление треугольника в базу данных с вводом данных с консоли
 * @param db Указатель на базу данных треугольников
 */
void AddTriangleFromConsole(TriangleDatabase* db);

/**
 * @brief Удаление треугольников из базы данных с вводом данных с консоли
 * @param db Указатель на базу данных треугольников
 */
void DeleteTriangleFromConsole(TriangleDatabase* db);

/**
 * @brief Поиск треугольника в базе данных с вводом данных с консоли
 * @param db Указатель на базу данных треугольников
 */
void FindTriangleFromConsole(const TriangleDatabase* db);

/**
 * @brief Сортировка базы данных треугольников с вводом данных с консоли
 * @param db Указатель на базу данных треугольников
 */
void SortDatabaseFromConsole(TriangleDatabase* db);
