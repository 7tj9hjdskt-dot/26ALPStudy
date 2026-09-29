#include <iostream>
#include <vector>

std::vector<int> dpZero;
std::vector<int> dpOne;

int count_print_one = 0;
int count_print_zero = 0;

int fibonacci(int n)
{
    if(n == 0)
    {
        count_print_zero = count_print_zero + 1;
        return 0;
    }
    else if(n == 1)
    {
        count_print_one = count_print_one + 1;
        return 1;
    }

    if(count_print_one[n] > 0)
    {
        return dp[n];
    }

    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);


    return dp[n];
}





int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    int T;
    std::cin>>T;

    dp.resize(100, 0);

    for(size_t i = 0; i < T; i++)
    {
        int input_;
        int result;
        std::cin>>input_;
        fibonacci(input_);
        std::cout<<count_print_zero<<" "<<count_print_one<<'\n';
        count_print_one = 0;
        count_print_zero = 0;
    }


    return 0;
}