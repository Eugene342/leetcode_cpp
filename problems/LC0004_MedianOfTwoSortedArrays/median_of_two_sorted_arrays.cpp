#include <vector>

class Solution 
{
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) 
    {
        // всегда бинарный поиск по меньшему массиву
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int low = 0, high = m;
        int half = (m + n + 1) / 2;
        while (low <= high) 
        {
            int i = (low + high) / 2; // взяли i элементов из nums1 в левую часть
            int j = half - i;        // и j элементов из nums2 в левую часть
            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];
            if (Aleft <= Bright && Bleft <= Aright) 
            {
                // корректная граница
                if ((m + n) % 2 == 1) 
                {
                    return static_cast<double>(std::max(Aleft, Bleft));
                }
                else 
                {
                    double left_max = static_cast<double>(std::max(Aleft, Bleft));
                    double right_min = static_cast<double>(std::min(Aright, Bright));
                    return (left_max + right_min) / 2.0;
                }
            }
            else if (Aleft > Bright) 
            {
                // нужно уменьшить i
                high = i - 1;
            }
            else 
            {
                // Bleft > Aright -> увеличить i
                low = i + 1;
            }
        }
        // По теории сюда не должны попадать (корректный ввод)
        return 0.0;
    }
};

// --- Тестовый код ниже ---
bool approx_eq(double a, double b, double eps = 1e-9) 
{
    return fabs(a - b) <= eps;
}
bool run_test(vector<int> a, vector<int> b, double expected) 
{
    Solution s;
    double got = s.findMedianSortedArrays(a, b);
    if (!approx_eq(got, expected)) 
    {
        std::cerr << "Test failed\n";
        std::cerr << "A: [";
        for (size_t i = 0; i < a.size(); ++i) 
        { 
            if (i) cerr << ","; cerr << a[i]; 
        }
        std::cerr << "]\nB: [";
        for (size_t i = 0; i < b.size(); ++i) 
        { 
            if (i) cerr << ","; cerr << b[i]; 
        }
        std::cerr << "]\n";
        std::cerr << "Expected: " << expected << " Got: " << got << "\n";
        return false;
    }
    return true;
}

int main() 
{
    // Примеры из задачи
    if (!run_test({ 1,3 }, { 2 }, 2.0)) return 1;            // -> 2.0
    if (!run_test({ 1,2 }, { 3,4 }, 2.5)) return 1;         // -> 2.5
    // Дополнительные тесты (разные длины, нули, отрицательные)
    if (!run_test({}, { 1 }, 1.0)) return 1;
    if (!run_test({ 2 }, {}, 2.0)) return 1;
    if (!run_test({ 0,0 }, { 0,0 }, 0.0)) return 1;
    if (!run_test({ 1,3,8,9,15 }, { 7,11,18,19,21,25 }, 11.0)) return 1; // even total: (11+11)/2
    if (!run_test({ 1,2 }, { -1,3 }, 1.5)) return 1;
    if (!run_test({ 1,2,3 }, { 4,5,6,7,8 }, 4.0)) return 1;
    std::cout << "OK\n";
    return 0;
}









