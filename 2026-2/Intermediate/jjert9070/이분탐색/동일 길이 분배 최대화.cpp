#include <iostream>
#include <vector>
#include <algorithm>


long long getTotalQuotient(std::vector<long long>& arr, long long start, long long end, long long select)
{
    long long totalQuotient = 0;

    for(size_t i = start; i < end; i++)
    {
        totalQuotient = totalQuotient + (arr[i] / select);   
    }

    return totalQuotient;
}


long long findOptimalStickSize(std::vector<long long>& arr, long long start, long long end, long long m)
{
    long long mid;
    long long totalQuotient = 0;

    while (start < end)
    {
        mid = (start + end) / 2;
        totalQuotient = getTotalQuotient(arr, start, end, arr[mid]);

        if(totalQuotient > m)
        {
            start = mid;
        }
        else if(totalQuotient < m)
        {
            end = mid;
        }
        else if(totalQuotient == m)
        {
            return arr[mid];
        }
    }

    return 0;
}


int main()
{

    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);


    long long m;
    long long n;
    long long result;
    std::vector<long long> arr;

    std::cin>>m>>n;
    arr.resize(n);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }

    std::sort(arr.begin(), arr.end());
    result = findOptimalStickSize(arr, 0, arr.size(), m);

    std::cout<<result<<'\n';

    return 0;
    
}