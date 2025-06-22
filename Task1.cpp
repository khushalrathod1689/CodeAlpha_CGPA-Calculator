#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    double grade;
    int creditHours;
};

int main() {
    int numCourses;
    cout << "Enter the number of courses taken: ";
    cin >> numCourses;

    vector<Course> courses;
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        Course course;
        cout << "Enter course " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, course.name);
        cout << "Enter grade for " << course.name << ": ";
        cin >> course.grade;
        cout << "Enter credit hours for " << course.name << ": ";
        cin >> course.creditHours;

        totalCredits += course.creditHours;
        totalGradePoints += course.grade * course.creditHours;

        courses.push_back(course);
    }

    if (totalCredits == 0) {
        cout << "Total credits cannot be zero." << endl;
        return 1;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\nCourse Grades:\n";
    for (const auto& course : courses) {
        cout << course.name << " - Grade: " << course.grade << ", Credit Hours: " << course.creditHours << endl;
    }

    cout << "\nFinal CGPA: " << cgpa << endl;

    return 0;
}