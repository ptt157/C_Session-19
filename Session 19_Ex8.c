#include <stdio.h>
#include <string.h>

#define MAX 5

// Khai bao cau truc sinh vien
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Ham sap xep sinh vien theo ten
void sortStudentsByName(Student students[], int currentLength) {
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\nDanh sach sinh vien da duoc sap xep theo ten.\n");
}

// Ham in danh sach sinh vien
void printStudents(Student students[], int currentLength) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[MAX] = {
        {1, "Nguyen Van A", 19, "0123456789"},
        {2, "Le Thi B", 20, "0987654321"},
        {3, "Tran Van C", 18, "0345678901"},
        {4, "Pham Thi D", 21, "0567890123"},
        {5, "Hoang Van E", 22, "0678901234"}
    };

    int currentLength = 5;  // So luong sinh vien hien tai

    printStudents(students, currentLength);

    // Sap xep sinh vien theo ten
    sortStudentsByName(students, currentLength);

    // In lai danh sach sinh vien sau khi sap xep
    printStudents(students, currentLength);

    return 0;
}

