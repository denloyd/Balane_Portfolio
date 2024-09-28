#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define FLUSH fflush(stdin)
#define MAX_RECEIPTS 100
#define MAX_SIZE 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 100
#define MAX_STALL_LENGTH 100

typedef struct {
    char Email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    char stall[MAX_STALL_LENGTH];
} Staff;

Staff staffArray[MAX_SIZE];
int size = 0, i;
void createFile();
void print_staff();
void inputArray();
void editStaff();
void deleteStaff();
void readFromFile();
void clearInputBuffer();
int isDataAlreadyPresent();

struct Receipt {
    struct Item {
        char name[100];
        float price;
        int quantity;
    } items[100];
    int itemCount;
    float total;
    float change;
    float cash;
};

void DISPLAY();
bool LOG_IN();
int ADMIN_LOGIN();
bool STAFF_LOGIN();
void ADMIN_DOMAIN();
void STAFF_DOMAIN();
void saveReceiptToFile(struct Receipt receipt, int maxReceiptNumber);
void RECEIPT_GENERATOR();
void SALES_REPORT();
void Search_Inventory();
void frie_yay_products_INVENTORY();
void scoop_on_the_waffs_products_INVENTORY();
void sizzsilog_house__INVENTORY();
void frie_yay_products_Order_System();
void scoop_on_the_waffs_products_Order_System();
void sizzsilog_house_products_Order_System();
void View_Receipt();
bool accessInventory();
bool accessOrderingSystem();


struct MenuItem {
    char name[50];
    float price;
    int quantity;
    char code[10];
};

int getNextReceiptNumber=0;
struct Receipt receipt;

         struct MenuItem frie_yay_products[] = {
                {"Yueng Plain Rice", 15.00, 20,"YPL" },
                {"Yueng Plain Rice with Pork Shanghai", 45.00, 20,"PSHR"},
                {"Yueng Plain Rice with Pork Siomai", 30.00, 20,"PSR"},
                {"Yueng Plain Rice with Beef Siomai", 30.00, 20,"BSIR"},
                {"Yueng Plain Rice with Chicken Siomai", 30.00, 20,"CSIR"},
                {"Regular Fries - Ketchup/Mayo Drizzle", 15.00, 20,"FWK"},
                {"Regular Fries - Spicy Cheese Drizzle", 20.00, 20,"FSPC"},
                {"Regular Fries - Barbeque Drizzle", 20.00, 20,"FBBQ"},
                {"Drinks - Lemon Iced Tea (16 oz)", 15.00, 20,"LM1"},
                {"Drinks - Lemon Iced Tea (22 oz)", 25.00, 20,"LM2"},
                {"Drinks - Cucumber Lemonade (16 oz)", 15.00, 20,"CUM1"},
                {"Drinks - Cucumber Lemonade (22 oz)", 25.00, 20,"CUM2"},
                {"Drinks - Blue Lemonade (16 oz)", 15.00, 20,"BL1"},
                {"Drinks - Blue Lemonade (22 oz)", 25.00, 20,"BL2"}
            };
        struct MenuItem scoop_on_the_waffs_products[] = {
            {"Waffs - Strawberry Waffs (Original)", 55.00,20,"ORSW"},
            {"Waffs - Strawberry Waffs (Overload)", 110.00,20,"OVSW"},
            {"Waffs - Kiwi Waffs (Original)", 55.00,20,"ORKW"},
            {"Waffs - Kiwi Waffs (Overload)", 110.00,20,"OVKW"},
            {"Waffs - Mango Waffs (Original)", 55.00,20,"ORMW"},
            {"Waffs - Mango Waffs (Overload)", 110.00,20,"OVMW"},
            {"Streetfoods - Kwek-kwek ", 20.00,20,"SKK"},
            {"Streetfoods - Chickenballs", 20.00,20,"SCB"},
            {"Streetfoods - Kikiam", 20.00,20,"SKIK"},
            {"Drinks - Water ", 15.00,20, "H2O"},
            {"Drinks - Softdrinks (Coke)", 25.00,20,"SCK"},
            {"Drinks - Softdrinks (Sprite)", 25.00,20,"SPR"},
            {"Drinks - Softdrinks (Mountain Dew)", 25.00,20,"MTD"}
        };

        struct MenuItem sizzsilog_house_products[] = {
            {"Silog - Hotsilog", 55.00, 20, "HOT"},
            {"Silog - Tocilog", 60.00, 20, "TOC"},
            {"Silog - Shangsilog", 45.00, 20, "SHANG"},
            {"Silog - Chicksilog", 65.00, 20, "CHICK"},
            {"Silog - Porksilog", 70.00, 20, "PORK"},
            {"Silog - Liemposilog", 70.00, 20, "LIEM"},
            {"Extra - Hainanese Rice", 15.00, 20, "EXHR"},
            {"Extra - Plain Rice", 10.00, 20, "EXPR"},
            {"Budget Meal - Siomai Rice", 30.00, 20, "SMR"},
            {"Sizzling - Burger Steak", 89.00, 20, "SIZBS"},
            {"Sizzling - Pork Steak", 99.00, 20, "SIZPS"},
            {"Sizzling - Chicken Sisig", 99.00, 20, "SIZCG"},
            {"Sizzling - Pork Sisig", 99.00, 20, "SIZPG"},
            {"Sizzling - Liempo", 99.00, 20, "SIZLIEM"},
            {"Drink - Gulaman (12 oz)", 10.00, 20, "GUL"},
            {"Shake - Mango Shake (12 oz)", 20.00, 20, "MANSH"}
        };

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    hideCursor();
    LOG_IN();

    return 0;
}

bool LOG_IN()
{
    int userType;
    system("cls");
    createFile();
    gotoxy(37, 5);
    printf("  ___         _          _              __     ___          _            ");
    gotoxy(37, 6);
    printf(" | _ \\  ___  (_)  _ _   | |_     ___   / _|   / __|  __ _  | |  ___   ___");
    gotoxy(37, 7);
    printf(" |  _/ / _ \\ | | | ' \\  |  _|   / _ \\ |  _|   \\__ \\ / _` | | | / -_) (_-<");
    gotoxy(37, 8);
    printf(" |_|   \\___/ |_| |_||_|  \\__|   \\___/ |_|     |___/ \\__,_| |_| \\___| /__/");
    printf("                                                                      ");
    gotoxy(61, 9);
    printf("  _____   _   _   ___");
    gotoxy(61, 10);
    printf(" |_   _| | | | | | _ \\");
    gotoxy(61, 11);
    printf("   | |   | |_| | |  _/");
    gotoxy(61, 12);
    printf("   |_|    \\___/  |_|");
    gotoxy(54, 14);
    printf("Welcome to Our Point of Sales Program!");
    gotoxy(59, 15);
    printf("=======================\n\n");
    gotoxy(59, 16);
    printf("Please select your role:\n");
    gotoxy(59, 17);
    printf("1. Admin\n");
    gotoxy(59, 18);
    printf("2. Staff\n\n");
    gotoxy(59, 19);
    printf("=======================");
    gotoxy(59, 20);
    printf("Enter your role number: ");
    scanf("%i", &userType);
    switch (userType)
    {
        do {
            case 1:
            ADMIN_DOMAIN();
            break;

            case 2:
            STAFF_DOMAIN();
            break;

            default:
            break;
        } while (true);

        printf("Invalid user type. Please try again.\n");
        system("pause");
        FLUSH;
        LOG_IN();
        return (false);
    }
}
void hideCursor() {
    printf("\033[?25l");
}

int ADMIN_LOGIN() {
    FILE *fp;
    int p;
    bool driveOpened = false;
    system("cls");
    gotoxy(50, 11);
    printf("    _   ___  __  __ ___ _  _   _    ___   ___ ___ _  _ \n");
    gotoxy(50, 12);
    printf("   /_\\ |   \\|  \\/  |_ _| \\| | | |  / _ \\ / __|_ _| \\| |\n");
    gotoxy(50, 13);
    printf("  / _ \\| |) | |\\/| || || .` | | |_| (_) | (_ || || .` |\n");
    gotoxy(50, 14);
    printf(" /_/ \\_\\___/|_|  |_|___|_|\\_| |____\\___/ \\___|___|_|\\_|\n");
    gotoxy(50, 15);
    printf("                                                      \n");
    do {
        fp = fopen("E:\\ADMIN.txt", "r");
        if (fp != NULL) {
            ADMIN_DOMAIN();
            driveOpened = true;
        }
         else {
        gotoxy(60, 18);
            printf("\033[1;32mPLEASE INSERT THE KEY ADMIN TO LOGIN\033[0m");
            hideCursor();
            driveOpened = false;
        }

        fscanf(fp, "%d %d", &p, &p);
    } while (!driveOpened);

    if (fp != NULL) {
        fclose(fp);
    }

    return 0;
}

bool STAFF_LOGIN() {
    system("cls");
    char providedEmail[MAX_EMAIL_LENGTH];
    char providedPassword[MAX_EMAIL_LENGTH];  // Added variable for password
    gotoxy(43, 5);
    printf("  ___   _____     _     ___   ___     _       ___     ___   ___   _  _");
    gotoxy(43, 6);
    printf(" / __| |_   _|   /_\\   | __| | __|   | |     / _ \\   / __| |_ _| | \\| |");
    gotoxy(43, 7);
    printf(" \\__ \\   | |    / _ \\  | _|  | _|    | |__  | (_) | | (_ |  | |  | .` |");
    gotoxy(43, 8);
    printf(" |___/   |_|   /_/ \\_\\ |_|   |_|     |____|  \\___/   \\___| |___| |_|\\_|");
    gotoxy(43, 10);
    printf("Please enter your email address and password (or enter 'exit' to go back)");
    gotoxy(60, 12);
    printf("Email address: ");
    scanf("%s", providedEmail);

    while (strcmp(providedEmail, "exit") != 0) {
        FILE *file;
        file = fopen("staff_updated.txt", "r");

        if (file == NULL) {
            printf("Error opening staff file.\n");
            return false;
        }

        char line[1000];
        bool emailFound = false;

        gotoxy(60, 14);
        printf("Password: ");
        scanf("%s", providedPassword);  // Ask for password
        clearInputBuffer();
        while (fgets(line, sizeof(line), file) != NULL) {
            char email[MAX_EMAIL_LENGTH], name[MAX_NAME_LENGTH], stall[MAX_STALL_LENGTH];
            sscanf(line, "Email: %s | Name: %s | Stall Designation: %[^\n]s\n", email, name, stall);

            if (strcmp(email, providedEmail) == 0 && strcmp(name, providedPassword) == 0) {  // Check both email and password
                emailFound = true;
                break;
            }
        }

        fclose(file);

        if (emailFound) {
            STAFF_DOMAIN();
            return true;
        } else {
            printf("\n\nInvalid email or password. Please try again.\n\n");
            system("pause");
            break;
        }
    }

    LOG_IN(); // User chose to exit the login loop
}
// Function to handle admin actions
void ADMIN_DOMAIN() {
    int choice;
    while (1) {
    system("cls");
    gotoxy(55, 5);
    printf("\033[0m    _     ___    __  __   ___   _  _\033[0m");
    gotoxy(55, 6);
    printf("   /_\\   |   \\  |  \\/  | |_ _| | \\| |");
    gotoxy(55, 7);
    printf("  / _ \\  | |) | | |\\/| |  | |  | .` |");
    gotoxy(55, 8);
    printf(" /_/ \\_\\ |___/  |_|  |_| |___| |_\\_ |");
    gotoxy(35, 9);
    printf("  __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____");
    gotoxy(35, 10);
    printf(" |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|");
    gotoxy(35, 11);
    printf(" | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |");
    gotoxy(35, 12);
    printf(" |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_ \ \_|   |_|");
    gotoxy(50, 13);
    printf("  ___  __   __  ___   _____    ___   __  __");
    gotoxy(50, 14);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(50, 15);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(50, 16);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");

    gotoxy(50, 18);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(50, 19);
    printf("Welcome to the Admin Management System!");
    gotoxy(50, 20);
    printf("Please select an option from the following:");
    gotoxy(50, 21);
    printf("1. Add Staff");
    gotoxy(50, 22);
    printf("2. Edit Staff");
    gotoxy(50, 23);
    printf("3. Delete Staff");
    gotoxy(50, 24);
    printf("4. View Staff Record");
    gotoxy(50, 25);
    printf("5. View Stalls Inventory");
    gotoxy(50, 26);
    printf("6. View Sales Report");
    gotoxy(50, 27);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(50, 28);
    printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            gotoxy(50, 29);
            printf("Invalid input. Please enter a valid choice.");
            gotoxy(50, 30);
            system("pause");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                inputArray();
                system("pause");
                break;
            case 2:
                editStaff();
                printf("\n\t\t\t\t\t\t");
                system("pause");
                break;
            case 3:
                deleteStaff();
                printf("\n\t\t\t\t\t\t");
                system("pause");
                break;
            case 4:
                readFromFile();
                printf("\n\t\t\t\t\t\t");
                system("pause");
                break;
            case 5:
                accessInventory(); // Call the function to access the inventory
                printf("\n\t\t\t\t\t\t");
                system("pause");
                break;
            case 6:
                SALES_REPORT();
                break;
            case 0:
                gotoxy(50, 29);
                printf("Exiting the program.\n");
                exit(1);
            default:
                gotoxy(50, 29);
                printf("Invalid choice. Please try again.\n");
        }
    }
}


void createFile()
{
    FILE* file = fopen("staff_updated.txt", "r");
    if (file == NULL) {
        file = fopen("staff_updated.txt", "w");
        fprintf(file,"Email: staff@tup.edu.ph | Name: Staff | Stall Designation: N/A ");
        if (file == NULL) {
            printf("Error creating 'staff_updated.txt' file.\n");
            return;
        }
        fclose(file);
    } else {
        fclose(file);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void readFromFile() {
    system("cls");
    gotoxy(55, 5);
    printf("    _     ___    __  __   ___   _  _");
    gotoxy(55, 6);
    printf("   /_\\   |   \\  |  \\/  | |_ _| | \\| |");
    gotoxy(55, 7);
    printf("  / _ \\  | |) | | |\\/| |  | |  | .` |");
    gotoxy(55, 8);
    printf(" /_/ \\_\\ |___/  |_|  |_| |___| |_\\_ |");
    gotoxy(35, 9);
    printf("  __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____");
    gotoxy(35, 10);
    printf(" |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|");
    gotoxy(35, 11);
    printf(" | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |");
    gotoxy(35, 12);
    printf(" |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_ \ \_|   |_|");
    gotoxy(50, 13);
    printf("  ___  __   __  ___   _____    ___   __  __");
    gotoxy(50, 14);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(50, 15);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(50, 16);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");
    gotoxy(50, 18);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(63, 19);
    printf("*** Staff Details ***");
    FILE *file = fopen("staff_updated.txt", "r");
    if (file != NULL) {
    int isEmpty = 1, i = 21;
    char line[100]; // Assuming a maximum line length of 100 characters

    gotoxy(45, i);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);  // Print the line
        isEmpty = 0;
        i++;
        gotoxy(45, i);  // Move to the next line
    }
        fclose(file);

        if (isEmpty) {
            printf("The file is empty. No staff members found.\n");
        }
    } else {
        printf("Error opening file for reading.\n");
    }
}

void printArray() {
    FILE* file = fopen("staff_updated.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    if (isDataAlreadyPresent(staffArray[size].Email, staffArray[size].name)) {
        gotoxy(50, 23);
        printf("Data already exists in the file.");
        gotoxy(50, 24);
        system("pause");
        ADMIN_DOMAIN();
        return;
    }
    fprintf(file,"\n");
    fprintf(file, "Email: %s | Name: %s | Stall Designation: %s", staffArray[size].Email, staffArray[size].name, staffArray[size].stall);
    fclose(file);
}

void inputArray() {
    system("cls");
    gotoxy(55, 5);
    printf("    _     ___    __  __   ___   _  _");
    gotoxy(55, 6);
    printf("   /_\\   |   \\  |  \\/  | |_ _| | \\| |");
    gotoxy(55, 7);
    printf("  / _ \\  | |) | | |\\/| |  | |  | .` |");
    gotoxy(55, 8);
    printf(" /_/ \\_\\ |___/  |_|  |_| |___| |_\\_ |");
    gotoxy(35, 9);
    printf("  __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____");
    gotoxy(35, 10);
    printf(" |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|");
    gotoxy(35, 11);
    printf(" | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |");
    gotoxy(35, 12);
    printf(" |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_ \ \_|   |_|");
    gotoxy(50, 13);
    printf("  ___  __   __  ___   _____    ___   __  __");
    gotoxy(50, 14);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(50, 15);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(50, 16);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");
    if (size >= MAX_SIZE) {
        gotoxy(50, 17);
        printf("Maximum staff capacity reached.\n");
        return;
    }
    gotoxy(50, 18);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(60, 20);
    printf("*** Enter staff details ***");

    // Prompt and read the email username
    char providedUsername[20];
    char keyword[] = "@tup.edu.ph";
    gotoxy(50, 22);
    printf("Email of Staff: ");
    scanf("%s", providedUsername);

    // Check if the provided username contains the keyword
    if (strstr(providedUsername, keyword) == NULL) {
        gotoxy(50, 22);
        printf("Error: Please use a TUP email.");
        gotoxy(50, 23);
        return;
    }

    // Combine the username and domain to form the full email
    char fullEmail[MAX_EMAIL_LENGTH];
    strcpy(fullEmail, providedUsername);
    strcpy(staffArray[size].Email, fullEmail);

    // Prompt and read the name
    gotoxy(50, 23);
    printf("Name of Staff: ");
    getchar(); // Clear the newline character from the previous input
    fgets(staffArray[size].name, MAX_NAME_LENGTH, stdin);
    staffArray[size].name[strcspn(staffArray[size].name, "\n")] ='\0'; // Remove the trailing newline

    if (isDataAlreadyPresent(staffArray[size].Email, staffArray[size].name)) {
        gotoxy(50, 23);
        printf("Data already exists in the file.");
        gotoxy(50, 24);
        system("pause");
        ADMIN_DOMAIN();
        return;
    }

    // Prompt and read the stall designation
    gotoxy(50, 25);
    printf("Choose a Stall in TUP Cafeteria: Frie Yay, Scoop on the Waffs, Sizzsilog House");
    gotoxy(50, 26);
    printf("Stall Designation: ");
    fgets(staffArray[size].stall, MAX_STALL_LENGTH, stdin);
    staffArray[size].stall[strcspn(staffArray[size].stall, "\n")] ='\0'; // Remove the trailing newline
    gotoxy(50, 27);
    printArray(); // Update the file with the new staff member
    size++;
}
int isDataAlreadyPresent(const char *email, const char *name) {
    FILE *file = fopen("staff_updated.txt", "r");
    if (file == NULL) {
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char storedEmail[MAX_EMAIL_LENGTH];
        char storedName[MAX_NAME_LENGTH];
        sscanf(line, "Email: %s | Name: %[^\n]s | Stall Designation:", storedEmail, storedName);

        if (strcmp(email, storedEmail) == 0 || strcmp(name, storedName) == 0) {
            fclose(file);
            return 1; // Data already present
        }
    }

    fclose(file);
    return 0; // Data not present
}
void editStaff() {
    char editEmail[MAX_EMAIL_LENGTH];
    system("cls");
    gotoxy(55, 5);
    printf("    _     ___    __  __   ___   _  _");
    gotoxy(55, 6);
    printf("   /_\\   |   \\  |  \\/  | |_ _| | \\| |");
    gotoxy(55, 7);
    printf("  / _ \\  | |) | | |\\/| |  | |  | .` |");
    gotoxy(55, 8);
    printf(" /_/ \\_\\ |___/  |_|  |_| |___| |_\\_ |");
    gotoxy(35, 9);
    printf("  __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____");
    gotoxy(35, 10);
    printf(" |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|");
    gotoxy(35, 11);
    printf(" | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |");
    gotoxy(35, 12);
    printf(" |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_ \ \_|   |_|");
    gotoxy(50, 13);
    printf("  ___  __   __  ___   _____    ___   __  __");
    gotoxy(50, 14);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(50, 15);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(50, 16);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");
    gotoxy(50, 18);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(55, 20);
    printf("*** Enter staff details to Edit ***");
    gotoxy(50, 22);
    printf("Enter the email of the staff member to edit: ");
    scanf("%s", editEmail);

    int found = 0;
    FILE *file = fopen("staff_updated.txt", "r");
    if (file == NULL) {
        gotoxy(50, 22);
        printf("Error opening file.");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        gotoxy(50, 22);
        printf("Error opening temporary file.");
        fclose(file);
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        char email[MAX_EMAIL_LENGTH], name[MAX_NAME_LENGTH], stall[MAX_STALL_LENGTH];
        sscanf(line, "Email: %s | Name: %[^|] | Stall Designation: %[^\n]s\n", email, name, stall);

        if (strcmp(email, editEmail) == 0) {
            found = 1;
            gotoxy(50, 23);
            printf("Staff member with EMAIL %s found. Enter new details!", editEmail);
            gotoxy(50, 24);
            printf("Name of Staff: ");
            getchar(); // Clear the newline character from the previous input
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline
            gotoxy(50, 25);
            printf("Stall Designation: ");
            fgets(stall, MAX_STALL_LENGTH, stdin);
            stall[strcspn(stall, "\n")] = '\0'; // Remove the trailing newline

            fprintf(tempFile, "Email: %s | Name: %s | Stall Designation: %s\n", email, name, stall);
            gotoxy(50, 27);
            printf("\n\nStaff member with EMAIL %s edited successfully.\n", editEmail);
        } else {
            fprintf(tempFile, "Email: %s | Name: %s | Stall Designation: %s\n", email, name, stall);
        }
    }
    fclose(file);
    fclose(tempFile);

    remove("staff_updated.txt");
    rename("temp.txt", "staff_updated.txt");

    if (!found) {
        gotoxy(50, 23);
        printf("Staff member with EMAIL %s not found.\n", editEmail);
        gotoxy(50, 24);
    }
}
void deleteStaff() {
    char deleteEmail[MAX_EMAIL_LENGTH];
    system("cls");
    gotoxy(55, 5);
    printf("    _     ___    __  __   ___   _  _");
    gotoxy(55, 6);
    printf("   /_\\   |   \\  |  \\/  | |_ _| | \\| |");
    gotoxy(55, 7);
    printf("  / _ \\  | |) | | |\\/| |  | |  | .` |");
    gotoxy(55, 8);
    printf(" /_/ \\_\\ |___/  |_|  |_| |___| |_\\_ |");
    gotoxy(35, 9);
    printf("  __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____");
    gotoxy(35, 10);
    printf(" |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|");
    gotoxy(35, 11);
    printf(" | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |");
    gotoxy(35, 12);
    printf(" |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_ \ \_|   |_|");
    gotoxy(50, 13);
    printf("  ___  __   __  ___   _____    ___   __  __");
    gotoxy(50, 14);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(50, 15);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(50, 16);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");
    gotoxy(50, 18);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = ");
    gotoxy(48, 20);
    printf("*** Enter the email of the staff member to Delete***");
    gotoxy(50, 22);
    printf("Email: ");
    scanf("%s", deleteEmail);

    int found = 0;
    FILE *file = fopen("staff_updated.txt", "r");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        gotoxy(50, 23);
        printf("Error opening temporary file.");
        fclose(file);
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        char email[MAX_EMAIL_LENGTH], name[MAX_NAME_LENGTH], stall[MAX_STALL_LENGTH];
        sscanf(line, "Email: %s | Name: %[^|] | Stall Designation: %[^\n]", email, name, stall);

        if (strcmp(email, deleteEmail) == 0) {
            found = 1;
            gotoxy(50, 23);
            printf("Staff member with EMAIL %s deleted successfully.", deleteEmail);
            gotoxy(50, 24);
        } else {
            fprintf(tempFile, "Email: %s | Name: %s | Stall Designation: %s\n", email, name, stall);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("staff_updated.txt");
    rename("temp.txt", "staff_updated.txt");

    if (!found) {
        gotoxy(50, 24);
        printf("Staff member with EMAIL %s not found.", deleteEmail);
        gotoxy(50, 25);
    }
}

bool accessInventory() {
    system("cls");
    int choice;

        // Display menu options
        gotoxy(50, 5);
        printf("  ___ _  ___   _____ _  _ _____ ___  _____   __\n");
        gotoxy(50, 6);
        printf(" |_ _| \\| \\ \\ / / __| \\| |_   _/ _ \\| _ \\ \\ / /\n");
        gotoxy(50, 7);
        printf("  | || .` |\\ V /| _|| .` | | || (_) |   /\\ V / \n");
        gotoxy(50, 8);
        printf(" |___|_|\\_| \\_/ |___|_|\\_| |_| \\___/|_|_\\ |_|  \n");
        gotoxy(48, 10);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = \n");
        gotoxy(35, 11);
        printf("To make a selection, enter the corresponding number of the Stall you want to choose.\n");
        gotoxy(50, 12);
        printf("1. Frie Yay Products Inventory\n");
        gotoxy(50, 13);
        printf("2. Scoop on the Waffs Products Inventory\n");
        gotoxy(50, 14);
        printf("3. Sizzsilog House Inventory\n");
        gotoxy(50, 15);
        printf("4. Back");
        gotoxy(49, 16);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = =");
        gotoxy(50, 17);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute selected option
        switch (choice) {
        clearInputBuffer();
            do{
                case 1:
                    frie_yay_products_INVENTORY();
                    break;
                case 2:
                    scoop_on_the_waffs_products_INVENTORY();
                    break;
                case 3:
                    sizzsilog_house__INVENTORY();
                    break;
                case 4:
                    ADMIN_DOMAIN();
                    break;
                default:
                    break;
            } while (true);
        gotoxy(50, 18);
        printf("\nInvalid choice. Please try again.\n");
        system("pause");
        FLUSH;
        accessInventory();
        return (false);
        }
}
// Function to view inventory
void frie_yay_products_INVENTORY()
{
   system("cls");
    int inv,  addinventory;
    char code[10];
    system("cls");
    gotoxy(50, 5);
    printf("  ___ _  ___   _____ _  _ _____ ___  _____   __\n");
    gotoxy(50, 6);
    printf(" |_ _| \\| \\ \\ / / __| \\| |_   _/ _ \\| _ \\ \\ / /\n");
    gotoxy(50, 7);
    printf("  | || .` |\\ V /| _|| .` | | || (_) |   /\\ V / \n");
    gotoxy(50, 8);
    printf(" |___|_|\\_| \\_/ |___|_|\\_| |_| \\___/|_|_\\ |_|  \n");
    gotoxy(48, 10);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = \n");
    gotoxy(70, 11);
    printf("Frie Yay");
    gotoxy(48, 12);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\n\t\t\t\t\t\033[1;36mAVAILABE PRODUCTS\033[0m");
    printf("\n\t\t\t\t\t%s\t%-40s %-10s %-8s\n","Code", "Product Name", "Price", "Quantity");
    printf("\t\t\t\t\t-------------------------------------------------\n");

    for (int i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
        printf("\t\t\t\t\t%s\t%-40s %-10.2f %-8d\n",frie_yay_products[i].code, frie_yay_products[i].name, frie_yay_products[i].price, frie_yay_products[i].quantity);
    }
    printf("\t\t\t\t\t-------------------------------------------------\n");
    printf("\n\t\t\t\t\tClick 1 to Add Inventory");
    printf("\n\t\t\t\t\tClick 2 to Subtract Inventory");
    printf("\n\t\t\t\t\tClick 3 to Search Inventory");
    printf("\n\t\t\t\t\tClick 4 to Return  ");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d",&inv);
   do {
        if (inv == 1)
        {
            printf("\n\t\t\t\t\tChoose which product to add: ");
            scanf(" %s", code);

            // Convert the code to uppercase
            for (int i = 0; code[i]; i++)
                {
                    code[i] = toupper(code[i]);
                }

            int codeExists = 0; // Variable to track if the entered code exists

            for (int i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                if (strcmp(frie_yay_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    frie_yay_products[i].quantity += addinventory;
                    printf("\n\t\t\t\t\t");
                    system("pause");
                    break;

                }
            }
            if (!codeExists) {
                printf("\t\t\t\t\t\033[1;31mError: Code/Product name not found in the system. \033[0m\n");
                system("pause");
            }

            frie_yay_products_INVENTORY();
        }
        else if (inv == 2)
        {
            printf("\n\t\t\t\t\tChoose which product to subtract: ");
            scanf(" %s", code);

            for (int i = 0; code[i]; i++)
            {
                code[i] = toupper(code[i]);
            }

            int codeExists = 0;

            for (int i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                if (strcmp(frie_yay_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    if (frie_yay_products[i].quantity >= addinventory)
                    {
                        frie_yay_products[i].quantity -= addinventory;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\t\033[1;31mInsufficient quantity.\033[1;0m\n");
                        system("pause");
                    }
                     break;
                }
            }
            if (!codeExists)
            {
                printf("\t\t\t\t\t\033[1;31mError: Code/Product name not found in the system. \033[0m\n");
                system("pause");
            }

            frie_yay_products_INVENTORY();
        }
        else if (inv == 3)
        {
            printf("\n\t\t\t\t\tEnter the product code to search(Enter CODE all caps): ");
            scanf(" %s", code);
            if ((strcmp(frie_yay_products[i].code, code) == 0))
            for (int i = 0; code[i]; i++)
            {
                code[i] = toupper(code[i]);
            }
            bool found = false;
            for (int i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                if (strcmp(frie_yay_products[i].code, code) == 0) {
                    found = true;
                    printf("\t\t\t\t\tProduct Name: %s\n", frie_yay_products[i].name);
                    printf("\t\t\t\t\tPrice: %.2f\n", frie_yay_products[i].price);
                    printf("\t\t\t\t\tQuantity: %d\n", frie_yay_products[i].quantity);
                    break;
                }
            }
            if (!found) {
                printf("\n\t\t\t\t\t\033[1;31mInvalid product code.\033[1;0m\n");
            }
            system("pause");
            frie_yay_products_INVENTORY();
        }
        else if (inv == 4)
        {
            accessInventory();
        }
        else
        {
            break;
        }

    } while (inv != 5);
    printf("\nInvalid Input\n");
    system("pause");
    FLUSH;
    frie_yay_products_INVENTORY();
}
void scoop_on_the_waffs_products_INVENTORY()
{
   system("cls");
    int inv, addinventory;
    char code[10];
    system("cls");
    gotoxy(50, 5);
    printf("  ___ _  ___   _____ _  _ _____ ___  _____   __\n");
    gotoxy(50, 6);
    printf(" |_ _| \\| \\ \\ / / __| \\| |_   _/ _ \\| _ \\ \\ / /\n");
    gotoxy(50, 7);
    printf("  | || .` |\\ V /| _|| .` | | || (_) |   /\\ V / \n");
    gotoxy(50, 8);
    printf(" |___|_|\\_| \\_/ |___|_|\\_| |_| \\___/|_|_\\ |_|  \n");
    gotoxy(48, 10);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = \n");
    gotoxy(65, 11);
    printf("Scoop on the Waffs");
    gotoxy(48, 12);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\n\t\t\t\t\t\033[1;36mAVAILABE PRODUCTS\033[0m");
    printf("\n\t\t\t\t\t%s\t%-40s   %-10s  %-8s\n","Code", "Product Name", "Price", "Quantity");
    printf("\t\t\t\t\t-------------------------------------------------\n");

    for (int i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
        printf("\t\t\t\t%s\t%-40s           %-10.2f   %-8d\n",scoop_on_the_waffs_products[i].code, scoop_on_the_waffs_products[i].name, scoop_on_the_waffs_products[i].price, scoop_on_the_waffs_products[i].quantity);
    }

    printf("\t\t\t\t-------------------------------------------------\n");
    printf("\n\t\t\t\tClick 1 to Add Inventory");
    printf("\n\t\t\t\tClick 2 to Subtract Inventory");
    printf("\n\t\t\t\tClick 3 to Search Inventory");
    printf("\n\t\t\t\tClick 4 to Return  ");
    printf("\n\t\t\t\tEnter your choice: ");
    scanf("%d",&inv);

    do {
        if (inv == 1)
        {
            printf("\n\t\t\t\tChoose which product to add: ");
            scanf(" %s", code);

            // Convert the code to uppercase
            for (int i = 0; code[i]; i++)
                {
                    code[i] = toupper(code[i]);
                }

            int codeExists = 0; // Variable to track if the entered code exists

            for (int i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    scoop_on_the_waffs_products[i].quantity += addinventory;
                    system("pause");
                    break;

                }
            }

            if (!codeExists) {
                printf("\t\t\t\t\033[1;31mError: Code/Product name not found in the system.\033[0m\n");
                system("pause");
            }

            scoop_on_the_waffs_products_INVENTORY();
        }
        else if (inv == 2)
        {
            printf("\n\t\t\t\tChoose which product to subtract: ");
            scanf(" %s", code);
            for (int i = 0; code[i]; i++)
                {
                    code[i] = toupper(code[i]);
                }

            int codeExists = 0; // Variable to track if the entered code exists

            for (int i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    if (scoop_on_the_waffs_products[i].quantity >= addinventory)
                    {
                        scoop_on_the_waffs_products[i].quantity -= addinventory;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\033[1;31mInsufficient quantity.\033[1;0m\n");
                        system("pause");
                    }
                     break;
                }
            }

            if (!codeExists) {
                printf("\t\t\t\t\033[1;31mError: Code/Product name not found in the system. \033[0m\n");
                system("pause");
            }

            scoop_on_the_waffs_products_INVENTORY();
        }
        else if (inv == 3)
        {
             printf("\t\t\t\t\nEnter the product code to search(Enter CODE all caps): ");
            scanf(" %s", code);
            if ((strcmp(scoop_on_the_waffs_products[i].code, code) == 0))
            for (int i = 0; code[i]; i++)
            {
                code[i] = toupper(code[i]);
            }
            bool found = false;
            for (int i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                    found = true;
                    printf("\t\t\t\t\tProduct Name: %s\n", scoop_on_the_waffs_products[i].name);
                    printf("\t\t\t\t\tPrice: %.2f\n", scoop_on_the_waffs_products[i].price);
                    printf("\t\t\t\t\tQuantity: %d\n",scoop_on_the_waffs_products[i].quantity);
                    break;
                }
            }
            if (!found) {
                printf("\n\t\t\t\t\033[1;31mInvalid product code.\033[1;0m\n");
            }
            system("pause");
            scoop_on_the_waffs_products_INVENTORY();
        }
        else if (inv == 4)
        {
            accessInventory();
        }
        else
        {
            break;
        }
    } while (inv != 5);
    printf("\nInvalid Input\n");
    system("pause");
    FLUSH;
    scoop_on_the_waffs_products_INVENTORY();
}


void sizzsilog_house__INVENTORY()
{
   system("cls");
    int inv, addinventory;
    char code[10];
    system("cls");
    gotoxy(50, 5);
    printf("  ___ _  ___   _____ _  _ _____ ___  _____   __\n");
    gotoxy(50, 6);
    printf(" |_ _| \\| \\ \\ / / __| \\| |_   _/ _ \\| _ \\ \\ / /\n");
    gotoxy(50, 7);
    printf("  | || .` |\\ V /| _|| .` | | || (_) |   /\\ V / \n");
    gotoxy(50, 8);
    printf(" |___|_|\\_| \\_/ |___|_|\\_| |_| \\___/|_|_\\ |_|  \n");
    gotoxy(48, 10);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = \n");
    gotoxy(66, 11);
    printf("Sizzsilog House");
    gotoxy(48, 12);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\n\t\t\t\t\t\033[1;36mAVAILABE PRODUCTS\033[0m");
    printf("\n\t\t\t\t\t%s\t%-40s %-10s %-8s\n","Code", "Product Name", "Price", "Quantity");
    printf("\t\t\t\t\t-------------------------------------------------\n");
    for (int i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
        printf("\t\t\t\t\t%s\t%-40s %-10.2f %-8d\n",sizzsilog_house_products[i].code, sizzsilog_house_products[i].name, sizzsilog_house_products[i].price, sizzsilog_house_products[i].quantity);
    }

    printf("\t\t\t\t\t-------------------------------------------------\n");
    printf("\n\t\t\t\t\tClick 1 to Add Inventory");
    printf("\n\t\t\t\t\tClick 2 to Subtract Inventory");
    printf("\n\t\t\t\t\tClick 3 to Search Inventory");
    printf("\n\t\t\t\t\tClick 4 to Return  ");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d",&inv);
   do {
        if (inv == 1)
        {
            printf("\n\t\t\t\t\tChoose which product to add: ");
            scanf(" %s", code);

            // Convert the code to uppercase
            for (int i = 0; code[i]; i++)
                {
                    code[i] = toupper(code[i]);
                }

            int codeExists = 0; // Variable to track if the entered code exists

            for (int i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    sizzsilog_house_products[i].quantity += addinventory;
                    system("pause");
                    break;

                }
            }

            if (!codeExists) {
                printf("\t\t\t\t\t\033[1;31mError: Code/Product name not found in the system.\033[0m\n");
                system("pause");
            }

            sizzsilog_house__INVENTORY();
        }
        else if (inv == 2)
        {
            printf("\n\t\t\t\t\tChoose which product to subtract: ");
            scanf(" %s", code);

            for (int i = 0; code[i]; i++)
            {
                code[i] = toupper(code[i]);
            }

            int codeExists = 0;

            for (int i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                    codeExists = 1; // Set the flag to indicate that the code exists
                    printf("\t\t\t\t\tHow many products?: ");
                    scanf("%d", &addinventory);
                    if (sizzsilog_house_products[i].quantity >= addinventory)
                    {
                        sizzsilog_house_products[i].quantity -= addinventory;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\t\033[1;31mInsufficient quantity.\033[1;0m\n");
                        system("pause");
                    }
                     break;
                }
            }

            if (!codeExists) {
                printf("\t\t\t\t\t\033[1;31mError: Code/Product name not found in the system.\033[1;0m\n");
                system("pause");
            }

            sizzsilog_house__INVENTORY();
        }

        else if (inv == 3)
        {
            printf("\n\t\t\t\t\tEnter the product code to search(Enter CODE all caps): ");
            scanf(" %s", code);
            if ((strcmp(sizzsilog_house_products[i].code, code) == 0))
            for (int i = 0; code[i]; i++)
            {
                code[i] = toupper(code[i]);
            }
            bool found = false;
            for (int i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                    found = true;
                    printf("\n\t\t\t\t\tProduct Name: %s\n", sizzsilog_house_products[i].name);
                    printf("\t\t\t\t\tPrice: %.2f\n", sizzsilog_house_products[i].price);
                    printf("\t\t\t\t\tQuantity: %d\n", sizzsilog_house_products[i].quantity);
                    break;
                }
            }
            if (!found) {
                printf("\n\t\t\t\t\t033[1;31mInvalid product code.\033[1;0m\n");
            system("pause");
            sizzsilog_house__INVENTORY();
        }
        }

        else if (inv == 4)
        {
           accessInventory();
        }

        else
        {
            break;
        }

    } while (inv != 5);

    printf("\nInvalid Input\n");
    system("pause");
    FLUSH;
    sizzsilog_house__INVENTORY();
}
void SALES_REPORT()
{
    system("cls");
    float totalSales = 0.0;

    printf("\n\n");
    printf("\033[1;32m\t\t\t\t\t ,------.                       ,--.          ,--.    \033[0m\n");
    printf("\t\t\t\t\t |  .--. ' ,---.  ,---.  ,---.  `--'  ,---. ,-'  '-.  \n");
    printf("\t\t\t\t\t |  '--'.'|  .-.||  .--'|  .-.: ,--. | .-. |'-.  .-'  \n");
    printf("\t\t\t\t\t |  |\\  \\ \\   --.|   --.|  --.| |  | | '-' '  |  |    \n");
    printf("\t\t\t\t\t `--' '--' `----'  `---' `----' `--' |  |-'   `--'    \n");
    printf("\t\t\t\t\t                                     `--'             \n\n");
    printf("\t\t\t\t\t   ,-----.       ,--.,--.                ,--.  ,--. \n");
    printf("\t\t\t\t\t '  .--.| ,---. |  ||  | ,---.  ,---. ,-'  '-.`--' ,---. ,--,---,  \n");
    printf("\t\t\t\t\t |  |    | .-. ||  ||  ||  .-.||  .--''-.  .-',--.| .-. ||      | \n");
    printf("\t\t\t\t\t '  '--'|' '-' '|  ||  |\\   --.|  `--.  |  |  |  |' '-' '|  ||  | \n");
    printf("\t\t\t\t\t  `-----' `---' `--'`--' `----' `---'   `--'  `--' `---' `--''--' \n\n\033[0m");

    printf("\n\t\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = ");
    printf("\n\t\t\t\t\t                    SALES REPORT                   ");
    printf("\n\t\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = ");
    int receiptNumber = 1;
    char fileName[100];
    FILE *file;

    do {
        sprintf(fileName, "receipt_%d.txt", receiptNumber);
        file = fopen(fileName, "r");

        if (file == NULL) {
            break;
        }

        struct Receipt receipt;
        receipt.total = 0.0;

        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strncmp(line, " Total: ", 8) == 0) {
                // Extract the total amount from the line
                float amount;
                sscanf(line + 8, "%f", &amount);
                receipt.total = amount;
                totalSales += receipt.total;
                break;
            }
        }

        fclose(file);

        printf("\n\n\t\t\t\t\t\tReceipt %#d: %.2f", receiptNumber, receipt.total);

        receiptNumber++;
    } while (1);

    printf("\n\n\t\t\t\t\tTotal Sales: %.2f\n\n", totalSales);
    printf("\n\n\t\t\t\t\tPress any key to go back to the main menu...");
    getch();
}

void STAFF_DOMAIN()
{
    int choice;
    getMaxReceiptNumber();

        // Display staff menu option
        system("cls");
    gotoxy(50, 5);
    printf("   ___    ___   ___    ___   ___   ___   _  _    ___ ");
    gotoxy(50, 6);
    printf("  /   \\  | _ \\ |   \\  | __| | _ \\ |_ _| | \\| |  / __|  ");
    gotoxy(50, 7);
    printf(" |  () | |   / | |) | | _|  |   /  | |  | .` | | ( |   ");
    gotoxy(50, 8);
    printf("  \\___/  |_|_\\ |___/  |___| |_|_\\ |___| |_\\__|  \\___|  ");
    gotoxy(55, 9);
    printf("  ___  __   __  ___   _____   ___   __  __");
    gotoxy(55, 10);
    printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
    gotoxy(55, 11);
    printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
    gotoxy(55, 12);
    printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|");
        gotoxy(49, 13);
        printf("--------------------------------------------------------");
        gotoxy(49, 14);
        printf("||             >>>   STAFF DOMAIN   <<<               ||");
        gotoxy(49, 15);
        printf("||         [1]  CHOOSE A STALL                        ||");
        gotoxy(49, 16);
        printf("||         [2]  VIEW RECEIPTS                         ||");
        gotoxy(49, 17);
        printf("||         [3]  BACK                                  ||");
        gotoxy(49, 18);
        printf("--------------------------------------------------------");
        // Get staff input
        gotoxy(50, 20);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on staff choice

            switch (choice)
            {
                do {
                    case 1:
                        system("cls");
                        accessOrderingSystem();
                        break;
                    case 2:
                        View_Receipt();
                        break;
                    case 3:
                        LOG_IN();
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
            } while (choice != 5);
        }
    FLUSH;
    STAFF_DOMAIN();
}

bool accessOrderingSystem() {
    int choice;
    system("cls");

        // Display menu options
        gotoxy(45, 5);
        printf("  ___ _____ _   _    _    ___   ___ _  _   _____ _   _ ___ \n");
        gotoxy(45, 6);
        printf(" / __|_   _/_\\ | |  | |  / __| |_ _| \\| | |_   _| | | | _ \\\n");
        gotoxy(45, 7);
        printf(" \\__ \\ | |/ _ \\| |__| |__\\__ \\  | || .` |   | | | |_| |  _/\n");
        gotoxy(45, 8);
        printf(" |___/ |_/_/ \\_\\____|____|___/ |___|_|\\_|   |_|  \\___/|_|  \n");
        gotoxy(44, 10);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        gotoxy(44, 11);
        printf("1. Order Frie Yay Products\n");
        gotoxy(44, 12);
        printf("2. Order Scoop on the Waffs Products\n");
        gotoxy(44, 13);
        printf("3. Order Sizzsilog House Products\n");
        gotoxy(44, 14);
        printf("4. Exit\n");
        gotoxy(43, 15);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        gotoxy(45, 16);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute selected option
        switch (choice) {
             do {
                    case 1:
                        frie_yay_products_Order_System();
                        break;
                    case 2:
                        scoop_on_the_waffs_products_Order_System();
                        break;
                    case 3:
                        sizzsilog_house_products_Order_System();
                        break;
                    case 4:
                        STAFF_DOMAIN();
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        system("pause");
                        break;
            } while (true);

        FLUSH;
        accessOrderingSystem();
        return (false);
        }
}

void frie_yay_products_Order_System() {
    struct Receipt receipts[MAX_RECEIPTS];
    int receiptCount = 0;
    char code[10], ans,name[50];


    do {
        system("cls");
        gotoxy(51, 5);
        printf("   ___    ___   ___    ___   ___   ___   _  _    ___ ");
        gotoxy(51, 6);
        printf("  /   \\  | _ \\ |   \\  | __| | _ \\ |_ _| | \\| |  / __|  ");
        gotoxy(51, 7);
        printf(" |  () | |   / | |) | | _|  |   /  | |  | .` | | ( |   ");
        gotoxy(51, 8);
        printf("  \\___/  |_|_\\ |___/  |___| |_|_\\ |___| |_\\__|  \\___|  ");
        gotoxy(57, 9);
        printf("  ___  __   __  ___   _____   ___   __  __");
        gotoxy(57, 10);
        printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
        gotoxy(57, 11);
        printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
        gotoxy(57, 12);
        printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|\n");

        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\t\t\t\t                                        Frie Yay                                      ");
        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

        struct Receipt receipt;
        receipt.total = 0.0;
        receipt.itemCount = 0;

        int qty;
        float amt;
        for (int i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
           printf("\n\t\t\t\t  [%s] %-45s  Php %.2f\n", frie_yay_products[i].code, frie_yay_products[i].name, frie_yay_products[i].price);

        }
        printf("\n\t\t\t\t  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

        // Initialize receipt.items array
        for (i = 0; i < sizeof(receipt.items) / sizeof(receipt.items[0]); i++) {
            strcpy(receipt.items[i].name, "");
            receipt.items[i].price = 0.0;
            receipt.items[i].quantity = 0;
        }

        do {
            bool found = false; // Flag to indicate if the product was found

            printf("\n\n\t\t\t\t\t  Product Code or Search (S) or Back (B)\t: ");
            scanf("%s", code);

            if (strcasecmp(code, "S") == 0) {
                // Search for product

                printf("\n\t\t\t\t\t  Enter product code to search: ");
                scanf("%s", code);

                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                    if (strcmp(frie_yay_products[i].code, code) == 0) {
                        found = true;

                        // Display product details
                        printf("\n\t\t\t\t\t  Product: %s\t\tPhp %.2f\n", frie_yay_products[i].name, frie_yay_products[i].price);
                        break;
                    }
                }
                if (!found) {
                    printf("\n\t\t\t\t\t  Product not found!\n");
                }

            }
            else if (strcasecmp(code, "B") == 0){
                printf("\n\t\t\t\t\tReturning on Main Menu.\n");
                printf("\n\t\t\t\t\t");
                system("pause");
                return (0);
            }

            else {
                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                    if (strcmp(frie_yay_products[i].code, code) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    printf("\n\t\t\t\t\t  Invalid product code!\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");
                }
            }

            if (found) {
                printf("\n\t\t\t\t\t  Quantity\t: ");
                    if (scanf("%d", &qty) != 1 || qty <= 0) {
                    printf("\n\t\t\t\t\tInvalid input. Please enter a valid number.\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");
                    return 1; // Exit the program with an error code
                }
                for (i = 0; i < sizeof(frie_yay_products) / sizeof(frie_yay_products[0]); i++) {
                    if (strcmp(frie_yay_products[i].code, code) == 0) {
                        if (frie_yay_products[i].quantity >= qty) {
                            // Add item to receipt
                            strcpy(receipt.items[receipt.itemCount].name, frie_yay_products[i].name);
                            receipt.items[receipt.itemCount].price = frie_yay_products[i].price;
                            receipt.items[receipt.itemCount].quantity = qty;
                            receipt.total += frie_yay_products[i].price * qty;
                            receipt.itemCount++;
                            amt = qty * frie_yay_products[i].price;
                            printf("\n\t\t\t\t\t  Amount\t\t: %.2f\n", amt);
                            frie_yay_products[i].quantity -= qty;
                        } else {
                            printf("\n\t\t\t\t\t  Insufficient quantity. Please enter a lower quantity.\n");
                        }
                        break;
                    }
                }
            }
            printf("\n\n\t\t\t\t\t  Do you want to add more items? (y/n) ");
            scanf(" %c", &ans);
        } while (ans != 'n' && ans != 'N');

        if (receipt.itemCount > 0) {
            printf("\n\n\t\t\t\t\t  Press any key to generate receipt");
            getch();
            RECEIPT_GENERATOR(receipt, receiptCount + 1);
            receipts[receiptCount] = receipt;
            receiptCount++;
        } else {
            printf("\n\n\t\t\t\t\t  No items added to the receipt. Receipt not generated.\n");
        }

    } while (receiptCount < MAX_RECEIPTS);
            printf("\n\n\t\t\t\t\t  Maximum number of receipts reached. Exiting the system.\n");
            printf("\n\t\t\t\t\t");
            system("pause");
}

void scoop_on_the_waffs_products_Order_System() {

    struct Receipt receipts[MAX_RECEIPTS];
    int receiptCount = 0;
    char code[10], ans, name[50];


    do {
        system("cls");
        gotoxy(51, 5);
        printf("   ___    ___   ___    ___   ___   ___   _  _    ___ ");
        gotoxy(51, 6);
        printf("  /   \\  | _ \\ |   \\  | __| | _ \\ |_ _| | \\| |  / __|  ");
        gotoxy(51, 7);
        printf(" |  () | |   / | |) | | _|  |   /  | |  | .` | | ( |   ");
        gotoxy(51, 8);
        printf("  \\___/  |_|_\\ |___/  |___| |_|_\\ |___| |_\\__|  \\___|  ");
        gotoxy(57, 9);
        printf("  ___  __   __  ___   _____   ___   __  __");
        gotoxy(57, 10);
        printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
        gotoxy(57, 11);
        printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
        gotoxy(57, 12);
        printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|\n");

        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\t\t\t\t                                      Scoop on the Waffs                                      ");
        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

        struct Receipt receipt;
        receipt.total = 0.0;
        receipt.itemCount = 0;

        int qty;
        float amt;
        for (int i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
            printf("\n\t\t\t\t\t  [%s] %-45s  Php %.2f\n", scoop_on_the_waffs_products[i].code, scoop_on_the_waffs_products[i].name, scoop_on_the_waffs_products[i].price);

        }
        printf("\n\t\t\t\t  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");

        // Initialize receipt.items array
        for (i = 0; i < sizeof(receipt.items) / sizeof(receipt.items[0]); i++) {
            strcpy(receipt.items[i].name, "");
            receipt.items[i].price = 0.0;
            receipt.items[i].quantity = 0;
        }

        do {
            bool found = false; // Flag to indicate if the product was found
            printf("\n\n\t\t\t\t\t  Product Code or Search (S) or Back (B)\t: ");
            scanf("%s", code);

            if (strcasecmp(code, "S") == 0) {
                // Search for product

                printf("\n\t\t\t\t\t  Enter product code to search: ");
                scanf("%s", code);

                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                    if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                        found = true;

                        // Display product details
                        printf("\n\t\t\t\t\t  Product: %s\t\tPhp %.2f\n", scoop_on_the_waffs_products[i].name, scoop_on_the_waffs_products[i].price);
                        break;
                    }
                }
                if (!found) {
                    printf("\n\t\t\t\t\t  Product not found!\n");
                }

            }

            else if (strcasecmp(code, "B") == 0) {
                printf("\n\t\t\t\t\tReturning on Main Menu.\n");
                printf("\n\t\t\t\t\t");
                system("pause");
                return (0);
            }

            else {
                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                    if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    printf("\n\t\t\t\t\t  Invalid product code!\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");

                }
            }

            if (found) {
                printf("\n\t\t\t\t\t  Quantity\t: ");
                if (scanf("%d", &qty) != 1 || qty <= 0) {
                    printf("\n\t\t\t\t\tInvalid input. Please enter a valid number.\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");
                    return 1; // Exit the program with an error code
                }

                for (i = 0; i < sizeof(scoop_on_the_waffs_products) / sizeof(scoop_on_the_waffs_products[0]); i++) {
                    if (strcmp(scoop_on_the_waffs_products[i].code, code) == 0) {
                        if (scoop_on_the_waffs_products[i].quantity >= qty) {
                            // Add item to receipt
                            strcpy(receipt.items[receipt.itemCount].name, scoop_on_the_waffs_products[i].name);
                            receipt.items[receipt.itemCount].price = scoop_on_the_waffs_products[i].price;
                            receipt.items[receipt.itemCount].quantity = qty;
                            receipt.total += scoop_on_the_waffs_products[i].price * qty;
                            receipt.itemCount++;
                            amt = qty * scoop_on_the_waffs_products[i].price;
                            printf("\n\t\t\t\t\t  Amount\t\t: %.2f\n", amt);
                            scoop_on_the_waffs_products[i].quantity -= qty;
                        } else {
                            printf("\n\t\t\t\t\t  Insufficient quantity. Please enter a lower quantity.\n");
                        }
                        break;
                    }
                }
            }

            printf("\n\n\t\t\t\t\t  Do you want to add more items? (y/n) ");
            scanf(" %c", &ans);
        } while (ans != 'n' && ans != 'N');

        if (receipt.itemCount > 0) {
            printf("\n\n\t\t\t\t\t  Press any key to generate receipt");
            getch();
            RECEIPT_GENERATOR(receipt, receiptCount + 1);
            receipts[receiptCount] = receipt;
            receiptCount++;
        } else {
            printf("\n\t\t\t\t\t  No items added to the receipt. Receipt not generated.\n");
            printf("\n\t\t\t\t\t");
            system("pause");
            return 1;
        }

    } while (receiptCount < MAX_RECEIPTS);
            printf("\n\n\t\t\t\t\t  Maximum number of receipts reached. Exiting the system.\n");
            printf("\n\t\t\t\t\t");
            system("pause");
}

void sizzsilog_house_products_Order_System() {
    system("cls");
    struct Receipt receipts[MAX_RECEIPTS];
    int receiptCount = 0;
    char code[10], ans, name[50];


    do {
        system("cls");
        gotoxy(50, 5);
        printf("   ___    ___   ___    ___   ___   ___   _  _    ___ ");
        gotoxy(50, 6);
        printf("  /   \\  | _ \\ |   \\  | __| | _ \\ |_ _| | \\| |  / __|  ");
        gotoxy(50, 7);
        printf(" |  () | |   / | |) | | _|  |   /  | |  | .` | | ( |   ");
        gotoxy(50, 8);
        printf("  \\___/  |_|_\\ |___/  |___| |_|_\\ |___| |_\\__|  \\___|  ");
        gotoxy(56, 9);
        printf("  ___  __   __  ___   _____   ___   __  __");
        gotoxy(56, 10);
        printf(" / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
        gotoxy(56, 11);
        printf(" \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
        gotoxy(56, 12);
        printf(" |___/   |_|   |___/   |_|   |___| |_|  |_|\n");

        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\t\t\t\t                                         Sizzsilog House                                     ");
        printf("\n\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  \n");

        struct Receipt receipt;
        receipt.total = 0.0;
        receipt.itemCount = 0;

        int qty;
        float amt;
        for (int i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
            printf("\n\t\t\t\t\t  [%s] %-45s  Php %.2f\n", sizzsilog_house_products[i].code, sizzsilog_house_products[i].name, sizzsilog_house_products[i].price);

        }
        printf("\n\t\t\t\t  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

        // Initialize receipt.items array
        for (i = 0; i < sizeof(receipt.items) / sizeof(receipt.items[0]); i++) {
            strcpy(receipt.items[i].name, "");
            receipt.items[i].price = 0.0;
            receipt.items[i].quantity = 0;
        }

        do {
            bool found = false; // Flag to indicate if the product was found

            printf("\n\n\t\t\t\t\t  Product Code or Search (S) or Back (B)\t: ");
            scanf("%s", code);

            if (strcasecmp(code, "S") == 0) {
                // Search for product

                printf("\n\t\t\t\t\t  Enter product code to search: ");
                scanf("%s", code);

                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                    if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                        found = true;

                        // Display product details
                        printf("\n\t\t\t\t\t  Product: %s\t\tPhp %.2f\n", sizzsilog_house_products[i].name, sizzsilog_house_products[i].price);
                        break;
                    }
                }
                if (!found) {
                    printf("\n\t\t\t\t\t  Product not found!\n");
                }

            }

            else if (strcasecmp(code, "B") == 0) {
                printf("\n\t\t\t\t\tReturning on Main Menu.\n");
                printf("\n\t\t\t\t\t");
                system("pause");
                return (0);
            }

            else {
                // Convert code to uppercase for case-insensitive comparison
                for (i = 0; code[i]; i++) {
                    code[i] = toupper(code[i]);
                }

                for (i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                    if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    printf("\n\t\t\t\t\t  Invalid product code!\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");

                }
            }

            if (found) {
                printf("\n\t\t\t\t\t  Quantity\t: ");
                    if (scanf("%d", &qty) != 1 || qty <= 0) {
                    printf("\n\t\t\t\t\tInvalid input. Please enter a valid number.\n");
                    printf("\n\t\t\t\t\t");
                    system("pause");
                    return 1; // Exit the program with an error code
                }

                for (i = 0; i < sizeof(sizzsilog_house_products) / sizeof(sizzsilog_house_products[0]); i++) {
                    if (strcmp(sizzsilog_house_products[i].code, code) == 0) {
                        if (sizzsilog_house_products[i].quantity >= qty) {
                            // Add item to receipt
                            strcpy(receipt.items[receipt.itemCount].name, sizzsilog_house_products[i].name);
                            receipt.items[receipt.itemCount].price = sizzsilog_house_products[i].price;
                            receipt.items[receipt.itemCount].quantity = qty;
                            receipt.total += sizzsilog_house_products[i].price * qty;
                            receipt.itemCount++;
                            amt = qty * sizzsilog_house_products[i].price;
                            printf("\n\t\t\t\t\t  Amount\t\t: %.2f\n", amt);
                            sizzsilog_house_products[i].quantity -= qty;
                        } else {
                            printf("\n\t\t\t\t\t  Insufficient quantity. Please enter a lower quantity.\n");
                        }
                        break;
                    }
                }
            }

            printf("\n\n\t\t\t\t\t  Do you want to add more items? (y/n) ");
            scanf(" %c", &ans);
        } while (ans != 'n' && ans != 'N');

        if (receipt.itemCount > 0) {
            printf("\n\n\t\t\t\t\t  Press any key to generate receipt");
            getch();
            RECEIPT_GENERATOR(receipt, receiptCount + 1);
            receipts[receiptCount] = receipt;
            receiptCount++;
        } else {
            printf("\n\t\t\t\t\t  No items added to the receipt. Receipt not generated.\n");
            printf("\n\t\t\t\t\t");
            system("pause");
            return 1;
        }
    } while (receiptCount < MAX_RECEIPTS);
            printf("\n\n\t\t\t\t\t  Maximum number of receipts reached. Exiting the system.\n");
            printf("\n\t\t\t\t\t");
            system("pause");
}

int getMaxReceiptNumber() {
    int maxReceiptNumber = 0;
    FILE *file;

    for (int i = 1; i <= MAX_RECEIPTS; i++) {
        char fileName[100];
        sprintf(fileName, "receipt_%d.txt", i);
        file = fopen(fileName, "r");
        if (file != NULL) {
            maxReceiptNumber = i; // Update maxReceiptNumber if the file exists
            fclose(file);
        } else {
            break; // Exit the loop if the file doesn't exist
        }
    }

    return maxReceiptNumber;
}


void saveReceiptToFile(struct Receipt receipt, int maxReceiptNumber)
{
    char fileName[100];
    sprintf(fileName, "receipt_%d.txt", maxReceiptNumber + 1); // Generate unique file name

    FILE *file = fopen(fileName, "w"); // Open file in write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "------------------- RECEIPT -------------------\n");
    for (int i = 0; i < receipt.itemCount; i++) {
        fprintf(file, " Product: %s\n", receipt.items[i].name);
        fprintf(file, " Price: %.2f\n", receipt.items[i].price);
        fprintf(file, " Quantity: %d\n", receipt.items[i].quantity);
        fprintf(file, " Total: %.2f\n", receipt.items[i].price * receipt.items[i].quantity);
        fprintf(file, " ----------------------------------------------\n");
    }

    fprintf(file, " Cash: %.2f\n", receipt.cash);
    fprintf(file, " Grand Total: %.2f\n", receipt.total);
    fprintf(file, " Change: %.2f\n", receipt.change);
    fclose(file); // Close the file
}

void RECEIPT_GENERATOR(struct Receipt receipt, int receiptNumber) {
    int cash;
    int change;
    char customerType[10];

    system("cls");
    gotoxy(60, 5);
    printf("  ___ ___ ___ ___ ___ ___ _____ \n");
    gotoxy(60, 6);
    printf(" | _ \\ __/ __| __|_ _| _ \\_   _|\n");
    gotoxy(60, 7);
    printf(" |   / _| (__| _| | ||  _/ | |  \n");
    gotoxy(60, 8);
    printf(" |_|_\\___\\___|___|___|_|   |_|  \n");
    gotoxy(60, 9);
    printf("                                \n");
    printf("\t\t\t\t\t\t    ------------------- RECEIPT ------------------\n");

    for (int i = 0; i < receipt.itemCount; i++) {
        printf("\n\t\t\t\t\t Product: %s\n", receipt.items[i].name);
        printf("\n\t\t\t\t\t Price: %.2f\n", receipt.items[i].price);
        printf("\n\t\t\t\t\t Quantity: %d\n", receipt.items[i].quantity);
        printf("\n\t\t\t\t\t Total: %.2f\n", receipt.items[i].price * receipt.items[i].quantity);
        printf("\n\t\t\t\t\t\t    ------------------------------------------------\n");
    }

    printf("\n\n\t\t\t\t\tTotal: %.2f\n", receipt.total);

    printf("\n\n\t\t\t\t\tAre you a PWD (Person with Disabilities) or elderly? (y/n): ");
    scanf("%s", customerType);

    if (strcmp(customerType, "y") == 0 || strcmp(customerType, "Y") == 0)  {
        receipt.total *= 0.8;  // Apply 20% discount
        printf("\n\n\t\t\t\t\tDiscount Applied: 20%%\n");
    }

    do {
        printf("\n\t\t\t\t\t = = = = = = = = = = = = = = = = = = = = = = = = = \n");
        printf("\n\t\t\t\t\t TOTAL\t\t: %.2f\n", receipt.total);
        printf("\n\n\t\t\t\t\t Cash\t\t: ");
        scanf("%d", &cash);
        printf("\n");

        receipt.change = change;
        receipt.cash = cash;
        receipt.change = cash - receipt.total;

        if (receipt.change < 0) {
            printf("\n\t\t\t\t\tInsufficient cash. Please enter a higher amount.\n");
        } else if (receipt.change >= 0) {
            printf("\n\t\t\t\t\t Change\t\t: %.2f\n", receipt.change);
            printf("\n\t\t\t\t\t = = = = = = = = = = = = = = = = = = = = = = = = =  \n");
        }
    } while (receipt.change < 0);

    // Save receipt to file
    printf("\n\t\t\t\t\tThank you! Please Come Again\n");
    printf("\t\t\t\t\t");
    system("pause");
    int maxReceiptNumber = getMaxReceiptNumber(); // Get the maximum receipt number from the existing files
    saveReceiptToFile(receipt, maxReceiptNumber);
    return;
}


void View_Receipt() {
    int receiptNumber = 1;  // Start with the first receipt number
    char fileName[100];

    do {
        system("cls");
        gotoxy(53, 5);
        printf("  ___            _      _     _    _    _   \n");
        gotoxy(53, 6);
        printf(" | _ \\___ __ ___(_)_ __| |_  | |  (_)__| |_ \n");
        gotoxy(53, 7);
        printf(" |   / -_) _/ -_) | '_ \\  _| | |__| (_-<  _|\n");
        gotoxy(53, 8);
        printf(" |_|_\\___\\__\\___|_| .__/\\__| |____|_/__/\\__|\n");
        gotoxy(53, 9);
        printf("                  |_|\n");
        printf("\n\t\t\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = ");
        printf("\n\t\t\t\t\t\t                  RECEIPT COLLECTION                ");
        printf("\n\t\t\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = ");

        sprintf(fileName, "receipt_%d.txt", receiptNumber); // Generate the file name

        FILE *file = fopen(fileName, "r"); // Open the file in read mode

        if (file == NULL) {
            // No more receipts found, exit the loop
            break;
        }

        printf("\n");
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("\n\t\t\t\t\t\t%s", line);
        }
        printf("\n\t\t\t\t\t   = = = = = = = = = = = = = = = = = = = = = = = = = \n");
        fclose(file); // Close the file

        receiptNumber++;  // Move to the next receipt number

        // Delay for a short period before displaying the next receipt
        // You can adjust the delay time as needed
        printf("\t\t\t\t\t");
        system("pause");// Sleep for 1 second

    } while (1); // Infinite loop until a break statement is encountered

    printf("\n");
}
