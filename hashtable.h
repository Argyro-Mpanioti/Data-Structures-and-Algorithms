#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using namespace std;

class hashtable
{
private:
	int *data; //Ο δείκτης data χρησιμοποιείται για τη δημιουργία του δυναμικού πίνακα ακεραίων data ο οποίος είναι ο πίνακας κατακερματισμού μας
	int maxsize; //Η ακέραια μεταβλητή maxsize είναι το μέγεθος του πίνακα data
public:
	hashtable(); //Default κατασκευαστής της hashtable που αρχικοποιεί το maxsize με 50 και κάνει το data πίνακα με 50 θέσεις
	void build(const char* filename5); //Μία συνάρτηση που δέχεται ως παράμετρο το όνομα του αρχείου από το οποίο θα διαβάζει τα δεδομένα για την κατασκευή του πίνακα κατακερματισμού
	void insert(int n); //Με την συνάρητση insert εισάγουμε στον πίνακα κατακερματισμού το στοιχείο με τιμή n
	int getsize(); //Η συνάρτηση getsize υπολογίζει κι επιστρέφει το πλήθος των στοιχείων του πίνακα κατακερματισμού
	string search(int n); //Η συνάρτηση search αναζητάει το στοιχείο με τιμή n στον πίνακα κατακερματισμού και αν το βρει επιστρέφει το string "SUCCESS". Αλλιώς επιστρέφει το string "FAILURE".
};

#endif