#include "graph.h"
#include "minheap_gr.h"
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;

//Υλοποιούμε μία συνάρτηση build που δέχεται ως παράμετρο το όνομα του αρχείου από το οποίο διαβάζει τα δεδομένα για την κατασκευή του γράφου και κατασκευάζει τον γράφο
void graph::build(const char* filename)
{
	ifstream l;
	int n1,n2,w;
	
    l.open(filename);//Ανοίγουμε το αρχείο filename από το οποίο θα διαβάσουμε τα δεδομένα
    if(l.is_open()) //Ελέγχουμε αν το αρχείο άνοιξε επιτυχώς
    {
        order=0;
		size=0;
		koryfes=NULL;
        while(l.eof()==false)
        {
			l>>n1>>n2>>w; //Αποθηκεύω την πρώτη τιμή της γραμμής του αρχείου στη μεταβλητή n1, την δεύτερη στη μεταβλητή n2 και την τριτή στη μεταβλητή w
			insert(n1,n2,w);//Εισάγουμε στον γράφο τις κορυφές με τιμή n1 και n2 αν αυτές δεν υπάρχουν ήδη. Επίσης εισάγουμε στον γράφο την ακμή με τερματικά σημεία τις κορυφές με τιμές n1 και n2 και βάρος w αν αυτή δεν υπάρχει ήδη
			
        }
        l.close(); //Κλείνουμε το αρχείο
    }
    else
    {
        cerr<<"Couldn't open file."; //Αν το αρχείο δεν μπορεί να ανοίξει επιτυχώς εμφανίζουμε ένα μήνυμα σφάλαμτος στην οθόνη
    }
}


//Υλοποιούμε τον default κατασκευαστή του graph που αρχικοποιεί την τάξη και το μέγεθός του με 0
graph::graph() 
{
	order=0;
	size=0;
}


//Υλοποιούμε την συνάρτηση insert με την οποία εισάγουμε στον γράφο τις κορυφές με τιμή n1 και n2 αν αυτές δεν υπάρχουν ήδη. Επίσης εισάγουμε στον γράφο την ακμή με τερματικά σημεία τις κορυφές με τιμές n1 και n2 και βάρος w αν αυτή δεν υπάρχει ήδη
void graph::insert(int n1,int n2,int w)
{
	
	bool found1;
	int thesh1;
	bool found2;
	int thesh2;
	
	vertice *temp;
	int i;
	
	//Αναζητούμε την κορυφή με τιμή n1 στον πίνακα με τις κορυφές για να δούμε αν ήδη υπάρχει ή αν πρέπει να την εισάγουμε
	found1=false;
	for(i=0;i<order && found1==false;i++)
	{
		if(koryfes[i].getvalue()==n1)
		{
			found1=true;
			thesh1=i;
		}
	}
	
	//Αναζητούμε την κορυφή με τιμή n2 στον πίνακα με τις κορυφές για να δούμε αν ήδη υπάρχει ή αν πρέπει να την εισάγουμε
	found2=false;
	for(i=0;i<order && found2==false;i++)
	{
		if(koryfes[i].getvalue()==n2)
		{
			found2=true;
			thesh2=i;
		}
	}

	
	if(found1==false && found2==false) //Αν καμία από τις δύο κορυφές δεν υπάρχουν στον γράφο
	{
		vertice v1(n1); //Ορίζω κορυφή v1 με τιμή n1
		vertice v2(n2); //Ορίζω κορυφή v2 με τιμή n2
		
		//Εισάγω τις v1,v2 στον πίνακα με τις κορυφές του γράφου
		temp=new vertice[order+2];
		for(i=0;i<order;i++)
		{
			temp[i]=koryfes[i];	
		}
		
		temp[order]=v1; 
		temp[order+1]=v2;
		delete[] koryfes;
		koryfes=temp;

		v1.set_th_ston_koryfes(order);
		v2.set_th_ston_koryfes(order+1);
		
		//Εισάγω την ακμή που συνδέει την v1 με την v2 με βάρος w στον γράφο
		koryfes[order].insert(koryfes[order+1],w,order+1);
		koryfes[order+1].insert(koryfes[order],w,order);
			
		size++;
		order+=2; //Καμία από τις δύο κορυφές δεν υπάρχουν στον γράφο άρα η τάξη αυξάνεται κατά δύο
	}
	else if(found1==false) //Αν η κορυφή με την τιμή n2 υπάρχει ήδη στον γράφο αλλά η κορυφή με τιμή n1 δεν υπάρχει στον γράφο
	{
		vertice v1(n1); //Ορίζω κορυφή v1 με τιμή n1
		
		//Εισάγω την v1 στον πίνακα με τις κορυφές του γράφου
		temp=new vertice[order+1];
		for(i=0;i<order;i++)
		{
			temp[i]=koryfes[i];	
		}		
		temp[order]=v1;
		delete[] koryfes;
		koryfes=temp;
		
		v1.set_th_ston_koryfes(order);
		
		
		//Εισάγω την ακμή που συνδέει την v1 με την κορυφή με τιμή n2 (koryfes[thesh2]) με βάρος w στον γράφο
		koryfes[order].insert(koryfes[thesh2],w,thesh2);
		koryfes[thesh2].insert(koryfes[order],w,order);

		size++;
		order+=1; //Η μία κορυφή ήδη υπάρχει στον γράφο άρα η τάξη αυξάνεται κατά ένα
	}
	else if(found2==false) //Αν η κορυφή με την τιμή n1 υπάρχει ήδη στον γράφο αλλά η κορυφή με τιμή n2 δεν υπάρχει στον γράφο
	{
		vertice v2(n2); //Ορίζω κορυφή v2 με τιμή n2
		
		//Εισάγω την v2 στον πίνακα με τις κορυφές του γράφου
		temp=new vertice[order+1];
		for(i=0;i<order;i++)
		{
			temp[i]=koryfes[i];	
		}		
		temp[order]=v2;
		delete[] koryfes;
		koryfes=temp;

		
		v2.set_th_ston_koryfes(order);
		
		//Εισάγω την ακμή που συνδέει την κορυφή με τιμή n1 (koryfes[thesh1]) με την v2 με βάρος w στον γράφο
		koryfes[thesh1].insert(koryfes[order],w,order);
		koryfes[order].insert(koryfes[thesh1],w,thesh1);

		size++;
		order+=1; //Η μία κορυφή ήδη υπάρχει στον γράφο άρα η τάξη αυξάνεται κατά ένα
	}
	else //Αν και οι δύο κορυφές υπάρχουν ήδη στον γράφο
	{
		//Υποθέτουμε ότι η ακμή δεν υπάρχει στον γράφο
		//Εισάγουμε την ακμή στον γράφο
		
		koryfes[thesh1].insert(koryfes[thesh2],w,thesh2);
		koryfes[thesh2].insert(koryfes[thesh1],w,thesh1);
		
		size++;
	}
}

//Συνάρτηση που διαγράφει από τον γράφο την ακμή που ενώνει τις κορυφές με τιμές n1 και n2
void graph::delete_graph_edge(int n1,int n2)
{
	bool found1;
	int thesh1;
	bool found2;
	int thesh2;
	int i;

	
	//Αναζητούμε την κορυφή με τιμή n1 στον πίνακα με τις κορυφές για να δούμε αν ήδη υπάρχει
	found1=false;
	for(i=0;i<order && found1==false;i++)
	{
		if(koryfes[i].getvalue()==n1)
		{
			found1=true;
			thesh1=i;
		}
	}
	
	//Αναζητούμε την κορυφή με τιμή n2 στον πίνακα με τις κορυφές για να δούμε αν ήδη υπάρχει
	found2=false;
	for(i=0;i<order && found2==false;i++)
	{
		if(koryfes[i].getvalue()==n2)
		{
			found2=true;
			thesh2=i;
		}
	}


	
	if(found1==true && found2==true) //Αν και οι δύο κορυφές υπάρχουν στον γράφο
	{
		//Υποθέτουμε ότι η ακμή υπάρχει στον γράφο
		//Διαγράφουμε την ακμή
		koryfes[thesh1].delete_edge(koryfes[thesh2]);
		koryfes[thesh2].delete_edge(koryfes[thesh1]);
		size--;
	}		
}

long int graph::cc2() //Η συνάρτηση cc2 βοηθάει στην εκτέλεση του Prim για κάθε συνιστώσα του γράφου
{
	long int result;
	char color2[order]; //Ο πίνακας color2 έχει αποθηκευμένο το χρώμα κάθε κορυφής. Αν δεν έχουμε επισκεπτεί την κορυφή τότε το χρώμα της είναι 'w'. Όσο την επισκεπτόμαστε το χρώμα της είναι 'g'. Αφού την επισκεπτούμε το χρώμα της είναι 'b'.
	char *color3;
	color3=new char[order];

	result=0;
	int i,j;

	//Αρχικοποίηση του πίνακα color2 με 'w'
	for(i=0;i<order;i++)
	{
		color2[i]='w';
	}

	
	for(i=0;i<order;i++) //Για κάθε κορυφή του γράφου
	{
		if(color2[i]=='w') //Αν δεν την έχουμε επισκεπτεί
		{
			//Έχουμε έναν πίνακα color3 τον οποίο αρχικοποιούμε με 'w'
			for(j=0;j<order;j++)
			{
				color3[j]='w';
			}
			DFSVisit2(color2,i,color3);
			//Πλέον ο πίνακας color3 περιέχει την τιμή 'b' μόνο για τις κορυφές της συνεκτικής συνιστώσας στην οποία ανήκει η κορυφή της θέσης i του πίνακα koryfes. 
			result+=Prim(color3,i); 
		}
	}
	return result;
}

void graph::DFSVisit2(char color2[],int u,char color3[]) //Η συνάρτηση DFSVisit2 προσπελάυνει τα στοιχεία της συνιστώσας που περιέχει την κορυφή που βρίσκεται στην θέση u στον πίνακα koryfes
{
	color2[u]='g';
	int j;
	int th;
	
	for(j=0;j<koryfes[u].get_pl_edges();j++)
	{
		th=koryfes[u].get_th_edges(j);
		if(color2[th]=='w')
		{
			DFSVisit2(color2,th,color3);
		}
	}
	color2[u]='b';
	color3[u]='b';
}

//Συνάρτηση που υλοποιεί τον αλγόριθμο του Prim 
long int graph::Prim(char color3[],int n) 
{
	int i;
	//Οι πίνακες color και key είναι παράλληλοι με τον πίνακα koryfes
	int key[order]; 
	char color[order];
	//Αν το color μίας κορυφής είναι 'w' τότε δεν έχουμε επισκεπτεί ακόμα.
	//Αν είναι 'b' τότε την έχουμε επισκεπτεί.
	vertice u;
	int t;
	int t1;

	//Αρχικοποίηση των πινάκων color και key
	for(i=0;i<order;i++)
	{
		if(color3[i]=='b')
		{
			key[i]=INT_MAX;
			color[i]='w';
		}
	}
	key[n]=0;

	
	minheap_gr Q;
	//Εισάγουμε στον σωρό κάθε κόμβο του γράφου με το αντίστοιχο key και τη θέση του στον πίνακα koryfes
	for(i=0;i<order;i++)
	{
		if(color3[i]=='b')
		{
			Q.insert(koryfes[i],key[i],i);
		}
	}

	
	while(Q.getsize()!=0) //Όσο ο σωρός έχει στοιχεία
	{
		//Διαγράφουμε τη ρίζα του και την αποθηκεύουμε στην κορυφή u
		u=Q.deletemin();
		t1=u.get_th_ston_koryfes();
		for(i=0;i<u.get_pl_edges();i++) //Για κάθε γειτονική κορυφή της u
		{
			t=u.get_th_edges(i);
			//Αν δεν την έχουμε επισκεπτεί και μπορούμε να μειώσουμε το key του u μέσω της γειτονικής κορυφής
			if(color[t]=='w' && u.get_weights(i)<key[t])
			{
				//Ενημερώνουμε το key και τον σωρό
				key[t]=u.get_weights(i);
				Q.decreasekey(koryfes[t],key[t]);
			}
		}
		color[t1]='b'; //Έχουμε επισκεπτεί την u
	}

	long int weight; //Το weight είναι το βάρος του ελάχιστου εκτεινόμενου δένδρου της συνεκτικής συνιστώσας που περιέχει τα στοιχεία τα οποία έχουν color3 'b'
	weight=0;

	//Το weight θα γίνει το άθροισμα των key τα οποία έχουν color3 'b'
	for(i=0;i<order;i++)
	{
		if(color3[i]=='b')
		{
			weight+=key[i];
		}
	}
	
	return weight; //Η συνάρτηση επιστρέφει το weight
}


int graph::fcc() //Η συνάρτηση fcc υπολογίζει και επιστρέφει το πλήθος των συνιστωσών του γράφου
{
	int cc; //Στην μεταβλητή cc αποθηκεύουμε το πλήθος των συνεκτικών συνιστωσών του γράφου
	cc=0;

	char color[order]; //Ο πίνακας color έχει αποθηκευμένο το χρώμα κάθε κορυφής. Αν δεν έχουμε επισκεπτεί την κορυφή τότε το χρώμα της είναι 'w'. Όσο την επισκεπτόμαστε το χρώμα της είναι 'g'. Αφού την επισκεπτούμε το χρώμα της είναι 'b'.
	
	int i;
	
	//Αρχικοποίηση του πίνακα color
	for(i=0;i<order;i++)
	{
		color[i]='w';
	}
	
	//Για κάθε κορυφή
	for(i=0;i<order;i++)
	{
		//Αν δεν την έχουμε επισκεπτεί
		if(color[i]=='w')
		{
			//Αυξάνουμε το πλήθος των συνεκτικών συνιστωσών κατά 1
			cc++;
			//Επισκεπτόμαστε την κορυφή και κάθε κορυφή της συνεκτικής συνιστώσας στην οποία ανήκει η κορυφή
			DFSVisit(color,i);
		}
	}
	return cc;
}

void graph::DFSVisit(char color[],int u) //Η συνάρτηση DFSVisit προσπελάυνει τα στοιχεία της συνιστώσας που περιέχει την κορυφή που βρίσκεται στην θέση u στον πίνακα koryfes
{
	color[u]='g'; //Επισκεπτόμαστε την κορυφή στη θέση u
	int j;
	int th;

	for(j=0;j<koryfes[u].get_pl_edges();j++) //Για κάθε γειτονική κορυφή 
	{
		th=koryfes[u].get_th_edges(j);
		if(color[th]=='w') //Αν δεν την έχουμε επισκεπτεί
		{
			DFSVisit(color,th); //Την επισκεπτόμαστε
		}
	}
	color[u]='b'; //Έχουμε επισκεπτεί την κορυφή u
}

int graph::Dijkstra(int n1,int n2) //Συνάρτηση που εφαρμόζει τον αλγόριθμο του Dijkstra
{
	int th_s; //Θέση του κόμβου με τιμή n1 στον πίνακα koryfes
	int th2; //Θέση του κόμβου με τιμή n2 στον πίνακα koryfes
	int d[order]; //Ο ακέραιος πίνακας d περιέχει τις αποστάσεις όλων των κόμβων του γράφου από τον κόμβο με τιμή n1
	int i,j;
	int t1;
	int th;
	vertice u;
	bool f;

	//Αρχικοποίηση του πίνακα d με τον μεγαλύτερο ακέραιο (INT_MAX) και εύρεση των th_s,th2
	for(j=0;j<order;j++)
	{
		if(koryfes[j].getvalue()==n1)
		{
			th_s=j;
		}
		if(koryfes[j].getvalue()==n2)
		{
			th2=j;
		}
		d[j]=INT_MAX;
	}
	
	d[th_s]=0; //Η απόσταση του κόμβου με τιμή n1 από τον εαυτό του είναι 0

	minheap_gr Q1;
	for(i=0;i<order;i++) //Εισαγωγή των κόμβων του γράφου στον σωρό ελαχίστων
	{
		Q1.insert(koryfes[i],d[i],i);
	}
	while(Q1.getsize()!=0)
	{
		//Διαγραφή της ρίζας του σωρού και αποθήκευσή της στην κορυφή u
		u=Q1.deletemin();
		t1=u.get_th_ston_koryfes();

		//Ενημέρωση του πίνακα d αν με το στοιχείο που διαγράφηκε από τον σωρό μειώνεται κάποια από τις αποστάσεις του κόμβου με τιμή n1 προς κάποιον γειτονικό κόμβο της u
		for(i=0;i<u.get_pl_edges();i++)
		{
			f=false;
			th=u.get_th_edges(i);
			if(d[t1]+u.get_weights(i)<d[th])
			{
				d[th]=d[t1]+u.get_weights(i);
				Q1.decreasekey(koryfes[th],d[th]);
			}
		}
	}
	return d[th2]; //Επιστρέφεται η απόσταση του κόμβου με τιμή n2 από τον κόμβο με τιμή n1
}


//getters
int graph::getsize()
{
	return size;
}

int graph::getorder()
{
	return order;
}

vertice graph::getkoryfes(int i)
{
	return koryfes[i];
}
