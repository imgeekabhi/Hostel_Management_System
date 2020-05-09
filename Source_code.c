//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//--------------------------------------------------------------------------------------------------------------------
//global variables declaration
int i,j,main_exit;


//functions declaration
void new_records();
void update_records();
void view_records();
void view_stu_rec();
void remove_records();
void about();
void close();

//--------------------------------------------------------------------------------------------------------------------

//defining structures

struct date
{
    int day,month,year;
};
struct
{
    char roll_no[10];
    char name[60];
    int age;
    char gender[10];
    struct date dob;
    char mob_no[15];
    char mail_id[30];
    char adhar_no[13];
    char city[60];
    char father_name[60];
    char father_mob[20];
    char hostel_name[20];
    char room_no[10];
}add,upd,view,check,del;
//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{
	login();
    main_menu();
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------
//login page

int login(void)
{
   int a=0,i=0;
    char u_name[10],c=' ';
    char p_word[10];
    char admin[10]="admin";
    char password[10]="admin123";
    do
{
	system("cls");

    printf("\n############################  LOGIN PAGE  #############################\n");
    printf("%c",201); for(int i=1 ; i<70 ; i++){printf("%c",205);} printf("%c\n",187);
    printf("\n                         ENTER USERNAME:-",186);
	scanf("%s", &u_name);
	printf("\n                         ENTER PASSWORD:-",186);
	while(i<10)
	{
	    p_word[i]=getch();
	    c=p_word[i];
	    if(c==13)
            break;
	    else
            printf("*");
	    i++;
	}
	p_word[i]='\0';

	i=0;

		if(strcmp(u_name,admin)==0 && strcmp(p_word,password)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN SUCCESSFULLY\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  WRONG USERNAME OR PASSWORD\n");
		system("PAUSE");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong Username OR Password for four times!!!!!");

		getch();

		}
		system("CLS");
}

//--------------------------------------------------------------------------------------------------------------------
//main menu


void main_menu()
{
    int choice;

    system("CLS");
    printf("\n\n\t\t\tLNCT HOSTEL MANAGEMENT SYSTEM\n");
    printf("\n\tNOTE : please use underscore(_) in place of <white space>");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1> Enter new Student's Data");
    printf("\n\n\t\t2> Update information of existing student");
    printf("\n\n\t\t3> View all Students of a particular Hostel");
    printf("\n\n\t\t4> View record of particular student");
    printf("\n\n\t\t5> Remove existing record of student");
    printf("\n\n\t\t6> About project maker");
    printf("\n\n\t\t7> Exit");
    printf("\n\n\n\t\t*  Enter your choice:-");

    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_records(); break;
        case 2:update_records(); break;
        case 3:view_records(); break;
        case 4:view_stu_rec(); break;
        case 5:remove_records(); break;
        case 6:about(); break;
        case 7:close(); break;
        default:main_menu();
    }
}

//------------------------------------------------------------------------------------------------------------------

//new entry function
void new_records()
{
    system("CLS");
    FILE *fp;
    fp=fopen("student_record.dat","a+");
    if(fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\tNOTE : please use underscore(_) in place of <white space>\n\n");
    printf("\nEnter Roll Number:");
    scanf("%s",add.roll_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter Gender [Male,Female,Others]");
    scanf("%s",add.gender);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the mobile number: ");
    scanf("%s",add.mob_no);
    printf("\n Enter your E-Mail id :");
    scanf("%s",add.mail_id);
    printf("\nEnter Aadharcard Number:");
    scanf("%s",add.adhar_no);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%s",add.father_mob);
    printf("\n Enter your hostel name from (RATANPUR) OR (TRIPURI) :");
    scanf("%s",add.hostel_name);
    printf("\n Enter your room no.:");
    scanf("%s",add.room_no);



    fprintf(fp,"\n%s ",add.roll_no);
    fprintf(fp,"%s ",add.name);
    fprintf(fp,"%d ",add.age);
    fprintf(fp,"%s ",add.gender);
    fprintf(fp,"%d/%d/%d ",add.dob.day,add.dob.month,add.dob.year);
    fprintf(fp,"%s ",add.mob_no);
    fprintf(fp,"%s ",add.mail_id);
    fprintf(fp,"%s ",add.adhar_no);
    fprintf(fp,"%s ",add.city);
    fprintf(fp,"%s ",add.father_name);
    fprintf(fp,"%s ",add.father_mob);
    fprintf(fp,"%s ",add.hostel_name);
    fprintf(fp,"%s ",add.room_no);



    if(strcmp(add.hostel_name,"RATANPUR")==0 || strcmp(add.hostel_name,"ratanpur")==0)
    {
        FILE *hostel;
        hostel=fopen("Ratanpur.dat","a+");
        if(hostel==NULL)
        {
        printf("File not found");
        exit(1);}

		fprintf(hostel, "\n%s  %s", add.roll_no,add.name);
		fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"TRIPURI")==0 || strcmp(add.hostel_name,"tripuri")==0)
    {
     FILE *hostel;
     hostel=fopen("Tripuri.dat","a+");
     if(hostel==NULL)
     {
        printf("File not found");
        exit(1);
     }
     fprintf(hostel, "\n%s  %s", add.roll_no,add.name);
     fclose(hostel);
    }
    fclose(fp);
    printf("\nStudent Record added successfully!!!");

    add_invalid:
    printf("\n\n\n\tEnter 1 to go to the main menu \n\tEnter 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
        main_menu();

    else if(main_exit==0)
        close();

    else
    {
            printf("\nInvalid!\a");
            goto add_invalid;
    }

}

//--------------------------------------------------------------------------------------------------------------------

//function to update student info

void update_records()
{
	system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("student_record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",upd.roll_no);
    while(fscanf(old,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, &add.age, add.gender, &add.dob.day, &add.dob.month, &add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no)!=EOF)

    {
        if (strcmp(add.roll_no,upd.roll_no)==0)
        {   test=1;
            printf("\nWhich information do you want to update?\n1.Student Name\n2.Gender\n3.Mail-ID\n4.Mobile no.\n5.Father's Mobile no.\n6.Room no.\n\nEnter your choice:");
            scanf("%d",&choice);


            if(choice==1)
                {
                printf("Enter the correct student name:");
                scanf("%s",upd.name);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, upd.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
                printf("Changes saved!");
                }

            else if(choice==2)
                {
                printf("Enter the correct Gender:");
                scanf("%s",upd.gender);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, upd.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
                printf("Changes saved!");
                }

            else if(choice==3)
                {
                printf("Enter the correct Mail-ID:");
                scanf("%s",upd.mail_id);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, upd.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
                printf("Changes saved!");
                }

            else if(choice==4)
                {
                printf("Enter the new mobile number:");
                scanf("%s",upd.mob_no);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, upd.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
                printf("Changes saved!");
                }

            else if(choice==5)
                {
                printf("Enter the new father's mobile number:");
                scanf("%s",upd.father_mob);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, upd.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, upd.father_mob, add.hostel_name, add.room_no);
                printf("Changes saved!");
                }

            else if(choice==6)
                {
                printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, upd.room_no);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
    }
    fclose(old);
    fclose(newrec);
    remove("student_record.dat");
    rename("new.dat","student_record.dat");

	if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
		printf("\n\nEnter 0 To try again!!!\nEnter 1 To return main menu \nEnter 2 To exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
			main_menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            update_records( );
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;
        }

}
//--------------------------------------------------------------------------------------------------------------------

//function to display all students of a hostel

void view_records()
{
	system("CLS");
    int choice,test=0;

    printf("\tSelect any one Hostel:\n\n\t1. Ratanapur \n\t2. Tripuri\n\n\tEnter year choice : ");
    scanf("%d",&choice);

    FILE *fp, *hostel;
    switch(choice)
    {
    	case 1: hostel=fopen("Ratanpur.dat","a+");break;
    	case 2: hostel=fopen("Tripuri.dat","a+");break;

    	default: view_records();
    }
    while(fscanf(hostel,"%s\n",check.roll_no)!=EOF)
    {
   	    fp=fopen("student_record.dat","r");
    	while(fscanf(fp,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",view.roll_no, view.name, &view.age, view.gender, &view.dob.day, &view.dob.month, &view.dob.year, view.mob_no, view.mail_id, view.adhar_no, view.city, view.father_name, view.father_mob, view.hostel_name, view.room_no)!=EOF)
    	{
    		if(strcmp(check.roll_no,view.roll_no)==0)
    		{
    			if(test==0)
    			{
    				printf("\n\t\tFollowing is the list of students:");
		            printf("\n\n\t ROLL NO.\t\tNAME\t\tROOM NO.\n");
    			}
    			printf("\n\t%8s\t\t%8s\t%s", view.roll_no, view.name, view.room_no);
           		test++;
    		}
    	}
    }

    fclose(fp);
    if (test==0)
        printf("\nNO RECORDS!!\n");

    view_list_invalid:
    printf("\n\nEnter 1 to go main menu\nEnter 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }

}

//------------------------------------------------------------------------------------------------------------------

//function to view all data of a particular student

void view_stu_rec()
{
	system("CLS");
    FILE *fptr;
    int test=0;
    int choice;
    fptr=fopen("student_record.dat","r");
    printf("\n\n\tCheck student record by:\n\t1.Student Roll no\n\t2.Student Name\n\n\tEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\n\tEnter the roll number of student:");
        scanf("%s",check.roll_no);

        while(fscanf(fptr,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, &add.age, add.gender, &add.dob.day, &add.dob.month, &add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no)!=EOF)
        {
            if(strcmp(add.roll_no,check.roll_no)==0)
            {
                test=1;
                printf("\nRoll no. : %s \nName           : %s \nAge            : %d \nGender         : %s \nDOB            : %d/%d/%d \nMob. no.       : %s\nMail-ID        : %s \nAdhar.no.      : %s \nCity           : %s \nFather's name  : %s \nF's mob. no.   : %s \nHostel Name    : %s \nRoom no.       : %s \n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
            }
        }
    }
    else if (choice==2)
    {   printf("\n\n\tEnter the name of student:");
        scanf("%s",check.name);
        while(fscanf(fptr,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, &add.age, add.gender, &add.dob.day, &add.dob.month, &add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {
                test=1;
                printf("\nRoll no. : %s \nName           : %s \nAge            : %d \nGender         : %s \nDOB            : %d/%d/%d \nMob. no.       : %s\nMail-ID        : %s \nAdhar.no.      : %s \nCity           : %s \nFather's name  : %s \nF's mob. no.   : %s \nHostel Name    : %s \nRoom no.       : %s \n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
            }
        }
    }

    fclose(fptr);
     if(test!=1)
     	printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again\nEnter 1 to return main menu\nEnter 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            main_menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            view_stu_rec();
        else
        {
        	printf("\nInvalid!\a");
            goto see_invalid;
		}
}

//------------------------------------------------------------------------------------------------------------------

//function to delete records
void remove_records()
{
	system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("student_record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll no. of student whose data you want to delete:");
    scanf("%s",del.roll_no);
    while (fscanf(old,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, &add.age, add.gender, &add.dob.day, &add.dob.month, &add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no)!=EOF)
   {
        if(strcmp(add.roll_no,del.roll_no)==0)
        {
            test=1;
            printf("\nRecord deleted successfully!\a\a\a");

        }
        else
        {
            fprintf(newrec,"%s %s %d %s %d/%d/%d %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.age, add.gender, add.dob.day, add.dob.month, add.dob.year, add.mob_no, add.mail_id, add.adhar_no, add.city, add.father_name, add.father_mob, add.hostel_name, add.room_no);
        }
    }
    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
    }
    fclose(old);
    fclose(newrec);
    remove("student_record.dat");
    rename("new.dat","student_record.dat");

    del_invalid:
        printf("\nEnter 0 to try again\nEnter 1 to return main menu\n Enter 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            main_menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            remove_records();
        else
        {
        	printf("\nInvalid!\a");
            goto del_invalid;
		}
}
//------------------------------------------------------------------------------------------------------------------
//about function
void about()
{
    system("CLS");
    printf("\n\n\n\t\tThis Application is developed by Abhishek Sharma\n\t\tFor any query contact me via Gmail:-imgeekabhi@gmail.com\n\n\n\n\n\n\n\n\n");
    getch();
}
//------------------------------------------------------------------------------------------------------------------
// close function & print greeting
void close()
{
	system("CLS");
    printf("\n\n\n\n\t\t Thank you for using Application\n\n\t\t\t\t\t~Abhishek Sharma\a\a\a\n\n\n\n\n\n\n");
    getch();
}



