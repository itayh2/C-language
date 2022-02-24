#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
#define ID_LEN 999999999


typedef struct
{
    unsigned int year; //  4 digits for year
    char month;// 2 digits for month
    char day; // 2 digits for day
}dateofbirth;

typedef struct  // Guy - struc of resident  , a
{
    long unsigned  id; // id - size of unsigned 8 bites
    char* first_name; // char dinamic array for fist name
    char* last_name;// char dinamic array for last name
    dateofbirth date_of_birth;
    long unsigned  partner_id;// id partner - size of unsigned 8 bites
    long unsigned  mother_id;// id mother - size of unsigned 8 bites
    long unsigned  father_id;// id father - size of unsigned 8 bites
    unsigned char num_of_children;
    long unsigned* children_ids;
}person;

typedef struct
{
    person* person_ptr;
    int size_of_db;
}db_mgr;


static person ERROR_PERSON = { -1,NULL ,NULL ,{0,0,0},0 ,0 ,0 ,0 ,0 };

void init_db(db_mgr* manager);//יוצר את כמות האנשים הראששונית
void menu(db_mgr* database_mgr); // סעיף ד
void add_person(db_mgr* db);//הוספת אדם למערך וסידורו בתוך המערך
person* search_id(db_mgr* database_mgr, long unsigned id_resident); // סעיף ו
int check_id(long unsigned number);// בדיקה האם הת.ז שהוזנה תקינה
person* search_id_check(db_mgr* database_mgr, long unsigned int id_resident);//פונקציית עזר למציאת אדם
person add_resident(db_mgr* db, person* new_resident);// פונקציית עזר לקליטת תושב חדש
bool birthday_check(dateofbirth date);//פונקציית עזר בדיקת תאריך
person* cahnge_db_person_len(db_mgr* db, person* temp, bool add);// פונרציית עזר לשינוי אורך המערך של האנשים
char* get_name(char* name, char* dest);//פונקציית עזר להעברה של שם בין אנשים
person* search_person(db_mgr* db);//סעיף ז
void search_parent(db_mgr* database_mgr); // סעיף ח
void delete_person(db_mgr* db);// סעיף ט
void delete_relatives(db_mgr* db, long unsigned id_resident);//פונקציית עזר המוחקת את הקרובים של האדם
int search_relatives(db_mgr* db, long unsigned id_resident, int* i);//פונקציית עזר המוצאת את הקרובים לאדם
void get_gen(db_mgr* db);// סעיף י
void print_db(db_mgr* database); // סעיף יא
void print_person(person* resident);
void search_by_name(const db_mgr* database); // סעיף יב
void quit(db_mgr* database); // סעיף יג





int main()
{
    db_mgr db;
    init_db(&db);
    return 0;
}

void init_db(db_mgr* manager)
{
    int number_of_residents;
    printf("Enter the number of residents \n");

    scanf("%d", &number_of_residents);
    if (number_of_residents <= 0)    // bigger then zero
    {
        printf("the number of residents cannot be negative or 0");
        return;
    }
    manager->size_of_db = number_of_residents;
    printf("%d is the number of residents \n", manager->size_of_db);

    manager->person_ptr = (person*)malloc((number_of_residents) * (sizeof(person)));
    if (!manager->person_ptr)//בדיקת הקצאת זכרון
    {
        printf("No memory");
        return;
    }
    for (int i = 0; i < manager->size_of_db; ++i)
    {
        manager->person_ptr[i] = ERROR_PERSON;
    }
    for (int i = 0; i < manager->size_of_db; ++i)
    {
        add_person(manager);
    }
}


void menu(db_mgr* database_mgr) // סעיף ד
{
    int choose = 0;
    while (choose != 8) // כל עוד הבחירה היא לא 8 להמשיך
    {
        printf("Database System Menu:\n1 - Add person\n2 - Search a person\n3 - Search Parents\n4 - Delete a person\n5 - Get generation\n6 - Print database\n7 - Search by name\n8 - Quit\n");
        scanf("%d", &choose); // קליטת בחירה מהמשתמש
        switch (choose)
        {
        case 1:
            printf("you choosed 1\n");
            add_person(database_mgr); // קריאה לפונקציית - הוספת תושב
            break;
        case 2:
            printf("you choosed 2\n");
            search_person(database_mgr); // קריאה לפונקציית - חיפוש בן אדם
            break;
        case 3:
            printf("you choosed 3\n");
            search_parent(database_mgr); // קריאה לפונקציית - חיפוש הורה
            break;
        case 4:
            printf("you choosed 4\n");
            delete_person(database_mgr); // קריאה לפונקציית - מחיקת בן אדם
            break;
        case 5:
            printf("you choosed 5\n");
            get_gen(database_mgr); // קריאה לפונקציית - מציאת מספר הדורות
            break;
        case 6:
            printf("you choosed 6\n");
            print_db(database_mgr); // קריאה לפונקציית - הדפסת כל התושבים
            break;
        case 7:
            printf("you choosed 7\n");
            search_by_name(database_mgr); // קריאה לפונקציית - חיפוש תושב לפי שם פרטי ושם משפחה
            break;
        case 8:
            printf("you choosed 8\n"); // קריאה לפונקציית - יציאה
            break;
            // quit
        default:
            printf("Your choice is incorrect, please try again\n");
            continue;
        }
    }
}



/*הפונקצייה מוסיפה תושב לדאטה בייס אך היא מוסיפה אותו במקום המתאים
ולכן התושבים יהיו תמיד מסודרים לפי תז בגלל שהיא מוסיפה את כולם החל מהתז הראשון*/

void add_person(db_mgr* db)
{
    person newperson = ERROR_PERSON;//הגדרה של המשתמש שנקלוט מהמשתמש
    newperson = add_resident(db, &newperson);//שליחה של המשתמש לפונקציית העזר שתשמש לקליטה

    if (newperson.id == -1)//בדיקה התושב לא הוזן כראוי
    {
        return;
    }
    person* temp = NULL;//הגדרה של משתנה להגדלץ המערך
    temp = cahnge_db_person_len(db, temp, true);//העתקה של כל המער הנוכחי למערך זמני למען הגדלת המערך

    bool check = false;// משתנה בוליאני כדי לחסוך בדיקות או בלבול במקרה של שגיאה במסד הנתונים
    for (int i = 0, j = 0; i < db->size_of_db; i++)//לולאה שתעבור על כל התושבים
    {
        if (!check)
        {
            if (temp[j].id > newperson.id || (temp[j].first_name == NULL && temp[j].last_name == NULL))//מסדר את התושב במקום הראוי לו ובכך מסדרת את התושב במקום הראוי
            {
                db->person_ptr[i] = newperson;//הוספה של התושב החדש במקום המתאים
                check = true;//שינוי הבדיקה
            }
            else
            {
                db->person_ptr[i] = temp[j];//הוספה של שאר התושבים הקודמים
                j++;//התקדמות המערך של שאר התושבים
            }
        }
        else
        {
            db->person_ptr[i] = temp[j];//הוספה של שאר התושבים הקודמים
            j++;//התקדמות המערך של שאר התושבים
        }
    }

    free(temp);//שחרור מערך התושבים הזמני

}


/*הפונקצייה הוספת תושב מאפשרת לקלוט תושב חדש ושליחת הנתונים בהתאם*/
person add_resident(db_mgr* db, person* new_resident)
{
    char name[SIZE];//הדרת גודל לשם
    printf("please enter the person id\n");
    scanf("%lu", &new_resident->id);//קליטת תז תושב
    printf("%lu is the new id \n", new_resident->id);

    person* temp = NULL;

    if (check_id(new_resident->id) == 0)
    {
        scanf("%lu", &new_resident->id);//קליטת תז תושב
        printf(" got into id check == 0\n");
    }

    temp = search_id_check(db, new_resident->id);//בדיקה האם קיין תושב עם התז הנל
    if (temp->id != -1)
    {
        printf("There are resident with the same ID\n");
        return ERROR_PERSON;//החזרה של קבוע משתנה שמסביר על בעיה בפונקצייה
    }

    printf("enter the person first name\n");
    fseek(stdin, 0, SEEK_END);
    gets(name);//קליטת שם פרטי
    new_resident->first_name = get_name(name, new_resident->first_name);//השמה של השם בתוך התושב
    printf("enter the person last name\n");
    *name = NULL;
    fseek(stdin, 0, SEEK_END);
    gets(name);//שליטת שם משפחה
    new_resident->last_name = get_name(name, new_resident->last_name);//השמה של השם בתוך התושב
    bool date_check = false;//הגדרה של משתנה בוליאני לבדיקת תאריך
    while (!date_check)//כל עוד התאריך לא תקין לבקש מהמשתמש להקליד תאריך נכון
    {
        printf("please enter the year of birth\n");
        scanf("%d", &new_resident->date_of_birth.year);//קליטת שנת לידה
        printf("please enter the month of birth\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &new_resident->date_of_birth.month);//קלית חודש לידה
        printf("please enter the day of birth\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &new_resident->date_of_birth.day);//קליטת יום לידה
        date_check = birthday_check(new_resident->date_of_birth);//בדיקה האם התאריך שהוקלד תקין
    }
    printf("please enter the person partner id\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%lu", &new_resident->partner_id);//קליטת תז שותף
    if (check_id(new_resident->partner_id) == 0)
    {
        scanf("%lu", &new_resident->partner_id);//קליטת תז
    }
    printf("please enter the person mother id\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%lu", &new_resident->mother_id);//קליטת תז אם
    if (check_id(new_resident->mother_id) == 0)
    {
        scanf("%lu", &new_resident->mother_id);//קליטת תז
    }
    printf("please enter the person father id\n");
    scanf("%lu", &new_resident->father_id);//קליטת תז אב
    if (check_id(new_resident->father_id) == 0)
    {
        scanf("%lu", &new_resident->father_id);//קליטת תז
    }
    fseek(stdin, 0, SEEK_END);
    printf("please enter the number of the children\n");
    scanf("%d", &new_resident->num_of_children);//קליטת מספר ילדים
    if ((int)new_resident->num_of_children > 0)
    {
        new_resident->children_ids = (long unsigned*)malloc(((int)new_resident->num_of_children) * sizeof(long unsigned));//הקצאת זכרון למספר ילדים
        if (!new_resident->children_ids)//בדיקת הקצאת זכרון
        {
            printf("No memory");
            new_resident->children_ids = NULL;
            return ERROR_PERSON;
        }
        for (int i = 0; i < (int)new_resident->num_of_children; i++)//קליטת תעודות זהות של הילדים
        {
            printf("please enter the id number of the %d children\n", i + 1);
            fseek(stdin, 0, SEEK_END);
            scanf("%lu", &new_resident->children_ids[i]);
            if (check_id(new_resident->children_ids[i]) == 0)
            {
                scanf("%lu", &new_resident->children_ids[i]);
            }
        }
    }
    else
    {
        printf("children number must to be positive");
        return ERROR_PERSON;
    }
    return *new_resident;
}

/*הפונקצייה הבאה בודקת שהתאריך שהוזן הגיוני ונכון מבחינת הימים בחודש*/
bool birthday_check(dateofbirth date)
{
    switch (date.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (date.day > 31 || date.day < 1 || NULL)
        {
            printf("the date is illegal please type again");
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date.day > 30 || date.day < 1 || NULL)
        {
            printf("the date is illegal please type again");
            return false;
        }
        break;
    case 2:
        if (date.day > 28 || date.day < 1 || NULL)
        {
            printf("the date is illegal please type again");
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}


/*הפונקצייה אחראית לשינוי גודל המערך של הדאטה בייס
ובנוסף על כך היא מעתיקה את הנתונים הקיימים כיום למערך זמני שישוחרר בתוך הפונקצייה*/

person* cahnge_db_person_len(db_mgr* db, person* temp, bool add)
{
    if (db->size_of_db > 0)//מעבר על כל המערך במידה ומסדובר במערך עם נתונים
    {
        temp = (person*)malloc((db->size_of_db) * (sizeof(person)));//הקצאת הזכרון למערך הזמני
        if (!temp)//בדיקת הקצאת זכרון
        {
            printf("No memory");
            return &ERROR_PERSON;
        }

        for (int i = 0; i < db->size_of_db; i++)//העתקת המערך הקיים
        {
            temp[i] = db->person_ptr[i];
        }

        free(db->person_ptr);//שחרור הדאטה
        db->person_ptr = NULL;

        if (add)//בדיקה האם צריך להגדיל את המערך או להקטין אותו
        {
            db->size_of_db++;//הגדלת המערך
        }
        else
        {
            db->size_of_db--;//הקטנת המערך
        }

        db->person_ptr = (person*)malloc((db->size_of_db) * (sizeof(person)));//הקצאת זכרון למערך החדש
        if (!db->person_ptr)
        {
            printf("there is no memory");
            return &ERROR_PERSON;
        }

        return(temp);
    }
    else
    {
        if (add)//הדלת המערך אם מדובר בהוספה של תושב אחד למערך ריק
        {
            db->size_of_db++;
            db->person_ptr = (person*)malloc((db->size_of_db) * (sizeof(person)));
            return(temp);
            if (!db->person_ptr)
            {
                printf("there is no memory");
                return &ERROR_PERSON;
            }
        }
        else
        {
            printf("ther is no one on the data base");
            return &ERROR_PERSON;
        }
    }
}

int check_id(long unsigned int number) // בדיקה האם הת.ז שהוזנה תקינה
{
    if (number >= 0 && number <= ID_LEN)
    {
        return 1;
    }
    else
    {
        printf("Invalid input Please try again");
        return 0;
    }
}

person* search_id(db_mgr* database_mgr, long unsigned int id_resident) // סעיף ו
{
    for (int i = 0; i < database_mgr->size_of_db; i++) // ריצה על התושבים
    {
        if (database_mgr->person_ptr[i].id == id_resident) // בדיקה האם התושב קיים לפי הת.ז
        {
            return database_mgr->person_ptr + i; // החזרת התושב לפי האינדקס אם הוא נמצא קיים
        }
    }
    printf("Unfortunately no match was found\n"); // אחרת הצגת הודעת מתאימה
    return &ERROR_PERSON;
}

person* search_id_check(db_mgr* database_mgr, long unsigned int id_resident)
{
    for (int i = 0; i < database_mgr->size_of_db; i++) // ריצה על התושבים
    {
        if (database_mgr->person_ptr[i].id == id_resident) // בדיקה האם התושב קיים לפי הת.ז
        {
            printf("i is %d and matching id is %lu", i, id_resident);

            return &database_mgr->person_ptr[i]; // החזרת התושב לפי האינדקס אם הוא נמצא קיים
        }
    }
    return &ERROR_PERSON;
}

char* get_name(char* name, char* dest)
{
    long long len = strlen(name);//מציאת אורך השם
    dest = (char*)malloc((len + 1) * sizeof(char));//הגדרת המערך באורך השם
    if (!dest)//בדיקת הקצאת זכרון
    {
        printf("No memory");
        dest = NULL;
        return dest;
    }
    strcpy(dest, name);//העתקת השם למיקום הסופי
    return dest;//החזרת השם
}

person* search_person(db_mgr* db)//סעיף ז
{
    long unsigned id;//הגדרת תז לחיפוש
    printf("enter id\n");
    scanf("%lu", &id);//קליטת תז לחיפוש
    person* temp;
    temp = search_id(db, id);//השץמשות בפוקציית עזר למציאת תושב לפי תז
    if (temp->id != -1)
    {
        print_person(temp);
        return temp;
    }
    printf("Unfortunately no match was found\n");
    return &ERROR_PERSON;
}

void search_parent(db_mgr* database_mgr) // סעיף ח
{
    long unsigned int id = 0;
    long unsigned int temp_father_id = 0;
    long unsigned int temp_mother_id = 0;
    int res = 0;
    person* temp_resident;
    while (res != 1)
    {
        printf("Please insert the id you looking for: \n");
        scanf("%lu", &id);
        fseek(stdin, 0, SEEK_END);
        res = check_id(id);
    }
    temp_resident = search_id(database_mgr, id);
    if (temp_resident == NULL)
    {
        printf("Not found\n");
        return;
    }
    temp_father_id = temp_resident->father_id;
    for (int i = 0; i < database_mgr->size_of_db; i++)
    {
        if (temp_father_id == database_mgr->person_ptr[i].id)
        {
            print_person((database_mgr->person_ptr + i));
            break;
        }
    }
    temp_mother_id = temp_resident->mother_id;
    for (int i = 0; i < database_mgr->size_of_db; i++)
    {
        if (temp_mother_id == database_mgr->person_ptr[i].id)
        {
            print_person((database_mgr->person_ptr + i));
            break;
        }
    }
}

/* הפונקצייה הבאה מוחקת אדם מהמערכת
ומשתמשת בפונקציות עזר כדי למחוק אותו מהקרובים
ובכדי לסדר מחדש את המערך*/
void delete_person(db_mgr* db)
{
    long unsigned delete_p;//תעודת הזהות למחיקה
    printf("enter the id of the person that you would like to delete\n");
    scanf("%lu", &delete_p);

    person* check_person = NULL;
    check_person = search_id_check(db, delete_p);//חיפוש תושב עם אותה תעודת זהות
    if (check_person->id == -1)
    {
        return;
    }

    person* temp = NULL;//הגדרת מערך תושבים לביצוע הפעולה ללא REALOOC
    cahnge_db_person_len(db, temp, false);//העתקת המערך ושינוי הקצאת המערך הנוכחי בהתאם

    bool check = true;//בדיקה כדי למנוע מחיקות מיותרות במקרה של דאטה שגוי
    for (int i = 0, j = 0; i < db->size_of_db; i++, j++)// ריצה על כל המערך שהועתקת ומחיקת העובד הרלוונטי
    {
        if (check)
        {
            if (temp[j].id == delete_p)//אם התעודת זהות שווה מדלגים על אותו תושב ולא מעתיקים אותו
            {
                printf("id that matches is %lu \n", temp[j].id);
                j++;

                check = false;
            }
        }
        db->person_ptr[i] = temp[j];
    }


    free(temp);//שחרור המערך הזמני

    delete_relatives(db, delete_p);//מחיקת קרובי התושב
}

/*פונקציית עזר המוחקת את הקרובים של אותו תושב*/

void delete_relatives(db_mgr* db, long unsigned id_resident)
{
    int i = 0;
    int search_relatives_result;
    search_relatives_result = search_relatives(db, id_resident, &i);//שימוש בפוקציית עזר למציאת קרובים לתושב
    long unsigned* temp = NULL;//הגדרת משתנה לשמירת הילדים לצורך שינוי האורך שלהם

    while (search_relatives_result != 0)
    {
        switch (search_relatives_result)
        {
        case 1:
            db->person_ptr[i].partner_id = 0;//מחיקת תז השותף
            break;
        case 2:
            db->person_ptr[i].mother_id = 0;//מחיקת תז האם
            break;
        case 3:
            db->person_ptr[i].father_id = 0;//מחיקת תז האב
            break;
        case 4:

            temp = (long unsigned*)malloc(((int)db->person_ptr[i].num_of_children) * (sizeof(long unsigned)));//הגדרץ המערך כילדים של התושב
            if (!temp)//בדיקת הקצאת זכרון
            {
                printf("No memory");
                return;
            }
            for (int j = 0; j < (int)db->person_ptr[i].num_of_children; j++)
            {
                temp[j] = db->person_ptr[i].children_ids[j];
            }
            free(db->person_ptr[i].children_ids);// שחרור הילדים של התושב
            db->person_ptr[i].num_of_children--;
            if (db->person_ptr[i].num_of_children != 0)
            {
                db->person_ptr[i].children_ids = (long unsigned*)malloc(((int)db->person_ptr[i].num_of_children) * (sizeof(long unsigned)));//הקצאת זכרון פחות 1
                if (!db->person_ptr[i].num_of_children)//בדיקת הקצאת זכרון
                {
                    free(temp);
                    printf("No memory");
                    return;
                }
                for (int j = 0, k = 0; j < (int)db->person_ptr[i].num_of_children; j++)//הכנסת הילדים בהתאם לתושב
                {
                    if (temp[k] == id_resident)//מחיקת הילד מהרשימה
                        k++;
                    db->person_ptr[i].children_ids[j] = temp[k];
                }
            }

            free(temp);
            break;

        default:
            break;
        }

        search_relatives_result = search_relatives(db, id_resident, &i);//בדיקה שאין עוד קרובים שצריך למחוק
    }
}

/*פונקציית עזר לחיפוש קרובי משפחה לתושב*/

int search_relatives(db_mgr* db, long unsigned id_resident, int* i)
{
    for (*i; *i < db->size_of_db; *i = *i + 1)//רץ בלולאה עם משתנה שקיבלנו מצביע שלו כדי לרות כל פעם מנק ההפסקה ולא לעבור על כל התושבים שוב
    {
        if (db->person_ptr[*i].partner_id == id_resident)// אם מדובר בשותף מחזיר את הערך 1
            return 1;
        if (db->person_ptr[*i].mother_id == id_resident)//אם מדובר באמ מחזיר את הערך 2
            return 2;
        if (db->person_ptr[*i].father_id == id_resident)// אם מדובר באב מחזיר את הערך 3
            return 3;
        for (int j = 0; j < (int)db->person_ptr->num_of_children; j++)
        {
            if (db->person_ptr[*i].children_ids[j] == id_resident)
                return 4;//אם מדובר בילד מחזיר את הערך 4
        }
    }
    return 0;
}

/*פונקצייה הסופרת את הדור של התושב
באמצעות העברת כל הילדים של התושבים למערך של תעודות זהות מצאית התאנשים שהם תושבים קיימים מהם
העברת הילדים שלהם למערך של התעודות זהות כך עד שהמערך יהיה ריק*/

void get_gen(db_mgr* db)
{
    int gen = 1;//הגדרת הדור
    person* parents = NULL;//הגדרת מערך ההורים
    long unsigned* childs;//הגדרת מערך הילדים
    long unsigned id;//הגדרת תעודת זהות לחיפוש
    person* temp = NULL;//אדם זמני לבדיקת ילדים
    int children_number = 1;
    int parents_number = 0;

    printf("Enter the id for the gen check\n");
    scanf("%lu", &id);
    person* check_person;
    check_person = search_id(db, id);//בדיקת תעודת זהות
    if (check_person->id == -1)
    {
        return;
    }

    childs = (long unsigned*)malloc((children_number) * (sizeof(long unsigned)));//הגדרת גודל מערך ילדים
    if (!childs)//בדיקת הקצאת זכרון
    {
        printf("No memory");
        return;
    }
    childs[0] = id;//הגדרת ילד ראשון כתושב שקיבלנו
    parents = (person*)malloc((sizeof(person)));//הגדרת מערך הורים
    if (!parents)//בדיקת הקצאת זכרון
    {
        printf("No memory");
        return;
    }

    while (childs[0] != -1)//כל עוד מערך הילדים לא ריק יש לבדוק האם יש לדור הבא ילדים וכך הלאה
    {
        for (int i = 0; i < children_number; i++)//מעבר על כל הילדים הקיימים להורה
        {
            temp = search_id_check(db, childs[i]);//בדיקה האם קיימים לו ילדים שהם יישויות של תושב במערכת
            if (temp->id != -1)//אם קיים כתושב
            {
                if (parents_number == 0)//הגדרה של המערך אם הוא ההורה הראשון מרשימת התושבים
                {
                    parents_number++;//הגדלת מספר ההורים
                    free(parents);//שחרור המערך שהיה לפני
                    parents = (person*)malloc((parents_number) * (sizeof(person)));
                    if (!parents)//בדיקת הקצאת זכרון
                    {
                        printf("No memory");
                        return;
                    }
                    parents[0] = *temp;//הגדרה של התושב הראשון כהורה
                }
                else
                {
                    parents_number++;//הגדלת מספר ההורים
                    parents = (person*)realloc(parents, (parents_number) * (sizeof(person)));//הגדלה של המערך הדינאמי
                    if (!parents)//בדיקת הקצאת זכרון
                    {
                        printf("No memory");
                        return;
                    }
                    parents[parents_number - 1] = *temp;//הוספה של הילד תושב למקום המתאים
                }
            }
        }
        children_number = 0;//איפוס מספר הילדים
        for (int i = 0; i < parents_number; i++)//מעבר על כל ההורים
        {
            children_number = children_number + (int)(parents[i].num_of_children);// ספירת מספר הילדים של כל ההורים במצטבר
        }
        if (children_number > 0)// אם מספר הילדים גדול מ0 יש לבצע:
        {
            childs = (long unsigned*)malloc((children_number) * (sizeof(long unsigned)));//התאמת גודל הזכרון של המערך לפי מספר הילדים
            if (!childs)//בדיקת הקצאת זכרון
            {
                printf("No memory");
                return;
            }
            for (int i = 0, k = 0; i < parents_number; i++)
            {
                for (int j = 0; j < (int)parents[i].num_of_children; j++)//הכנסה של כל הילדים במקום המתאים
                {
                    childs[k] = parents[i].children_ids[j];
                    k++;
                }
            }
            parents_number = 0;//איפוס מספר ההורים
            gen++;//הוספת דור
        }
        else//אם אין עוד ילדים
        {
            children_number = 1;//הגדרה של גודל המערך
            childs = (long unsigned*)malloc((children_number) * (sizeof(long unsigned)));//הקצאה דינאמית לגודל המערך
            if (!childs)//בדיקת הקצאת זכרון
            {
                printf("No memory");
                return;
            }
            childs[0] = -1;// התאמה של -1 לתז של הילד במקום הראשון
            printf("the genartion of %lu is %d\n", id, gen);//הדפסת הדור

        }
    }
    free(parents);
    free(childs);
}

void print_db(db_mgr* database)
{
    for (int i = 0; i < database->size_of_db; i++) // ריצה על כל האנשים
    {
        printf("-------------------------Details of resident number %d------------------------\n", i + 1);
        print_person(&database->person_ptr[i]); // הדפסת כל התושבים
    }
    printf("------------------------------------------------------------------------------\n");
}

void print_person(person* resident)
{
    printf("first name of resident: %s\n", resident->first_name);
    printf("last name of resident: %s\n", resident->last_name);
    printf("id of the resident: %lu\n", resident->id);
    printf("birth of resident: %d.%d.%d\n", resident->date_of_birth.day, resident->date_of_birth.month, resident->date_of_birth.year);
    printf("id of the partner: %lu\n", resident->partner_id);
    printf("id of mother: %lu\n", resident->mother_id);
    printf("id of father: %lu\n", resident->father_id);
    for (int i = 0; i < resident->num_of_children; i++)
    {
        printf("id of the %d children: %lu\n", i + 1, resident->children_ids[i]);
    }
}

void search_by_name(const db_mgr* database)  // סעיף יב
{
    if (database->person_ptr == NULL)
    {
        printf("No residents with the same first name and last name were found, try to add someone first\n");
        return;
    }
    int res1, res2;
    int check = 0;
    char tmp_firstname[SIZE]; // שמירת השם הפרטי
    char tmp_lastname[SIZE]; // שמירת שם המשפחה
    printf("Please insert first name of the resident: \n"); // בקשה מהמשתמש להזין שם פרטי של תושב
    fseek(stdin, 0, SEEK_END);
    gets(tmp_firstname);
    printf("Please insert last name of the resident: \n"); // בקשה מהמשתמש להזין שם משפחה של תושב
    fseek(stdin, 0, SEEK_END);
    gets(tmp_lastname);
    for (int i = 0; i < database->size_of_db; i++) // ריצה על כל התושבים
    {
        res1 = strcmp(database->person_ptr[i].first_name, tmp_firstname); // השוואה בין השמות הפרטיים
        res2 = strcmp(database->person_ptr[i].last_name, tmp_lastname); // השוואה בין שמות המשפחה
        if (res1 == 0 && res2 == 0) // בדיקה האם 2 התוצאות שוות ל0 ובאמת יש התאמה
        {
            printf("-----------------------------------details-------------------------------------\n");
            print_person(database->person_ptr + i); // הדפסת האנשים שנמצאו עם שם פרטי ושם משפחה תואם למה שהזין המשתמש
            check = 1;
        }
    }
    return;
    if (check != 1)
    {
        printf("sorry, not found any\n"); // הצגת הודעה שלא נמצאה התאמה
        return;
    }
}

void quit(db_mgr* database)//מחיקת כל ההקצאות שנפתחו
{
    printf("Thank you\n");
    for (int i = 0; i < database->size_of_db; i++)
    {
        free(database->person_ptr[i].first_name);
        database->person_ptr[i].first_name = NULL;
        free(database->person_ptr[i].last_name);
        database->person_ptr[i].last_name = NULL;
        for (int j = 0; j < database->person_ptr[i].num_of_children; j++)
        {
            free(database->person_ptr[i].children_ids + j);
        }
        free(database->person_ptr + i);
    }
}
