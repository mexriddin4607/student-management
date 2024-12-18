#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char phone[15];
    char email[50];
} Contact;

typedef struct {
    char name[15];
    Contact contact;
} Parent;

typedef struct {
    char first_name[50];
    char last_name[50];
    int age;
    Contact contact;
    Parent parent;
} Student;

typedef struct {
    int id;
    char name[122];
} Lesson;

typedef struct {
    Lesson lesson;
    Student student;
    int score;
} Score;

// Global Variables
Student* students = NULL;
int student_count = 0;

Lesson* lessons = NULL;
int lesson_count = 0;

Score* scores = NULL;
int score_count = 0;

// Function Prototypes
void add_student();
void get_students();
void get_student_detail();
void get_student_by_name();
void add_lesson();
void add_score();
void get_lesson_statistics();
void menu();

// Main Function
int main() {
    menu();
    // Free allocated memory before exiting
    free(students);
    free(lessons);
    free(scores);
    return 0;
}

// Function Definitions
void menu() {
    int choice;
    do {
        printf("\n1. Add Student\n2. View Students\n3. View Student Details\n4. Find Student by Name\n5. Add Lesson\n6. Add Score\n7. Get Lesson Statistics\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: get_students(); break;
            case 3: get_student_detail(); break;
            case 4: get_student_by_name(); break;
            case 5: add_lesson(); break;
            case 6: add_score(); break;
            // case 7: get_lesson_statistics(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 8);
}
//talabalarni qo`shish uchun
void add_student() {
    students = realloc(students, (student_count + 1) * sizeof(Student));
    if (!students) {
        printf("Memory allocation failed!\n");
        exit(1); // dasturni ishini yakunlash
    }
    printf("Enter first name: ");
    scanf("%s", students[student_count].first_name);

    printf("Enter last name: ");
    scanf("%s", students[student_count].last_name);

    printf("Enter age: ");
    scanf("%d", &students[student_count].age);

    printf("Enter phone: ");
    scanf("%s", students[student_count].contact.phone);

    printf("Enter email: ");
    scanf("%s", students[student_count].contact.email);

    printf("Enter parent's name: ");
    scanf("%s", students[student_count].parent.name);

    printf("Enter parent's phone: ");
    scanf("%s", students[student_count].parent.contact.phone);

    printf("Enter parent's email: ");
    scanf("%s", students[student_count].parent.contact.email);

    student_count++;
    printf("Student added successfully!\n");
}

void get_students(){
    if (student_count > 0)
    {
        printf("ID | First Name | Last Name | Age | Phone        | Email                   | Parent's Name | Parent's Phone | Parent's Email\n"); 
        for (int i = 0; i < student_count; i++)
        {
            printf("%-3d", i + 1);
            printf("| %-10s ", students[i].first_name);
            printf("| %-9s ", students[i].last_name);
            printf("| %-3d ", students[i].age);
            printf("| %-12s ", students[i].contact.phone);
            printf("| %-23s ", students[i].contact.email);
            printf("| %-13s ", students[i].parent.name);
            printf("| %-14s ", students[i].parent.contact.phone);
            printf("| %s\n", students[i].parent.contact.email);
        }
    }else
    {
        printf("Hozzircha birorta ham Talaba ro`yxatga olinmagan!");
    }
}

void get_student_detail(){
    int ID_1;
    printf("Enter student ID to get :");
    scanf("%d", &ID_1);
    if (ID_1 -1 <= student_count && student_count != 0)
    {
        printf("First Name: %s\n", students[ID_1 - 1].first_name);
        printf("Last Name : %s\n", students[ID_1 - 1].last_name);
        printf("Age : %d\n", students[ID_1 - 1].age);
        printf("Phone: %s\n", students[ID_1 - 1].contact.phone);
        printf("Email: %s\n", students[ID_1 - 1].contact.email);
        printf("Parent's Name: %s\n", students[ID_1 - 1].parent.name);
        printf("Parent's Phone: %s\n", students[ID_1 - 1].parent.contact.phone);
        printf("Parent's Email: %s\n", students[ID_1 - 1].parent.contact.email);
    }else
    {
        printf("Bunday ID da talaba yuq!\n");
    }   
}

void get_student_by_name(){
    char search_name[40];
    if (student_count != 0)
    {   
        printf("Talabani ismini kiriting: ");
        scanf("%s", search_name);
        printf("ID | First Name | Last Name | Age | Phone        | Email                   | Parent's Name | Parent's Phone | Parent's Email\n");
        for (int i = 0; i < student_count; i++)
        {
            if (strstr(students[i].first_name, search_name))
            {
                printf("%-3d", i + 1);
                printf("| %-10s ", students[i].first_name);
                printf("| %-9s ", students[i].last_name);
                printf("| %-3d ", students[i].age);
                printf("| %-12s ", students[i].contact.phone);
                printf("| %-23s ", students[i].contact.email);
                printf("| %-13s ", students[i].parent.name);
                printf("| %-14s ", students[i].parent.contact.phone);
                printf("| %s\n", students[i].parent.contact.email);
            }
        }
    }else
    {
        printf("Hozzircha bazada talabalar ro`yxati yuq!\n");
    }
}


void add_lesson(){

    lessons = realloc(lessons, (lesson_count + 1) * sizeof(Lesson));
    if (!lessons)
    {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    printf("Dars nomini kiriting: ");
    scanf("%s", lessons[lesson_count].name);
    lessons[lesson_count].id = lesson_count + 1;
    lesson_count++;
    printf("Lesson added successfully!\n");
}

void add_score(){
    if (student_count != 0)
    {
        if (lesson_count != 0)
        {
            int choose_student; 
            printf("ID | First Name | Last Name | Age | Phone        | Email                   | Parent's Name | Parent's Phone | Parent's Email\n");
            for (int i = 0; i < student_count; i++)
            {
                printf("%-3d", i + 1);
                printf("| %-10s ", students[i].first_name);
                printf("| %-9s ", students[i].last_name);
                printf("| %-3d ", students[i].age);
                printf("| %-12s ", students[i].contact.phone);
                printf("| %-23s ", students[i].contact.email);
                printf("| %-13s ", students[i].parent.name);
                printf("| %-14s ", students[i].parent.contact.phone);
                printf("| %s\n", students[i].parent.contact.email);
            }
            printf("Yuqoridagi talabalardan qaysi birini baholamoqchisiz? \nularni tartib raqamini tanlang: ");
            scanf("%d", &choose_student);
            if (choose_student - 1 <= student_count)
            {   
                int choose_lesson; 
                printf(" ID | Fanlar\n--------------------\n");
                for (int i = 0; i < lesson_count; i++)
                {
                    printf(" %-2d ", lessons[i].id);
                    printf("| %s\n",lessons[i].name);
                }
                printf("Fanni tanlang: ");
                scanf("%d", choose_lesson);
                if (choose_lesson - 1 <= lesson_count)
                {
                    scores = realloc(scores, (student_count + 1) * sizeof(Score));
                    if (!scores)
                    {
                        printf("Memory allocation failed!\n");
                        exit(1); 
                    }
                    printf("%s ismli talabaning %s fanidagi bahosini kiriting: ", students[choose_student - 1].first_name, lessons[choose_lesson].name);
                    scanf("%d", scores[score_count].score);      
                }else
                {
                    printf("Siz bazada yo`q bo`lgan fanni tanladingiz");
                }
                
                
            }else
            {
                printf("Bunday ID da talaba yuq");
            }
        
            
            
            
        }else
        {
            printf("Jadvalga birorta ham dars qo`yilmagan!\n");
        }
        
        
    }else
    {
        printf("Baholash uchun bazada talabalar bo`lishi kk, sizda esa ular yo`q :(\n");
    }
    
    
}