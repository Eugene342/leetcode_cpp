#include <iostream>   // для std::cout, std::cerr
#include <vector>     // для std::vector

// Класс с решением задачи "Remove Duplicates from Sorted Array" (LeetCode 26).
class Solution 
{
public:
    // Метод реализует подход "два указателя" (two pointers).
    // Принимает ссылку на вектор nums и возвращает количество уникальных элементов k.
    int removeDuplicates(std::vector<int>& nums) 
    {
        // Если массив пуст — ничего делать не надо, возвращаем 0.
        if (nums.empty()) return 0;

        // slow — индекс последнего уникального элемента в левом "сжатом" сегменте.
        int slow = 0;

        // fast проходит по всем элементам массива, начиная с 1.
        // static_cast<int>(nums.size()) — чтобы избежать предупреждений о сравнении signed/unsigned.
        for (int fast = 1; fast < static_cast<int>(nums.size()); ++fast) 
        {
            // Если текущий элемент отличается от элемента на позиции slow,
            // значит найден новый уникальный элемент.
            if (nums[fast] != nums[slow]) 
            {
                ++slow;                    // продвинуть slow на следующую позицию
                nums[slow] = nums[fast];   // записать найденный уникальный элемент
            }
            // Если nums[fast] == nums[slow], это дубликат — просто пропускаем.
        }

        // Количество уникальных элементов равно индексу slow + 1.
        return slow + 1;
    }
};

int main() 
{
    Solution sol;

    // Пример входных данных (отсортированный массив с дубликатами).
    std::vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };

    // Ожидаемый результат первых k элементов после удаления дубликатов.
    std::vector<int> expected = { 0,1,2,3,4 };

    // Вызов нашей функции.
    int k = sol.removeDuplicates(nums);

    // Проверяем, что возвращённое k соответствует ожидаемой длине.
    if (k != static_cast<int>(expected.size())) {
        std::cerr << "Wrong k: " << k << " expected " << expected.size() << "\n";
        return 1; // ненулевой код — удобен для CI/ctest, будет означать провал теста
    }

    // Проверяем, что первые k элементов массива совпадают с expected поэлементно.
    for (int i = 0; i < k; ++i) {
        if (nums[i] != expected[i]) {
            std::cerr << "Mismatch at " << i << ": got " << nums[i]
                << " expected " << expected[i] << "\n";
            return 1; // провал теста
        }
    }

    // Если все проверки прошли — печатаем OK и возвращаем 0.
    std::cout << "OK\n";
    return 0;
}



