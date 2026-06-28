#include "vertex.h"
#include <iostream>
using namespace std;

//Υλοποιούμε έναν κατασκευαστή της vertice που να δέχεται ως παράμετρο την τιμή της κορυφής
vertex::vertex(int value)
{
	this->value=value;
	edges_count=0;
}


//Υλοποιούμε έναν default κατασκευαστή της vertice 
vertex::vertex()
{
	value=0;
	edges_count=0;
}


//Υλοποιούμε έναν copy constructor για την κορυφή
vertex::vertex(const vertex &other)
{
	int i;
	value=other.value;
	edges_count=other.edges_count;

	edges_positions=new int[edges_count];
	edges=new vertex[edges_count];
	weights=new int[edges_count];
	
	for(i=0;i<edges_count;i++)
	{
		edges_positions[i]=other.edges_positions[i];
		edges[i]=other.edges[i];
		weights[i]=other.weights[i];
	}
	
}

//Υλοποιούμε μία συνάρτηση που συνδέει την κορυφή με την κορυφή που δέχεται ως παράμετρο. Η ακμή έχει το βάρος που δέχεται ως παράμετρο.
//Υποθέτουμε ότι οι δύο κορυφές δεν είναι ήδη συνδεδεμένες.
void vertex::insert(vertex v2,int w,int t)
{
	int i;

	//Ελέγχουμε αν η κορυφή είναι ήδη συνδεδεμένη με την ακμή
	for (i=0;i<edges_count;i++) {
		if(edges[i]==v2) {
			return;
		}
	}

	//Χρειάζεται να την εισάγουμε στον πίνακα edges
	//Χρειάζεται επίσης να ενημερώσουμε τον πίνακα weights και τον πίνακα edges_positions
	vertex *temp;
	int *temp2;
	int	*temp3;

	temp=new vertex[edges_count+1];
	temp2=new int[edges_count+1];
	temp3=new int[edges_count+1];
		
	for(i=0;i<edges_count;i++)
	{
		temp[i]=edges[i];
		temp2[i]=weights[i];
		temp3[i]=edges_positions[i];
	}
	
	temp[edges_count]=v2;
	temp2[edges_count]=w;
	temp3[edges_count]=t;
		
	edges=temp;
	weights=temp2;
	edges_positions=temp3;

	edges_count++;
	
}


void vertex::delete_edge(vertex v2)
{
	bool found; //Η μεταβλητή found παίρνει την τιμή true αν η ακμή που θέλουμε να διαγράψουμε υπάρχει στον γράφο και την τιμή false αν δεν υπάρχει
	int i;
	found=false;
	int position;

	//Με την παρακάτω for ελέγχουμε όλες τις ακμές της συγκεκριμένης κορυφής για να δουμε αν μία από αυτές είναι η ακμή που τη συνδέει με την κορυφή v2. Αποθηκεύουμε την θέση στην οποία την βρίσκουμε 
	for(i=0;i<edges_count;i++)
	{
		if(edges[i].value==v2.value)
		{
			position=i;
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
		//Χρειάζεται να ενημερώσουμε τον πίνακα weights και τον πίνακα edges_positions

		//Μειώνουμε τα μεγέθη των τριών πινάκων και αφαιρούμε το στοιχείο που βρίσκεται στη θέση position από τους πίνακες edges, weights και edges_positions με την βοήθεια τριών δυναμικών πινάκων temp, temp2, temp3.
		
		vertex *temp;
		int *temp2;
		int *temp3;

		temp=new vertex[edges_count-1];
		temp2=new int[edges_count-1];
		temp3=new int[edges_count-1];
		
		for(i=0;i<position;i++)
		{
			temp[i]=edges[i]; 
			temp2[i]=weights[i]; 
			temp3[i]=edges_positions[i];
		}
		for(i=position+1;i<edges_count;i++)
		{
			temp[i-1]=edges[i];
			temp2[i-1]=weights[i];
			temp3[i-1]=edges_positions[i];
		}
		delete []edges;
		delete[] weights;
		delete[] edges_positions;
		
		edges=temp;
		weights=temp2;
		edges_positions=temp3;
		
		edges_count--; //Μειώνουμε το πλήθος των προσπίπτουσων ακμών της κορυφής κατά 1

	}
}

//getters
int vertex::getvalue()
{
	return value;
}

int vertex::get_edges_count()
{
	return edges_count;
}

vertex vertex::get_edges(int i)
{
	return edges[i];
}

int vertex::get_weights(int i)
{
	return weights[i];
}

int vertex::get_position_in_vertices()
{
	return position_in_vertices;
}

int vertex::get_edges_positions(int i)
{
	return edges_positions[i];
}

//setters
void vertex::set_edges_count(int i)
{
	edges_count=i;
}

void vertex::set_edges(int i,vertex j)
{
	edges[i]=j;
}

void vertex::set_weights(int i,int j)
{
	weights[i]=j;
}

void vertex::set_value(int i)
{
	value=i;
}

void vertex::set_position_in_vertices(int i)
{
	position_in_vertices=i;
}
