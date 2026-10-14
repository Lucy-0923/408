// 在升序数组中查找
int B_Search_up(int A[], int L, int R, int x)
{
    int l = L - 1;
    int r = R + 1;

    while (l + 1 != r)
    {
        int mid = l + (r - l) / 2;

        if (A[mid] < x)
            l = mid;
        else
            r = mid;
    }

    if (r <= R && A[r] == x)
        return r;

    return -1;
}


// 在降序数组中查找
int B_Search_down(int A[], int L, int R, int x)
{
    int l = L - 1;
    int r = R + 1;

    while (l + 1 != r)
    {
        int mid = l + (r - l) / 2;

        if (A[mid] > x)
            l = mid;
        else
            r = mid;
    }

    if (r <= R && A[r] == x)
        return r;

    return -1;
}


// 主函数
int ans(int A[], int n, int key)
{
    int i;

    // 在降序部分查找
    i = B_Search_down(A, 0, n / 2 - 1, key);

    if (i != -1)
        return i;

    // 在升序部分查找
    return B_Search_up(A, n / 2, n - 1, key);
}
