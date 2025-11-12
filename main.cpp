#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>

struct Student {
    std::string firstName;
    std::string lastName;
    int age;
    float gpa;

    static void readFromFile(Student*& students, size_t& size, const char* filename) {
        std::ifstream file(filename);

        // Check if file opened successfully
        if (!file.is_open()) {
            std::cout << "Failed to open file: " << filename << std::endl;
            students = nullptr;
            size = 0;
            return;
        }

        // File has opened successfully

        // Read the number of students
        file >> size;
        students = new Student[size];

        // Read each student's data
        for (size_t i = 0; i < size; i++) {
            file >> students[i].firstName >> students[i].lastName >> students[i].age >> students[i].gpa;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.firstName << " " << student.lastName << ", Age: " << student.age << ", GPA: " << student.gpa;
        return os;
    }

};

Student readStudent() {
    Student s;
    std::cout << "Enter first name, last name, age, and GPA: ";
    std::cin >> s.firstName >> s.lastName >> s.age >> s.gpa;
    return s;
}

void generateArray(int*& numbers, size_t size) {
    numbers = new int[size];
    for (size_t i = 0; i < size; i++) {
        numbers[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

void printArray(std::string tag, int* numbers, size_t size) {
    std::cout << tag << ": ";
    for (size_t i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void duplicateArray(const int* source, int*& destination, size_t size) {
    destination = new int[size];
    for (size_t i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

/* First exercise */

/* 
    Class definition 
    DO NOT MODIFY 
*/

class MyContainer {
public:
    std::string s1;
    int i1;
    int i2;
    float f1;

    std::function<void(MyContainer* thisObj)> lambda;

    MyContainer(std::string str, int a, int b, float c) : s1(str), i1(a), i2(b), f1(c) {}

    void setLambda(std::function<void(MyContainer* thisObj)> func) {
        lambda = func;
    }

    void executeLambda() {
        if (lambda) {
            lambda(this);
        } else {
            std::cout << "Lambda function is not set." << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MyContainer& obj) {
        os << "s1: " << obj.s1 << ", i1: " << obj.i1 << ", i2: " << obj.i2 << ", f1: " << obj.f1;
        return os;
    }

};

/* TODO: create an instance of the class and set the lambda */
void testLambda() {
    MyContainer obj("Test", 1, 2, 3.0f);
   
    // TODO (1): set the lambda to print all member variables of the class instance


    // Execute the lambda

    // TODO (2): set the lambda to modify the member variables of the class instance


    // Print the original member variables

    // Execute the lambda again to modify the member variables

    // Print the modified member variables
}

/* Second exercise */
/* TODO: sort the array using a lambda */
void sortNumbers(int* numbers, size_t size) {
    // Your code here

    // End of your code

}


/* Third exercise */
/* TODO: sort the student array by the following criterias:
    1. by GPA in descending order
    2. by age in ascending order
    3. by last name in ascending order
*/
void sortStudents(Student* students, size_t size) {
    // Your code here

    // End of your code

}

/* Fourth exercise */
/* TODO: create a function that returns all numbers less than a given value */
void filterNumbers(int*& numbers, size_t& size, int threshold) {
    // Your code here

    // End of your code
}

/* Fifth exercise */
/* TODO: create a function that takes a lambda and returns whether a number is even or odd */
std::function<bool(int)> isEven() {
    // Your code here

    // End of your code
}

/* Sixth exercise */
/* TODO: create a function that filters an array based on a predicate */
void filterArray(int* numbers, size_t& size, auto predicate) {
    // Your code herepredicate

    // End of your code
}

int main() {

    std::cout << "Hello, Lambda!" << std::endl;

    Student* students = nullptr;
    size_t studentCount = 0;
    Student::readFromFile(students, studentCount, "students.in");

    // Test file read
    // for (size_t i = 0; i < studentCount; i++) {
    //     std::cout << "[" << i << "] " << students[i] << std::endl;
    // }

    // Exercise 1
    std::cout << "\n---- Exercise 1 ----\n\n";
    testLambda(); // TODO: implement it

    // Exercise 2
    std::cout << "\n---- Exercise 2 ----\n\n";
    size_t size_ex2 = 20;
    int* numbers_ex2 = nullptr;
    generateArray(numbers_ex2, size_ex2);

    printArray("Before sorting", numbers_ex2, size_ex2);

    sortNumbers(numbers_ex2, size_ex2); // TODO: implement it

    printArray("After sorting", numbers_ex2, size_ex2); 

    // Exercise 3
    std::cout << "\n---- Exercise 3 ----\n\n";
    std::cout << "Before sorting students:" << std::endl;
    for (size_t i = 0; i < studentCount; i++) {
        std::cout << "[" << i << "] " << students[i] << std::endl;
    }
    std::cout << std::endl;
    sortStudents(students, studentCount); // TODO: implement it

    std::cout << "After sorting students:" << std::endl;
    for (size_t i = 0; i < studentCount; i++) {
        std::cout << "[" << i << "] " << students[i] << std::endl;
    }

    // Exercise 4
    std::cout << "\n---- Exercise 4 ----\n\n";
    size_t size_ex4 = 15;
    int* numbers_ex4 = nullptr;
    generateArray(numbers_ex4, size_ex4);

    printArray("Before filtering", numbers_ex4, size_ex4);

    filterNumbers(numbers_ex4, size_ex4, 25); // TODO: implement it

    printArray("After filtering", numbers_ex4, size_ex4);

    // Exercise 5
    std::cout << "\n---- Exercise 5 ----\n\n";
    auto evenPredicate = isEven(); // TODO: implement it

    std::cout << "Is 4 even? " << (evenPredicate(4) ? "Yes" : "No") << std::endl;
    std::cout << "Is 7 even? " << (evenPredicate(7) ? "Yes" : "No") << std::endl;

    // Exercise 6
    std::cout << "\n---- Exercise 6 ----\n\n";
    size_t size_ex6 = 20;
    int* numbers_ex6 = nullptr;
    generateArray(numbers_ex6, size_ex6);

    std::cout << "\n=========[Filter Even Numbers]=========" << std::endl;
    size_t dup1_size = size_ex6;
    int* ex6_dup1 = nullptr;
    duplicateArray(numbers_ex6, ex6_dup1, dup1_size);

    printArray("Before filter 1", ex6_dup1, dup1_size);

    filterArray(ex6_dup1, dup1_size, isEven()); // TODO: implement it

    printArray("After filter 1", ex6_dup1, dup1_size);

    std::cout << "\n=========[Filter Numbers Greater Than 50]=========" << std::endl;

    size_t dup2_size = size_ex6;
    int* ex6_dup2 = nullptr;
    duplicateArray(numbers_ex6, ex6_dup2, dup2_size);

    printArray("Before filter 2", ex6_dup2, dup2_size);

    filterArray(ex6_dup2, dup2_size, [](int number) -> bool {
        // Numbers greater than 50 filter
        return number > 50;
    });

    printArray("After filter 2", ex6_dup2, dup2_size);

    std::cout << "\n=========[Filter Prime Numbers]=========" << std::endl;

    size_t dup3_size = size_ex6;
    int* ex6_dup3 = nullptr;
    duplicateArray(numbers_ex6, ex6_dup3, dup3_size);

    printArray("Before filter 3", ex6_dup3, dup3_size);
    filterArray(ex6_dup3, dup3_size, [](int number) -> bool {
        // Prime numbers filter
        if (number < 2) return false;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    });
    printArray("After filter 3", ex6_dup3, dup3_size);

    // Clean up
    delete[] students;
    delete[] numbers_ex2;
    delete[] numbers_ex4;
    delete[] numbers_ex6;
    delete[] ex6_dup1;
    delete[] ex6_dup2;
    delete[] ex6_dup3;

    return 0;
}

/* Bonus exercise */
/* TODO: given a vector of numbers, display them without using a loop */
void displayNumbers(const std::vector<int>& numbers) {
    // Your code here

    // End of your code
}



/* Bonus exercise */
/* TODO: given a vector of numbers, return a new vector with the numbers doubled*/
std::vector<int> doubleNumbers(const std::vector<int>& numbers) {
    // Your code here

    // End of your code
}

/* Bonus exercise */
/* TODO: given a vector of numbers, return a new vector with only the even numbers */
void onlyEven(std::vector<int>& numbers) {
    // Your code here

    // End of your code
}