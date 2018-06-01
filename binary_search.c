/* ２分探索（経過を表示） */

#include <stdio.h>
#include <stdlib.h>



/*--- 開始時の一番上の要素数を表示する ---*/
void start(int n)
{
    int i;

    printf("   |");
    for (i = 0; i < n; i++) {
        printf("   %d", i);
    }
    putchar('\n');

    printf("---+");

    for(i = 0; i < n; i++) {
        printf("----");
    }

    putchar('\n');
}

/*--- 探索範囲を表示 ---*/
void disp(int n, const int a[], int low, int high, int mid)
{
    int i;

    printf("   |");

    for (i = 0; i <= high; i++) {
        if (i == low)
            printf("   <");
        else if (i == mid)
            printf("   +");
        else if (i == high)
            printf("   >\n");
        else
            printf("    ");
    }

    printf("  %d|", mid);
    for (i = 0; i < n; i++) {
        printf("   %d", a[i]);
    }

    putchar('\n');

    printf("   |");
    /*
    for(i = 0; i < n; i++) {
        printf("----");
    }
    */
    putchar('\n');

}

/*--- ２分探索処理 ---*/
int bin_search(const int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    start(n);
    
    do {
        mid = (low + high) / 2;
        disp(n, a, low, high, mid);
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;

    } while(low <= high);


    return -1;
}


int main(void)
{
    int i, nx, ky, idx;
    int low, high, mid;
    int *x;

    printf("２分探索\n");
    printf("要素数 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    

    for (i = 0; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i-1]);
    }
    
    printf("検索する値 : ");
    scanf("%d", &ky);

    idx = bin_search(x, nx, ky);

    if(idx == -1)
        printf("探索に失敗しました。\n");
    else
        printf("%dはx[%d]にあります。\n", ky, idx);

    free(x);

    return 0;
}