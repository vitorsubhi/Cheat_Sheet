#include "Header.h"
#include "Accounts.h"

void clearscreen()
{
	#ifdef _WIN32
		system ("CLS");
	#else
		system ("clear");
	#endif
}

void authenticate()
{
	clearscreen();
	printf ("Username:");
	scanf ("%s", &username[0]);
	printf ("Password:");
	scanf ("%s", &password[0]);
}

int login(char user[20], char pass[30])
{
	FILE *fp;
	char local[50]="Files/Users/";
	strcat (local, user);
	fp = fopen (local, "r");
	if (fp == NULL)
		printf ( "Username or/and Password is/are Incorrect.\n");
	else
	{
		while (fgets(checkpass, 20, fp) != NULL)
		{

		}
		fscanf (fp, "%s", pass);
		if (strcmp(checkpass, pass) != 0)
			printf ("Username or/and Password is/are Incorrect.\n");
		else
			return TRUE;
	}
}

int checkuser(char user[20])
{
	FILE *fp;
	char local[50]="Files/Users/";
        strcat (local, user);
	fp = fopen (local, "r");
	if (fp == NULL)
		return FALSE;
	return TRUE;
}

int newuser(char user[20], char pass[30])
{
	FILE *fp;
	char local[50]="Files/Users/";
	strcat (local, user);
	if (!checkuser(user))
	{
		fp = fopen (local, "w");
		fprintf (fp, "%s", pass);
		printf ("Your Account has been created successfully\n");
	}
	else
		printf ("Account already exists, try another Username\n");
//fclose (fp);
}

int deluser(char user[20], char pass[30])
{
	FILE *fp;
	char local[50]="Files/Users/";
	strcat (local, user);
	if (!checkuser (user))
                printf ("This Account does not exists.\n");
        else
        {
		while (fgets(checkpass, 20, fp) != NULL)
                {
                }
                fscanf (fp, "%s", pass);
                if (strcmp(checkpass, pass) != 0)
                        printf ("Username or/and Password is/are Incorrect.\n");
		else
		{
			int status = 1;
        		status = remove(local);
			if (status == 0)
				printf ("User: %s has been deleted successfully\n", user);
			else
				printf ("Unable to delete User: %s . Try again Later.\n", user);
		}
        }

}

int edituser(char user[20], char pass[30], char newpass[30])
{
	FILE *fp;
	char local[50]="Files/Users/";
	strcat (local, user);
	fp = fopen (local, "r");
	if (!checkuser(user))
		printf ("This Account does not exists\n");
	else
	{
		while (fgets(checkpass, 20, fp) != NULL)
                {
                }
                fscanf (fp, "%s", pass);
                if (strcmp(checkpass, pass) != 0)
                        printf ("Username or/and Password is/are Incorrect.\n");
                else
                {
			if (strcmp(newpass, pass) == 0)
				printf ("New Password is the same as the Old Password\n");
                        else
			{
				fp = fopen (local, "w");
				fprintf (fp, "%s", newpass);
				printf ("Your new password is: %s\n", newpass);
			}
                }
	}
}
