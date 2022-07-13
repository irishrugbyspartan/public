#include <iostream>
using namespace std;

// Variable Declarations
const int rows = 8;
const int columns = 10;
const int array_min = 0;
const int ATM = 6;
const int ATE = 8;
const int CTM = 4;
const int CTE = 6;
char letter;
char user_choice;
char ticket_type;
char seating_chart1[rows][columns] = {{'0', '1', '2', '3', '4', '5', '6','7', '8'},{'1', '*', '*', '*', '*', '*', '*', '*', '*'},{'2', '*', '*', '*', '*', '*', '*', '*', '*'},{'3', '*', '*', '*', '*', '*', '*', '*', '*'},{'4', '*', '*', '*', '*', '*', '*', '*', '*'},{'5', '*', '*', '*', '*', '*', '*', '*', '*'},{'6', '*', '*', '*', '*', '*', '*', '*', '*'},{'7', '*', '*', '*', '*', '*', '*', '*', '*'}};
char seating_chart2[rows][columns] = {{'0', '1', '2', '3', '4', '5', '6', '7', '8'},{'1', '*', '*', '*', '*', '*', '*', '*', '*'},{'2', '*', '*', '*', '*', '*', '*', '*', '*'},{'3', '*', '*', '*', '*', '*', '*', '*', '*'},{'4', '*', '*', '*', '*', '*', '*', '*', '*'},{'5', '*', '*', '*', '*', '*', '*', '*', '*'},{'6', '*', '*', '*', '*', '*', '*', '*', '*'},{'7', '*', '*', '*', '*', '*', '*', '*', '*'}};
char seating_chart3[rows][columns] = {{'0', '1', '2', '3', '4', '5', '6', '7', '8'},{'1', '*', '*', '*', '*', '*', '*', '*', '*'},{'2', '*', '*', '*', '*', '*', '*', '*', '*'},{'3', '*', '*', '*', '*', '*', '*', '*', '*'},{'4', '*', '*', '*', '*', '*', '*', '*', '*'},{'5', '*', '*', '*', '*', '*', '*', '*', '*'},{'6', '*', '*', '*', '*', '*', '*', '*', '*'},{'7', '*', '*', '*', '*', '*', '*', '*', '*'}};
char seating_chart4[rows][columns] = {{'0', '1', '2', '3', '4', '5', '6', '7', '8'},{'1', '*', '*', '*', '*', '*', '*', '*', '*'},{'2', '*', '*', '*', '*', '*', '*', '*', '*'},{'3', '*', '*', '*', '*', '*', '*', '*', '*'},{'4', '*', '*', '*', '*', '*', '*', '*', '*'},{'5', '*', '*', '*', '*', '*', '*', '*', '*'},{'6', '*', '*', '*', '*', '*', '*', '*', '*'},{'7', '*', '*', '*', '*', '*', '*', '*', '*'}};
int user_number, lowest, highest;
int user_input = 0;
int row, column;
int menu_choice = 0;
int submenu1_choice, submenu2_choice;
int admin_input;
int adult_tickets, child_tickets, total_tickets;
double adult_ticket_sales, child_ticket_sales, total_ticket_sales = 0;

// Function Declarations
void theaterBanner();
void displayMenu();
void selectSeatingChart(int);
int selectShowing(int&);
void displaySeatingChart(const char array[rows][columns]);
void ticketPurchasePrompt(int&);
void purchaseTickets1(char, char array[rows][columns],int&, int&, int&, double&, double&, double&);
void purchaseTickets2(char, char array[rows][columns],int&, int&, int&, double&, double&, double&);
void purchaseTickets3(char, char array[rows][columns],int&, int&, int&, double&, double&, double&);
void purchaseTickets4(char, char array[rows][columns],int&, int&, int&, double&, double&, double&);
int inputValidate(int&, int, int);
char inputValidateYesOrNo(char);
char inputValidateAOrC(char);
void displayAdminMenu();
void adminAdultTicketsSold(int&);
void adminChildTicketsSold(int&);
void adminTotalTicketsSold(int&);
void adminAdultTicketProfits(double&);
void adminChildTicketProfits(double&);
void adminTotalTicketProfits(double&);
int adminShutdown(int&, int&);
void updateSeatingChart1(char array[rows][columns], int, int, int);
void updateSeatingChart2(char array[rows][columns], int, int, int);
void updateSeatingChart3(char array[rows][columns], int, int, int);
void updateSeatingChart4(char array[rows][columns], int, int, int);

// Program Main
int main()
{
    do
    {
        theaterBanner();
        displayMenu();

        cout << "Please make your selection now: " << endl;
        while (!(cin >> menu_choice) || !(menu_choice == 1 || menu_choice == 2 || menu_choice == -99))
        {
            cin.clear();
            cin.ignore();
            cout << "Error: Enter a 1 or a 2 to make your selection." << endl;
        }

        if (menu_choice == 1)
        {
            selectSeatingChart(user_input);
        }
        else if (menu_choice == 2)
        {
            selectShowing(user_input);
            ticketPurchasePrompt(user_input);
        }
        else if (menu_choice == -99)
        {
           do
           {
           displayAdminMenu();
           cin >> admin_input;
            switch (admin_input){
                case 1:
                    adminAdultTicketsSold(adult_tickets);
                    break;
                case 2:
                    adminChildTicketsSold(child_tickets);
                    break;
                case 3:
                    adminTotalTicketsSold(total_tickets);
                    break;
                case 4:
                    adminAdultTicketProfits(adult_ticket_sales);
                    break;
                case 5:
                    adminChildTicketProfits(child_ticket_sales);
                    break;
                case 6:
                    adminTotalTicketProfits(total_ticket_sales);
                    break;
                case 7:
                    break;
                case 8:
                    adminShutdown(menu_choice, admin_input);
                    break;
                default:
                    cout << "Invalid input! Please make a selection using the numbers 1-8." << endl;
                }
            } while (admin_input != 7);           
        }
        else
            cout << "Invalid input! Please make a selection using the numbers 1 and 2." << endl;
    } while (menu_choice != 8);
    cout << "Have a good evening! Goodbye!" << endl;
    return 0;
}

// Functions
void theaterBanner()
{
    cout << "********************************************************" << endl;
    cout << "*           Welcome to the CIS Monaco Theater!         *" << endl;
    cout << "********************************************************" << endl;
    cout << "* Today's Shows and Showtimes:                         *" << endl;
    cout << "* Free Birds          3:30     6:00                    *" << endl;
    cout << "* Bethooven           5:30     7:30                    *" << endl;
    cout << "********************************************************" << endl;
    cout << "* Ticket Prices                                        *" << endl;
    cout << "*                  Matinee Showing     Evening Showing *" << endl;
    cout << "* Adult Tickets         $6.00               $8.00      *" << endl;
    cout << "* Child Tickets         $4.00               $6.00      *" << endl;
    cout << "********************************************************" << endl;
}

void displayMenu()
{
    cout << "\nChoose from menu: " << endl
         << "1. See Available Seats" << endl
         << "2. Purchase Tickets" << endl
         << endl;
}

void selectSeatingChart(int user_input)
{
    cout << "Which show would you like to see the available seats for?" << endl;
    cout << "1. Free Birds  @  3:30" << endl;
    cout << "2. Free Birds  @  6:00" << endl;
    cout << "3. Bethooven   @  5:30" << endl;
    cout << "4. Bethooven   @  7:30" << endl;
    inputValidate(user_input, 1, 4);
    if (user_input == 1)
    {
        displaySeatingChart(seating_chart1);
    }
    else if (user_input == 2)
    {
        displaySeatingChart(seating_chart2);
    }
    else if (user_input == 3)
    {
        displaySeatingChart(seating_chart3);
    }
    else if (user_input == 4)
    {
        displaySeatingChart(seating_chart4);
    }
}

void displaySeatingChart(const char array[rows][columns])
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cout << array[row][column];
        }
        cout << endl;
    } 
}

int selectShowing(int& user_input)
{
    cin.clear();
    cin.ignore();
    cout << "Which show would you like to see the available seats for?" << endl;
    cout << "1. Free Birds @ 3:30" << endl;
    cout << "2. Free Birds @ 6:00" << endl;
    cout << "3. Bethooven  @ 5:30" << endl;
    cout << "4. Bethooven  @ 7:00" << endl;
    inputValidate(user_input, 1, 4);
    return user_input;
}

void ticketPurchasePrompt(int& user_input)
{
    if (user_input == 1)
    {
        purchaseTickets1(user_choice, seating_chart1, adult_tickets, child_tickets, total_tickets, adult_ticket_sales, child_ticket_sales, total_ticket_sales);
    }
    else if (user_input == 2)
    {
        purchaseTickets2(user_choice, seating_chart2, adult_tickets, child_tickets, total_tickets, adult_ticket_sales, child_ticket_sales, total_ticket_sales);
    }
    else if (user_input == 3)
    {
        purchaseTickets3(user_choice, seating_chart3, adult_tickets, child_tickets, total_tickets, adult_ticket_sales, child_ticket_sales, total_ticket_sales);
    }
    else if (user_input == 4)
    {
        purchaseTickets4(user_choice, seating_chart4, adult_tickets, child_tickets, total_tickets, adult_ticket_sales, child_ticket_sales, total_ticket_sales);
    }
    else
    {
        cout << "Invalid showing selected! Please select a show and time using 1, 2, 3, or 4." << endl;
        cin >> submenu2_choice;
    }
}

void purchaseTickets1(char user_choice,char seating_chart1[rows][columns], int& adult_tickets,  int& child_tickets, int& total_tickets, double& adult_ticket_sales, double& child_ticket_sales, double& total_ticket_sales)
{
    double this_sale;
    int next_seat;
    next_seat = 1;

    do
    {
    displaySeatingChart(seating_chart1);
    cout << "Seating chart: " << endl
    << "Taken = #/X | Available = *" << endl;
    cout << "Choose a seat: " << endl;
    cout << "Enter row #: ";
    int row_number = inputValidate(row_number, 1, 7);

    cout << "Enter seat #: ";
    int seat_number = inputValidate(seat_number, 1, 8);

        if (seating_chart1[row_number][seat_number] == '*')
        {
            cout << "That seat is available." << endl << endl;
            cout << "Would you like to purchase Row #" << row_number << " Seat #" << seat_number << "? ";
            user_choice = inputValidateYesOrNo(user_choice);

            if (user_choice == 'Y' || user_choice == 'y')
            {
                cout << "Is this ticket for an adult ticket or for a child ticket?" << endl;
                cout << "Please enter A for an adult ticket or C for a child ticket." << endl;
                ticket_type = inputValidateAOrC(ticket_type);


                if (ticket_type == 'A' || ticket_type == 'a')
                {
                    adult_tickets ++;
                    adult_ticket_sales += ATM;
                    this_sale += ATM;
                    total_tickets ++;
                    total_ticket_sales += ATM;
                }

                else if (ticket_type == 'C' || ticket_type == 'c')
                {
                    child_tickets ++;
                    child_ticket_sales += CTM;
                    this_sale += CTM;
                    total_tickets ++;
                    total_ticket_sales += CTM;
                }

                seating_chart1[row_number][seat_number] = '#';
                cin.clear();
                cin.ignore();
                cout << "Total charges = $" << this_sale << endl;
                cout << "Would you like to purchase another seat?" << endl;
                cout << "Enter 1 to select another seat or 2 to return to the main menu." << endl;
                while ((!(cin >> next_seat))|| (next_seat > 2) || (next_seat < 1))
                    {
                        cout << "Invalid input! Please make your selection with a 1 or a 2.";
                        cin.clear();
                        cin.ignore();
                    }
                if (next_seat == 2)
                {
                    user_choice == 'N';
                    updateSeatingChart1(seating_chart1, array_min, rows, columns);
                    break;
                }
            }
            else if (user_choice == 'N' || user_choice == 'n')
            {
                next_seat = 2;
                updateSeatingChart1(seating_chart1, array_min, rows, columns);
                break;
            }
        }
        else
        {
            cout << "That seat is not available, please select a different seat." << endl;
            next_seat = 1;
        }
    }
    while (next_seat != 2);
}

void purchaseTickets2(char user_choice,char seating_chart2[rows][columns], int& adult_tickets,  int& child_tickets, int& total_tickets, double& adult_ticket_sales, double& child_ticket_sales, double& total_ticket_sales)
{
    double this_sale;
    int next_seat;
    next_seat = 1;

    do
    {
    displaySeatingChart(seating_chart2);
    cout << "Seating chart: " << endl
    << "Taken = #/X | Available = *" << endl;
    cout << "Choose a seat: " << endl;
    cout << "Enter row #: ";
    int row_number = inputValidate(row_number, 1, 7);

    cout << "Enter seat #: ";
    int seat_number = inputValidate(seat_number, 1, 8);

        if (seating_chart2[row_number][seat_number] == '*')
        {
            cout << "That seat is available." << endl << endl;
            cout << "Would you like to purchase Row #" << row_number << " Seat #" << seat_number << "? ";
            user_choice = inputValidateYesOrNo(user_choice);
            

            if (user_choice == 'Y' || user_choice == 'y')
            {
                cout << "Is this ticket for an adult ticket or for a child ticket?" << endl;
                cout << "Please enter A for an adult ticket or C for a child ticket." << endl;
                ticket_type = inputValidateAOrC(ticket_type);


                if (ticket_type == 'A' || ticket_type == 'a')
                {
                    adult_tickets ++;
                    adult_ticket_sales += ATE;
                    this_sale += ATE;
                    total_tickets ++;
                    total_ticket_sales += ATE;
                }

                else if (ticket_type == 'C' || ticket_type == 'c')
                {
                    child_tickets ++;
                    child_ticket_sales += CTE;
                    this_sale += CTE;
                    total_tickets ++;
                    total_ticket_sales += CTE;
                }

                seating_chart2[row_number][seat_number] = '#';
                cin.clear();
                cin.ignore();
                cout << "Total charges = $" << this_sale << endl;
                cout << "Would you like to purchase another seat?" << endl;
                cout << "Enter 1 to select another seat or 2 to return to the main menu." << endl;
                while ((!(cin >> next_seat))|| (next_seat > 2) || (next_seat < 1))
                    {
                        cout << "Invalid input! Please make your selection with a 1 or a 2.";
                        cin.clear();
                        cin.ignore();
                    }
                if (next_seat == 2)
                {
                    user_choice == 'N';
                    updateSeatingChart2(seating_chart2, array_min, rows, columns);
                    break;
                }
            }
            else if (user_choice == 'N' || user_choice == 'n')
            {
                next_seat = 2;
                updateSeatingChart2(seating_chart2, array_min, rows, columns);
                break;
            }
        }
       else
        {
            cout << "That seat is not available, please select a different seat." << endl;
            next_seat = 1;
        }
    }
    while (next_seat != 2);
}

void purchaseTickets3(char user_choice,char seating_chart3[rows][columns], int& adult_tickets,  int& child_tickets, int& total_tickets, double& adult_ticket_sales, double& child_ticket_sales, double& total_ticket_sales)
{
    double this_sale;
    int next_seat;
    next_seat = 1;

    do
    {
    displaySeatingChart(seating_chart3);
    cin.clear();
    cin.ignore();
    cout << "Seating chart: " << endl
    << "Taken = #/X | Available = *" << endl;
    cout << "Choose a seat: " << endl;
    cout << "Enter row #: ";
    int row_number = inputValidate(row_number, 1, 7);

    cout << "Enter seat #: ";
    int seat_number = inputValidate(seat_number, 1, 8);

        if (seating_chart3[row_number][seat_number] == '*')
        {
            cout << "That seat is available." << endl << endl;
            cout << "Would you like to purchase Row #" << row_number << " Seat #" << seat_number << "? ";
            user_choice = inputValidateYesOrNo(user_choice);
            

            if (user_choice == 'Y' || user_choice == 'y')
            {
                cout << "Is this ticket for an adult ticket or for a child ticket?" << endl;
                cout << "Please enter A for an adult ticket or C for a child ticket." << endl;
                ticket_type = inputValidateAOrC(ticket_type);


                if (ticket_type == 'A' || ticket_type == 'a')
                {
                    adult_tickets ++;
                    adult_ticket_sales += ATM;
                    this_sale += ATM;
                    total_tickets ++;
                    total_ticket_sales += ATM;
                    seating_chart3[row_number][seat_number] == '#';
                }

                else if (ticket_type == 'C' || ticket_type == 'c')
                {
                    child_tickets ++;
                    child_ticket_sales += CTM;
                    this_sale += CTM;
                    total_tickets ++;
                    total_ticket_sales += CTM;
                    seating_chart3[row_number][seat_number] == '#';
                }

                seating_chart3[row_number][seat_number] = '#';
                cin.clear();
                cin.ignore();
                cout << "Total charges = $" << this_sale << endl;
                cout << "Would you like to purchase another seat?" << endl;
                cout << "Enter 1 to select another seat or 2 to return to the main menu." << endl;
                while ((!(cin >> next_seat))|| (next_seat > 2) || (next_seat < 1))
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input! Please make your selection with a 1 or a 2.";
                    }
                if (next_seat == 2)
                {
                    user_choice == 'N';
                    updateSeatingChart3(seating_chart3, array_min, rows, columns);
                    break;
                }
            }
            else if (user_choice == 'N' || user_choice == 'n')
            {
                next_seat = 2;
                updateSeatingChart3(seating_chart3, array_min, rows, columns);
                break;
            }
        }
        else
        {
            cout << "That seat is not available, please select a different seat." << endl;
            next_seat = 1;
        }
    }
    while (next_seat != 2);
}

void purchaseTickets4(char user_choice,char seating_chart4[rows][columns], int& adult_tickets,  int& child_tickets, int& total_tickets, double& adult_ticket_sales, double& child_ticket_sales, double& total_ticket_sales)
{
    double this_sale;
    int next_seat;
    next_seat = 1;

    do
    {
    displaySeatingChart(seating_chart4);
    cout << "Seating chart: " << endl
    << "Taken = #/X | Available = *" << endl;
    cout << "Choose a seat: " << endl;
    cout << "Enter row #: ";
    int row_number = inputValidate(row_number, 1, 7);

    cout << "Enter seat #: ";
    int seat_number = inputValidate(seat_number, 1, 8);

        if (seating_chart4[row_number + 1][seat_number + 1] == '*')
        {
            cout << "That seat is available." << endl << endl;
            cout << "Would you like to purchase Row #" << row_number << " Seat #" << seat_number << "? ";
            user_choice = inputValidateYesOrNo(user_choice);
            

            if (user_choice == 'Y' || user_choice == 'y')
            {
                cout << "Is this ticket for an adult ticket or for a child ticket?" << endl;
                cout << "Please enter A for an adult ticket or C for a child ticket." << endl;
                ticket_type = inputValidateAOrC(ticket_type);


                if (ticket_type == 'A' || ticket_type == 'a')
                {
                    adult_tickets ++;
                    adult_ticket_sales += ATE;
                    this_sale += ATE;
                    total_tickets ++;
                    total_ticket_sales += ATE;
                }

                else if (ticket_type == 'C' || ticket_type == 'c')
                {
                    child_tickets ++;
                    child_ticket_sales += CTE;
                    this_sale += CTE;
                    total_tickets ++;
                    total_ticket_sales += CTE;
                }

                seating_chart4[row_number + 1][seat_number + 1] = '#';
                cin.clear();
                cin.ignore();
                cout << "Total charges = $" << this_sale << endl;
                cout << "Would you like to purchase another seat?" << endl;
                cout << "Enter 1 to select another seat or 2 to return to the main menu." << endl;
                while ((!(cin >> next_seat))|| (next_seat > 2) || (next_seat < 1))
                    {
                        cout << "Invalid input! Please make your selection with a 1 or a 2.";
                        cin >> next_seat;
                    }
                if (next_seat == 2)
                {
                    user_choice == 'N';
                    updateSeatingChart4(seating_chart4, array_min, rows, columns);
                    break;
                }
            }
            else if (user_choice == 'N' || user_choice == 'n')
            {
                next_seat = 2;
                updateSeatingChart4(seating_chart4, array_min, rows, columns);
                break;
            }
        }
        else
        {
            cout << "That seat is not available, please select a different seat." << endl;
            next_seat = 1;
        }
    }
    while (next_seat != 2);
}

int inputValidate(int& user_input, int lowest, int highest)
{
    while(!(cin >> user_input) || (user_input < lowest) || (user_input > highest))
    {
        cin.clear();
        cin.ignore();
        cout << "Error: Enter a number from " << lowest << " to " << highest << ": " << endl;
    }
    return user_input;
}

char inputValidateYesOrNo(char letter)
{
    while (!(cin >> letter) || !(letter == 'Y' || letter == 'y' || letter == 'N' || letter == 'n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Error: Enter a Y for yes or N for no" << endl;
    }
    return letter;
}

char inputValidateAOrC(char letter)
{
    while (!(cin >> letter) || !(letter == 'A' || letter == 'a' || letter == 'C' || letter == 'c'))
    {
        cout << "Error: Please enter A/a for an adult ticket or C/c for a child ticket.";
        cin.clear();
        cin.ignore();
    }
    return letter;
}

void displayAdminMenu()
{
    cout << "********************************************************" << endl;
    cout << "*                 Welcome Administrator!               *" << endl;
    cout << "********************************************************" << endl;
    cout << "* Administrator's Menu                                 *" << endl;
    cout << "* 1. Display Adult Tickets sold                        *" << endl;
    cout << "* 2. Display Child Tickets sold                        *" << endl;
    cout << "* 3. Display Total Tickets sold                        *" << endl;
    cout << "* 4. Display Adult Ticket profits                      *" << endl;
    cout << "* 5. Display Child Ticket profits                      *" << endl;
    cout << "* 6. Display Total Ticket profits                      *" << endl;
    cout << "* 7. Return to User Menu                               *" << endl;
    cout << "* 8. Program Shutdown                                  *" << endl;
    cout << "********************************************************" << endl;
}

void adminAdultTicketsSold(int& adult_tickets)
{
    cout << "We have sold " << adult_tickets << " adult tickets today." << endl;
}

void adminChildTicketsSold(int& child_tickets)
{
    cout << "We have sold " << child_tickets << " child tickets today." << endl;
}

void adminTotalTicketsSold(int& total_tickets)
{
    cout << "We have sold " << total_tickets << " tickets today." << endl;
}

void adminAdultTicketProfits(double& adult_tickets_sales)
{
    cout << "We have earned $" << adult_ticket_sales << " in adult tickets sold today." << endl;
}

void adminChildTicketProfits(double& child_tickets_sales)
{
    cout << "We have earned $" << child_ticket_sales << " in child tickets sold today." << endl;
}

void adminTotalTicketProfits(double& total_ticket_sales)
{
    cout << "We have earned $" << total_ticket_sales << " in profits today." << endl;
}

int adminShutdown(int& menu_choice,int& admin_input)
{
    menu_choice = 8;
    admin_input = 7;
    return menu_choice, admin_input;
}

void updateSeatingChart1(char seating_chart1[rows][columns],const int array_min,int rows,int columns)
{
    for (int row = 1; row < rows; row++)
    {
        for (int column = 1; column < columns; column++)
        {
            if (row == 1)
            {
                if (column == 1)
                {
                    if (seating_chart1[row][column] = '#')
                    {
                        if (seating_chart1[row + 1][column] == '*')
                        {
                            seating_chart1[row + 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart1[row][column] == '#')
                    {
                        if (seating_chart1[row + 1][column] == '*')
                        {
                            seating_chart1[row + 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column +1] = 'X';
                        }
                        if (seating_chart1[row][column - 1] == '*')
                        {
                            seating_chart1[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart1[row][column - 1] == '*')
                    {
                        seating_chart1[row][column - 1] = 'X';
                    }
                    if (seating_chart1[row + 1][column] == '*')
                    {
                        seating_chart1[row + 1][column] = 'X';
                    }
                }
            }
            if (1 < row && row < rows)
            {
                if (column == 1)
                {
                    if (seating_chart1[row][column] == '#')
                    {
                        if (seating_chart1[row + 1][column] == '*')
                        {
                            seating_chart1[row + 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column +1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart1[row][column] == '#')
                    {
                        if (seating_chart1[row + 1][column] == '*')
                        {
                            seating_chart1[row + 1][column] = 'X';
                        }
                        if (seating_chart1[row - 1][column] == '*')
                        {
                            seating_chart1[row - 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column +1] = 'X';
                        }
                        if (seating_chart1[row][column - 1] == '*')
                        {
                            seating_chart1[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart1[row][column - 1] == '*')
                    {
                        seating_chart1[row][column - 1] = 'X';
                    }
                    if (seating_chart1[row + 1][column] == '*')
                    {
                        seating_chart1[row + 1][column] = 'X';
                    }
                    if (seating_chart1[row - 1][column] == '*')
                    {
                        seating_chart1[row - 1][column] = 'X';
                    }
                }
            }
            if (row == rows)
            {
                if (column == 1)
                {
                    if (seating_chart1[row][column] == '#')
                    {
                        if (seating_chart1[row - 1][column] == '*')
                        {
                            seating_chart1[row - 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column +1] = 'X';
                        }
                    }
                }
                if (array_min < column && column < columns)
                {
                    if (seating_chart1[row][column] == '#')
                    {
                        if (seating_chart1[row - 1][column] == '*')
                        {
                            seating_chart1[row - 1][column] = 'X';
                        }
                        if (seating_chart1[row][column + 1] == '*')
                        {
                            seating_chart1[row][column + 1] = 'X';
                        }
                        if (seating_chart1[row ][column - 1] == '*')
                        {
                            seating_chart1[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart1[row][column -1] == '*')
                    {
                        seating_chart1[row][column - 1] = 'X';
                    }
                    if (seating_chart1[row - 1][column] == '*')
                    {
                        seating_chart1[row - 1][column] = 'X';
                    }
                }
            }
        }
    }
}

void updateSeatingChart2(char seating_chart2[rows][columns],const int array_min,int rows,int columns)
{
    for (int row = 1; row < rows; row++)
    {
        for (int column = 1; column < columns; column++)
        {
            if (row == 1)
            {
                if (column == 1)
                {
                    if (seating_chart2[row][column] = '#')
                    {
                        if (seating_chart2[row + 1][column] == '*')
                        {
                            seating_chart2[row + 1][column] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart2[row][column] == '#')
                    {
                        if (seating_chart2[row + 1][column] == '*')
                        {
                            seating_chart2[row + 1][column] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column +1] = 'X';
                        }
                        if (seating_chart2[row][column - 1] == '*')
                        {
                            seating_chart2[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart2[row][column - 1] == '*')
                    {
                        seating_chart2[row][column - 1] = 'X';
                    }
                    if (seating_chart2[row + 1][column] == '*')
                    {
                        seating_chart2[row + 1][column] = 'X';
                    }
                }
            }
            if (1 < row && row < rows)
            {
                if (column == 1)
                {
                    if (seating_chart2[row][column] == '#')
                    {
                        if (seating_chart2[row + 1][column] == '*')
                        {
                            seating_chart2[row + 1][column] = 'X';
                        }
                        if (seating_chart2[row - 1][column] == '*')
                        {
                            seating_chart2[row - 1][column] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart2[row][column] == '#')
                    {
                        if (seating_chart2[row + 1][column] == '*')
                        {
                            seating_chart2[row + 1][column] = 'X';
                        }
                        if (seating_chart2[row - 1][column] == '*')
                        {
                            seating_chart2[row - 1][column] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column + 1] = 'X';
                        }
                        if (seating_chart2[row][column - 1] == '*')
                        {
                            seating_chart2[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart2[row][column - 1] == '*')
                    {
                        seating_chart2[row][column - 1] = 'X';
                    }
                    if (seating_chart2[row + 1][column] == '*')
                    {
                        seating_chart2[row + 1][column] = 'X';
                    }
                    if (seating_chart2[row - 1][column] == '*')
                    {
                        seating_chart2[row - 1][column] = 'X';
                    }
                }
            }
            if (row == rows)
            {
                if (column == 1)
                {
                    if (seating_chart2[row][column] == '#')
                    {
                        if (seating_chart2[row - 1][column] == '*')
                        {
                            seating_chart2[row - 1][column] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column +1] = 'X';
                        }
                    }
                }
                if (array_min < column && column < columns)
                {
                    if (seating_chart2[row][column] == '#')
                    {
                        if (seating_chart2[row - 1][column] == '*')
                        {
                            seating_chart2[row - 1][columns] = 'X';
                        }
                        if (seating_chart2[row][column + 1] == '*')
                        {
                            seating_chart2[row][column +1] = 'X';
                        }
                        if (seating_chart2[row][column - 1] == '*')
                        {
                            seating_chart2[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart2[row][column - 1] == '*')
                    {
                        seating_chart2[row][column - 1] = 'X';
                    }
                    if (seating_chart2[row - 1][column] == '*')
                    {
                        seating_chart2[row - 1][column] = 'X';
                    }
                }
            }
        }
    }
}

void updateSeatingChart3(char seating_chart3[rows][columns],const int array_min,int rows,int columns)
{
    for (int row = 1; row < rows; row++)
    {
        for (int column = 1; column < columns; column++)
        {
            if (row == 1)
            {
                if (column == 1)
                {
                    if (seating_chart3[row][column] = '#')
                    {
                        if (seating_chart3[row + 1][column] == '*')
                        {
                            seating_chart3[row + 1][column] = 'X';
                        }
                        if (seating_chart3[row][column + 1] == '*')
                        {
                            seating_chart3[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart3[row][column] == '#')
                    {
                        if (seating_chart3[row + 1][column] == '*')
                        {
                            seating_chart3[row + 1][column] = 'X';
                        }
                        if (seating_chart3[row][column + 1] == '*')
                        {
                            seating_chart3[row][column + 1] = 'X';
                        }
                        if (seating_chart3[row][column - 1] == '*')
                        {
                            seating_chart3[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart3[row][column - 1] == '*')
                    {
                        seating_chart3[row][column - 1] = 'X';
                    }
                    if (seating_chart3[row + 1][column] == '*')
                    {
                        seating_chart3[row + 1][column] = 'X';
                    }
                }
            }
            if (1 < row && row < rows)
            {
                if (column == 1)
                {
                    if (seating_chart3[row][column] == '#')
                    {
                        if (seating_chart3[row + 1][column] == '*')
                        {
                            seating_chart3[row + 1][column] = 'X';
                        }
                        if (seating_chart3[row - 1][column] == '*')
                        {
                            seating_chart3[row - 1][column] = 'X';
                        }
                        if (seating_chart3[row][column + 1] == '*')
                        {
                            seating_chart3[row][column +1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart3[row][column] == '#')
                    {
                        if (seating_chart3[row + 1][column] == '*')
                        {
                            seating_chart3[row + 1][column] = 'X';
                        }
                        if (seating_chart3[row - 1][column] == '*')
                        {
                            seating_chart3[row - 1][column] = 'X';
                        }
                        if (seating_chart3[row][column + 1] == '*')
                        {
                            seating_chart3[row][column + 1] = 'X';
                        }
                        if (seating_chart3[row][column - 1] == '*')
                        {
                            seating_chart3[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart3[row][column - 1] == '*')
                    {
                        seating_chart3[row][column - 1] = 'X';
                    }
                    if (seating_chart3[row + 1][column] == '*')
                    {
                        seating_chart3[row + 1][column] = 'X';
                    }
                    if (seating_chart3[row - 1][column] == '*')
                    {
                        seating_chart3[row - 1][column] = 'X';
                    }
                }
            }
            if (row == rows)
            {
                if (column == 1)
                {
                    if (seating_chart3[row][column] == '#')
                    {
                        if (seating_chart3[row - 1][column] == '*')
                        {
                            seating_chart3[row - 1][column] = 'X';
                        }
                        if (seating_chart3[row][column + 1] == '*')
                        {
                            seating_chart3[row][column +1] = 'X';
                        }
                    }
                }
                if (array_min < column && column < columns)
                {
                    if (seating_chart3[row][column] == '#')
                    {
                        if (seating_chart3[row - 1][column] == '*')
                        {
                            seating_chart3[row - 1][column] = 'X';
                        }
                        if (seating_chart3[row ][column + 1] == '*')
                        {
                            seating_chart3[row][column + 1] = 'X';
                        }
                        if (seating_chart3[row][column - 1] == '*')
                        {
                            seating_chart3[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart3[row][column - 1] == '*')
                    {
                        seating_chart3[row][column - 1] = 'X';
                    }
                    if (seating_chart3[row - 1][column] == '*')
                    {
                        seating_chart3[row - 1][column] = 'X';
                    }
                }
            }
        }
    }
}

void updateSeatingChart4(char seating_chart4[rows][columns],const int array_min,int rows,int columns)
{
    for (int row = 1; row < rows; row++)
    {
        for (int column = 1; column < columns; column++)
        {
            if (row == 1)
            {
                if (column == 1)
                {
                    if (seating_chart4[row][column] = '#')
                    {
                        if (seating_chart4[row + 1][column] == '*')
                        {
                            seating_chart4[row + 1][column] = 'X';
                        }
                        if (seating_chart4[row][column + 1] == '*')
                        {
                            seating_chart4[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart4[row][column] == '#')
                    {
                        if (seating_chart4[row + 1][column] == '*')
                        {
                            seating_chart4[row + 1][column] = 'X';
                        }
                        if (seating_chart4[row][column + 1] == '*')
                        {
                            seating_chart4[row][column +1] = 'X';
                        }
                        if (seating_chart4[row][column - 1] == '*')
                        {
                            seating_chart4[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart4[row][column - 1] == '*')
                    {
                        seating_chart4[row][column - 1] = 'X';
                    }
                    if (seating_chart4[row + 1][column] == '*')
                    {
                        seating_chart4[row + 1][column] = 'X';
                    }
                }
            }
            if (1 < row && row < rows)
            {
                if (column == 1)
                {
                    if (seating_chart4[row][column] == '#')
                    {
                        if (seating_chart4[row + 1][column] == '*')
                        {
                            seating_chart4[row + 1][column] = 'X';
                        }
                        if (seating_chart4[row - 1][column] == '*')
                        {
                            seating_chart4[row - 1][column] = 'X';
                        }
                        if (seating_chart4[row][column + 1] == '*')
                        {
                            seating_chart4[row][column + 1] = 'X';
                        }
                    }
                }
                if (1 < column && column < columns)
                {
                    if (seating_chart4[row][column] == '#')
                    {
                        if (seating_chart4[row + 1][column] == '*')
                        {
                            seating_chart4[row + 1][column] = 'X';
                        }
                        if (seating_chart4[row - 1][column] == '*')
                        {
                            seating_chart4[row - 1][column] = 'X';
                        }
                        if (seating_chart4[row][column + 1] == '*')
                        {
                            seating_chart4[row][column +1] = 'X';
                        }
                        if (seating_chart4[row][column - 1] == '*')
                        {
                            seating_chart4[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart4[row][column - 1] == '*')
                    {
                        seating_chart4[row][column - 1] = 'X';
                    }
                    if (seating_chart4[row + 1][column] == '*')
                    {
                        seating_chart4[row + 1][column] = 'X';
                    }
                    if (seating_chart4[row - 1][column] == '*')
                    {
                        seating_chart4[row - 1][column] = 'X';
                    }
                }
            }
            if (row == rows)
            {
                if (column == 1)
                {
                    if (seating_chart4[row][column] == '#')
                    {
                        if (seating_chart4[row - 1][column] == '*')
                        {
                            seating_chart4[row - 1][column] = 'X';
                        }
                        if (seating_chart4[row ][column + 1] == '*')
                        {
                            seating_chart4[row][column +1] = 'X';
                        }
                    }
                }
                if (array_min < column && column < columns)
                {
                    if (seating_chart4[row][column] == '#')
                    {
                        if (seating_chart4[row - 1][column] == '*')
                        {
                            seating_chart4[row - 1][column] = 'X';
                        }
                        if (seating_chart4[row ][column + 1] == '*')
                        {
                            seating_chart4[row][column + 1] = 'X';
                        }
                        if (seating_chart4[row][column - 1] == '*')
                        {
                            seating_chart4[row][column - 1] = 'X';
                        }
                    }
                }
                if (column == columns)
                {
                    if (seating_chart4[row][column - 1] == '*')
                    {
                        seating_chart4[row][column - 1] = 'X';
                    }
                    if (seating_chart4[row - 1][column] == '*')
                    {
                        seating_chart4[row - 1][column] = 'X';
                    }
                }
            }
        }
    }
}
