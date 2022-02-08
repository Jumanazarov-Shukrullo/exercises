/// The algorithm to find the max subarry sum
/// the problem can be solved in 3 different time complexities as in cubic,square and linear

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

///Solve in cubic time
size_t CubicMaxSubSum(std::vector<int>& arr) {
        int best = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
                for(size_t j = i; j < arr.size(); ++j) {
                        int sum = 0;
                        for (size_t k = i; k <= j; ++k)
                                sum += arr[k];
                best = max(best, sum);
                }
        }
        return best;
}

/// Solve in square time
size_t SquareMaxSubSum(std::vector<int>& arr) {
        int best = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
                int sum = 0;
                for(size_t j = i; j < arr.size(); ++j) {
                        sum += arr[j];
                        best = max(best, sum);
                }
        }
        return best;
}

/// Solve in linear time
size_t LinearMaxSubSum(std::vector<int>& arr) {
        int best = 0, sum = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
                sum = max(arr[i],sum + arr[i]);
                best = max(sum, best);
        }
        return best;
}

int main() {
        std::vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};
        std::cout << CubicMaxSubSum(arr) << std::endl;
        std::cout << SquareMaxSubSum(arr) << std::endl;
        std::cout << LinearMaxSubSum(arr) << std::endl;
}
