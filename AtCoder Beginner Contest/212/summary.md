# AtCoder Beginner Contest 212 2021-7-31
## A
+ type:implementation
+ diff:5
## B
+ type:implementation
+ diff:64
## C
+ type:binary_search / two_pointer
+ diff:246
+ tips:
    - 返回b[0]的边界情况处理
    b[0] = b[1];
    *(upper_bound(b + 1, b + m + 1, a[k]) - 1);
## D
+ type:priority_queue + partial_sum
+ diff:775
+ tips:
    - priority_queue<T, vector<T>, greater<T>> q;
