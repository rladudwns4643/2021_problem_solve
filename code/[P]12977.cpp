#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int a) {
    if (a < 2) return false;
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());

    //vector<bool> filter(nums.size(), false);
    //for (int i = 0; i < 3; ++i) filter[i] = true;
    //
    //do {
    //   int sum = 0;
    //    for (int i = 0; i < nums.size(); ++i) {
    //        if (filter[i]) {
    //            sum += nums[i];
    //        }
    //    }
    //    if (isPrime(sum)) ++answer;
    //} while (next_permutation(nums.begin(), nums.end()));

    
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (isPrime(sum)) ++answer;
            }
        }
    }
    return answer;
}