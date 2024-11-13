#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Student {
    string surname;
    int course;
    int speciality;
    int physicsGrade;
    int mathGrade;
    union {
        int informaticsGrade;  
    } ExtraGrade;
};

string specialityStr[] = { "Комп'ютерні науки", "Інформаційні системи", "Кібербезпека" };

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void CountMathGrades(const Student* students, const int N, int& count5, int& count4, int& count3);
void FindTopStudents(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    int count5 = 0, count4 = 0, count3 = 0;
    CountMathGrades(students, N, count5, count4, count3);
    cout << "\nОцінки з математики:\n";
    cout << "Оцінка 5: " << count5 << "\nОцінка 4: " << count4 << "\nОцінка 3: " << count3 << endl;

    cout << "\nСтуденти, які отримали оцінку 5 з фізики і математики:\n";
    FindTopStudents(students, N);

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Студент №" << i + 1 << ":" << endl;
        cin.ignore();

        cout << " Прізвище: ";
        getline(cin, students[i].surname);
        cout << " Курс: ";
        cin >> students[i].course;

        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформаційні системи, 2 - Кібербезпека): ";
        cin >> students[i].speciality;

        cout << " Оцінка з фізики: ";
        cin >> students[i].physicsGrade;
        cout << " Оцінка з математики: ";
        cin >> students[i].mathGrade;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].ExtraGrade.informaticsGrade;
        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "======================================================================================" << endl;
    cout << "| № | Прізвище      | Курс | Спеціальність       | Фізика | Математика | Інформатика |" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(14) << left << students[i].surname;
        cout << "| " << setw(4) << right << students[i].course << " ";
        cout << "| " << setw(20) << left << specialityStr[students[i].speciality];
        cout << "| " << setw(6) << right << students[i].physicsGrade << " ";
        cout << "| " << setw(10) << right << students[i].mathGrade << " ";
        cout << "| " << setw(11) << right << students[i].ExtraGrade.informaticsGrade << " |" << endl;
    }
    cout << "======================================================================================" << endl;
}

void CountMathGrades(const Student* students, const int N, int& count5, int& count4, int& count3) {
    count5 = count4 = count3 = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].mathGrade == 5) count5++;
        else if (students[i].mathGrade == 4) count4++;
        else if (students[i].mathGrade == 3) count3++;
    }
}

void FindTopStudents(const Student* students, const int N) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (students[i].physicsGrade == 5 && students[i].mathGrade == 5) {
            cout << " " << students[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << " Немає студентів з оцінкою 5 з фізики і математики." << endl;
    }
}
