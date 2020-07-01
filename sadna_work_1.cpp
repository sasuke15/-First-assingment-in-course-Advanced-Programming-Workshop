

/*
Assigend by:
Shay Bach #204263842,:61108
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define a 3
#define b 2
#define c 3
typedef struct node {
    int data;
    int raw;
    int claw;
    struct node* next;
} Node;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */

/* ------------------------------- */

/* Function definitions */

/* ------------------- */

/* ------------------- */

void free_mat_or_list(int** mat, int n, Node* list)
{
    int i;
    Node* curr;

    if (n != 0) {
        for (i = 0; n > i; i++)
            free(mat[i]);

        free(mat);
    }

    else
        while (list != NULL) {

            curr = list;

            list = list->next;

            free(curr);
        }
}
int** create_mat(int n, int m)
{
    int **mat, i;

    mat = (int**)malloc(n * sizeof(int*));

    for (i = 0; n > i; i++)
        mat[i] = (int*)malloc(m * sizeof(int));

    return mat;
}

/* Exercise1 */

void help_funk1(unsigned int* p, unsigned int n)
{
    int i, j;

    printf("the arry valiues are:\n");

    for (i = 0; n > i; i++)
        if (i % 32 == 31)
            printf("2147483648\t");
        else
            printf("%d\t", p[i]);

    printf("\n\n");
}
unsigned int* powerArry(int n)
{
    unsigned int* p;
    unsigned int i, j;

    p = (unsigned int*)malloc(n * sizeof(unsigned int));

    for (i = 0; n > i; i++) {
        if (i % 32 == 0)
            p[i] = 1;

        else
            p[i] = (p[i - 1] * 2);
    }

    return p;
}
void Ex1()
{
    unsigned int *p, n, i;

    printf("plese enter the size of the arry\n");
    scanf("%d", &n);
    printf("\n");

    p = powerArry(n);

    help_funk1(p, n);

    free(p);
}

/* Exercise2 */

void help_funk2(int mat1[a][b], int mat2[b][c], int** result_mat)
{
    int i, j;

    printf(" the metrix\n ");

    for (i = 0; a > i; i++) {

        for (j = 0; b > j; j++)
            printf("%d\t", mat1[i][j]);

        printf("\n");
    }

    printf("\n");

    for (i = 0; b > i; i++) {

        for (j = 0; c > j; j++)
            printf("%d\t", mat2[i][j]);

        printf("\n");
    }

    printf(" the result\n\n");

    for (i = 0; a > i; i++) {

        for (j = 0; c > j; j++)
            printf("%d\t", result_mat[i][j]);

        printf("\n");
    }
}
int** time_mat(int mat1[a][b], int mat2[b][c])
{
    int** result_mat;
    int i, j, k;

    result_mat = create_mat(a, c);

    for (i = 0; a > i; i++)
        for (j = 0; c > j; j++) {
            result_mat[i][j] = 0;
            for (k = 0; b > k; k++)
                result_mat[i][j] += (mat1[i][k] * mat2[k][j]);
        }

    return result_mat;
}
void Ex2()
{
    int i, j;
    int mat1[a][b], mat2[b][c];
    int** result_mat;

    printf("please enter the values of the metrix sized %d %d", a, b);

    for (i = 0; a > i; i++)
        for (j = 0; b > j; j++)
            scanf("%d", &mat1[i][j]);

    printf("please enter the values of the metrix sized %d %d", b, c);

    for (i = 0; b > i; i++)
        for (j = 0; c > j; j++)
            scanf("%d", &mat2[i][j]);

    result_mat = time_mat(mat1, mat2);

    help_funk2(mat1, mat2, result_mat);

    free_mat_or_list(result_mat, a, NULL);
}

/* Exercise3 */

void help_funk3(int n, int m, int** mat, int count, Node* arr, Node* list)
{

    int i, j;
    Node* curr;

    printf("the metrix is\n\n");

    for (i = 0; n > i; i++) {

        for (j = 0; m > j; j++)
            printf("%d\t", mat[i][j]);

        printf("\n");
    }

    printf("\n the number of the times is %d \n\n ", count);

    printf(" the arry\n\n ");
    for (i = 0; count > i; i++)
        printf(" %d %d %d \n\n ", arr[i].data, arr[i].raw, arr[i].claw);

    curr = list;

    printf(" the list\n ");
    while (curr != NULL) {

        printf("%d %d %d\n\n", curr->data, curr->raw, curr->claw);
        curr = curr->next;
    }
}
int chek_mat(int n, int m, int** mat, Node** arr, Node** list)
{
    int i, j;
    int count = 0;
    Node* curr;

    *list = NULL;

    for (i = 0; n > i; i++)
        for (j = 0; m > j; j++)
            if (mat[i][j] == (i + j)) {

                if (*list == NULL) {
                    *list = (Node*)malloc(sizeof(Node));

                    (*list)->data = mat[i][j];

                    (*list)->raw = i;

                    (*list)->claw = j;
                    (*list)->next = NULL;
                }

                else {
                    curr = *list;

                    while (curr->next != NULL)
                        curr = curr->next;

                    curr->next = (Node*)malloc(sizeof(Node));

                    curr->next->data = mat[i][j];

                    curr->next->raw = i;

                    curr->next->claw = j;

                    curr->next->next = NULL;
                }

                ++count;
            }

    *arr = (Node*)malloc(count * sizeof(Node));

    count = 0;

    for (i = 0; n > i; i++)
        for (j = 0; m > j; j++)
            if (mat[i][j] == (i + j)) {

                (*arr)[count].data = mat[i][j];
                (*arr)[count].raw = i;
                (*arr)[count].claw = j;

                ++count;
            }

    return count;
}
void Ex3()
{

    int n, m;
    int i, j;
    int** mat;
    int count;

    Node* arr;
    Node* list;

    printf("please enter the size of the metrix\n\n");
    scanf("%d%d", &n, &m);

    mat = create_mat(n, m);

    printf("please enter the metrix");

    for (i = 0; n > i; i++)
        for (j = 0; m > j; j++)
            scanf("%d", &mat[i][j]);

    count = chek_mat(n, m, mat, &arr, &list);

    help_funk3(n, m, mat, count, arr, list);

    free_mat_or_list(mat, n, NULL);

    free_mat_or_list(NULL, 0, list);

    free(arr);
}

/*Exercise4 */

void help_funk4(Node* list)
{

    Node* curr;

    curr = list;

    printf("the list is\n\n");
    while (curr != NULL) {

        printf("%d\t", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
Node* chek_odd(Node** l)
{

    Node *ptr, *pre_ptr = NULL, *odd_ptr = NULL;
    Node* l_odd = NULL;
    ptr = (*l);

    while (ptr != NULL) {

        if (ptr->data % 2 != 0) {
            if (ptr == *l) {

                if (l_odd == NULL) {

                    l_odd = (Node*)malloc(sizeof(Node));

                    l_odd->data = ptr->data;

                    l_odd->next = NULL;

                    odd_ptr = l_odd;

                    (*l) = (*l)->next;

                    free(ptr);

                    ptr = (*l);
                }

                else {
                    odd_ptr->next = (Node*)malloc(sizeof(Node));

                    odd_ptr = odd_ptr->next;

                    odd_ptr->data = ptr->data;

                    odd_ptr->next = NULL;

                    (*l) = (*l)->next;

                    free(ptr);

                    ptr = (*l);
                }
            }
            else {
                if (l_odd == NULL) {
                    l_odd = (Node*)malloc(sizeof(Node));

                    l_odd->data = ptr->data;

                    l_odd->next = NULL;

                    odd_ptr = l_odd;

                    pre_ptr->next = ptr->next;

                    free(ptr);

                    ptr = pre_ptr->next;
                }
                else {
                    odd_ptr->next = (Node*)malloc(sizeof(Node));
                    odd_ptr = odd_ptr->next;
                    odd_ptr->data = ptr->data;
                    odd_ptr->next = NULL;
                    pre_ptr->next = ptr->next;
                    free(ptr);
                    ptr = pre_ptr->next;
                }
            }
        }
        else

        {

            pre_ptr = ptr;
            ptr = ptr->next;
        }
    }

    return l_odd;
}
Node* creat_list()
{

    int num;

    Node* list = NULL;

    Node* curr;
    printf("enter the numbers of the list\n\n");
    scanf("%d", &num);

    while (num >= 0) {

        if (list == NULL) {

            list = (Node*)malloc(sizeof(Node));

            list->data = num;

            list->next = NULL;
        }

        else {

            curr = list;

            while (curr->next != NULL)
                curr = curr->next;

            curr->next = (Node*)malloc(sizeof(Node));

            curr->next->data = num;

            curr->next->next = NULL;
        }

        scanf("%d", &num);
    }

    return list;
}
void Ex4()
{

    Node* list;

    Node* odd;

    list = creat_list();

    help_funk4(list);

    odd = chek_odd(&list);

    help_funk4(list);

    help_funk4(odd);

    free_mat_or_list(NULL, 0, list);

    free_mat_or_list(NULL, 0, odd);
}

/* Exercise5 */

void help_funk5(Node* list)
{

    Node* curr;

    curr = list;
    printf(" the list is\n\n ");
    while (curr != NULL) {

        printf("%d\t", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
Node* chek_odd2(Node** l)
{

    Node *ptr, *temp, *pre_ptr = NULL, *odd_ptr = NULL;
    Node* l_odd = NULL;
    ptr = (*l);

    while (ptr != NULL) {
        if (ptr->data % 2 != 0) {

            if (ptr == *l) {

                if (l_odd == NULL) {
                    l_odd = (*l);
                    (*l) = (*l)->next;
                    ptr = (*l);
                    odd_ptr = l_odd;
                    odd_ptr->next = NULL;
                }

                else {

                    odd_ptr->next = (*l);
                    (*l) = (*l)->next;
                    ptr = (*l);
                    odd_ptr = odd_ptr->next;
                    odd_ptr->next = NULL;
                }
            }
            else {
                if (l_odd == NULL) {
                    pre_ptr->next = ptr->next;
                    odd_ptr = ptr;
                    l_odd = odd_ptr;
                    odd_ptr->next = NULL;
                    ptr = pre_ptr->next;
                }
                else {
                    pre_ptr->next = ptr->next;
                    odd_ptr->next = ptr;
                    odd_ptr = odd_ptr->next;
                    odd_ptr->next = NULL;
                    ptr = pre_ptr->next;
                }
            }
        }
        else {
            pre_ptr = ptr;
            ptr = ptr->next;
        }
    }
    return l_odd;
}
Node* creat_list2()
{

    int num;

    Node* list = NULL;

    Node* curr;

    scanf("%d", &num);

    while (num >= 0) {

        if (list == NULL) {

            list = (Node*)malloc(sizeof(Node));

            list->data = num;

            list->next = NULL;
        }

        else {

            curr = list;

            while (curr->next != NULL)
                curr = curr->next;

            curr->next = (Node*)malloc(sizeof(Node));

            curr->next->data = num;

            curr->next->next = NULL;
        }

        scanf("%d", &num);
    }

    return list;
}
void Ex5()
{

    Node* list;

    Node* odd;

    list = creat_list2();

    help_funk5(list);

    odd = chek_odd2(&list);

    help_funk5(list);

    help_funk5(odd);

    free_mat_or_list(NULL, 0, list);

    free_mat_or_list(NULL, 0, odd);
}

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= 5; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-5 : ");
                scanf("%d", &select);
            } while ((select < 0) || (select > 5));
            switch (select) {
            case 1:
                Ex1();
                break;
            case 2:
                Ex2();
                break;
            case 3:
                Ex3();
                break;
            case 4:
                Ex4();
                break;
            case 5:
                Ex5();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}


