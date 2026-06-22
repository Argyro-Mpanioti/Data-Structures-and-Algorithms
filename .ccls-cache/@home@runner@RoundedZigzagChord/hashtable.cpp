#include "hashtable.h"
#include <fstream>
#include <iostream>
using namespace std;


hashtable::hashtable(const hashtable &other) //Copy constructor της hashtable
{
	int i;
	for(i=0;i<)
}


hashtable::hashtable(const char* filename) //Ένας κατασκευαστή πίνακα κατακερματισμού που να δέχεται ως παράμετρο το όνομα του αρχείου από το οποίο θα διαβάζει τα δεδομένα για την κατασκευή του πίνακα κατακερματισμού
{
	ifstream l;
	int n1;
	size=0;
	
    l.open(filename);//Ανοίγουμε το αρχείο filename από το οποίο θα διαβάσουμε τα δεδομένα
    if(l.is_open()) //Ελέγχουμε αν το αρχείο άνοιξε επιτυχώς
    {
        while(l.eof()==false)
        {
			size++;
        }
        l.(); //Κλείνουμε το αρχείο
		while(l.eof()==false)
        {
			l.seekg(0);
              //  ()>>n1; //Αποθηκεύω την τιμή της γραμμής του αρχείου στη μεταβλητή n1
			insert(n1);//Εισάγουμε στον πίνακα κατακερματισμού την τιμή n1 αν αυτή δεν υπάρχει ήδη.
			
        }
        l.close(); //Κλείνουμε το αρχείο
		
    }
    else
    {
        cerr<<"Couldn't open file."; //Αν το αρχείο δεν μπορεί να ανοίξει επιτυχώς εμφανίζουμε ένα μήνυμα σφάλαμτος στην οθόνη
    }
}
