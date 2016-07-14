#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void printMatrix(int *arr, int *row, int *col, int *row_defect, int *col_defect, int dimen_matrix);

int find_Closed_Defect_Row(int *row, int dimen_matrix);
int find_Closed_Defect_Col(int *col, int dimen_matrix);

void traverse_in_the_Row(int *arr, int *row, int dimen_matrix);
void traverse_in_the_Col(int *arr, int *col, int dimen_matrix);
