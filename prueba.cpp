#include <iostream>
#include <fstream>
#include <vector>

enum class Gender { Male, Female };
enum class Performance { Excellent, Good, Average, BelowAverage };

void processLine(const std::string& line, int& male, int& female, int& men, int& may, int& excel, int& good, int& ave, int& belAve) {
    Gender gender = Gender::Male; // Default value
    int age = 0;
    Performance performance = Performance::Excellent; // Default value

    size_t j = 0;
    while (j < line.length() && line[j] != '\t') {
        ++j;
    }

    if (j < line.length()) {
        age = std::stoi(line.substr(0, j));

        size_t k = j + 1;
        while (k < line.length() && line[k] != '\t') {
            ++k;
        }

        if (k < line.length()) {
            gender = (line.substr(j + 1, k - j - 1) == "Male") ? Gender::Male : Gender::Female;

            size_t m = k + 1;
            while (m < line.length() && line[m] != '\t') {
                ++m;
            }

            if (m < line.length()) {
                performance = (line.substr(k + 1, m - k - 1) == "Excellent") ? Performance::Excellent :
                              (line.substr(k + 1, m - k - 1) == "Good") ? Performance::Good :
                              (line.substr(k + 1, m - k - 1) == "Average") ? Performance::Average :
                              Performance::BelowAverage;

                // Incrementar contadores según el género, edad y rendimiento académico
                if (gender == Gender::Male) {
                    ++male;
                } else {
                    ++female;
                }

                if (age <= 22) {
                    ++men;
                } else {
                    ++may;
                }

                switch (performance) {
                    case Performance::Excellent:
                        ++excel;
                        break;
                    case Performance::Good:
                        ++good;
                        break;
                    case Performance::Average:
                        ++ave;
                        break;
                    case Performance::BelowAverage:
                        ++belAve;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

int main() {
    std::ifstream inFile("resultados.txt");
    std::ofstream outFile("Reporte.txt");

    if (inFile.is_open() && outFile.is_open()) {
        std::string line;
        std::vector<std::string> lines;

        while (std::getline(inFile, line)) {
            lines.push_back(line);
        }

        int male = 0, female = 0, men = 0, may = 0, excel = 0, good = 0, ave = 0, belAve = 0;

        for (const auto& currentLine : lines) {
            processLine(currentLine, male, female, men, may, excel, good, ave, belAve);
        }

        // Escribir resultados en el archivo
        outFile << "Male: " << male << std::endl;
        outFile << "Female: " << female << std::endl;
        outFile << "Men: " << men << std::endl;
        outFile << "May: " << may << std::endl;
        outFile << "Excellent: " << excel << std::endl;
        outFile << "Good: " << good << std::endl;
        outFile << "Average: " << ave << std::endl;
        outFile << "Below Average: " << belAve << std::endl;

        std::cout << "Proceso completado. Resultados escritos en Reporte.txt" << std::endl;

        // Cerrar archivos
        inFile.close();
        outFile.close();
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }

    return 0;
}
