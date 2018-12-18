#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**< Double linked list customer structure */
struct Customer
{
    char fname[255];
    char lname[255];
    char email[255];
    char username[255];
    char password[255];
    int points;
    struct Customer *next;
    struct Customer *prev;
}*start;

/**< Add customer from menu */
void addCustomer();
/**< Delete customer by username */
void deleteCustomer(char *username);
/**< Search customer by username*/
void searchCustomer(char *username);
/**< Check username-password pair for vaild */
char loginAsCustomer(char *username, char *password);
/**< Print info about all customers in console */
void viewAllCustomers();
/**< Edit customer's data functions*/
void editFirstName(char *username, char *newFirstName);
void editLastName(char *username, char *newLastName);
void editEmail(char *username, char *newEmail);
void editUsername(char *username, char *newUsername);
void editPassword(char *username, char *newPassword);
/**< Redeem reward for customer */
void redeemReward(char *username, int sum);
/**< Check customer's gifts */
void viewCustomerGifts(char *username);
/**< Load data from file */
void loadCustomers();
/**< Save data to file */
void saveCustomers();
/**< Menu printing function */
void printMenu(int kind);
/**< Print top 5 customers */
void printTopFive();

int main()
{
    /**< Variables declaration */
    char username[255], password[255], loginResult;
    int choice, subChoice, subSubChoice, purchaseAmount;
    start = NULL;
    /**< Load data */
    loadCustomers();
    /**< Welcome message */
    printf(" Welcome to customer loyalty program!\n");
    /**< Main menu loop */
    while(1)
    {
        /**< Variables initializing */
        subSubChoice = 0;
        subChoice = 0;
        printMenu(0);
        /**< Menu navigation */
        scanf("%d", &choice);
        switch (choice)
        {
            /**< Add customer choice */
        case 1:
            {
                addCustomer();
                break;
            }
            /**< Login as customer */
        case 2:
            {
                /**< Read username-data pair */
                printf("\n Enter username:\n");
                scanf("%s", username);
                printf(" Enter password:\n");
                scanf("%s", password);
                /**< Check for valid username-password pair */
                loginResult = loginAsCustomer(username, password);
                switch (loginResult)
                {
                    /**< Login successfully */
                case 's':
                    {
                        printf("Login successfully.\n");
                        /**< Admin menu navigation */
                        while (subChoice != 6 && subChoice != 3)
                        {
                            printMenu(1);
                            scanf("%d", &subChoice);
                            switch(subChoice)
                            {
                                /**< Edit username data choice */
                            case 1:
                                {
                                    printMenu(3);
                                    scanf("%d", &subSubChoice);
                                    switch (subSubChoice)
                                    {
                                        /**< Edit first name */
                                    case 1:
                                        {
                                            char fname[255];
                                            printf("\n Enter new first name:\n");
                                            scanf("%s", fname);
                                            editFirstName(username, fname);
                                            break;
                                        }
                                        /**< Edit last name */
                                    case 2:
                                        {
                                            char lname[255];
                                            printf("\n Enter new last name:\n");
                                            scanf("%s", lname);
                                            editLastName(username, lname);
                                            break;
                                        }
                                        /**< Edit e-mail */
                                    case 3:
                                        {
                                            char email[255];
                                            printf("\n Enter new e-mail:\n");
                                            scanf("%s", email);
                                            editEmail(username, email);
                                            break;
                                        }
                                        /**< Edit username */
                                    case 4:
                                        {
                                            char uname[255];
                                            printf("\n Enter new username:\n");
                                            scanf("%s", uname);
                                            editUsername(username, uname);
                                            strcpy(username, uname);
                                            break;
                                        }
                                        /**< Edit password */
                                    case 5:
                                        {
                                            char pword[255];
                                            printf("\n Enter new password:\n");
                                            scanf("%s", pword);
                                            editPassword(username, pword);
                                            break;
                                        }
                                        /**< Exit */
                                    case 6:
                                        {
                                            break;
                                        }
                                    default:
                                        {
                                            printf("\n Wrong choice.\n");
                                            break;
                                        }
                                    }
                                    break;
                                }
                                /**< Search customer choice */
                            case 2:
                                {
                                    searchCustomer(username);
                                    break;
                                }
                                /**< Delete customer choice */
                            case 3:
                                {
                                    deleteCustomer(username);
                                    break;
                                }
                                /**< Redeem reward choice */
                            case 4:
                                {
                                    printf("\n Enter purchase amount: ");
                                    scanf("%d", &purchaseAmount);
                                    redeemReward(username, purchaseAmount);
                                    break;
                                }
                                /**< View all available gifts choice */
                            case 5:
                                {
                                    viewCustomerGifts(username);
                                    break;
                                }
                                /**< Exit choice */
                            case 6:
                                {
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    /**< Wrong password switching */
                case 'w':
                    {
                        printf(" Wrong password.\n");
                        break;
                    }
                    /**< User not found switching */
                case 'n':
                    {
                        printf("User not found.\n");
                        break;
                    }
                }
                break;
            }
            /**< Login as administrator */
        case 3:
            {
                /**< Read password */
                printf("\n Enter password:\n");
                scanf("%s", password);
                /**< Check password */
                if (strcmp(password, "admin") == 0)
                {
                    /**< Admin menu navigation loop */
                    while (subChoice != 8)
                    {
                        /**< Print admin menu */
                        printMenu(2);
                        scanf("%d", &subChoice);
                        switch (subChoice)
                        {
                            /**< Add customer to list choice */
                        case 1:
                            {
                                addCustomer();
                                break;
                            }
                            /**< Edit customer choice */
                        case 2:
                            {
                                printf("\n Enter customer's username:\n");
                                scanf("%s", username);
                                printMenu(3);
                                scanf("%d", &subSubChoice);
                                switch (subSubChoice)
                                {
                                    /**< Edit first name */
                                case 1:
                                    {
                                        char fname[255];
                                        printf("\n Enter new first name:\n");
                                        scanf("%s", fname);
                                        editFirstName(username, fname);
                                        break;
                                    }
                                    /**< Edit last name */
                                case 2:
                                    {
                                        char lname[255];
                                        printf("\n Enter new last name:\n");
                                        scanf("%s", lname);
                                        editLastName(username, lname);
                                        break;
                                    }
                                    /**< Edit e-mail */
                                case 3:
                                    {
                                        char email[255];
                                        printf("\n Enter new e-mail:\n");
                                        scanf("%s", email);
                                        editEmail(username, email);
                                        break;
                                    }
                                    /**< Edit username */
                                case 4:
                                    {
                                        char uname[255];
                                        printf("\n Enter new username:\n");
                                        scanf("%s", uname);
                                        editUsername(username, uname);
                                        break;
                                    }
                                    /**< Edit password */
                                case 5:
                                    {
                                        char pword[255];
                                        printf("\n Enter new password:\n");
                                        scanf("%s", pword);
                                        editPassword(username, pword);
                                        break;
                                    }
                                    /**< Exit */
                                case 6:
                                    {
                                        break;
                                    }
                                default:
                                    {
                                        printf("Wrong choice.\n");
                                        break;
                                    }
                                }
                                break;
                            }
                            /**< Delete customer from list choice */
                        case 3:
                            {
                                printf("\n Enter username that you want to delete:\n");
                                scanf("%s", username);
                                deleteCustomer(username);
                                break;
                            }
                            /**< Search customer in list choice */
                        case 4:
                            {
                                printf("\n Enter customer's username:\n");
                                scanf("%s", username);
                                searchCustomer(username);
                                break;
                            }
                            /**< View all customers choice */
                        case 5:
                            {
                                viewAllCustomers();
                                break;
                            }
                            /**< Redeem reward choice */
                        case 6:
                            {
                                printf("\n Enter customer's username:\n");
                                scanf("%s", username);
                                printf(" Enter purchase amount: ");
                                scanf("%d", &purchaseAmount);
                                redeemReward(username, purchaseAmount);
                                break;
                            }
                            /**< View all available gifts choice */
                        case 7:
                            {
                                printMenu(4);
                                break;
                            }
                            /**< Print top 5 customers choice */
                        case 8:
                            {
                                printTopFive();
                                break;
                            }
                            /**< Exit choice */
                        case 9:
                            {
                                break;
                            }
                        }
                    }
                }
                /**< Wrong password switching */
                else
                {
                    printf(" Wrong password.\n");
                }
                break;
            }
            /**< Exit choice */
        case 4:
            {
                printf("\n Goodbye!");
                saveCustomers();
                return 0;
                break;
            }
            /**< Error input case */
        default:
            {
                printf(" Wrong input. Try Again.\n");
                break;
            }
        }
    }
    return 0;
}

void addCustomer()
{
    char fname[255], lname[255], email[255], username[255], password[255];
    /**< Read customer's data */
    printf("\n Enter customer's first name:\n");
    scanf("%s", fname);
    printf(" Enter customer's last name:\n");
    scanf("%s", lname);
    printf(" Enter customer's e-mail:\n");
    scanf("%s", email);
    printf(" Enter customer's username:\n");
    scanf("%s", username);
    printf(" Enter customer's password:\n");
    scanf("%s", password);
    /**< Set new customer */
    struct Customer *s, *temp;
    temp = (struct Customer *) malloc(sizeof(struct Customer));
    strcpy(temp->fname, fname);
    strcpy(temp->lname, lname);
    strcpy(temp->email, email);
    strcpy(temp->username, username);
    strcpy(temp->password, password);
    temp->points = 0;
    temp->next = NULL;
    /**< Adding customers to list */
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void deleteCustomer(char *username)
{
    /**< Delete customer from list */
    struct Customer *s, *temp;
    /**< If customer first in the list */
    if (strcmp(start->username, username) == 0)
    {
        if (start->next != NULL)
        {
            temp = start;
            start = start->next;
            start->prev = NULL;
            free(temp);
            return;
        }
        else
        {
            start = NULL;
            return;
        }
    }
    s = start;
    /**< If customer not first and not last in the list */
    while(s->next->next != NULL)
    {
        if (strcmp(s->next->username, username) == 0)
        {
            temp = s->next;
            s->next = temp->next;
            temp->next->prev = s;
            free(temp);
            return;
        }
        s = s->next;
    }
    /**< If customer last in the list */
    if (strcmp(s->next->username, username) == 0)
    {
        temp = s->next;
        free(temp);
        s->next = NULL;
        return;
    }
}

void searchCustomer(char *username)
{
    struct Customer *s;
    s = start;
    /**< Searching loop */
    while (s != NULL)
    {
        /**< If customer was found print info */
        if (strcmp(s->username, username) == 0)
        {
            printf("\n %s was found.\n", username);
            printf(" First name - %s.\n", s->fname);
            printf(" Last name - %s.\n", s->lname);
            printf(" E-mail - %s.\n", s->email);
            printf(" Password - %s.\n", s->password);
            printf(" Loyalty program points - %d.\n", s->points);
            return;
        }
        s = s->next;
    }
    printf("\n Customer not found.\n");
}

char loginAsCustomer(char *username, char *password)
{
    struct Customer *s;
    s = start;
    /**< Searching customer with inputted data */
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            if (strcmp(s->password, password) == 0)
            {
                return 's';
            }
            else
            {
                /**< Wrong password */
                return 'w';
            }
        }
        s = s->next;
    }
    /**< User not found */
    return 'n';
}

void viewAllCustomers()
{
    struct Customer *s;
    s = start;
    /**< Loop for printing all customers info */
    while (s != NULL)
    {
        printf(" %s customer:\n", s->username);
        printf(" First name - %s.\n", s->fname);
        printf(" Last name - %s.\n", s->lname);
        printf(" E-mail - %s.\n", s->email);
        printf(" Password - %s.\n", s->password);
        printf(" Loyalty program points - %d.\n\n", s->points);
        s = s->next;
    }
}

void printTopFive()
{
    /**< Variables that containing data of top customers */
    int topPoints1 = -1, topPoints2 = -1, topPoints3 = -1, topPoints4 = -1, topPoints5 = -1;
    char topUsername1[255], topUsername2[255], topUsername3[255], topUsername4[255], topUsername5[255];
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        /**< Check if customer should be in top */
        if (s->points > topPoints1)
        {
            strcpy(topUsername5, topUsername4);
            topPoints5 = topPoints4;
            strcpy(topUsername4, topUsername3);
            topPoints4 = topPoints3;
            strcpy(topUsername3, topUsername2);
            topPoints3 = topPoints2;
            strcpy(topUsername2, topUsername1);
            topPoints2 = topPoints1;
            strcpy(topUsername1, s->username);
            topPoints1 = s->points;
        }
        else
            if (s->points > topPoints2)
            {
                strcpy(topUsername5, topUsername4);
                topPoints5 = topPoints4;
                strcpy(topUsername4, topUsername3);
                topPoints4 = topPoints3;
                strcpy(topUsername3, topUsername2);
                topPoints3 = topPoints2;
                strcpy(topUsername2, s->username);
                topPoints2 = s->points;
            }
            else
                if (s->points > topPoints3)
                {
                    strcpy(topUsername5, topUsername4);
                    topPoints5 = topPoints4;
                    strcpy(topUsername4, topUsername3);
                    topPoints4 = topPoints3;
                    strcpy(topUsername3, s->username);
                    topPoints3 = s->points;
                }
                else
                {
                    if (s->points > topPoints4)
                    {
                        strcpy(topUsername5, topUsername4);
                        topPoints5 = topPoints4;
                        strcpy(topUsername4, s->username);
                        topPoints4 = s->points;
                    }
                    else
                    {
                        if (s->points > topPoints5)
                        {
                            strcpy(topUsername5, s->username);
                            topPoints5 = s->points;
                        }
                    }
                }
        s = s->next;
    }
    /**< Printing top */
    if (topPoints1 >= 0)
        printf("\n Top 1. %s. %d points.\n", topUsername1, topPoints1);
    if (topPoints2 >= 0)
        printf(" Top 2. %s. %d points.\n", topUsername2, topPoints2);
    if (topPoints3 >= 0)
        printf(" Top 3. %s. %d points.\n", topUsername3, topPoints3);
    if (topPoints4 >= 0)
        printf(" Top 4. %s. %d points.\n", topUsername4, topPoints4);
    if (topPoints5 >= 0)
        printf(" Top 5. %s. %d points.\n\n", topUsername5, topPoints5);
}

/**< Data edit functions */

void editFirstName(char *username, char *newFirstName)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            strcpy(s->fname, newFirstName);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void editLastName(char *username, char *newLastName)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            strcpy(s->lname, newLastName);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void editEmail(char *username, char *newEmail)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            strcpy(s->email, newEmail);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void editUsername(char *username, char *newUsername)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            strcpy(s->username, newUsername);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void editPassword(char *username, char *newPassword)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        if (strcmp(s->username, username) == 0)
        {
            strcpy(s->password, newPassword);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

/**< Redeem reward */
void redeemReward(char *username, int sum)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        /**< If customer with inputted username was found set him bonus points */
        if (strcmp(s->username, username) == 0)
        {
            if (sum < 50) s->points += 10;
            if (sum >= 50 && sum < 100) s->points += 20;
            if (sum >= 100 && sum < 300) s->points += 40;
            if (sum >= 300 && sum < 600) s->points += 70;
            if (sum >= 600 && sum < 1000) s->points += 100;
            if (sum >= 1000) s->points += 150;
            printf(" Now you have %d points. Do not forget to see your gifts list.\n", s->points);
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void viewCustomerGifts(char *username)
{
    struct Customer *s;
    s = start;
    while (s != NULL)
    {
        /**< If user with inputted username was found print gift for customer */
        if (strcmp(s->username, username) == 0)
        {
            if (s->points < 20)
                printf("\n No gifts.\n");
            if (s->points >= 20 && s->points <= 40)
                printf("\n One Free Ride by Uber Coupon (2017APU1).\n");
            if (s->points >= 41 && s->points <= 70)
                printf("\n RM20 Digi credit card mobile (5114485).\n");
            if (s->points >= 71 && s->points <= 100)
                printf("\n Free lunch at APU cafe (Bring your ID card).\n");
            if (s->points >= 101 && s->points <= 150)
                printf("\n Free trip to Genting highlands. Contact with Mrs.Mary thing to know the procedures.\n");
            if (s->points >= 151)
                printf("\n Free ticket in Air Asia airline. Contact with Mrs.Mary thing to know the procedures.\n");
            return;
        }
        s = s->next;
    }
    printf(" Customer not found.\n");
}

void loadCustomers()
{
    /**< Open file for reading */
    char fname[255], lname[255], email[255], username[255], password[255];
    int points;
    FILE *fin;
    fin = fopen("customers.txt", "r");
    if (fin == NULL)
        return;
        /**< Reading data */
    while (fscanf(fin, "First name: %s\n", fname) != EOF) {
        fscanf(fin, "Last name: %s\nE-mail: %s\nUsername: %s\nPassword: %s\nPoints: %d\n", lname, email, username, password, &points);
        /**< This function is similar to creating a new customer */
        struct Customer *s, *temp;
        temp = (struct Customer *) malloc(sizeof(struct Customer));
        strcpy(temp->fname, fname);
        strcpy(temp->lname, lname);
        strcpy(temp->email, email);
        strcpy(temp->username, username);
        strcpy(temp->password, password);
        temp->points = points;
        temp->next = NULL;
        if (start == NULL)
        {
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            s = start;
            while (s->next != NULL)
                s = s->next;
            s->next = temp;
            temp->prev = s;
        }
    }
    /**< Close input stream */
    fclose(fin);
}

void saveCustomers()
{
    /**< Open file for save data */
    FILE *fout;
    fout = fopen("customers.txt", "w");
    struct Customer *s;
    s = start;
    if (fout == NULL)
        return;
        /**< If file was opened normally */
    while (s != NULL)
    {
        /**< Save customers */
        fprintf(fout, "First name: %s\nLast name: %s\nE-mail: %s\nUsername: %s\nPassword: %s\nPoints: %d\n", s->fname, s->lname, s->email, s->username, s->password, s->points);
        s = s->next;
    }
    fclose(fout);
}

/**< Menus printing functions */
void printMenu(int kind)
{
    switch (kind)
    {
        /**< Main menu*/
    case 0:
        {
            printf("   ______________________________\n");
            printf("  |                              | \n");
            printf("  |   1. Add new customer        | \n");
            printf("  |   2. Login as customer       | \n");
            printf("  |   3. Login as admin          | \n");
            printf("  |   4. Exit                    | \n");
            printf("  |                              | \n");
            printf("  |   Enter your choice (1-4)    | \n");
            printf("  |______________________________| \n\n ");
            break;
        }
        /**< Customer's menu */
    case 1:
        {
            printf("   ______________________________\n");
            printf("  |                              | \n");
            printf("  |   1. Edit my details         | \n");
            printf("  |   2. View my details         | \n");
            printf("  |   3. Delete my account       | \n");
            printf("  |   4. Redeem reward           | \n");
            printf("  |   5. View my gifts           | \n");
            printf("  |   6. Sign out                | \n");
            printf("  |                              | \n");
            printf("  |   Enter your choice (1-6)    | \n");
            printf("  |______________________________| \n\n ");
            break;
        }
        /**< Admin's menu */
    case 2:
        {
            printf("   ______________________________\n");
            printf("  |                              | \n");
            printf("  |   1. Create new account      | \n");
            printf("  |   2. Edit account            | \n");
            printf("  |   3. Delete account          | \n");
            printf("  |   4. Search for a customer   | \n");
            printf("  |   5. View all customers      | \n");
            printf("  |   6. Redeem reward           | \n");
            printf("  |   7. View all gifts          | \n");
            printf("  |   8. View top 5 customers    | \n");
            printf("  |   9. Sign out                | \n");
            printf("  |                              | \n");
            printf("  |   Enter your choice (1-9)    | \n");
            printf("  |______________________________| \n\n ");
            break;
        }
        /**< Edit data menu */
    case 3:
        {
            printf("\n 1. Edit first name.\n");
            printf(" 2. Edit last name.\n");
            printf(" 3. Edit e-mail.\n");
            printf(" 4. Edit username.\n");
            printf(" 5. Edit password.\n");
            printf(" 6. Cancel.\n");
            printf(" Enter your choice (1-6):\n\n ");
            break;
        }
        /**< Gifts menu */
    case 4:
        {
            printf("\n 20 - 40 points: One Free Ride by Uber Coupon (2017APU1).\n");
            printf(" 41 - 70 points: RM20 Digi credit card mobile (5114485).\n");
            printf(" 71 - 100 points: Free lunch at APU cafe (Bring your ID card).\n");
            printf(" 101 - 150 points: Free trip to Genting highlands. Contact with Mrs.Mary thing to know the procedures.\n");
            printf(" 151+ points: Free ticket in Air Asia airline. Contact with Mrs.Mary thing to know the procedures.\n");
            break;
        }
    }
}
