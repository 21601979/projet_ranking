#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	double val;
	struct NODE* suivcolonne;
	struct NODE* suivligne;
	int ligne;
	int colonne;
}node;

typedef struct MATR
{
	node** ligne;
	node** colonne;
}matr;

void add_node(int ligne, int colonne, double val, matr ma)
{
	//création de la node 
	node* new = malloc(sizeof(node));
	node* temp;
	new->val = val;
	new->colonne = colonne;
	new->ligne = ligne;
	//link colonne 
	if(ma.colonne[colonne] == NULL)
	{
		ma.colonne[colonne] = new;
	}
	else
	{
		temp = ma.colonne[colonne];
		while(temp->suivcolonne != NULL)
		{
			temp = temp->suivcolonne;
		}
		temp->suivcolonne = new;
	} 
	
	//link ligne 
	if(ma.ligne[ligne] == NULL)
	{
		ma.ligne[ligne] = new;
	}
	else
	{
		temp = ma.ligne[ligne];
		while(temp->suivligne != NULL)
		{
			temp = temp->suivligne;
		}
		temp->suivligne = new;
	}
}

int main()
{
	FILE* f = fopen("trop.txt","r"); 
	int nb ;
	int size;
	int ligne;
	int colonne;
	int nbval;
	double val;
	fscanf(f,"%d",&nb);
	fscanf(f,"%d",&size);
	printf("%d  \n",size);
	matr ma;
	ma.ligne = malloc(sizeof(node*)*size);
	ma.colonne = malloc(sizeof(node*)*size);
	
	//lecture du fichier et chargement de la matrice
	int i,j;
	for(i=0;i<size;i++)
	{
		fscanf(f,"%d",&ligne);
		fscanf(f,"%d",&nbval);
		for(j=0; j<nbval; j++)
		{
			fscanf(f,"%d",&colonne);
			fscanf(f,"%lf",&val);
			add_node(ligne,colonne,val,ma);
		}
	}
	printf("end\n");
	fclose(f);
}	
	