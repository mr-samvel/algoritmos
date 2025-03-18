#include <iostream>
#include <string>
#include <vector>

void readInput(int &R, int &C, int &K, std::vector<std::string> &matrix, std::vector<std::string> &pattern) {
    std::cin >> R >> C >> K;
    
    matrix.resize(R);
    pattern.resize(R);

    for (int i = 0; i < R; i++)
        std::cin >> matrix[i] >> pattern[i];
}

char solve(int rows, int matrix_cols, int pattern_cols, std::vector<std::string> led_matrix, std::vector<std::string> led_pattern) {
    bool row_has_failure = false;
    bool row_cant_fail = false;
    int max_cols = matrix_cols > pattern_cols ? matrix_cols : pattern_cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < max_cols; j++) {
            if (!row_has_failure && j < matrix_cols && led_matrix[i][j] == '-')
                row_has_failure = true;

            if (!row_cant_fail && j < pattern_cols && led_pattern[i][j] == '*')
                row_cant_fail = true;
            
            if (row_has_failure && row_cant_fail)
                return 'N';
        }
        row_has_failure = false;
        row_cant_fail = false;
    }
    return 'Y';
}

int main() {
    int rows, matrix_cols, pattern_cols;
    std::vector<std::string> led_matrix;
    std::vector<std::string> led_pattern;
    
    readInput(rows, matrix_cols, pattern_cols, led_matrix, led_pattern);
    std::cout << solve(rows, matrix_cols, pattern_cols, led_matrix, led_pattern);
}