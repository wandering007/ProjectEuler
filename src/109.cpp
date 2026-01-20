#include <iostream>
#include <vector>
#include<iomanip>


int main()
{
    clock_t start = clock();
    // 1 dart: D
    // 2 darts: S/T, D
    // 3 darts: S/T,S/T,D
    std::vector<int> hits;
    std::vector<int> doubles;
    for(int i = 1; i <= 20; ++i) {
        hits.push_back(i);
        hits.push_back(2 * i);
        hits.push_back(3 * i);
        doubles.push_back(2 * i);
    }
    hits.push_back(25);         // Outer Bull
    hits.push_back(50);         // Inner Bull (Double)
    doubles.push_back(50);
    int total_checkouts = 0;
    for(auto last_dart : doubles) {
        if(last_dart < 100) {
            ++total_checkouts;
        }
        for(int i = 0; i < hits.size(); ++i) {
            if(hits[i] + last_dart < 100) {
                ++total_checkouts;
            }
        }
        for(int i = 0; i < hits.size(); ++i) {
            // j >= i
            for(int j = i; j < hits.size(); ++j) {
                if(hits[i] + hits[j] + last_dart < 100) {
                    ++total_checkouts;
                }
            }
        }
    }
    std::cout << "Total checkouts below 100: " << total_checkouts << std::endl;
    std::cout << "Time cost: " << std::setprecision(6) << std::scientific << (double)(clock() - start) / CLOCKS_PER_SEC << " s." << std::endl;
    return 0;
}
