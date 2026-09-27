#include <iostream>
#include <vector>
#include <algorithm>


bool compareFunc(std::vector<std::vector<long long>>& arr, long long row_index_1, long long row_index_2)
{

    for(size_t i = 0; i < arr[0].size() - 2 + 1; i++)
    {
        for(size_t j = i + 1; j < arr[0].size(); j++)
        {
            if (arr[row_index_1][i] < arr[row_index_1][j] && arr[row_index_2][i] < arr[row_index_2][j])
            {
                continue;
            }
            else if (arr[row_index_1][i] > arr[row_index_1][j] && arr[row_index_2][i] > arr[row_index_2][j])
            {
                continue;
            }
            else if (arr[row_index_1][i] == arr[row_index_1][j] && arr[row_index_2][i] == arr[row_index_2][j])
            {
                continue;
            }
            else
            {
                return false; 
            }
        }
    }

    return true;
}

long long countIsomorphism(std::vector<std::vector<long long>>& arr)
{
    long long count = 0;

    for(size_t i = 0; i < arr.size() - 2 + 1; i++)
    {
        for(size_t j = i + 1; j < arr.size(); j++)
        {
            if(compareFunc(arr, i, j) == true)
            {
                count++;
            }
        }

    }

    return count;
}


int main()
{
    int n;
    int m;
    int result;
    std::vector<std::vector<long long>> arr;
    std::vector<std::vector<long long>> arr_copy;
    std::cin>>m>>n;

    arr.resize(m, std::vector<long long>(n, 0));
    arr_copy.resize(m, std::vector<long long>(n, 0));


    for(size_t i = 0; i < arr.size(); i++)
    {
        for(size_t j = 0; j < arr[0].size(); j++)
        {
            std::cin>>arr[i][j];
        }
        std::copy(arr[i].begin(), arr[i].end(), arr_copy[i].begin());
        std::sort(arr_copy[i].begin(), arr_copy[i].end());
        auto it = std::unique(arr_copy[i].begin(), arr_copy[i].end());
        arr_copy[i].erase(it, arr_copy[i].end());       
    }


    for(size_t i = 0; i < arr.size(); i++)
    {
        for(size_t j = 0; j < arr[0].size(); j++)
        {
            arr_copy[i][j] = std::lower_bound(arr_copy[i].begin(), arr_copy[i].end(), arr[i][j]) - arr_copy[i].begin();
        }
    }

    return 0;
}