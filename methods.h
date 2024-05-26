#include <stdio.h> 
#include <stdlib.h> 
typedef struct Triangle Triangle;
typedef struct TriangleDatabase TriangleDatabase;
/**
 * @brief �������� ������������ � ��������� ���������
 * @param side_1 ����� ������ ������� ������������
 * @param side_2 ����� ������ ������� ������������
 * @param side_3 ����� ������� ������� ������������
 * @return ��������� �� ��������� �����������, ��� NULL, ���� ����������� ���������� �������
 */
Triangle* CreateTriangle(double side_1, double side_2, double side_3);

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
double Perimeter(const Triangle* triangle);

/**
 * @brief ���������� ������� ������������ �� ������� ������
 * @param triangle ��������� �� �����������
 * @return �������� ������� ������������
 */

double Area(const Triangle* triangle);

/**
 * @brief ���������� ����� ������������ � ��������
 * @param triangle ��������� �� �����������
 * @param alpha ��������� �� ����������, � ������� ����� ������� ���� �����
 * @param beta ��������� �� ����������, � ������� ����� ������� ���� �����
 * @param gamma ��������� �� ����������, � ������� ����� ������� ���� �����
 */
void FindAngles(const Triangle* triangle, double* alpha, double* beta, double* gamma);

/**
 * @brief ����� ����� ������������ � ��������
 * @param alpha ���� �����
 * @param beta ���� �����
 * @param gamma ���� �����
 */
void PrintTriangleAngles(double alpha, double beta, double gamma);

/**
 * @brief ����� ������������� �� ����� ������� � ���� ������ � ����� ���������� � ���
 * @param db ��������� �� ���� ������ �������������
 * @param side_choice ����� ������� ������������ ��� ������ (1 - ������� 1, 2 - ������� 2, 3 - ������� 3)
 * @param side_value �������� ����� ������� ��� ������
 */
void FindTrianglesBySide(const TriangleDatabase* db, int side_choice, double side_value);

/**
 * @brief �������� ������������� �� ���� ������ �� �������� ����� �������
 * @param db ��������� �� ���� ������ �������������
 * @param side_choice ����� ������� ������������ ��� �������� (1 - ������� 1, 2 - ������� 2, 3 - ������� 3)
 * @param side_value �������� ����� ������� ��� ��������
 */
void DeleteTrianglesBySide(TriangleDatabase* db, int side_choice, double side_value);

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

void DeleteDatabase(struct TriangleDatabase* db);
