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

// Ham xoa sinh vien theo id
void deleteStudent(Student students[], int *currentLength, int id) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            printf("Sinh vien co ID %d da bi xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n", id);
    }
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

    // Xoa sinh vien co id 3
    deleteStudent(students, &currentLength, 3);

    // In lai danh sach sinh vien
    printStudents(students, currentLength);

    return 0;
}

