#include <iostream>
#include <vector>

int material(const std::vector<int>& spaceShip);

int main() {
    std::vector<int> A = {4, 2, 0, 3, 2, 5};
    std::cout << "result: " << material(A) << "\texpected: 9" << std::endl;

    std::vector<int> B = {6, 2, 1, 1, 8, 0, 5, 5, 0, 1, 8, 9, 6, 9, 4, 8, 0, 0};
    std::cout << "result: " << material(B) << "\texpected: 50" << std::endl;

    std::vector<int> C = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    std::cout << "result: " << material(C) << "\texpected: 83" << std::endl;

    std::vector<int> D = {0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2};
    std::cout << "result: " << material(D) << "\texpected: 8" << std::endl;
    return 0;
}

int material(const std::vector<int>& spaceShip){
    std::vector<int> sum_f;
    std::vector<int> sum_b;
    int size = spaceShip.size();
    int h1 = spaceShip[0];
    int h2 = spaceShip[size - 1];
    int i = 0;
    int j = size - 1;
  
    while (i < size){
        if (spaceShip[i] < h1){
            sum_f.push_back(h1 - spaceShip[i]);
        } else{
            sum_f.push_back(0);
            h1 = spaceShip[i];
        }
        if (spaceShip[j] < h2){
            sum_b.push_back(h2 - spaceShip[j]);
        } else{
            sum_b.push_back(0);
            h2 = spaceShip[j];
        }
        i++;
        j--;
    }
    int sum = 0;
    j++;
    while (j < size){
        sum += std::min(sum_f[j], sum_b[(size - 1) - j]);
        j++;
    }
    return sum;
}
