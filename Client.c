#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include"Implementation.c"

int main() 
{ 
struct Node *root = NULL; 
int ch;
while(ch!=9)
{	system("cls");	//clrscr();
	int n,j;
	printf("\n\t\t\t\t AVL Trees\n1.Insert into Trees\n2.PreOrder\n3.PostOrder\n4.InOrder\n5.Balance factors(along PreOrder)\n");
	printf("6.Search\n7.Delete\n8.Clear tree\n9.Exit\n\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{	
		case 1 :	printf("\nEnter number elements to be inserted:");
					scanf("%d",&n);
					printf("\nEnter the element(s) to be inserted:");
					if(n>0)
					{while(n-->0)
					{
						scanf("\n%d",&j);
						root=insert(root,j);
					}
					printf("\nInsertion Sucessful");
					}
					break;
		case 2 :	if(root!=NULL) 
					{
						printf("\nPreOrder: " );
						preOrder(root);
					}
					else
						printf("\nNo Elements to display: " );
					break;
		case 3 :	if(root!=NULL)
					{
						printf("\nPostOrder: " );
						postOrder(root);
					}
					else
						printf("\nNo Elements to display: " );
					break;
		case 4 :	if(root!=NULL)
					{
						printf("\nInOrder: ");
						inOrder(root);
					}
						else
						printf("\nNo Elements to display: " );
					break;
		case 5 :	if(root!=NULL)
					Balancefactors(root);
					else
						printf("\nNo Elements to display: " );
					break;
		/*case 6 :	printf("\nEnter element to be deleted:");
					//int n;
					scanf("%d",&n);
					//root=delete(root,n);
					break;*/
		case 6 :	printf("\nEnter element to be searched: " );
					scanf("\n%d",&n);
					j=search(root,n);
					if(j)
						printf("\nElement is present in the Tree");
					else
						printf("\nElement is not present in the Tree");
					break;
					//deletetree(Node);
		
		case 7 : 	if(root!=NULL)
					{
						printf("\nEnter Element to be deleted ");
						scanf("\n%d",&n);
						if(search(root,n))
						{
							root = deleteNode(root,n);
							printf("\nDeletion Complete ");
						}
						else
							printf("\nElement not Found");
					}
					else
						printf("\nTree is empty");
					getch();
					break;			
		case 8 :	if(root!=NULL)
					{
						free(root);
						root=NULL;
						printf("\nOperation Successful");
					}
					break;

		
		case 9 : 	system("cls");
					free(root);
					root=NULL;
					exit(0);
					break;
		default :	printf("%s\n","Please Enter a valid option" );
					
	}
printf("\n\nPress Enter to continue" );
getch();
}

return 0; 
} 