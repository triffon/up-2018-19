#include <iostream>
using namespace std;

const int MAX_NAME = 45;

struct Student {
  char name[MAX_NAME];
  int fn;
  double grade;
};

void readStudent(Student& student) {
  cout << "Име: ";
  cin.getline(student.name, MAX_NAME);
  cout << "Ф№: ";
  cin >> student.fn;
  cout << "Оценка: ";
  cin >> student.grade;
  cin.get();
}

int readStudents(Student s[]) {
  cout << "Въведете брой студенти: ";
  int n;
  cin >> n;
  cin.get();
  for(int i = 0; i < n; i++)
    readStudent(s[i]);
  return n;
}

void printStudentLine(Student s) {
  cout << s.fn << '\t' << s.grade << '\t' << s.name << endl;
}

void printStudents(Student s[], int n) {
  cout << "\n\nФ№\tОценка\tИме\n";
  cout << "-----------------------------------------------\n";
  for(int i = 0; i < n; i++)
    printStudentLine(s[i]);
}

double averageGrade(Student students[], int n) {
  double sumGrade = 0;
  for(int i = 0; i < n; i++)
    sumGrade += students[i].grade;
  return sumGrade / n;
}

void testStudents() {
  Student students[100];
  int n = readStudents(students);
  printStudents(students, n);
  cout << "Среден успех: " << averageGrade(students, n) << endl;
}

int main() {
  testStudents();
  return 0;
}
