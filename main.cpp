#include<iostream>

typedef unsigned long long ull;
int main()
{
    unsigned int n, s, p, q;
    std::cin >> n >> s >> p >> q;
    std::cout << n << ", " << s << ", " << p << ", " << q << '\n';
    auto f = [p, q](unsigned int x){return (x * p) + q;};
    constexpr ull p_231 = static_cast<ull>(1u << 31);
    ull x0 = s % p_231;
    ull tort = f(x0) % p_231;
    ull hare = f(x0) % p_231;
    hare = f(hare) % p_231;
    ull result = 1;
    while(tort != hare)
    {
        if(result >= n)
        {
            std::cout << "Result = " << n << '\n';
            return n;
        }
        else
        {
            tort = f(tort) % p_231;
            hare = f(hare) % p_231;
            hare = f(hare) % p_231;
            ++result;
        }
    }
    ull mu = 0;
    tort = x0;
    while(tort != hare)
    {
        tort = f(tort) % p_231;
        hare = f(hare) % p_231;
        ++mu;
    }
    ull lambda = 1;
    hare = f(tort) % p_231;
    while(tort != hare)
    {
        hare = f(hare) % p_231;    
        ++lambda;
    }
    std::cout << "Result = " << (mu + lambda) << '\n';
    return 0;
    return (mu + lambda);
}
