## CS50 FINAL PROJECT
## Organizational application for managing violation reports

### Description:
This is a command line application written in C with text UI using the Ncurses library.
As Ncurses is a unix library, you can only install and run it on unix based OS.

### To run the project you need to install Ncurses.
##### To install Ncurses library(on debian based):
```shell
sudo apt-get install libncurses5-dev libncursesw5-dev
```
##### To compile and run (with gcc compiler which you shold have previously installed):
```shell
gcc core.c -lncurses -o core.out
```
```shell
./core.out
```
### What does the application do:
  Citizens as normal users can submit violation reports with specific tags in specific ctegories, title and description, address of the crime, and priority. All the datas from reports are saved in **Binary files** and loaded to admin panel. So admins can recieve the reports, and accept or reject them. The user will be notified in his or her panel about the state of report(pending, accepted, or rejected). 

### List of features:
- registeration as new user or admin
- repeated user not allowed
- login to user panel or admin panel
- application is closed in specified times of night (by the function: int check_time (), in core.c)

### List of features in normal user's panel:
- **edit** or **delete** reports from inbox.
- **write & submit** new report
- specify **mid or high priority** for all reports so that it will show up with lower or higher priority in admin's panel 
- see the **history** of previous accepted or rejected reports
- find all **related** reports with specific tags that has been submited by other users in the database
- credit gained from admins is shown 

### List of features in normal admin's panel:
- see all user reports with detail in **inbox**
- **accept or reject** reports by their title
- give **credit** to accepted reports
- **block** users with rejected reports so that their accound will not be accesible anymore.
- see the **history** of all answerd reports

### implementation details:
#### - I have developed personal UI library for the project : ui.h
#### - Two Binary File as database
#### - User's and report's datas are stored in Structs
#### - Account states, categories and ... are defined in Enums
#### - I have broke the code into several abstract functions
##### Watch my [Presentation Video](https://youtu.be/X8MXnmaEceY).
