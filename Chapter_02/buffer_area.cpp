/* 
Buffer Analysis

A buffer region is an area created around a geographic feature at a specified distance.

For example, a 1 km buffer around a water point represents all locations that are within 1 km of that water source.

Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

 Task

Write a program that:

- Takes a specific point coordinate as the center location.
- Creates buffers of different sizes around that point.
- Takes a given set of points.
- Determines which points fall within each buffer.
- Returns the points contained in each buffer region
8
*/

#include <iostream>
#include <vector>
#include <cmath>

struct Point {
   int id;
    double x;
    double y;
};

struct BufferResult {
    double radius;
    std::vector<Point> containedPoints;
};

// Calculates 2D Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Performs buffer analysis for a set of buffer radii
std::vector<BufferResult> analyzeBuffers(
    const Point& center,
    const std::vector<double>& radii,
    const std::vector<Point>& points
) {
    std::vector<BufferResult> results;
    results.reserve(radii.size());

    for (double radius : radii) {
        BufferResult result;
        result.radius = radius;

        for (const auto& point : points) {
            if (calculateDistance(center, point) <= radius) {
                result.containedPoints.push_back(point);
            }
        }
        results.push_back(result);
    }

    return results;
}

int main() {
    // Define center location
    Point center = {0, 0.0, 0.0};

    // Define buffer radii to evaluate
    std::vector<double> radii = {1.0, 2.5, 5.0};

    // Sample dataset of points
    std::vector<Point> dataset = {
        {1, 0.5, 0.5},   // Distance ~ 0.71 (Within 1.0, 2.5, 5.0)
        {2, 1.5, 1.5},   // Distance ~ 2.12 (Within 2.5, 5.0)
        {3, 3.0, 3.0},   // Distance ~ 4.24 (Within 5.0)
        {4, 5.0, 5.0}    // Distance ~ 7.07 (Outside all)
    };

    // Execute analysis
    std::vector<BufferResult> analysis = analyzeBuffers(center, radii, dataset);

    // Output results
    std::cout << "Center Point: (" << center.x << ", " << center.y << ")\n\n";

    for (const auto& res : analysis) {
        std::cout << "Buffer Radius: " << res.radius << " units\n";
        std::cout << "Points contained (" << res.containedPoints.size() << "):\n";
        
        for (const auto& pt : res.containedPoints) {
            std::cout << "  - Point ID " << pt.id 
                      << " at (" << pt.x << ", " << pt.y << ")\n";
        }
        std::cout << "-------------------------------------\n";
    }

    return 0;
}