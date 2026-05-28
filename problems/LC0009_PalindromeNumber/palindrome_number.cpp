#include <iostream>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // отрицательное число - не палиндром из-за минуса в записи
        if (x < 0) return false;
        // числа, оканчивающиеся на нуль (кроме самого нуля) - не палиндромы 
        if (x % 10 == 0 && x != 0) return false;
        int rev_half = 0;
        // приводим х к первой половине числа, формируем rev_half как реверс второй половины
        while (x > rev_half)
        {
            int digit = x % 10;
            rev_half = rev_half * 10 + digit;
            x /= 10;
        }
        // если длина чётная: x == rev_half
        // если длина нечётная, то отбрасываем последнюю цифру, 
        // чтобы не сравнивать её с самой собой: x == rev_half / 10
        return (x == rev_half) || (x == rev_half / 10);
    }
};

// Вспомогательная функция для тестов
bool run_test(int x, bool expected) 
{
    Solution s;
    bool got = s.isPalindrome(x);
    if (got != expected) 
    {
        std::cerr << "Test failed: input = " << x << " expected = " << (expected ? "true" : "false") << " got = " << (got ? "true" : "false") << "\n";
        return false;
    }
    return true;
}

int main() 
{
    // Базовые тесты
    if (!run_test(121, true)) return 1;
    if (!run_test(-121, false)) return 1;
    if (!run_test(10, false)) return 1;
    if (!run_test(0, true)) return 1;
    if (!run_test(12321, true)) return 1;
    if (!run_test(1221, true)) return 1;
    if (!run_test(2147447412, true)) return 1; // палиндром в пределах int
    if (!run_test(1000021, false)) return 1;   // заканчивается нулём + не палиндром

    std::cout << "OK\n";
    return 0;
}








