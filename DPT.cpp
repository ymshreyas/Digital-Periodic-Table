#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<direct.h>
#include<vector>
#include<string.h>
#include<ctype.h>
struct node {
    int atno; char name[15], config[70], sym[5], ss[7]; float atmass; struct node* next; struct node* prev;
};
struct node* start = NULL, * cur = NULL, * temp;
void skeleton();
using namespace std;
void print_req_data() {
    printf("\nAtomic number = %d\nElement name = %s\nElectronic configuration = %s\nSymbol = %s\n", temp->atno, temp->name, temp->config, temp->sym);
    printf("Standard state = %s\nAtomic mass = %f\n", temp->ss, temp->atmass);
}
int userinputvalidation(int l, int h)
{
    int ch;
    scanf("%d", &ch);
    if (ch <= h && ch >= l)
    {
        return ch;
    }
    else
    {
        cout << "Your have entered a wrong choice\nenter again\n";
        userinputvalidation(l, h);
    }
}
void print_table()
{
    //CONSOLE_FONT_INFOEX cfi;
    //cfi.cbSize = sizeof(cfi);
    //cfi.nFont = 0;
    //cfi.dwFontSize.X = 0;
    //cfi.dwFontSize.Y = 20;
    FILE* fp1;
    //HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(console_color, 11);
    char ch;
    fp1 = fopen("table.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp1);
    }
    return;
}
void load() {
    FILE* fp1, * fp2, * fp3, * fp4, * fp5, * fp6; char s2[3], ec[100], name[10], state[7]; float am; int atn = 0; struct node* nn;
    fp1 = fopen("atname.txt", "r"); fp2 = fopen("atn.txt", "r"); fp3 = fopen("ele.txt", "r"); fp4 = fopen("symbols.txt", "r");
    fp5 = fopen("atomicmass.txt", "r"); fp6 = fopen("standardstate.txt", "r");
    while (fscanf(fp4, "%s\0", s2) != EOF && fscanf(fp2, "%d", &atn) != EOF && fscanf(fp3, "%s", ec) != EOF && fscanf(fp1, "%s", name) != EOF && fscanf(fp5, "%f", &am) != EOF && fscanf(fp6, "%s", state) != EOF) {
        nn = (struct node*)malloc(sizeof(struct node));
        nn->next = NULL; nn->prev = NULL;
        strcpy(nn->name, name); strcpy(nn->config, ec); nn->atno = atn; strcpy(nn->sym, s2); strcpy(nn->ss, state); nn->atmass = am;
        if (start == NULL) {
            start = nn; cur = nn;
        }
        else {
            cur->next = nn;
            nn->prev = cur; cur = cur->next;
        }
    }
    cur->next = start; start->prev = cur;
    fclose(fp1), fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6); skeleton();
}
void aim_by_atno() {
    char tc, atn1; int atn;
    print_table();
    temp = start;
    getchar();
    printf("Enter atomic number:");
    scanf("%d", &atn);
    atn1=(char)atn;
    if (isalpha(atn1)) {
        system("CLS");
        aim_by_atno();
    }
    else {
        for (int i = 1; i < atn; i++) {
            temp = temp->next;
        }
        print_req_data();
        while (1) {
            getchar();
            printf("\n\nPress 1 ==> view next element\nPress 2 ==> view previous element\nPress 3 ==> return to main menu\nEnter a choice:");
            scanf("%c", &tc);
            switch (tc) {
            case '1':system("CLS");
                print_table(); temp = temp->next;
                print_req_data(); break;
            case '2':system("CLS");
                print_table(); temp = temp->prev;
                print_req_data(); break;
            case '3':system("CLS");
                skeleton(); break;
            default:printf("Enter the right choice number\n");
            }
        }
    }
}
void aim_by_atname() {
    print_table();
    int tf = 1, k = 0; char tc;
    temp = start;
    char name1[15];
    printf("Enter the element name:");
    scanf("%s", name1);
    name1[0] = toupper(name1[0]);
    while (strcmp(name1, temp->name) != 0)
    {
        temp = temp->next; tf += 1;
        if (tf == 119) {
            k = 1; break;
        }
    }
    if (k == 1) {
        printf("Enter the element name and not the symbol or atomic number\n");
        system("CLS");
        aim_by_atname();
    }
    else {
        print_req_data();
        while (1) {
            getchar();
            printf("\n\nPress 1 ==> view next element\nPress 2 ==> view previous element\nPress 3 ==> return to main menu\nEnter a choice:");
            scanf("%c", &tc);
            switch (tc) {
            case '1':system("CLS");
                print_table(); temp = temp->next;
                print_req_data(); break;
            case '2':system("CLS");
                print_table(); temp = temp->prev;
                print_req_data(); break;
            case '3':system("CLS");
                skeleton(); break;
            default:printf("Enter the right choice number\n"); break;
            }
        }
    }
}
void aim_by_symbol() {
    print_table();
    int tf = 1, k = 0; char tc;
    temp = start;
    char name1[15];
    printf("\nEnter the element symbol:");
    scanf("%s", name1);
    name1[0] = toupper(name1[0]);
    while (strcmp(name1, temp->sym) != 0)
    {
        temp = temp->next; tf += 1;
        if (tf == 119) {
            k = 1; break;
        }
    }
    if (k == 1) {
        printf("There exists no such element\n");
        system("CLS");
        aim_by_symbol();
    }
    else {
        print_req_data();
        while (1) {
            getchar();
            printf("\n\nPress 1 ==> view next element\nPress 2 ==> view previous element\nPress 3 ==> return to main menu\nEnter a choice:");
            scanf("%c", &tc);
            switch (tc) {
            case '1':system("CLS");
                print_table(); temp = temp->next;
                print_req_data(); break;
            case '2':system("CLS");
                print_table(); temp = temp->prev;
                print_req_data(); break;
            case '3':system("CLS");
                skeleton(); break;
            default:printf("Enter the right choice number\n"); break;
            }
        }
    }
}
void skeleton()
{
    system("CLS");
    //HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); 
    int ch, ch1;
    //CONSOLE_FONT_INFOEX cfi;
    //cfi.cbSize = sizeof(cfi);
    //cfi.nFont = 0;
    //cfi.dwFontSize.X = 20;
    //cfi.dwFontSize.Y = 30;
    //cfi.FontFamily = FF_DONTCARE;
    //cfi.FontWeight = 900;
    //wcscpy_s(cfi.FaceName, L"Calibri");
    //SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //SetConsoleTextAttribute(console_color, 1);
    cout << "\DIGITAL PERIODIC TABLE\n\n";
    //SetConsoleTextAttribute(console_color, 6);
    cout << "CHOOSE ANY OPERATION\n\n";
    //SetConsoleTextAttribute(console_color, 10);
    cout << "1)Retrive Data by atomic number\n";
    cout << "2)Retrive Data by element name \n";
    cout << "3)Data by symbol\n";
    cout << "4)Exit\n\n";
    //SetConsoleTextAttribute(console_color, 11);
    printf("Enter your choice:");
    ch = userinputvalidation(1, 10); ch1 = ch;
    switch (ch1)
    {
    case 1:
        system("CLS");
        aim_by_atno();
        break;
    case 2:
        system("CLS");
        aim_by_atname();
        break;
    case 3:
        system("CLS");
        aim_by_symbol(); break;
    case 4:
        system("CLS");
        printf("Thank You\n");
        exit(1);
        break;
    }
    return;
}
int main()
{
    load();
    return 0;
}