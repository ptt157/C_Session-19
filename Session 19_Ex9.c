#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai bao cau truc sinh vien
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Ham in danh sach sinh vien
void printStudents(Student students[], int currentLength) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

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

// Ham them sinh vien
void addStudent(Student students[], int *currentLength) {
    if (*currentLength >= MAX) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    Student newStudent;
    printf("Nhap ID: "); scanf("%d", &newStudent.id);
    printf("Nhap Ten: "); scanf("%s", newStudent.name);
    printf("Nhap Tuoi: "); scanf("%d", &newStudent.age);
    printf("Nhap SDT: "); scanf("%s", newStudent.phoneNumber);
    students[*currentLength] = newStudent;
    (*currentLength)++;
    printf("Sinh vien da duoc them thanh cong.\n");
}

// Ham sua thong tin sinh vien
void updateStudent(Student students[], int currentLength, int id) {
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Nhap Ten moi: "); scanf("%s", students[i].name);
            printf("Nhap Tuoi moi: "); scanf("%d", &students[i].age);
            printf("Nhap SDT moi: "); scanf("%s", students[i].phoneNumber);
            printf("Thong tin sinh vien da duoc cap nhat.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n", id);
    }
}

// Ham tim kiem sinh vien theo id
void searchStudent(Student students[], int currentLength, int id) {
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n", id);
    }
}

int main() {
    Student students[MAX];
    int currentLength = 0;
    int choice, id;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, currentLength);
                break;
            case 2:
                addStudent(students, &currentLength);
                break;
            case 3:
                printf("Nhap ID sinh vien can sua: ");
                scanf("%d", &id);
                updateStudent(students, currentLength, id);
                break;
            case 4:
                printf("Nhap ID sinh vien can xoa: ");
                scanf("%d", &id);
                deleteStudent(students, &currentLength, id);
                break;
            case 5:
                printf("Nhap ID sinh vien can tim kiem: ");
                scanf("%d", &id);
                searchStudent(students, currentLength, id);
                break;
            case 6:
                sortStudentsByName(students, currentLength);
                printStudents(students, currentLength);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

