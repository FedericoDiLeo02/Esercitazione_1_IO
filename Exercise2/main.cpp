#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

double map_point(double x) {
    return (3*x - 7) / 4;
}

int main() {
    std::ifstream data_file("data.csv");
    std::ofstream result_file("result.csv");
    std::vector<double> values;
    double x;

    while (data_file >> x) {
        values.push_back(map_point(x));
    }

    result_file << "# N Mean\n";
    double sum = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        sum += values[i];
        double mean = sum / (i + 1);
        result_file << i + 1 << " " << std::scientific << std::setprecision(16)<< mean << "\n";
    }

    data_file.close();
    result_file.close();

    return 0;
}
