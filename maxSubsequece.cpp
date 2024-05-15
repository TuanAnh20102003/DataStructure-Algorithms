#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    int max_sum = INT_MIN, current_sum = 0, min_odd = INT_MAX;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
              current_sum = std::max(a[i], current_sum + a[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            if (max_sum % 2 != 0) {
                max_sum -= min_odd;
            }
        }
        if (a[i] % 2 != 0 && a[i] < min_odd) {
            min_odd = a[i];
        }
    }
    if (max_sum <= 0) {
        std::cout << "NOT_FOUND" << std::endl;
    } else {
        std::cout << max_sum << std::endl;
    }

    return 0;
}