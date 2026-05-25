# leetcode-cpp

Коллекция решений задач LeetCode на C++ с использованием CMake.

[![CI](https://github.com/Eugene342/leetcode_cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/Eugene342/leetcode_cpp/actions)

Содержимое репозитория:
- CMakeLists.txt — корневой файл CMake, автоматически собирает все задачи в папке `problems/`.
- problems/<task>/ — папки с задачами (каждая папка превращается в исполняемый файл и тест).
- .github/workflows/ci.yml — GitHub Actions workflow (матрица: ubuntu/macOS/Windows).

Как собрать локально:

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release --parallel
```

Как запустить тесты (ctest):

```bash
cd build
ctest --output-on-failure -C Release
```

Пример ожидаемого вывода ctest (если у вас одна задача `two_sum`, которая проходит):

```
Test project /path/to/leetcode-cpp/build
    Start 1: two_sum
1/1 Test #1: two_sum .........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
```

Как добавить новую задачу:
1. Создайте папку `problems/<task_name>`.
2. Добавьте файл `<task_name>.cpp` с реализацией и `main()` для self-test.
3. При следующем вызове `cmake ..` новая цель будет автоматически обнаружена.

Пример простого `main()` для self-test (возвращает 0 при успехе, !=0 при ошибке):

```cpp
int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    auto res = sol.twoSum(nums, 9);
    if (res.size() == 2) return 0;
    return 1;
}
```

Советы:
- Добавляйте в README краткое описание решения, сложность по времени/памяти и ссылку на задачу на LeetCode.
- Поддерживайте чистый стиль кода и комментарии.
- Регистрируйте тесты через `add_test` (уже включено в корневой CMake). 
