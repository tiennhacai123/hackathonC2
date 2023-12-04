#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int n;
struct SinhVien
{
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};
struct SinhVien studentList[100];
typedef struct SinhVien std;
void output(std studentList[], int i)
{
    printf("ID: %d  Name: %s\tBirthday: %s\tAddress: %s\tStatus:%d\n\n",
           studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
}
void input(std studentList[], int i)
{
    printf("Nhap ma sinh vien ");
    scanf("%d", &studentList[i].id);
    printf("Nhap ten sinh vien ");
    getchar();
    gets(studentList[i].name);
    printf("Nhap ngay thang nam sinh ");
    gets(studentList[i].birthday);
    printf("Nhap dia chi cu tru ");
    gets(studentList[i].address);
    printf("Nhap trang thai ");
    scanf("%d", &studentList[i].status);
    printf("\n");
}
int main()
{
    int search_status = 0;
    int numStdList = 2;
    int count;
    struct SinhVien studentList[2] =
        {
            {1, "Le Dien Tien", "28/07/2005", "ha dong", 1},
            {2, "Dang Dung", "20/10/2005", "thanh xuan", 0}};
    do
    {
        printf("\n\t\tMENU\t\t\n");
        printf("1.In ra toan bo danh sach sinh vien co trong mang\n");
        printf("2.Them sinh vien moi\n");
        printf("3.Cap nhap thong tin sinh vien\n");
        printf("4.Xoa thong tin cua sinh vien\n");
        printf("5.Sap xep noi bot\n");
        printf("6.Tim kiem sinh vien theo ten\n");
        printf("7.Tim kiem sinh vien theo Status\n");
        printf("8.Thoat\n");
        int choice;
        printf("Nhap lua chon cua ban ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < numStdList; i++)
            {
                output(studentList, i);
            }

            break;
        case 2:
            printf("Nhap so sinh vien can them ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                input(studentList, numStdList);
                numStdList++;
            }break;
        case 3:
            printf("Nhap ten sinh vien muon thay doi thong tin ");
            count = 0;
            char update_name[50];
            getchar();
            gets(update_name);
            for (int i = 0; i < numStdList; i++)
            {
                if (strcmp(update_name, studentList[i].name) == 0)
                {
                    input(studentList, i);
                    count = 1;
                }
            }
            if (count == 0)
            {
                printf("Khong tim thay");
            }
            break;    
        case 4:
            printf("Nhap ten sinh vien muon xoa thong tin");
            count = 0;
            char delete_name[50];
            gets(delete_name);
            for (int i = 0; i < numStdList; i++)
            {
                if (strcmp(delete_name, studentList[i].name) == 0)
                {
            for (int j = i; j < numStdList - 1; j++)
                    {
                        studentList[j] = studentList[j + 1];
                    }
                    count = 1;
                }
            }
            if (count == 0)
            {
                printf("Khong tim thay");
            }
            break;
        case 5:
            for (int i = 0; i < numStdList - 1; i++)
            {
            for (int j = 0; j < numStdList - i - 1; j++)
            {
                if (studentList[j].name[0] > studentList[j + 1].name[0])
                {
                    std temp = studentList[j];
                    studentList[j] = studentList[j + 1];
                    studentList[j + 1] = temp;
                    }
                }
            }
            break;
        case 7:
                printf("Nhap status can tim kiem: ");
                scanf("%d", &search_status);
                int found_status = 0;
                for (int i = 0; i < numStdList; i++) {
                    if (studentList[i].status == search_status) {
                        output(studentList, i);
                        found_status = 1;
                    }
                }
                if (!found_status) {
                    printf("Khong tim thay sinh vien voi status tuong ung.\n");
                }
				break;
        default:
                printf("vui long nhap 1-8");
                break;
                }
        } while (1 == 1);
}