#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    int n;
    int result;
    int max_value = INT_MIN;
    std::vector<int> arr;
    std::vector<int> dp;
    std::cin>>n;

    arr.resize(n + 1);
    dp.resize(n + 1);

    bool flag = false;


    for(size_t i = 1; i <= n; i++)
    {
        std::cin>>arr[i];
        if(arr[i] >= 0)
        {
            flag = true;
        }
    }


    if(flag == false)
    {
        result = *(std::max_element(arr.begin() + 1, arr.end()));
        std::cout<<result<<'\n';
    }
    else
    {
        for(size_t i = 1; i <= n; i++)
        {
            dp[i] = arr[i];
        }

        for(size_t windowSize = 2; windowSize <= n; windowSize++)
        {
            for(size_t j = 1; j <= n - (windowSize - 1); j = j + 1)
            {
                dp[j] = dp[j] + arr[windowSize - 1 + j];
            }

            int current_value = *(std::max_element(dp.begin() + 1, dp.end()));

            if(current_value > max_value)
            {
                max_value = current_value;
            }

        }

        std::cout<<max_value<<'\n';
    }

    return 0;

}