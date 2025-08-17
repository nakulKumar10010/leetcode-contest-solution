class Solution {
public:
    int minSensors(int n, int m, int k) {
        // Each sensor covers cells within Chebyshev distance ≤ k
        // That means in both row and column direction, 
        // coverage length = (2 * k + 1)

        int coverageSize = 2 * k + 1;

        // ✅ Calculate how many sensors are required along rows
        // Each sensor covers `coverageSize` rows
        int sensorsAlongRows = n / coverageSize;
        if (n % coverageSize != 0) {
            sensorsAlongRows++; // Add one more if rows left uncovered
        }

        // ✅ Calculate how many sensors are required along columns
        // Each sensor covers `coverageSize` columns
        int sensorsAlongCols = m / coverageSize;
        if (m % coverageSize != 0) {
            sensorsAlongCols++; // Add one more if columns left uncovered
        }

        // ✅ Total sensors needed = product of row-wise and column-wise sensors
        // because sensors are arranged in a grid-like pattern
        return sensorsAlongRows * sensorsAlongCols;
    }
};
