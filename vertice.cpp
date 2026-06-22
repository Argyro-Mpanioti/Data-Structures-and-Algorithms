#include "vertice.h"
#include <iostream>
using namespace std;

//Υλοποιούμε έναν κατασκευαστή της vertice που να δέχεται ως παράμετρο την τιμή της κορυφής
vertice::vertice(int value)
{
	this->value=value;
	pl_edges=0;
}


//Υλοποιούμε έναν default κατασκευαστή της vertice 
vertice::vertice()
{
	value=0;
	pl_edges=0;
}


//Υλοποιούμε έναν copy constructor για την κορυφή
vertice::vertice(const vertice &other)
{
	int i;
	value=other.value;
	pl_edges=other.pl_edges;

	th_edges=new int[pl_edges];
	edges=new vertice[pl_edges];
	weights=new int[pl_edges];
	
	for(i=0;i<pl_edges;i++)
	{
		th_edges[i]=other.th_edges[i];
		edges[i]=other.edges[i];
		weights[i]=other.weights[i];
	}
	
}

//Υλοποιούμε μία συνάρτηση που συνδέει την κορυφή με την κορυφή που δέχεται ως παράμετρο. Η ακμή έχει το βάρος που δέχεται ως παράμετρο.
//Υποθέτουμε ότι οι δύο κορυφές δεν είναι ήδη συνδεδεμένες.
void vertice::insert(vertice v2,int w,int t)
{
	int i;

	//Χρειάζεται να την εισάγουμε στον πίνακα edges
	//Χρειάζεται επίσης να ενημερώσουμε τον πίνακα weights και τον πίνακα th_edges
	vertice *temp;
	int *temp2;
	int	*temp3;

	temp=new vertice[pl_edges+1];
	temp2=new int[pl_edges+1];
	temp3=new int[pl_edges+1];
		
	for(i=0;i<pl_edges;i++)
	{
		temp[i]=edges[i];
		temp2[i]=weights[i];
		temp3[i]=th_edges[i];
	}
	
	temp[pl_edges]=v2;
	temp2[pl_edges]=w;
	temp3[pl_edges]=t;
		
	edges=temp;
	weights=temp2;
	th_edges=temp3;

	pl_edges++;
	
}


void vertice::delete_edge(vertice v2)
{
	bool found; //Η μεταβλητή found παίρνει την τιμή true αν η ακμή που θέλουμε να διαγράψουμε υπάρχει στον γράφο και την τιμή false αν δεν υπάρχει
	int i;
	found=false;
	int thesh;

	//Με την παρακάτω for ελέγχουμε όλες τις ακμές της συγκεκριμένης κορυφής για να δουμε αν μία από αυτές είναι η ακμή που τη συνδέει με την κορυφή v2. Αποθηκεύουμε την θέση στην οποία την βρίσκουμε 
	for(i=0;i<pl_edges;i++)
	{
		if(edges[i].value==v2.value)
		{
			thesh=i;
			found=true;
		}
	}

	
	if(found==false)//Αν η ακμή που θέλουμε να διαγράψουμε δεν υπάρχει τότε
	{
		//Δεν χρειάζεται να κάνουμε κάτι
		return;
	}
	else
	{
		//Διαγράφουμε την ακμή από τον πίνακα edges
		//Χρειάζεται να ενημερώσουμε τον πίνακα weights και τον πίνακα th_edges

		//Μειώνουμε τα μεγέθη των τριών πινάκων και αφαιρούμε το στοιχείο που βρίσκετι στη θέση thesh από τους πίνακες edges, weights και th_edges με την βοήθεια τριών δυναμικών πινάκων temp, temp2, temp3.
		
		vertice *temp;
		int *temp2;
		int *temp3;

		temp=new vertice[pl_edges-1];
		temp2=new int[pl_edges-1];
		temp3=new int[pl_edges-1];
		
		for(i=0;i<thesh;i++) 
		{
			temp[i]=edges[i]; 
			temp2[i]=weights[i]; 
			temp3[i]=th_edges[i];
		}
		for(i=thesh+1;i<pl_edges;i++)
		{
			temp[i-1]=edges[i];
			temp2[i-1]=weights[i];
			temp3[i-1]=th_edges[i];
		}
		delete []edges;
		delete[] weights;
		delete[] th_edges;
		
		edges=temp;
		weights=temp2;
		th_edges=temp3;
		
		pl_edges--; //Μειώνουμε το πλήθος των προσπίπτουσων ακμών της κορυφής κατά 1

	}
}

//getters
int vertice::getvalue()
{
	return value;
}

int vertice::get_pl_edges()
{
	return pl_edges;
}

vertice vertice::get_edges(int i)
{
	return edges[i];
}

int vertice::get_weights(int i)
{
	return weights[i];
}

int vertice::get_th_ston_koryfes()
{
	return th_ston_koryfes;
}

int vertice::get_th_edges(int i)
{
	return th_edges[i];
}

//setters
void vertice::set_pl_edges(int i)
{
	pl_edges=i;
}

void vertice::set_edges(int i,vertice j)
{
	edges[i]=j;
}

void vertice::set_weights(int i,int j)
{
	weights[i]=j;
}

void vertice::set_value(int i)
{
	value=i;
}

void vertice::set_th_ston_koryfes(int i)
{
	th_ston_koryfes=i;
}
