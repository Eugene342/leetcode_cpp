#include <vector>
#include <iostream>
#include <algorithm>

class Solution 
{
public:
    // Двухуказательный подход:
    // Инициализируем left = 0, right = n-1 и двигаем указатель, указывающий на меньшую высоту.
    // Для каждой пары вычисляем площадь: (right-left) * min(height[left], height[right])
    // Время: O(n), память: O(1)
    int maxArea(const std::vector<int>& height) 
    {
        if (height.size() < 2) return 0; // защитный случай для локального запуска
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_area = 0;
        while (left < right) 
        {
            // ширина текущего контейнера
            int current_width = right - left;
            // высота ограничивается минимальной из двух стенок
            int current_height = std::min(height[left], height[right]);
            int current_area = current_width * current_height;
            max_area = std::max(max_area, current_area);
            // передвигаем тот указатель, у которого меньшая высота,
            // потому что сдвиг более высокой стены потенциально не увеличит высоту,
            // а сдвиг более низкой может найти большую высоту и компенсировать уменьшение ширины
            if (height[left] < height[right]) 
            {
                ++left;
            }
            else 
            {
                --right;
            }
        }
        return max_area;
    }
};

// Вспомогательная функция для тестов: проверяет, что решение даёт ожидаемый результат.
bool check_case(const std::vector<int>& height, int expected) 
{
    Solution sol;
    int got = sol.maxArea(height);
    if (got != expected) 
    {
        std::cerr << "Fail: expected " << expected << " but got " << got << "\n";
        return false;
    }
    return true;
}

int main() 
{
    // Примеры и базовые тесты
    if (!check_case({ 1,8,6,2,5,4,8,3,7 }, 49)) return 1;        // пример -> 49
    if (!check_case({ 1,1 }, 1)) return 1;                       // два столбца -> площадь 1
    if (!check_case({ 4,3,2,1,4 }, 16)) return 1;                // симметрично -> 16
    if (!check_case({ 1,2,1 }, 2)) return 1;                     // маленький пример -> 2
    if (!check_case({}, 0)) return 1;                          // пустой массив -> 0 (локальная защита)
    cout << "OK\n";
    return 0;
}








