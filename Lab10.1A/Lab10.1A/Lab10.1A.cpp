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

string specialityStr[] = { "����'����� �����", "����������� �������", "ʳ����������" };

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void CountMathGrades(const Student* students, const int N, int& count5, int& count4, int& count3);
void FindTopStudents(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    int count5 = 0, count4 = 0, count3 = 0;
    CountMathGrades(students, N, count5, count4, count3);
    cout << "\n������ � ����������:\n";
    cout << "������ 5: " << count5 << "\n������ 4: " << count4 << "\n������ 3: " << count3 << endl;

    cout << "\n��������, �� �������� ������ 5 � ������ � ����������:\n";
    FindTopStudents(students, N);

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "������� �" << i + 1 << ":" << endl;
        cin.ignore();

        cout << " �������: ";
        getline(cin, students[i].surname);
        cout << " ����: ";
        cin >> students[i].course;

        cout << " ������������ (0 - ����'����� �����, 1 - ����������� �������, 2 - ʳ����������): ";
        cin >> students[i].speciality;

        cout << " ������ � ������: ";
        cin >> students[i].physicsGrade;
        cout << " ������ � ����������: ";
        cin >> students[i].mathGrade;
        cout << " ������ � �����������: ";
        cin >> students[i].ExtraGrade.informaticsGrade;
        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "======================================================================================" << endl;
    cout << "| � | �������      | ���� | ������������       | Գ���� | ���������� | ����������� |" << endl;
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
        cout << " ���� �������� � ������� 5 � ������ � ����������." << endl;
    }
}
