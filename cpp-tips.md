# CPP Tips

加入以下代码段以提高性能：

```cpp
static int x = [] () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
} ();
```
