#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashtable
{
private:
	int *data;
	int size;
public:

	//Κατασκευαστές

	hashtable(const hashtable &other); //Copy constructor της hashtable
	hashtable(const char* filename5); //Ένας κατασκευαστή πίνακα κατακερματισμού που να δέχεται ως παράμετρο το όνομα του αρχείου από το οποίο θα διαβάζει τα δεδομένα για την κατασκευή του πίνακα κατακερματισμού


};

#endif