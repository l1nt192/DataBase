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
 * @brief �������� ������������ � ��������� ���������
 * @param side_1 ����� ������ ������� ������������
 * @param side_2 ����� ������ ������� ������������
 * @param side_3 ����� ������� ������� ������������
 * @return ��������� �� ��������� �����������, ��� NULL, ���� ����������� ���������� �������
 */
Triangle* CreateTriangle(float side_1, float side_2, float side_3);

/**
 * @brief ����� ���������� � ������������
 * @param triangle ��������� �� �����������, ���������� � ������� ����� �������
 */
void PrintTriangle(const Triangle* triangle);

/**
 * @brief ���������� ��������� ������������
 * @param triangle ��������� �� �����������
 * @return �������� ��������� ������������
 */
float Perimeter(const Triangle* triangle);

/**
 * @brief ���������� ������� ������������ �� ������� ������
 * @param triangle ��������� �� �����������
 * @return �������� ������� ������������
 */
float Area(const Triangle* triangle);

/**
 * @brief ���������� ����� ������������ � ��������
 * @param triangle ��������� �� �����������
 * @param alpha ��������� �� ����������, � ������� ����� ������� ���� �����
 * @param beta ��������� �� ����������, � ������� ����� ������� ���� �����
 * @param gamma ��������� �� ����������, � ������� ����� ������� ���� �����
 */
void FindAngles(const Triangle* triangle, float* alpha, float* beta, float* gamma);

/**
 * @brief ����� ����� ������������ � ��������
 * @param alpha ���� �����
 * @param beta ���� �����
 * @param gamma ���� �����
 */
void PrintTriangleAngles(float alpha, float beta, float gamma);

/**
 * @brief ����� ������������� �� ����� ������� � ���� ������ � ����� ���������� � ���
 * @param db ��������� �� ���� ������ �������������
 * @param side_choice ����� ������� ������������ ��� ������ (1 - ������� 1, 2 - ������� 2, 3 - ������� 3)
 * @param side_value �������� ����� ������� ��� ������
 */
void FindTrianglesBySide(const TriangleDatabase* db, int side_choice, float side_value);

/**
 * @brief �������� ������������� �� ���� ������ �� �������� ����� �������
 * @param db ��������� �� ���� ������ �������������
 * @param side_choice ����� ������� ������������ ��� �������� (1 - ������� 1, 2 - ������� 2, 3 - ������� 3)
 * @param side_value �������� ����� ������� ��� ��������
 */
void DeleteTrianglesBySide(TriangleDatabase* db, int side_choice, float side_value);

/**
 * @brief ���������� ���� ������ ������������� �� ����� �������� �������
 * @param db ��������� �� ���� ������ �������������
 * @param side_choice ����� ������� ������������ ��� ���������� (1 - ������� 1, 2 - ������� 2, 3 - ������� 3)
 */
void SortDatabaseBySide(TriangleDatabase* db, int side_choice);

/**
 * @brief �������� ���� ������ ������������� � ��������� ��������
 * @param initial_capacity ��������� ������� ���� ������
 * @return ��������� �� ��������� ���� ������ �������������
 */
TriangleDatabase* CreateDatabase(size_t initial_capacity);

/**
 * @brief ���������� ������������ � ���� ������
 * @param db ��������� �� ���� ������ �������������
 * @param triangle ����������� ��� ����������
 */
void AddTriangle(TriangleDatabase* db, Triangle triangle);

/**
 * @brief ����� ����������� ���� ������ �������������
 * @param db ��������� �� ���� ������ �������������
 */
void PrintDatabase(const TriangleDatabase* db);

/**
 * @brief ���������� ������������ � ���� ������ � ������ ������ � �������
 * @param db ��������� �� ���� ������ �������������
 */
void AddTriangleFromConsole(TriangleDatabase* db);

/**
 * @brief �������� ������������� �� ���� ������ � ������ ������ � �������
 * @param db ��������� �� ���� ������ �������������
 */
void DeleteTriangleFromConsole(TriangleDatabase* db);

/**
 * @brief ����� ������������ � ���� ������ � ������ ������ � �������
 * @param db ��������� �� ���� ������ �������������
 */
void FindTriangleFromConsole(const TriangleDatabase* db);

/**
 * @brief ���������� ���� ������ ������������� � ������ ������ � �������
 * @param db ��������� �� ���� ������ �������������
 */
void SortDatabaseFromConsole(TriangleDatabase* db);
