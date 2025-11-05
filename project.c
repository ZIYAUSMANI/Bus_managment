#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sing_up();
int login();
char main_menu();
char login_menu();
int clear_input_buffer();
int check_bus();
int cancel_ticket();

char username[3][20], email[3][30], password[3][10];
char destination[3][20]={"Bihar","Patna","Bhagalpur"};
int bus[3] = {101, 102, 103};
int seat1 = 50, seat2 = 50, seat3 = 50;
int fare[3] = {1000, 1200, 1800};
int seat_num = 0, count = 0;

int cancel_ticket()
{
	int bus_num,seat_num,s1,s2,s3;
	printf("Enter the bus number = ");
	scanf("%d",&bus_num);
	printf("Enter the seat number = ");
	scanf("%d",&seat_num);
	s1=50-seat1;
	s2=50-seat2;
	s3=50-seat3;
	if(bus_num==bus[0])
	{
	       if(seat_num<=s1)
	       {
			printf("Cancellation successful! %d seats canceled on bus number %d\n",seat_num,bus_num);
			seat1=seat1+seat_num;
		}
		else
		printf("These many seats are not booked!\n");
	}
	else if(bus_num==bus[1])
	{
	       if(seat_num<=s2)
	       {
			printf("Cancellation successful! %d seats canceled on bus number %d\n",seat_num,bus_num);
			seat2=seat2+seat_num;
		}
		else
		printf("These many seats are not booked\n!");
	}
	else if(bus_num==bus[2])
	{
	       if(seat_num<=s3)
	       {
			printf("Cancellation successful! %d seats canceled on bus number %d\n",seat_num,bus_num);
			seat3=seat3+seat_num;
		}
		else
		printf("These many seats are not booked!\n");
	}
	else
	printf("Bus number is invalid\n");
    return 0;
}

int check_bus()
{
	int bus_num;
	printf("Enter the bus number = ");
	scanf("%d",&bus_num);
	if(bus_num==bus[0])
	{
		printf("Bus Number:  %d\n",bus[0]);
		printf("Source City: Delhi\n");
		printf("Destination City: %s\n",destination[0]);
		printf("Total Seats:  50\n");
		printf("Available Seats: %d\n",seat1);
		printf("Fare: 1000\n");
	}
	else if(bus_num==bus[1])
	{
		printf("Bus Number:  %d\n",bus[1]);
		printf("Source City: Delhi\n");
		printf("Destination City: %s\n",destination[1]);
		printf("Total Seats:  50\n");
		printf("Available Seats: %d\n",seat2);
		printf("Fare: 1200\n");
	}
	else if(bus_num==bus[2])
	{
		printf("Bus Number:  %d\n",bus[2]);
		printf("Source City: Delhi\n");
		printf("Destination City: %s\n",destination[2]);
		printf("Total Seats:  50\n");
		printf("Available Seats: %d\n",seat3);
		printf("Fare: 1800\n");
	}
	else
	printf("Invalid bus number\n");

    return 0;
}

int book_ticket()
{
	int bus_num;
	printf("%d Delhi to %s and available seats are %d\n",bus[0],destination[0],seat1);
	printf("%d Delhi to %s and available seats are %d\n",bus[1],destination[1],seat2);
	printf("%d Delhi to %s and available seats are %d\n",bus[2],destination[2],seat3);
	printf("Enter the bus number = ");
	scanf("%d",&bus_num);
	printf("Enter number of seats = ");
	scanf("%d",&seat_num);

	if((bus_num==bus[0])&&(seat_num<=seat1))
	{
		printf("Booking successful! %d seats booked on bus number %d\n",seat_num,bus_num);
		printf("Total amount is %d\n",fare[0]*seat_num);
		seat1=seat1-seat_num;
	}
	else if((bus_num==bus[1])&&(seat_num<=seat2))
	{
		printf("Booking successful! %d seats booked on bus number %d\n",seat_num,bus_num);
		printf("Total amount is %d\n",fare[1]*seat_num);
		seat2=seat2-seat_num;
	}
	else if((bus_num==bus[2]) && (seat_num<=seat3))
	{
		printf("Booking successful! %d seats booked on bus number %d\n",seat_num,bus_num);
		printf("Total amount is %d\n",fare[2]*seat_num);
		seat3=seat3-seat_num;
	}
	else
		printf("Invalid bus number or seats more than available seats\n");
    
    return 0;
}

int clear_input_buffer()
{
	int c;
	while((c=getchar())!='\n' && c!=EOF);
    return 0;
}

int sing_up()
{
	int u=0,e=0,p=0,i;
	clear_input_buffer();
	if(count>2)
		printf("Registration is full! Only three people can register.\n");
	else
	{
		printf("Enter name = ");
		scanf(" %[^\n]", username[count]);

		printf("Enter email = ");
		scanf(" %[^\n]", email[count]);

		printf("Enter password = ");
		scanf(" %[^\n]", password[count]);

		for(i=0;username[count][i]!='\0';i++)
		{
			if(!((username[count][i]>='a' && username[count][i]<='z') || (username[count][i]>='A' && username[count][i]<='Z')))
            {
                u = 1;
                break;
            }

		}

		if(strlen(email[count]) < 10 || strstr(email[count], "@gmail.com") == NULL || strcmp(email[count] + strlen(email[count]) - 10, "@gmail.com") != 0)
            e = 1;
		if(strlen(password[count])!=8)
			p=1;

		if(p==0 && u==0 && e==0)
		{
			printf("Registration done successfully!\n");
			count++;
		}
		 else
        {
            if(u == 1)
                printf("Invalid name (must have characters only)\n");

            if(e == 1)
                printf("Invalid email (must end with @gmail.com)\n");

            if(p == 1)
                printf("Invalid password (must have 8 characters or digits)\n");

            printf("Registration failed! Try again.\n");
        }
	}
    return 0;
}

int login()
{
	int u,e,p,i,f=0;
	char user_name[20],e_mail[20],pass_word[20],c;
	clear_input_buffer();

	printf("Enter name = ");
	scanf(" %[^\n]", user_name);

	printf("Enter email = ");
	scanf(" %[^\n]", e_mail);

	printf("Enter password = ");
	scanf(" %[^\n]", pass_word);

	for(i=0;i<count;i++)
	{
		u=strcmp(username[i],user_name);
		e=strcmp(email[i],e_mail);
		p=strcmp(password[i],pass_word);

		if(u==0 && e==0 && p==0)
		{
			printf("Login successfully!\n");
			while(1)
			{
				c=login_menu();
				switch(c)
				{
					case '1':
						book_ticket();
						break;
					case '2':
						cancel_ticket();
						break;
					case '3':
						check_bus();
						break;
					case '4':
						printf("Thank you ! Visit again");
						exit(0);
						break;
					default:
						printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
				}
			}
			f=1;
			break;
		}
		else if(u!=0 && e==0 && p==0)
		{
			printf("Invalid username\n");
			f=1;
			break;
		}
		else if(e!=0 && u==0 && p==0)
		{
			printf("Invalid email\n");
			f=1;
			break;
		}
		else if(p!=0 && e==0 && u==0)
		{
			printf("Invalid password\n");
			f=1;
			break;
		}
	}

	if(f==0)
		printf("Details not found\n");
    
    return 0;
}

char main_menu()
{
	char choice;
    printf("****************BUS RESERVATION SYSTEM*******************\n");
    printf("---------------------------------------------------------");
	printf("\n1. Sign up\n2. Login\n3. Exit\n");
	printf("=============================\n");
	printf("Enter choice: ");
	scanf(" %c",&choice);
	return choice;
}

char login_menu()
{
	char choice;
    printf("=======User Menu======");
	printf("\n1. Book a ticket\n2. Cancel a ticket\n3. Check bus status\n4. Logout\n");
	printf("=============================\n");
	printf("Enter choice: ");
	scanf(" %c",&choice);
	return choice;
}

int main()
{
	char c;
	while(1)
	{
		c=main_menu();
		switch(c)
		{
			case '1':
				sing_up();
				break;
			case '2':
				login();
				break;
			case '3':
				printf("Thank you ! Visit again");
				exit(0);
				break;
			default :
				printf("Invalid choice! Please enter 1, 2, or 3.\n");
		}
	}
    return 0;
}
