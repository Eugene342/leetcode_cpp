#include <algorithm> // std::remove
#include <vector>
#include <iostream>
#include <cassert>

// Решение: использовать std::remove, который сдвигает все элементы != val в начало контейнера
// и возвращает итератор на новую "конец" логического массива.
// Время: O(n), Память: O(1) дополнительной.
class Solution 
{
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        auto it = std::remove(nums.begin(), nums.end(), val);
        return static_cast<int>(std::distance(nums.begin(), it));
    }
};

// Простая функция-помощник для проверки результата:
// проверяем, что returned_k совпадает с ожидаемым (если указано) и что
// в первых k элементах нет значения val.
bool check_result(std::vector<int> nums, int val, int expected_k = -1) 
{
    Solution sol;
    int k = sol.removeElement(nums, val);
    if (expected_k >= 0 && k != expected_k) return false;
    for (int i = 0; i < k; ++i) {
        if (nums[i] == val) return false;
    }
    return true;
}

int main() 
{
    // Примеры из LeetCode
    if (!check_result({ 3,2,2,3 }, 3, 2)) 
    {
        std::cerr << "Test1 failed\n";
        return 1;
    }
    if (!check_result({ 0,1,2,2,3,0,4,2 }, 2, 5)) 
    {
        std::cerr << "Test2 failed\n";
        return 1;
    }

    // Доп. проверка: удаляем элемент которого нет
    if (!check_result({ 1,2,3,4 }, 5, 4)) 
    {
        std::cerr << "Test3 failed\n";
        return 1;
    }
    std::cout << "OK\n";
    return 0;
}








