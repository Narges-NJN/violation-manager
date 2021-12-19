//-----including needed libraries-----
#include <ncurses.h>                    //for text UI
#include <string.h>                     //for strlen() , strcmp() functions
#include <time.h>                       //for time() function 
#include <unistd.h>                     //for access() function 
#include <ctype.h>                      //for isdigit() function
#include "ui.h"                         

/*** all states in program are diffined in enums ***/
enum Has_account{
    no = 2,
    yes = 3,
};
enum Login_State {
    normal_user_login_successful = 0,
    admin_login_successful = 1,
    no_account = 2,
    wrong_password = 4,
    block = 22
};
enum Signup_State {
    repeated_national_code = 5,
    signup_successful = 6,
    already_has_account = 7
};
enum cartable_menu_state{
    inbox = 0 , 
    compose = 1,
    history = 2,
    related = 3
};
enum Priority{
    mid_priority = 0 , 
    high_priority = 1
};
enum Tags{
    building_permit = 1 , 
    traffic = 2,
    bussiness_licence = 3,
    boating = 4,
    jaywalking = 5,
    other = 6
};
enum delete_or_edit{
    delete = 0,
    edit = 1,
};
enum accept_or_reject{
    accept = 0,
    reject = 1,
};


/**** structs ****/
struct User_info{
    char national_code [13];
    char username[10];
    char password[10];
    int block;           // value 1 = block ** value 0 = not block
    int admin_or_normal; // value 1 = admin ** value 0 = normal user
};

struct Reports{
    char title [50];
    char tag [30];
    char describtion [300];
    char address_or_reason[50];
    char priority[5];
    time_t time;
    char username[10];
    char accept[10];
    int credit;
};

/***** initial setups *****/
void ncurses_setup();
void make_files();
/*************************/

/**** Login & Sign up Functions ****/
// core //
int first_pages(int maxY, int maxX, char* username);
int ask_if_user_has_account(int maxY, int maxX);
int login_page(int maxY, int maxX, char* username);
void scan_login_info(char* username, char* password, int maxY, int maxX);
int check_login(char* username, char* password);
int signup_page(int maxY, int maxX);
void scan_signup_info(int maxY,int maxX,struct User_info *s);
int check_admin_or_user(int maxY, int maxX);
void check_national_code(int maxY, int maxX, char* input);
int check_time ();
// file //
int get_users_count_from_file(FILE *users, int size_of_struct);
void write_sinup_info_in_file(FILE *users, struct User_info s);
/***********************************/

/**** Normal User Cartable Functions *****/
void normal_user_cartable(int maxY, int maxX, char* username);
void credit_appearence(int maxY, int maxX, char* username);
void normal_user_cartable_menu(int maxY, int maxX,char* username);
void compose_handle(int maxY, int maxX, char* username);
void scan_compose_title (int maxY, int maxX, struct Reports *report);
int tag_menu(int maxY, int maxX, struct Reports *report );
void scan_compose_description(int maxY, int maxX, struct Reports *report);
void scan_compose_address(int maxY, int maxX, struct Reports *report);
int compose_priority_menu(int maxY, int maxX, struct Reports *report );
void save_time(struct Reports *report);
void read_file(struct User_info *n, FILE *users, int user_count);
void save_national_code(struct Reports *report);
void save_struct_report_in_file(struct Reports *report);
int get_report_count_from_file(FILE *report_data);
void inbox_handle(int maxY, int maxX, char* username);
void read_reports_from_file_and_print(int maxY, int maxX, char* username);
void delete_or_edit(int maxY, int maxX, char* username);
void scan_delete_or_edit_title(int maxY, int maxX, struct Reports *report);
int delete_or_edit_menu(int maxY,int maxX);
void delete_report_handle(char title [50]);
void edit_report_handle(int maxY, int maxX, char title [50],char* username);
void related_handle(int maxY,int maxX,char* username);
void get_number_of_tag_to_search(int maxY, int maxX, struct Reports *report);
void read_and_print_related_reports(int maxY, int maxX, struct Reports *report);
void user_history_handle(int maxY, int maxX,char* username );
/*****************************************/

/**** Admin Cartable Functions *****/
void admin_cartable(int maxY, int maxX);
void admin_cartable_menu(int maxY, int maxX);
void admin_inbox_handle(int maxY, int maxX);
void read_all_reports_and_print_admin(int maxY,int maxX);
void reject_or_accept(int maxY,int maxX);
void scan_accept_or_reject_title(int maxY, int maxX, struct Reports *report);
int accept_or_reject_menu(int maxY, int maxX);
void accept_report_handle(int maxY, int maxX, struct Reports report);
void scan_credit_value(int maxY,int maxX,int* credit);
void reject_report_handle(int maxY, int maxX, struct Reports report);
void scan_reason_to_reject(int maxY,int maxX, struct Reports *report);
int block_menu(int maxY,int maxX);
void block_handle(struct Reports report);
void admin_history_handle(int maxY,int maxX);
/***********************************/

/*********** main *************/
int main (){

    ncurses_setup();

    // to privent core dump error when files do not exist
    // make_files function inithially makes files
    make_files();

    // maxX and maxY are used for saving maximum width and hight of shell
    int maxX, maxY;
    getmaxyx(stdscr,maxY,maxX);
    
    char username [10];

    //first pages contain welcome, sign up and login.
    int admin_or_normal = first_pages(maxY, maxX, username);

    if ( admin_or_normal == admin_login_successful)
        admin_cartable(maxY, maxX);

    else if ( admin_or_normal == normal_user_login_successful)
        normal_user_cartable(maxY, maxX, username);

    // note: admin_login_successful & normal_user_login_successful states
    // are defined in enum line 14

    endwin();
    return 0;
}
/*******************************/

/***** initial setups *****/
void ncurses_setup(){
    // start screen
    initscr(); 
    
    // enable ncurses key pad                 
    keypad(stdscr,TRUE);
    
    //start_color();

    // set blinking curser off
    curs_set(0);
    
    // dont display input charachters
    noecho();
}

void make_files(){
    FILE *users = fopen("user-info.dat","a");;
    fclose(users);
    FILE* Report = fopen("report_data.dat","a");
    fclose(Report);
}
/*************************/

/**** Login & Sign up Functions ****/
int first_pages(int maxY, int maxX, char* username){

    clear();

    // welcome_screen_ui is a function in ui.h 
    welcome_screen_ui(maxY, maxX);

    
    int has_account = ask_if_user_has_account(maxY, maxX);
    
    // yes and no values are defined in enum Has_account, line 12
    if (has_account == yes)
        has_account = login_page(maxY, maxX, username);

    int result ;
    if (has_account == no)
        result = signup_page(maxY, maxX);

    // result values are defined in enum Signup_State line 21 
    if(result == repeated_national_code)
    {
        print_repeated_code_error(maxY, maxX);
        getch();
        first_pages(maxY, maxX, username);
    }

    else if (result == already_has_account)
    {
        print_has_account_error(maxY,maxX);
        getch();
        first_pages(maxY, maxX, username);
    }

    else if( result == signup_successful)
        has_account = login_page(maxY, maxX, username);
    
    if ( has_account == admin_login_successful || has_account == normal_user_login_successful)
        return has_account;
}

int ask_if_user_has_account(int maxY, int maxX){
    // highligh value yes or no
    // yes and no are defined in enum Has_account- line12
    int highligh = yes;
    // choise saves value of the cherachter that user enters
    int choise;

    // This infinit loop make it possible for the user to swich between yes and no choises
    // logic : gets right or left keys from user and saves the key value in choise
    // checks the value of choice and increase or decrease the value of highligh
    // if highlight value is 1, yes is highlighted
    // if highlight value is 0, no is highlighted
    // the loop breaks when user press enter
    // the value of highlight is returned
    while(1){
        if (highligh == yes){
            // function in ui.h
            print_yes_highlighted(maxY, maxX); 
        } 
        else if (highligh == no){
            // function in ui.h
            print_no_highlighted(maxY, maxX); 
        }
        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highligh --;
            if( highligh < no)
                highligh = yes;
            break;
        
        case KEY_LEFT:
            highligh ++;
            if( highligh > yes)
                highligh = no;
            
            break;
        case 10:
        case 13:
            return highligh;
            break;
        default:
            break;
        }
    }
}

int login_page(int maxY, int maxX, char* username){

    // this function is the core of login page

    clear();

    // login_page_ui is a function in ui.h
    login_page_ui(maxY, maxX);

    char password [10];

    scan_login_info(username, password, maxY, maxX);

    int login_state = check_login(username, password);

    if (login_state == admin_login_successful)
        return  admin_login_successful;

    if (login_state == normal_user_login_successful)
        return  normal_user_login_successful;

    else if (login_state == block){
        clear();
        print_block_error(maxY,maxX);

        if (getch())
            return block;
    }
    else if (login_state == wrong_password) {

        // if user entered wrong pass, an error will be printed 
        clear();
        print_wrong_pass_error(maxY,maxX);

        // if user press any key, login page is called again, and user can try to login again
        if (getch())
            login_page (maxY, maxX, username);

    }
    else if (login_state == 55)
        return 55;
    else {

        // else, user does not have account so
        // an error is printed
        clear();
        print_no_account_error(maxY,maxX);
        
        // if user presses any key, no_account is returned to main
        // in main function, next line calls signup function so that user can create account
        if (getch())
            return no_account;
    }
}

void scan_login_info(char* username, char* password, int maxY, int maxX){

    // set curser blinking on, because it fills more natural in an input field
    curs_set(1);
    // display input charachters
    echo();

    mvscanw( maxY/3 , maxX/2 + 5 ,"%s", username );
    mvscanw( maxY/2 , maxX/2 + 5 ,"%s", password );

    // again set curser off
    curs_set(0);
    //set back to no echo, dont display input
    noecho();
}

int check_login(char* username, char* password){

    // This function compair username and password that user entered 
    // with usernames and passwords that are priviously written in the file
    // and return 3 enum states, defined in line 16
    int c;
    c = check_time();
    if (c == 55)
    {
        clear();
        mvprintw(25 , 80,"Application is closed between 12 to 15 pm!");
        getch();
        return 55;
    }

    FILE *users = fopen("user-info.dat","r+");

    // getting number of users from file
    int size_of_struct = (int) sizeof(struct User_info);
    int user_count = get_users_count_from_file(users, size_of_struct);

    //array of struct
    struct User_info registered_user[user_count];

    // this for loop reads file and stores the data in the array of struct
    for (int i = 0; i < user_count ; i++ )
        fread (&registered_user[i], sizeof(struct User_info), 1, users) ;    

    fclose(users);

    // compairing struct array(which is filled with file's data)
    // with username and password that user entered
    for (int i = 0; i < user_count; i++){
        if (strcmp ( registered_user[i].username, username) == 0 
            && strcmp ( registered_user[i].password, password) == 0 
            && registered_user[i].block == 1)
            return block;
    }
    for (int i = 0; i < user_count ; i++ ){
        if (strcmp ( registered_user[i].username, username) == 0
            && strcmp ( registered_user[i].password, password) == 0)
            return registered_user[i].admin_or_normal;
    }
    for (int i = 0; i < user_count ; i++ ){
        if (strcmp ( registered_user[i].username, username) == 0 && strcmp ( registered_user[i].password, password) != 0)
            return wrong_password;
    }
    

    return no_account;
    
}


int check_time (){
    
    /***********************************************/
    // application will be closed and unacessible
    //  during the hours specified in this function:
    /**********************************************/
    
    time_t s; 
    struct tm* current_time; 

    int start = 1;
    int end = 2;
    // time in seconds 
    s = time(NULL); 
  
    // to get current time 
    current_time = localtime(&s); 

    if (current_time->tm_hour > start, current_time->tm_hour < end)
    return 55; 
}

int signup_page(int maxY, int maxX){

    // signup_page_ui is a function in ui.h
    signup_page_ui(maxY,maxX);
    
    struct User_info new_user;

    scan_signup_info(maxY,maxX, &new_user);

    int admin_or_normal = check_admin_or_user(maxY, maxX);
    new_user.admin_or_normal = admin_or_normal;

    // open file that contain users information in mode of read
    FILE *users;
    users = fopen("user-info.dat","a+");

    int size_of_struct = (int) sizeof(struct User_info);
    int user_count = get_users_count_from_file(users, size_of_struct);

    struct User_info registered_user[user_count];

    for (int i = 0; i < user_count ; i++ )
        fread (&registered_user[i], sizeof(struct User_info), 1, users) ;   
    
    fclose(users);

    for (int i = 0; i < user_count ; i++ ){
        if( strcmp ( registered_user[i].national_code, new_user.national_code) == 0 && 
            strcmp (registered_user[i].username, new_user.username) == 0  &&  
            strcmp (registered_user[i].password, new_user.password) == 0 ) {

            return already_has_account;
            break;
        }
    }

    for (int i = 0; i < user_count ; i++ ){
        if( strcmp ( registered_user[i].national_code, new_user.national_code) == 0  && 
            strcmp (registered_user[i].username, new_user.username) != 0 &&  
            strcmp (registered_user[i].password, new_user.password) != 0 ) {
                
            return repeated_national_code;
            break;
        }
    }
    //set defualt value of block = 0 
    new_user.block = 0;

    write_sinup_info_in_file(users, new_user);
    
    return signup_successful;
}

void scan_signup_info(int maxY,int maxX,struct User_info *s){

    curs_set(1);
    echo();

    mvscanw(maxY/3, maxX/2 + 5, "%s", s->national_code);

    check_national_code(maxY, maxX, s->national_code);

    mvscanw(maxY/2.3, maxX/2 + 5, "%s", s->username);

    mvscanw( maxY/1.9, maxX/2 + 5, "%s", s->password);

    noecho();
    curs_set(0);
}

int check_admin_or_user(int maxY, int maxX){
    // highlight value normal user 0 
    // highlight value admin 1 
    int highlight = 1;
    // choise saves value of the cherachter that user enters
    int choise;

    while(1){
        if (highlight == 1){
            // function in ui.h
            print_admin_highlighted(maxY, maxX); 
        } 
        else if (highlight == 0){
            // function in ui.h
            print_normal_highlighted(maxY, maxX); 
        }
        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highlight --;
            if( highlight < 0)
                highlight = 1;
            break;
        
        case KEY_LEFT:
            highlight ++;
            if( highlight > 1)
                highlight = 0;
            
            break;
        case 10:
        case 13:
            return highlight;
            break;
        default:
            break;
        }
    }
}

void check_national_code(int maxY, int maxX, char* input){
    //this function first check if user input is 10 charachters-because national code should only be 10 chars
    //then isdigit checks each charachter in a loop, 
    //if any charachter is not digit, isdigit returns 0

    int len = (int)strlen(input) ;
    
    int valid = 0;

    if (len == 10)
    {
            valid = 1;
            for (int i = 0; i < len; ++i)
            {
                if (!isdigit(input[i]))
                {
                    valid = 0;
                    break;
                }
            }
    }

    // valid == 0 simply means user input is less or more than 10 chars 
    // or it contains nondigit chars

    if (valid == 0){
        //print error function in ui.h
        print_national_code_error(maxY,maxX);
        
        //get a key and return to signup_page, so that user can enter another national code 
        getch();
        curs_set(1);
        signup_page(maxY, maxX);
    }
}

int get_users_count_from_file(FILE *users, int size_of_struct){

    // put the curser in the end of file 
    fseek(users, 0, SEEK_END);

    // tell the curser location and store it in pos 
    long int pos = ftell(users);

    // n structs * size of struct = possition of curser at the end of file
    // so pos/size_of_structs gives n, which is user_count
    int user_count =(int) (pos/size_of_struct);

    // put the curses back to the begining of the file
    fseek(users, 0, SEEK_SET); 

    return user_count;
}

void write_sinup_info_in_file(FILE *users, struct User_info s){
    users = fopen("user-info.dat","a+");
    fwrite (&s, sizeof(struct User_info), 1, users);
    fclose(users);
}
/***********************************/

/**** Normal User Cartable Functions *****/
void normal_user_cartable(int maxY, int maxX, char* username){

    //function in ui.h
    normal_user_cartable_ui(maxY,maxX, username);

    credit_appearence(maxY,maxX,username);

    //call cartable menu function
    normal_user_cartable_menu(maxY,maxX, username);
}

void normal_user_cartable_menu(int maxY, int maxX, char* username){

    // highlight values :   inbox 0
    //                      compose 1
    //                      history 2
    //                      related 3
    // defined in enum line 27

    int highlight = 0;
    int choise;
    while(1){
        if (highlight == inbox){
            // function in ui.h
            print_inbox_highlighted(maxY, maxX); 
            inbox_handle(maxY,maxX,username);
            normal_user_cartable_ui(maxY,maxX, username);
            credit_appearence(maxY,maxX,username);
            printinbox(maxY, maxX);
        } 
        else if (highlight == compose){
            clear();
            // function in ui.h
            normal_user_cartable_ui(maxY,maxX, username);
            credit_appearence(maxY,maxX,username);
            print_compose_highlighted(maxY, maxX);
            printcompose(maxY,maxX);
        }
        else if (highlight == history){
            print_history_highlighted(maxY, maxX);
            credit_appearence(maxY,maxX,username);
            user_history_handle(maxY, maxX,username); 
        }
        else if (highlight == related){
            clear();
            normal_user_cartable_ui(maxY,maxX, username);
            credit_appearence(maxY,maxX,username);
            print_related_highlighted(maxY, maxX);
            printrelated(maxY ,maxX);
        }

        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highlight ++;
            if( highlight > 3)
                highlight = 0;
            break;
        
        case KEY_LEFT:
            highlight --;
            if( highlight < 0)
                highlight = 3;
            
            break;
        
        case 10:
        case 13:
            if (highlight == compose){
                credit_appearence(maxY,maxX,username);
                compose_handle(maxY,maxX,username);
                credit_appearence(maxY,maxX,username);
            }
            if (highlight == related){
                credit_appearence(maxY,maxX,username);
                related_handle(maxY,maxX,username);
                clear();
                normal_user_cartable_ui(maxY,maxX, username);
                credit_appearence(maxY,maxX,username);
            }
                
        default:
            break;
        }
    }

}

void compose_handle(int maxY, int maxX, char* username){
    //call function from ui.h
    compose_ui(maxY,maxX);
    
    struct Reports current;

    scan_compose_title(maxY, maxX, &current);

    tag_menu(maxY, maxX, &current);
   
    scan_compose_description(maxY, maxX, &current);

    scan_compose_address(maxY, maxX, &current);

    compose_priority_menu(maxY, maxX, &current);

    print_send_button_active(maxY, maxX);

    getch();
    normal_user_cartable_ui(maxY,maxX, username);

    save_time(&current);
    
    strcpy (current.username , username);
    strcpy (current.accept , "pending");
    current.credit = 0;

    save_struct_report_in_file(&current);
}

void scan_compose_title (int maxY, int maxX, struct Reports *report){
  
    char title[50];
    echo();
    curs_set(1);
    mvgetstr(18,maxX/8+17 , title);
    // fill the title field of struct with the title user entered
    strcpy( report->title , title);
    noecho();
    curs_set(0);

    // to show number of chars user entered
    int i = strlen(title);
    mvprintw(18,maxX/8+134,"%d", i);
}

int tag_menu(int maxY, int maxX, struct Reports *report ){

    print_tag_building_permit_highlighted(maxY,maxX);

    int highlight = 1;
    int choise;
    while(1){
        if (highlight == building_permit){
            // function in ui.h
            print_tag_building_permit_highlighted( maxY, maxX);
        } 
        else if (highlight == traffic){
            // function in ui.h
            print_tag_traffic_highlighted( maxY, maxX);
        }
        else if (highlight == bussiness_licence){
            print_tag_bussiness_licence_highlighted( maxY, maxX);
        }
        else if (highlight == boating){
            print_tag_boating_highlighted( maxY, maxX);
        }
        else if (highlight == jaywalking){
            print_tag_jaywalking_highlighted( maxY, maxX);
        }
        else if (highlight == other){
            print_tag_other_highlighted( maxY, maxX);
        }

        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highlight ++;
            if( highlight > 6)
                highlight = 1;
            break;
        
        case KEY_LEFT:
            highlight --;
            if( highlight < 1)
                highlight = 6;
            
            break;
        
        case 10:
        case 13:
            if (highlight == building_permit){
                strcpy( report->tag, "building_permit");
                return building_permit;
            } 

            else if (highlight == traffic){
                strcpy( report->tag, "traffic");
                return traffic;
            }
            
            else if (highlight == bussiness_licence){
                strcpy( report->tag, "bussiness_licence");
                return bussiness_licence;
            }
            
            else if (highlight == boating){
                strcpy( report->tag, "boating");
                return boating;
            }
            
            else if (highlight == jaywalking){
                strcpy( report->tag, "jaywalking");
                return jaywalking;
            }
            
            else if (highlight == other){
                strcpy( report->tag, "other");
                return other;
            }
        default:
            break;
        }
    }

}

void scan_compose_description(int maxY, int maxX, struct Reports *report){
    int i;
    char description[300];

    //this loop gets user input charachter by charachter and shows number of charachters
    for ( i = 0; i <= 300; i++ ){

        // print i (number of chars) in blinking mode
        attron( A_BLINK );
        mvprintw(31,maxX/8+148,"%d", i);
        attroff( A_BLINK );

        // move curser and getch
        move(31, maxX/8-1+i);
        curs_set(1);
        description[i] = getch();
        
        // if user press enter(ascci code = 10) count of charachters is printes non-blinking
        if(description[i]==10){
            mvprintw(31,maxX/8+148,"%d", i);
            break;
        }

        // if user press backspace array i - 1 is free and a space is printed 
        else if ( description[i] == '\b'){
            description[i-1]='\0';
            mvprintw(31,maxX/8-1+i-1, " "); 
        }

        // else every char that user enters is printed
        else {
            mvprintw(31,maxX/8-1+i,"%c", description[i]);
        }

        refresh();
    }    
    // copy desciption to describtion field of struct
    strcpy( report->describtion , description);

    curs_set(0);
}

void scan_compose_address(int maxY, int maxX, struct Reports *report){
    int i;
    char address[20];
    for ( i = 0; i <= 20; i++ ){
        attron( A_BLINK );
        mvprintw(40,maxX/8+134,"%d", i);
        attroff( A_BLINK );

        move(40, maxX/8+50+i);
        curs_set(1);
        address[i] = getch();

        if(address[i]==10){
            mvprintw(40,maxX/8+134,"%d", i);
            break;
        }

        else if ( address[i] == '\b'){
            address[i-1]='\0';
            mvprintw(40, maxX/8+50+i-1," "); 
        }

        else {
            mvprintw(40,maxX/8+50+i,"%c", address[i]);
        }

        refresh();
    }    
    strcpy( report->address_or_reason , address);

    curs_set(0);
}

int compose_priority_menu(int maxY, int maxX, struct Reports *report ){
    print_mid_priority_highlighted(maxY,maxX);

    int highlight = 0;
    int choise;
    while(1){
        if (highlight == mid_priority){
            // function in ui.h
            print_mid_priority_highlighted(maxY,maxX);
        } 
        else if (highlight == high_priority){
            // function in ui.h
            print_high_priority_highlighted(maxY,maxX);
        }

        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highlight ++;
            if( highlight > 1)
                highlight = 0;
            break;
        
        case KEY_LEFT:
            highlight --;
            if( highlight < 0)
                highlight = 1;
            
            break;
        
        case 10:
        case 13:
            if (highlight == mid_priority){
                char mid[3] = "mid";
                strcpy( report->priority, mid);
                return mid_priority;
            } 

            else if (highlight == high_priority){
                char high[4] = "high";
                strcpy( report->priority, high);
                return high_priority;
            }
            
        default:
            break;
        }
    }
}

void save_time(struct Reports *report){
    //save the current time and date in struct field
    time_t t ;
    time(&t);
    report->time = t;
}
    
void save_struct_report_in_file(struct Reports *report){
    
    FILE *report_data = fopen("report_data.dat", "r");
    FILE *temp = fopen("report_temp.dat", "a+");
    
    fwrite(report, sizeof(struct Reports), 1, temp);

    int report_count = get_report_count_from_file(report_data);
    
    struct Reports a;
    
    for(int i = 0; i < report_count; i++)
    {
        fread(&a, sizeof(struct Reports), 1, report_data);
        fwrite(&a, sizeof(struct Reports), 1, temp);
    }

    fclose(temp);
    fclose(report_data);
    
    rename("report_temp.dat", "report_data.dat");
}
    
int get_report_count_from_file(FILE *report_data){
    fseek(report_data, 0, SEEK_END);
    long int pos = ftell(report_data);
    int report_count =(int) (pos/sizeof(struct Reports));
    fseek(report_data, 0, SEEK_SET); 
    return report_count;
}

void inbox_handle(int maxY, int maxX, char* username){
    
    inbox_ui(maxY, maxX);
    
    read_reports_from_file_and_print(maxY,maxX,username);

    inbox_ui(maxY, maxX);
    int ch = getch();
    if(ch != KEY_RIGHT && ch != KEY_LEFT && ch!=27){
        delete_or_edit(maxY,maxX,username);
        getch();
        normal_user_cartable_ui(maxY,maxX, username);
    }
}

void read_reports_from_file_and_print(int maxY, int maxX, char* username){
    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);
    struct Reports all_users;
    int line = 0;
    //int credit = 0;
    credit_appearence(maxY,maxX,username);
    if (access("report_data.dat", F_OK) == 0){
    for(int i = 0; i<count; i++){
        fread(&all_users, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_users.username , username) == 0 && strcmp( all_users.accept , "pending") == 0){
            mvprintw(17+line,maxX/8-10,"%s",all_users.tag);
            mvprintw(17+line,maxX/8*2-8,"%s",all_users.title);
            mvprintw(17+line,maxX/8*4-10,"%s",ctime(&all_users.time));
            mvprintw(17+line,maxX/8*5-3,"%s",all_users.accept);
            mvprintw(18+line,0,"         ");   
            line += 2;
        }
    }
    fclose(report_data);
    
    }
    else{
        mvprintw(maxY/2,maxX/2-strlen("No reports yet!"), "No reports yet!");
        normal_user_cartable(maxY, maxX, username);

    }
}

void credit_appearence(int maxY, int maxX, char* username){
    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);
    struct Reports all_users;
    int credit = 0;
    for(int i = 0; i<count; i++){
        fread(&all_users, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_users.username , username) == 0 ){
            credit = credit + all_users.credit;
            mvprintw(5, maxX/8*7,"%d",credit);   
        }
    }
    fclose(report_data);
}

void delete_or_edit(int maxY, int maxX, char* username){
    
    struct Reports selected_report;

    scan_delete_or_edit_title(maxY, maxX, &selected_report);

    FILE *report_data = fopen("report_data.dat", "r");
    
    int count = get_report_count_from_file(report_data);
    struct Reports all_reports;

    for(int i = 0; i<count; i++){
        fread(&all_reports, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_reports.username , selected_report.username) == 0 && strcmp( all_reports.title , selected_report.title) == 0){
            selected_report = all_reports;
        }
    }
    fclose(report_data);

    int del_or_ed = delete_or_edit_menu(maxY,maxX);
    if (del_or_ed == delete)
        delete_report_handle(selected_report.title);
        
    else if (del_or_ed == edit)
        edit_report_handle(maxY,maxX,selected_report.title,username);
    
}

void scan_delete_or_edit_title(int maxY, int maxX, struct Reports *report){
    char title[50];
    curs_set(1);
    echo();
    mvgetstr(26,maxX/8*7 - 29 , title);   
    strcpy( report->title , title);
    noecho();
    curs_set(0);
}

int delete_or_edit_menu(int maxY,int maxX){

    int highligh = delete;
    int choise;

    while(1){
        if (highligh == delete){
            // function in ui.h
            print_delete_highlighted(maxY, maxX); 
        } 
        else if (highligh == edit){
            // function in ui.h
            print_edit_highlighted(maxY, maxX); 
        }
        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highligh --;
            if( highligh <  delete)
                highligh = edit;
            break;
        
        case KEY_LEFT:
            highligh ++;
            if( highligh >edit)
                highligh =  delete;
            
            break;
        case 10:
        case 13:
            return highligh;
            break;
        default:
            break;
        }
    }
}

void delete_report_handle(char title [50]){

    FILE *report_data = fopen("report_data.dat", "r");
    FILE *temp = fopen("report_temp.dat", "a+");

    int report_count = get_report_count_from_file(report_data);
    
    struct Reports a;

    for(int i = 0; i < report_count; i++)
    {
            fread(&a, sizeof(struct Reports), 1, report_data);
            if( strcmp(a.title, title )==0 ){}

            else{
                fwrite(&a, sizeof(struct Reports), 1, temp);
            }      
    }

    fclose(temp);

    rename("report_temp.dat", "report_data.dat");
    
    fclose(report_data);
}

void edit_report_handle(int maxY, int maxX, char title [50],char* username){
    clear();
    compose_ui(maxY,maxX);
    
    struct Reports new;

    scan_compose_title(maxY, maxX, &new);

    tag_menu(maxY, maxX, &new);
   
    scan_compose_description(maxY, maxX, &new);

    scan_compose_address(maxY, maxX, &new);

    compose_priority_menu(maxY, maxX, &new);

    print_send_button_active(maxY, maxX);

    save_time(&new);
    
    strcpy (new.username , username);
    strcpy (new.accept , "pending");

    FILE *report_data = fopen("report_data.dat", "r");
    FILE *temp = fopen("report_temp.dat", "a");

    int report_count = get_report_count_from_file(report_data);
    
    struct Reports a;

    for(int i = 0; i<report_count; i++){
        fread(&a, sizeof(struct Reports), 1, report_data);
        if( strcmp(a.title, title) == 0)
            fwrite(&new, sizeof(struct Reports), 1, temp);
        else
        {
            fwrite(&a, sizeof(struct Reports), 1, temp);
        }
        
    }
    

    fclose(temp);
    fclose(report_data);
    rename("report_temp.dat", "report_data.dat");
}

void related_handle(int maxY,int maxX,char* username){
    related_ui(maxY, maxX);
    struct Reports related_report;

    get_number_of_tag_to_search(maxY,maxX,&related_report);

    read_and_print_related_reports(maxY,maxX,&related_report);  

    wrefreshcartable(maxY,maxX);

}

void get_number_of_tag_to_search(int maxY, int maxX, struct Reports *report){
    int i;
    echo();
    curs_set(1);
    mvscanw(17,maxX/2 + strlen("Enter number of the tag you want, to see all reports with that tag: _")/2, "%d", &i);
    noecho();
    curs_set(0);
    if (i == building_permit)
        strcpy( report->tag, "building_permit");
    else if (i == traffic){
        strcpy( report->tag, "traffic");
    }       
    else if (i == bussiness_licence){
        strcpy( report->tag, "bussiness_licence");
    }          
    else if (i == boating){
        strcpy( report->tag, "boating");
    }            
    else if (i == jaywalking){
        strcpy( report->tag, "jaywalking");
    }    
    else if (i == other){
        strcpy( report->tag, "other");
    }

}

void read_and_print_related_reports(int maxY, int maxX, struct Reports *report){
    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);
    struct Reports all_reports;
    int line = 0;
    if (access("report_data.dat", F_OK) == 0){
    for(int i = 0; i<count; i++){
        fread(&all_reports, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_reports.tag , report->tag) == 0){
            mvprintw(maxY/2,maxX/2-3,"         ");
            mvprintw(24+line,maxX/8-10,"              ");
            mvprintw(24+line,maxX/8*2-25,"                           ");
            mvprintw(24+line,maxX/8*3-30,"                                                   ");
            mvprintw(24+line,maxX/8*4-20,"                                                    ");
            mvprintw(24+line,maxX/8*7-15,"                                   ");
            mvprintw(24+line,maxX/8-10,"%s",all_reports.username);
            mvprintw(24+line,maxX/8*2-25,"%s",all_reports.tag);
            mvprintw(24+line,maxX/8*3-30,"%s",all_reports.title);
            mvprintw(24+line,maxX/8*4-20,"%s",all_reports.describtion);
            mvprintw(24+line,maxX/8*7-15,"%s",ctime(&all_reports.time));
            mvprintw(25+line,0,"         ");
            mvprintw(maxY/2,maxX/2-3,"         ");
            refresh();
            line += 2;
        }
    }
    fclose(report_data);
    
    if(line == 0){
        mvprintw(maxY/2,maxX/2-3,"       ");
        mvprintw(maxY/2,maxX/2-strlen("No related reports found!")/2, "No related reports found!");
    }
        
    
    }
    else{
        mvprintw(maxY/2,maxX/2-strlen("No reports yet!"), "No reports yet!");

    }
    if (getch()){
        mvprintw(maxY/2,maxX/2-strlen("No related reports found!")/2, "                             ");
        wrefreshcartable(maxY,maxX);
    }
        
}

void user_history_handle(int maxY, int maxX, char* username){
    history_ui(maxY,maxX);
    mvprintw(14,maxX/8*2+25,"describtion / reason to reject");
    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);

    struct Reports all_users;

    int line = 0;
    int credit = 0;

    for(int i = 0; i<count; i++){
        fread(&all_users, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_users.accept , "pending") == 0){}
        else if(strcmp(all_users.username, username) == 0)
        {
            mvprintw(17+line,maxX/8-8,"%s",all_users.username);
            mvprintw(17+line,maxX/8+4,"%s",all_users.tag);
            mvprintw(17+line,maxX/8*2+6,"%s",all_users.title);
            mvprintw(17+line,maxX/8*2+20,"%s",all_users.address_or_reason);
            mvprintw(17+line,maxX/8*5,"%s",all_users.priority);
            mvprintw(17+line,maxX/8*6-10,"%s",ctime(&all_users.time));
            mvprintw(17+line,maxX/8*7,"%s",all_users.accept);
            mvprintw(18+line,0,"         ");   
            line += 2;
        }
    }
    fclose(report_data);
    
}
/*****************************************/

/**** Admin Cartable Functions *****/
void admin_cartable(int maxY, int maxX){

    admin_cartable_ui(maxY,maxX);
    
    admin_cartable_menu(maxY,maxX);
    
    
}

void admin_cartable_menu(int maxY, int maxX){

    // highlight values :   inbox 0
    //                      history 1
    int highlight = 0;
    int choise;
    while(1){
        if (highlight == inbox){
            clear();
            admin_cartable_ui(maxY,maxX);
            wrefreshcartable(maxY,maxX);
            print_admin_inbox_highlighted(maxY, maxX);
            admin_inbox_handle(maxY,maxX);
            
        } 
        else if (highlight == 1){
            clear();
            admin_cartable_ui(maxY,maxX);
            wrefreshcartable(maxY,maxX);
            print_admin_history_highlighted(maxY, maxX);
            admin_history_handle(maxY,maxX);
        }

        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highlight ++;
            if( highlight > 1)
                highlight = 0;
            break;
        
        case KEY_LEFT:
            highlight --;
            if( highlight < 0)
                highlight = 1;
            
            break;
                
        default:
            break;
        }
    }

}

void admin_inbox_handle(int maxY, int maxX){
    
    admin_inbox_ui(maxY, maxX);
    read_all_reports_and_print_admin(maxY,maxX);

    int ch = getch();
    if(ch != KEY_RIGHT && ch != KEY_LEFT && ch!=27)
        reject_or_accept(maxY,maxX);

}

void read_all_reports_and_print_admin(int maxY,int maxX){
    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);
    struct Reports all_reports;
    int line = 0;
    if (access("report_data.dat", F_OK) == 0){
    for(int i = 0; i<count; i++){
        fread(&all_reports, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_reports.accept , "pending") == 0 && strcmp(all_reports.priority, "high") == 0){
            mvprintw(17+line,maxX/8-10,"%s",all_reports.username);
            mvprintw(17+line,maxX/8*2-22,"%s",all_reports.title);
            mvprintw(17+line,maxX/8*4-42,"%s",all_reports.describtion);
            mvprintw(18+line,0,"         ");
            refresh();
            line += 3;
        }
    }
    fseek(report_data, SEEK_SET,0);
    for(int i = 0; i<count; i++){
        fread(&all_reports, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_reports.accept , "pending") == 0 && strcmp(all_reports.priority, "mid") == 0){
            mvprintw(17+line,maxX/8-10,"%s",all_reports.username);
            mvprintw(17+line,maxX/8*2-22,"%s",all_reports.title);
            mvprintw(17+line,maxX/8*4-42,"%s",all_reports.describtion);
            mvprintw(18+line,0,"         ");
            
            refresh();
            line += 3;
        }
    }
    mvprintw(19+line,0,"         ");
    fclose(report_data);
    }
    else{
        mvprintw(maxY/2,maxX/2-strlen("No reports yet!"), "No reports yet!");
    }
}

void reject_or_accept(int maxY,int maxX){
    
    struct Reports selected_report;

    scan_accept_or_reject_title(maxY, maxX, &selected_report);

    FILE *report_data = fopen("report_data.dat", "r");
    
    int count = get_report_count_from_file(report_data);
    struct Reports all_reports;
    
    for(int i = 0; i<count; i++){
        fread(&all_reports, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_reports.title , selected_report.title) == 0){
            strcpy( selected_report.username, all_reports.username);
            strcpy( selected_report.tag, all_reports.tag);
            strcpy( selected_report.describtion, all_reports.describtion);
            selected_report.credit= all_reports.credit;
            strcpy( selected_report.address_or_reason, all_reports.address_or_reason);
            strcpy( selected_report.priority, all_reports.priority);
        }
    }
    fclose(report_data);

    int accept_or_reject = accept_or_reject_menu(maxY,maxX);
    if (accept_or_reject == 0)
        accept_report_handle(maxY,maxX,selected_report);
        
    else if (accept_or_reject == 1)
        reject_report_handle(maxY,maxX,selected_report);
}

void scan_accept_or_reject_title(int maxY, int maxX, struct Reports *report){
    char title[50];
    curs_set(1);
    echo();
    mvgetstr(22,maxX/8*7 - 30 , title);   
    strcpy( report->title , title);
    noecho();
    curs_set(0);
}

int accept_or_reject_menu(int maxY, int maxX){
    int highligh = accept;
    int choise;

    while(1){
        if (highligh == accept){
            // function in ui.h
            print_accept_highlighted(maxY, maxX); 
        } 
        else if (highligh == reject){
            // function in ui.h
            print_reject_highlighted(maxY, maxX); 
        }
        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highligh ++;
            if( highligh >  reject)
                highligh = accept;
            break;
        
        case KEY_LEFT:
            highligh --;
            if( highligh <accept)
                highligh =  reject;
            
            break;
        case 10:
        case 13:
            return highligh;
            break;
        default:
            break;
        }
    }
}

void accept_report_handle(int maxY, int maxX, struct Reports report){

    accept_ui(maxY,maxX);
    strcpy(report.accept,"accepted");
    scan_credit_value(maxY,maxX,&report.credit);
    save_time(&report);

    FILE *report_data = fopen("report_data.dat", "r");
    FILE *temp = fopen("report_temp.dat", "a+");

    int report_count = get_report_count_from_file(report_data);
    
    struct Reports a;

    for(int i = 0; i < report_count; i++)
    {
        fread(&a, sizeof(struct Reports), 1, report_data);
        if (!strcmp(a.title, report.title))
        { 
            fwrite(&report, sizeof(struct Reports), 1, temp);

        }
            
        else
        {
            fwrite(&a, sizeof(struct Reports), 1, temp);
        }
    }

    fclose(temp);
    fclose(report_data);
    rename("report_temp.dat", "report_data.dat");

}

void scan_credit_value(int maxY,int maxX,int* credit){  
    move(37,maxX/8*7-1);
    curs_set(1);
    echo();
    scanw("%d",credit );
    noecho();
    curs_set(0);
}

void reject_report_handle(int maxY, int maxX, struct Reports report){
   
    reject_ui(maxY,maxX);
   
    strcpy(report.accept,"rejected");
    scan_reason_to_reject(maxY,maxX,&report);
    save_time(&report);

    FILE *report_data = fopen("report_data.dat", "r");
    FILE *temp = fopen("report_temp.dat", "a+");

    int report_count = get_report_count_from_file(report_data);
    
    struct Reports a;
    int count = 0;

    for(int i = 0; i < report_count; i++)
    {
        fread(&a, sizeof(struct Reports), 1, report_data);
        if (!strcmp(a.title, report.title)) 
            fwrite(&report, sizeof(struct Reports), 1, temp);
            
        else
        {
            fwrite(&a, sizeof(struct Reports), 1, temp);
        }
    }

    fclose(temp);
    fclose(report_data);
    rename("report_temp.dat", "report_data.dat");

    int block = block_menu(maxY,maxX);
    if (block==1)
        block_handle(report);
}

void scan_reason_to_reject(int maxY,int maxX,struct Reports *report){
    char reason[50];
    curs_set(1);
    echo();
    mvgetstr(37,maxX/8*7-41 , reason);   
    strcpy( report->address_or_reason , reason);
    noecho();
    curs_set(0);
}

int block_menu(int maxY,int maxX){
    int highligh = 1;
    int choise;

    while(1){
        if (highligh == 1){
            // function in ui.h
            print_block_highlighted(maxY, maxX); 
        } 
        else if (highligh == 0){
            // function in ui.h
            print_skip_highlighted(maxY, maxX); 
        }
        choise = getch();
        switch (choise)
        {
        case KEY_RIGHT:
            highligh ++;
            if( highligh >  0)
                highligh = 1;
            break;
        
        case KEY_LEFT:
            highligh --;
            if( highligh <1)
                highligh =  0;
            
            break;
        case 10:
        case 13:
            return highligh;
            break;
        default:
            break;
        }
    }
}

void block_handle(struct Reports report){
    FILE *users = fopen("user-info.dat","r");

    int size_of_struct = (int) sizeof(struct User_info);
    int user_count = get_users_count_from_file(users, size_of_struct);
    struct User_info registered_user;
    struct User_info block_user;
    for (int i = 0; i < user_count ; i++ ){
        fread (&registered_user, sizeof(struct User_info), 1, users) ;  
        if (strcmp(registered_user.username,report.username)==0 && registered_user.block==1){
            mvprintw(47,144,"You have already blocked this user.");
        }  
        else if (strcmp(registered_user.username,report.username)==0){
            strcpy(block_user.username,registered_user.username) ;
            strcpy(block_user.password,registered_user.password) ;
            strcpy(block_user.national_code,registered_user.national_code) ;
            block_user.admin_or_normal=registered_user.admin_or_normal ;
            block_user.block=1;
            mvprintw(47,149,"Blocked succesfully.");
            break;
        }
    }

    FILE *temp_users = fopen("temp-user-info.dat","a");
    fseek(users,0,SEEK_SET);
    struct User_info new;
    for (int i = 0; i < user_count ; i++ ){
        fread (&new, sizeof(struct User_info), 1, users) ;  
        if (strcmp(new.username,block_user.username)==0){
            fwrite(&block_user,sizeof(struct User_info),1,temp_users);
        }  
        else{
            fwrite(&new,sizeof(struct User_info),1,temp_users);
        }
    }
    
    fclose(users);
    fclose(temp_users);
    rename("temp-user-info.dat", "user-info.dat");

}

void admin_history_handle(int maxY,int maxX){

    history_ui(maxY,maxX);

    FILE *report_data = fopen("report_data.dat", "r");
    int count = get_report_count_from_file(report_data);

    struct Reports all_users;

    int line = 0;
    int credit = 0;

    for(int i = 0; i<count; i++){
        fread(&all_users, sizeof(struct Reports), 1, report_data);
        if(strcmp( all_users.accept , "pending") == 0){}
        else
        {
            mvprintw(17+line,maxX/8-8,"%s",all_users.username);
            mvprintw(17+line,maxX/8+4,"%s",all_users.tag);
            mvprintw(17+line,maxX/8*2+6,"%s",all_users.title);
            mvprintw(17+line,maxX/8*2+20,"%s",all_users.describtion);
            mvprintw(17+line,maxX/8*5,"%s",all_users.priority);
            mvprintw(17+line,maxX/8*6-10,"%s",ctime(&all_users.time));
            mvprintw(17+line,maxX/8*7,"%s",all_users.accept);
            mvprintw(18+line,0,"         ");   
            line += 2;
        }
    }
    fclose(report_data);
}