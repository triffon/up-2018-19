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

void printStudentsByIndex(Student* studentIndex[], int n) {
  cout << "\n\nФ№\tОценка\tИме\n";
  cout << "-----------------------------------------------\n";
  for(int i = 0; i < n; i++)
    printStudentLine(*studentIndex[i]);
}


double averageGrade(Student students[], int n) {
  double sumGrade = 0;
  for(int i = 0; i < n; i++)
    sumGrade += students[i].grade;
  return sumGrade / n;
}

void sortStudentsByFn(Student students[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int mini = i;
    for(int j = i + 1; j < n; j++)
      if (students[j].fn < students[mini].fn)
        mini = j;
    /*
    Student tmp = students[i];
    students[i] = students[mini];
    students[mini] = tmp;
    */
    swap(students[i], students[mini]);
  }
}

void initStudentIndex(Student students[], Student* studentIndex[], int n) {
  for(int i = 0; i < n; i++)
    studentIndex[i] = &students[i];
}

void sortStudentIndexByFn(Student* studentIndex[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int mini = i;
    for(int j = i + 1; j < n; j++)
      if (studentIndex[j]->fn < studentIndex[mini]->fn)
        mini = j;
    /*
    Student* tmp = studentIndex[i];
    studentIndex[i] = studentIndex[mini];
    studentIndex[mini] = tmp;
    */
    swap(studentIndex[i], studentIndex[mini]);
  }
}

const int MAX_STUDENTS = 100;

void testStudents() {
  Student students[MAX_STUDENTS];
  int n = readStudents(students);
  // sortStudentsByFn(students, n);
  Student* studentIndex[MAX_STUDENTS];
  initStudentIndex(students, studentIndex, n);
  sortStudentIndexByFn(studentIndex, n);
  //printStudents(students, n);
  printStudentsByIndex(studentIndex, n);
  cout << "Среден успех: " << averageGrade(students, n) << endl;
}

int main() {
  testStudents();
  return 0;
}
