#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//***TYPES***
typedef struct
{
	char name[30];
	char firstname [30];
	int age;
	int identity;
	char adr[40];
}Citizen;
typedef struct l{
	Citizen c;
	struct l *next;
}myList;
typedef myList *list;

Citizen filldata(){
	Citizen c;
	
	printf("First Name:");
	scanf("%s",c.firstname);
	
	printf("Name:");
	scanf("%s",c.name);
	
	printf("Age:");
	scanf("%d",&c.age);
	
	printf("ID:");
	scanf("%d",&c.identity);

	printf("Adress:");
	scanf("%s",c.adr);
	return c;
} 

//***creating an empty list***
void list_creation(list *l){
	*l=NULL;
}





//***filling in the list fifo(first in first out)***
void fill_list(list *l){
	list k,p;
	p=(myList*)malloc(sizeof(myList));
	p->c=filldata();
	p->next=NULL;
	if(*l==NULL){
		*l=p;
	}else{
		k=*l;
		while(k->next!=NULL){
			k=k->next;
		}
		k->next=p;
	}
}




//***show list content ***
void display(list l){
	list p;
	int i=1;
	p=l;
	while(p!=NULL){
		printf("\n \n");
		printf("CITIZEN %d:\n",i);
		printf("First name: %s\n",p->c.firstname);
		printf("Name: %s\n",p->c.name);
		printf("Age: %d\n",p->c.age);
		printf("identity: %d\n",p->c.identity);
		printf("Adress: %s\n",p->c.adr);
		printf("\n**-**-**-**-**-**");
		p=p->next;
		i++;
	}
}



//***searching a specific citizen using ID***
list search(list l,int id){
	if(l==NULL||l->c.identity==id)
		return l;
	else
		return search(l->next,id);
	
}


//***counting the number of citizens***
int nb(list l){
	list p=l;
	if(p==NULL)
		return 0;
	else
		return 1+nb(p->next);
}



//****deleting a citizen
void delet(list *l,int id){
	list k,p;
	
	k=search(*l,id);
	
	if(k==NULL)
		printf("ID doesn't exist");
		
	else 
		if(k==*l)
			*l=(*l)->next;
	else
	{
		p=*l;
		while(p->next!=k){
			p=p->next;
		}
		p->next=k->next;
	}
	free(k);
}

main(){
	list l,m;
	int choice,id;
	list_creation(&l);
	
	
	//********MENU
	printf("\t\t\t***********Menu************\n");
	printf("\t\t\t---------------------------\n");
	printf("if you want to:\n");
	printf("1_insert new citizen ==>Press 1\n\n");
	printf("2_Display list ==>Press 2\n\n");
	printf("3_search a citizen ID ==>Press 3\n\n");
	printf("4_delete a citizen ==>Press 4\n\n");
	printf("5_leave ==>Press 0\n\n");
	
	
	//***calling the functions
	do{
		printf("CHOICE:");
		scanf("%d",&choice);
		if(choice==1){
			fill_list(&l);
		}
		
		
		
		else if(choice==2){
			display(l);
		}
		
		
		
		
		else if(choice==3){
			printf("searching id:");
			scanf("%d",&id);
			m=search(l,id);
			if(m==NULL)
				printf("not found");
			else{
				printf("\t\t****----****----****\n");
				printf("\t\tfirst name:%s\n",m->c.firstname);
				printf("\t\tname:%s\n",m->c.name);
				printf("\t\tage:%d\n",m->c.age);
			
			}
		}
		else if(choice==4){
			printf("searching id:");
			scanf("%d",&id);
			delet(&l,id);
		}
		
	
	
	}while(choice!=0);
	
	printf("Number of citizens:%d",nb(l));
}