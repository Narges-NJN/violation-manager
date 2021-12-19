
//******** first pages *********//

//******** welcome ui ********//
void print_welcome(int y, int x){
    mvprintw(y  ,x," ___      ___        __  ");
    mvprintw(y+1,x,"/   \\    /   \\ ____ |  |    ____   ____    _____   ____  ");
    mvprintw(y+2,x,"\\    \\/\\/    // __ \\|  |   / ___\\ / __ \\  /     \\ / __ \\");
    mvprintw(y+3,x," \\          / \\  __/|  |__ \\ \\___( <__> )/  Y Y  \\\\  __/ ");
    mvprintw(y+4,x,"  \\___/\\___/   \\___ |_____/ \\___/ \\____/ \\__|_|__/ \\___   ");
    mvprintw(y+5,x,"                                                       ");
    refresh();
}

void welcome_screen_ui(int maxY, int maxX){
    print_welcome(maxY/8, maxX/2-30);
    box(stdscr,0,0);
    mvprintw(maxY/2, maxX/2-strlen("Do you have acount?")/2,"Do you have account?");
    mvprintw(maxY/2+2, maxX/2-strlen("Yes"),"Yes");
    mvprintw(maxY/2+2, maxX/2+strlen(" No ")," No ");
    refresh();
}

//********** login ui **********//
void print_login(int maxY, int maxX){
    mvprintw(maxY  , maxX, "  _                   _         ");
    mvprintw(maxY+1, maxX, " | |                 (_)        ");
    mvprintw(maxY+2, maxX, " | |   ___     __ _   _   _ ___  ");
    mvprintw(maxY+3, maxX, " | |  / _ \\   / _` | | | | '_  \\ ");
    mvprintw(maxY+4, maxX, " | | | (_) | | (_| | | | | | | |");
    mvprintw(maxY+5, maxX, " |_|  \\___/   \\__, | |_| |_| |_|");
    mvprintw(maxY+6, maxX, "               __/ |            ");
    mvprintw(maxY+7, maxX, "              |___/             ");
    refresh();
}

void login_page_ui(int maxY, int maxX){
    WINDOW *login;                                              
    login = newwin(maxY/2, maxX/4 , maxY/4 , maxX/2-maxX/8);           
    refresh();                                              
    box(login, 0, 0);                                           
    wrefresh(login); 
    print_login(maxY/10, maxX/2-16);
    mvprintw( maxY/3, maxX/2 - 15 , "User Name:");
    mvprintw( maxY/2, maxX/2 - 15 , "Password:");
}

//******* sign up ui **********//
void print_signup(int maxY, int maxX){
    mvprintw(maxY  , maxX, "       _                              ");
    mvprintw(maxY+1, maxX, "      (_)                             ");
    mvprintw(maxY+2, maxX, "  ___  _   __ _  _ __    _   _  _ __  ");
    mvprintw(maxY+3, maxX, " / __|| | / _` || '_ \\  | | | || '_ \\ ");
    mvprintw(maxY+4, maxX, " \\__ \\| || (_| || | | | | |_| || |_) |");
    mvprintw(maxY+5, maxX, " |___/|_| \\__, ||_| |_|  \\__,_|| .__/ ");
    mvprintw(maxY+6, maxX, "           __/ |               | |    ");
    mvprintw(maxY+7, maxX, "          |___/                |_|    ");
    refresh();
}

void print_yes_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw(maxY/2+2, maxX/2-strlen(" Yes ")," Yes ");
    attroff( A_REVERSE );
    mvprintw(maxY/2+2, maxX/2+strlen(" No ")," No ");
}

void print_no_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw(maxY/2+2, maxX/2+strlen(" No ")," No ");
    attroff( A_REVERSE );
    mvprintw(maxY/2+2, maxX/2-strlen(" Yes ")," Yes ");
    refresh();
}

void signup_page_ui(int maxY, int maxX){
    clear();
    WINDOW *signup;                                              
    signup = newwin(maxY/1.5, maxX/4 , maxY/4 , maxX/2-maxX/8);           
    refresh();                                              
    box(signup, 0, 0);                                           
    wrefresh(signup); 
    print_signup(maxY/10, maxX/2-19);
    mvprintw( maxY/3, maxX/2 - 15 , "National Code:");
    mvprintw( maxY/2.3, maxX/2 - 15 , "User Name:");
    mvprintw( maxY/1.9, maxX/2 - 15 , "Password:");
    mvprintw( maxY/1.5, maxX/2 - strlen("Admin or Normal user?")/2 , "Admin or Normal user?");
    mvprintw( maxY/1.4, maxX/2 - 12 , " Admin ");
    mvprintw( maxY/1.4, maxX/2 + 2 , " Normal user ");
    refresh();
}

void print_admin_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw( maxY/1.4, maxX/2 - 12 , " Admin ");
    attroff( A_REVERSE );
    mvprintw( maxY/1.4, maxX/2 + 2 , " Normal user ");
}

void print_normal_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw( maxY/1.4, maxX/2 + 2 , " Normal user ");
    attroff( A_REVERSE );
    mvprintw( maxY/1.4, maxX/2 - 12 , " Admin ");
    refresh();
}

//******* end of first pages ********//


//******* cartable ui *********//
void print_cartable(int maxY, int maxX){
    mvprintw(maxY  , maxX, "                        _             _       _        ");
    mvprintw(maxY+1, maxX, "                       | |           | |     | |       ");
    mvprintw(maxY+2, maxX, "   ___    __ _   _ __  | |_    __ _  | |__   | |   ___ ");
    mvprintw(maxY+3, maxX, "  / __|  / _` | | '__| | __|  / _` | | '_ \\  | |  / _ \\");
    mvprintw(maxY+4, maxX, " | (__  | (_| | | |    | |_  | (_| | | |_) | | | |  __/");
    mvprintw(maxY+5, maxX, "  \\___|  \\__,_| |_|     \\__|  \\__,_| |_.__/  |_|  \\___|");
    mvprintw(maxY+6, maxX, "                                                       ");
    refresh();
}
void wrefreshcartable(int maxY, int maxX){
    WINDOW *user_cartable ;
    user_cartable = newwin( maxY-14, maxX/8*7+2, 12, maxX/8-13);
    box(user_cartable,0,0);
    wrefresh(user_cartable);
}
void normal_user_cartable_ui(int maxY, int maxX, char* username){
    clear();

    print_cartable(1, maxX/2-27);

    wrefreshcartable(maxY, maxX);
    
    mvprintw(10.9,   maxX/8 - strlen("          inbox           ")/2, "          inbox           ");
    mvprintw(10.9, maxX/8*3 - strlen("         compose          ")/2, "         compose          ");
    mvprintw(10.9, maxX/8*5 - strlen("         history          ")/2, "         history          ");
    mvprintw(10.9, maxX/8*7 - strlen("         related          ")/2, "         related          ");

    mvprintw(5, maxX/8 - 13, "username: ");
    mvprintw(5, maxX/8 , "%s", username);
    mvprintw(5, maxX/8*7 -9, "credit: ");

    mvprintw(maxY-2,maxX/8-13, "- ctrl+c to exit");
}

void print_inbox_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw(  9.9,  maxX/8 - strlen("                          ")/2, "                          ");
    mvprintw( 10.9,  maxX/8 - strlen("          inbox           ")/2, "          inbox           ");
    mvprintw( 11.9,  maxX/8 - strlen("                          ")/2, "                          ");
    attroff( A_REVERSE );

    mvprintw( 9.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*3 - strlen("         compose          ")/2, "         compose          ");
    mvprintw(11.9, maxX/8*3 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8*5 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*5 - strlen("         history          ")/2, "         history          ");
    mvprintw(11.9, maxX/8*5 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8*7 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*7 - strlen("         related          ")/2, "         related          ");
    mvprintw(11.9, maxX/8*7 - strlen("                          ")/2, "                          ");
}

void print_compose_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw( 9.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*3 - strlen("         compose          ")/2, "         compose          ");
    mvprintw(11.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    attroff( A_REVERSE );

    mvprintw( 9.9, maxX/8*5 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*5 - strlen("         history          ")/2, "         history          ");
    mvprintw(11.9, maxX/8*5 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8*7 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*7 - strlen("         related          ")/2, "         related          ");
    mvprintw(11.9, maxX/8*7 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8 - strlen("          inbox           ")/2, "          inbox           ");
    mvprintw(11.9, maxX/8 - strlen("                          ")/2, "                          ");
}

void print_history_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw( 9.9, maxX/8*5 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*5 - strlen("         history          ")/2, "         history          ");
    mvprintw(11.9, maxX/8*5 - strlen("                          ")/2, "                          ");
    attroff( A_REVERSE );

    mvprintw( 9.9, maxX/8*7 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*7 - strlen("         related          ")/2, "         related          ");
    mvprintw(11.9, maxX/8*7 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*3 - strlen("         compose          ")/2, "         compose          ");
    mvprintw(11.9, maxX/8*3 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8 - strlen("          inbox           ")/2, "          inbox           ");
    mvprintw(11.9, maxX/8 - strlen("                          ")/2, "                          ");
}

void print_related_highlighted(int maxY, int maxX){
    attron( A_REVERSE );
    mvprintw( 9.9, maxX/8*7 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*7 - strlen("         related          ")/2, "         related          ");
    mvprintw(11.9, maxX/8*7 - strlen("                          ")/2, "                          ");
    attroff( A_REVERSE );

    mvprintw( 9.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*3 - strlen("         compose          ")/2, "         compose          ");
    mvprintw(11.9, maxX/8*3 - strlen("                          ")/2, "                          ");
    
    mvprintw( 9.9, maxX/8*5 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8*5 - strlen("         history          ")/2, "         history          ");
    mvprintw(11.9, maxX/8*5 - strlen("                          ")/2, "                          ");

    mvprintw( 9.9, maxX/8 - strlen("                          ")/2, "                          ");
    mvprintw(10.9, maxX/8 - strlen("          inbox           ")/2, "          inbox           ");
    mvprintw(11.9, maxX/8 - strlen("                          ")/2, "                          ");
}


void printinbox( int maxY ,int maxX){
    mvprintw(maxY/2,maxX/2-3," inbox ");
   
}
void printcompose( int maxY ,int maxX){
    mvprintw(maxY/2,maxX/2-3,"compose");
}
void printrelated( int maxY ,int maxX){
    mvprintw(maxY/2,maxX/2-3,"related");
   
}
void printhistory( int maxY ,int maxX){
    mvprintw(maxY/2,maxX/2-3,"history");
   
}

//******* compose ui *********//
void compose_ui(int maxY,int maxX){
    mvprintw(maxY/2,maxX/2-3,"        ");
    mvprintw(14,maxX/8-3, "Please fill the information below.");
    mvprintw(14,maxX/2 - strlen("Press Enter to start typing")/2, "Press Enter to start typing");

    mvprintw(18,maxX/8-3, "Voilation Title:");
    WINDOW *title_field;
    title_field = newwin( 3, 125, 17, maxX/8+15);
    box(title_field,0,0);
    
    mvprintw(18, maxX/8+141, "MAX 50 chars");
    
    refresh();
    wrefresh(title_field);
    mvprintw(18,maxX/8+136, "/50");

    mvprintw(22, maxX/8-3, "Choose a tag for your report from the list of most common violations.");
    mvprintw(24, maxX/8-3, "Violation Tag:");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen ("  building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");

    mvprintw(28, maxX/8-3, "Describe the violation in detail please:" );
    mvprintw(28, maxX/8+141, "MAX 300 chars");

    WINDOW *describtion_field;
    describtion_field = newwin( 8, 158, 30, maxX/8-3);
    box(describtion_field,0,0);
    wrefresh(describtion_field);
    mvprintw(31,maxX/8+150, "/300");

    mvprintw(40, maxX/8-3, "where did the violation happen? (postal address)");
    WINDOW *address_field;
    address_field = newwin( 3, 92, 39, maxX/8-3 + strlen("where did the violation happen? (postal address)")+3);
    box(address_field,0,0);
    mvprintw(40, maxX/8+141, "MAX 20 chars");
    refresh();
    wrefresh(address_field);
    mvprintw(40,maxX/8+136, "/20");

    mvprintw(44, maxX/8-3, "Priority:");
    mvprintw(44, maxX/8-3 + strlen("priority:")+4, "  Mid ");
    mvprintw(44, maxX/8-3 + strlen("priority:")+4 + strlen("  Mid ")+4, " High ");

    mvprintw( 48, maxX/2 - strlen("                         ")/2, "                         ");
    mvprintw( 49, maxX/2 - strlen("          send           ")/2, "          send           ");
    mvprintw( 50, maxX/2 - strlen("                         ")/2, "                         ");


    refresh();
    getch();

}

void print_tag_building_permit_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    
    refresh();
}

void print_tag_traffic_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    
    refresh();
}

void print_tag_bussiness_licence_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    
    refresh();
}

void print_tag_boating_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    
    refresh();
}

void print_tag_jaywalking_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    
    refresh();
}

void print_tag_other_highlighted(int maxY, int maxX){
    
    attron( A_BLINK );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+6, " -");
    attroff( A_BLINK );

    attron( A_REVERSE );
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, " Other ");
    attroff( A_REVERSE );

    mvprintw(24, maxX/8-3+strlen("violation tag:")+10, "  Building permit ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8, " Traffic ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+8, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+6, "  ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8, " Bussiness licence ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, " Boating ");
    mvprintw(24, maxX/8-3+strlen("violation tag:")+10 + strlen (" -building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, " Jaywalking ");
    
    refresh();
}

void print_mid_priority_highlighted(int maxY, int maxX){
    attron( A_BLINK );
    mvprintw(44, maxX/8-3 + strlen("priority:")+2, " -");
    attroff( A_BLINK );
    attron( A_REVERSE );
    mvprintw(44, maxX/8-3 + strlen("priority:")+4, " Mid ");
    attroff( A_REVERSE );   
    mvprintw(44, maxX/8-3 + strlen("priority:")+4 + strlen(" Mid ")+4, " High "); 
    mvprintw(44, maxX/8-3 + strlen("priority:")+2 + strlen(" Mid ")+4, "   ");
}

void print_high_priority_highlighted(int maxY, int maxX){
    attron( A_BLINK );
    mvprintw(44, maxX/8-3 + strlen("priority:")+2 + strlen(" Mid ")+4, " -");
    attroff( A_BLINK );
    attron( A_REVERSE );
    mvprintw(44, maxX/8-3 + strlen("priority:")+4 + strlen(" Mid ")+4, " High ");
    attroff( A_REVERSE );   
    mvprintw(44, maxX/8-3 + strlen("priority:")+4, " Mid "); 
    mvprintw(44, maxX/8-3 + strlen("priority:")+2, "  ");
}

void print_send_button_active(int maxY,int maxX){
    attron( A_REVERSE );
    mvprintw( 48, maxX/2 - strlen("                         ")/2, "                         ");
    attron( A_BLINK );
    mvprintw( 49, maxX/2 - strlen("          send           ")/2, "          send           ");
    attroff( A_BLINK );
    mvprintw( 50, maxX/2 - strlen("                         ")/2, "                         ");
    attroff( A_REVERSE );
}
//******* end of compose ui *********//

//******* inbox ui *********//
void inbox_ui(int maxY, int maxX){
    
    mvprintw(maxY/2,maxX/2-3,"       ");
    mvhline(15, maxX/8-12, '_', 175);
    mvvline(13.3, maxX/8+13, '|', 33);
    mvvline(13.3, maxX/8*4-15, '|', 33);
    mvvline(13.3, maxX/8*5-8, '|', 33);
    mvvline(13.3, maxX/8*5+9, '|', 33);

    mvprintw(14,maxX/8-2, "Tag");
    mvprintw(14,maxX/8*2+10, "Title");
    mvprintw(14,maxX/8*4-2, "Time");
    mvprintw(14,maxX/8*5-2, "State");
    mvprintw(14,maxX/8*7-20, "Delete/Edit");

    mvprintw(18, maxX/8*7-28, "Enter the Title of the report");
    mvprintw(20, maxX/8*7-29, "that you wish to delete or edit");

    mvprintw(26, maxX/8*7-36,"Title:");
    mvprintw(26,maxX/8*7 - 29, "_____________________________________");

    mvprintw(32, maxX/8*7-32, "You wish to dalete this report or edit?");
    mvprintw(36, maxX/8*7-24, " Delete ");
    mvprintw(36, maxX/8*7-10, "  Edit  ");
    refresh();
    
}
void print_delete_highlighted(int maxY,int maxX){
    attron(A_REVERSE);
    mvprintw(36, maxX/8*7-24, " Delete ");
    attroff(A_REVERSE);
    mvprintw(36, maxX/8*7-10, "  Edit  "); 
    refresh();
}
void print_edit_highlighted(int maxY,int maxX){
    attron(A_REVERSE);
    mvprintw(36, maxX/8*7-10, "  Edit  ");
    attroff(A_REVERSE);
    mvprintw(36, maxX/8*7-24, " Delete "); 
    refresh();
}
//******* end of inbox ui *********//

//******* related ui *********//
void related_ui(int maxY,int maxX){
    mvprintw(maxY/2,maxX/2-3,"       ");
    mvprintw(14, maxX/8, "Violation Tags:");
    mvprintw(14, maxX/8+strlen("violation tag:")+10, "1-Building permit ");
    mvprintw(14, maxX/8+strlen("violation tag:")+10 + strlen ("  building permit ") + 8, "2-Traffic ");
    mvprintw(14, maxX/8+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8, "3-Bussiness licence ");
    mvprintw(14, maxX/8+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8, "4-Boating ");
    mvprintw(14, maxX/8+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8, "5-Jaywalking ");
    mvprintw(14, maxX/8+strlen("violation tag:")+10 + strlen ("  building permit ") + 8 + strlen (" traffic ")+8 + strlen (" bussiness licence ")+8 + strlen (" boating ")+8 + strlen (" Jaywalking ")+8, "6-Other ");
    mvprintw(17, maxX/2 - strlen("Enter number of the tag you want, to see all reports with that tag: ___")/2, "Enter number of the tag you want, to see all reports with that tag: ___");
    mvhline(20, maxX/8-12, '_', 175);
}
//***** end of related ui ****//

//****** admin cartable ui *****//
void admin_cartable_ui(int maxY, int maxX){
    clear();
    print_cartable(1, maxX/2-27);
    wrefreshcartable(maxY, maxX);

    mvprintw( 9.9, maxX/8-12.8 , "                                                                                        ");
    mvprintw(10.9, maxX/8-12.8 , "                                         inbox                                          ");
    mvprintw(11.9, maxX/8-12.8 , "                                                                                        ");
    mvprintw( 9.9, maxX/2      , "                                                                                      ");
    mvprintw(10.9, maxX/2      , "                                       history                                        ");
    mvprintw(11.9, maxX/2      , "                                                                                      ");
    refresh();
}
void print_admin_inbox_highlighted(int maxY, int maxX){
    attron(A_REVERSE);
    mvprintw( 9.9, maxX/8-12.8 , "                                                                                        ");
    mvprintw(10.9, maxX/8-12.8 , "                                         inbox                                          ");
    mvprintw(11.9, maxX/8-12.8 , "                                                                                        ");
    attroff(A_REVERSE);
    mvprintw( 9.9, maxX/2      , "                                                                                      ");
    mvprintw(10.9, maxX/2      , "                                       history                                        ");
    mvprintw(11.9, maxX/2      , "                                                                                      ");
}
void print_admin_history_highlighted(int maxY, int maxX){
    
    attron(A_REVERSE);
    mvprintw( 9.9, maxX/2      , "                                                                                      ");
    mvprintw(10.9, maxX/2      , "                                       history                                        ");
    mvprintw(11.9, maxX/2      , "                                                                                      ");
    attroff(A_REVERSE);
    mvprintw( 9.9, maxX/8-12.8 , "                                                                                        ");
    mvprintw(10.9, maxX/8-12.8 , "                                         inbox                                          ");
    mvprintw(11.9, maxX/8-12.8 , "                                                                                        ");
}

void admin_inbox_ui(int maxY, int maxX){
    mvhline(15, maxX/8-12, '_', 175);
    mvvline(13.3, maxX/8 , '|', 33);
    mvvline(13.3, maxX/8*2+5, '|', 33);

    mvprintw(14,maxX/8-10, "Username");
    mvprintw(14,maxX/8+10, "Title");
    mvprintw(14,maxX/8*4-16, "Describtion");

    WINDOW *response;
    response = newwin( maxY-14, maxX/8*2+9,12 ,maxX/8*5+5 );
    box(response,0,0);
    wrefresh(response);
   
    mvprintw( 14,maxX/8*7-22, "Accept/Reject");
    mvprintw( 18, maxX/8*7-30, "Enter the Title of the report");

    mvprintw(22, maxX/8*7-38,"Title:");
    mvprintw(22,maxX/8*7 - 31, "_____________________________________");

    mvprintw(25, maxX/8*7-34, "You wish to accept this report or reject?");
    mvprintw(27, maxX/8*7-26, " Accept ");
    mvprintw(27, maxX/8*7-12, " Reject ");
    
    refresh();
}
void print_accept_highlighted(int maxY,int maxX){
    attron(A_REVERSE);
    mvprintw(27, maxX/8*7-26, " Accept ");
    attroff(A_REVERSE);
    mvprintw(27, maxX/8*7-12, " Reject ");
    refresh();
}
void print_reject_highlighted(int maxY,int maxX){
    mvprintw(27, maxX/8*7-26, " Accept ");
    attron(A_REVERSE);
    mvprintw(27, maxX/8*7-12, " Reject ");
    attroff(A_REVERSE);
    refresh();
}
void reject_ui(int maxY,int maxX){
    mvprintw(34,maxX/8*7-30,"What is the reason to reject?");
    mvprintw(37,maxX/8*7-42, "_____________________________________________________");
    mvprintw(43,maxX/8*7-32, "Do you also wish to block this user?");
    mvprintw(45,maxX/8*7-26, " Block ");
    mvprintw(45,maxX/8*7-12, " Skip ");
}
void accept_ui(int maxY,int maxX){
    mvprintw(34,maxX/8*7-36,"Do you want to give credit to this user?");
    mvprintw(37,maxX/8*7-40, "if Yes type how much credit you give: ________");
    mvprintw(40,maxX/8*7-28, "if No just press enter");
    
}
void print_block_highlighted(int maxY,int maxX){
    attron(A_REVERSE);
    mvprintw(45,maxX/8*7-26, " Block ");
    attroff(A_REVERSE);
    mvprintw(45,maxX/8*7-12, " Skip ");
    refresh();
}
void print_skip_highlighted(int maxY,int maxX){
    attron(A_REVERSE);
    mvprintw(45,maxX/8*7-12, " Skip ");
    attroff(A_REVERSE);
    mvprintw(45,maxX/8*7-26, " Block ");
    refresh();
}
void history_ui(int maxY,int maxX){
    mvprintw(maxY/2,maxX/2-3,"        ");
    mvhline(15.5, maxX/8-12, '_', 175);
    mvprintw(14,maxX/8-10,"username");
    mvprintw(14,maxX/8+10,"tag");
    mvprintw(14,maxX/8*2+6,"title");
    mvprintw(14,maxX/8*2+34,"describtion");
    mvprintw(14,maxX/8*5-2,"priority");
    mvprintw(14,maxX/8*6-6,"time of response");
    mvprintw(14,maxX/8*7+1,"state");
}
//********* end of admin cartable ui *******//


//********* print error fonctions *******//
void print_wrong_pass_error(int maxY,int maxX){
    mvprintw(maxY/2 -2, maxX/2 - strlen("Ronge user name or password!")/2,"Ronge user name or password!");
    mvprintw(maxY/2 + 2, maxX/2 - strlen("Press any key to try again.")/2, "Press any key to try again.");
}

void print_no_account_error(int maxY,int maxX){
    mvprintw(maxY/2 -2, maxX/2 - strlen("You don't have account!")/2,"You don't have account!");
    mvprintw(maxY/2 + 2, maxX/2 - strlen("Press any key to sign up.")/2, "Press any key to sign up.");
}

void print_block_error(int maxY,int maxX){
    mvprintw(maxY/2 -2, maxX/2 - strlen("Unfortunatly you are Blocked!")/2,"Unfortunatly You are Blocked!");
    mvprintw(maxY/2 + 2, maxX/2 - strlen("You can not login any more.")/2, "You can not login any more.");
}

void print_national_code_error(int maxY,int maxX){
    curs_set(0);
    //attron ( COLOR_RED );
    mvprintw(maxY/3+2, maxX/2 - 20, "National code sould a be 10 digit number" );
    //attroff ( COLOR_RED );
    
    refresh();
}

void print_has_account_error(int maxY, int maxX){
    clear();
    mvprintw(maxY/2-2, maxX/2 - strlen("You already have an account!")/2, "You already have an account!");
    mvprintw(maxY/2+2, maxX/2 - strlen("Please press a key to go back")/2, "Please press a key to go back");
    mvprintw(maxY/2+4, maxX/2 - strlen("This time choose Yes and try to login")/2, "This time choose Yes and try to login");
    refresh();
    
}

void print_repeated_code_error(int maxY, int maxX){
    clear();
    mvprintw(maxY/2-2, maxX/2 - strlen("This national code is already registered!")/2, "This national code is already registered!");
    mvprintw(maxY/2+2, maxX/2 - strlen("Please press a key to go back")/2, "Please press a key to go back");
    mvprintw(maxY/2+4, maxX/2 - strlen("You may try again")/2, "You may try again");
    refresh();
}

void print_break_error(int maxY, int maxX){
    mvprintw(maxY/2 -2, maxX/2 - strlen("Application is closed between 12 to 14 pm!")/2,"Application is closed between 12 to 14 pm!");
}