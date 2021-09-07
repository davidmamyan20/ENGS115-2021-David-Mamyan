#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <time.h>

int** create_matrix(int n)
{
    int** m = new int*[n];
    for (int i = 0; i < n; ++i) {
        m[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = 0;
        }
    }
    return m;
}

void delete_matrix(int** m, int n)
{
    for (int i = 0; i < n; ++i) {
        delete [] m[i];
    }
    delete [] m;
}

void fill_matrix_with_random_elements(int** m, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int r = rand() % 2;
            m[i][j] = r;
        }
    }
}

void print_matrix(int** m, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

bool check_all_elements_in_row_are_zero(int** a, int n, int i)
{
    assert(i >= 0);
    assert(i < n);
    for (int j = 0; j < n; ++j) {
        if (a[i][j] != 0) {
            return false;
        }
    }
    return true;
}

bool check_all_elements_in_column_are_zero(int** a, int n, int i)
{
    assert(i >= 0);
    assert(i < n);
    for (int j = 0; j < n; ++j) {
        if (a[j][i] != 0) {
            return false;
        }
    }
    return true;
}

void check_for_zero(int** m, int n)
{
    for (int i = 0; i < n; ++i) {
        bool b = check_all_elements_in_row_are_zero(m, n, i);
        bool x = check_all_elements_in_column_are_zero(m, n, i);
        if (b) {
            printf("all elements in row %d are zero\n", i);
            break;
        }
        if (x) {
            printf("all elements in column %d are zero\n", i);
            break;
        }
    }
}

int main()
{
    int n = 0;
    // Use current time as seed for random generator
    srand(time(0));
    printf("Enter array size: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input, exiting...\n");
        return EXIT_FAILURE;
    }
    int** matrix = create_matrix(n);
    fill_matrix_with_random_elements(matrix, n);
    print_matrix(matrix, n);
    check_for_zero(matrix, n);
    return EXIT_SUCCESS;
}


