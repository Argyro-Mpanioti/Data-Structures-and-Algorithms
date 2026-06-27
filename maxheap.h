#ifndef MAXHEAP_H
#define MAXHEAP_H

class maxheap
{
private:
    int size; //Το μέγεθος του σωρού
    int *value; //Ο πίνακας με τις τιμές των κόμβων
public:
    maxheap(); //default κατασκευαστής που αρχικοποιεί το μέγεθος του σωρού με 0 και δίνει στον δείκτη value την τιμή NULL
    void build(const char *filename); //Συνάρτηση με όρισμα το όνομα του αρχείου από το οποίο διαβάζει τις τιμές του σωρού
    int getvalue(int i); //Getter για την τιμή της i θέσης του πίνακα value
    int getsize(); //Η συνάρτηση getsize είναι η getter που επιστρέφει το μέγεθος του σωρού
    int findmax(); //Η συνάρτηση getmax επιστρέφει το μέγιστο στοιχείο του σωρού
    void insert(int number); //Η συνάρτηση insert έχει ως όρισμα εναν ακέραιο αριθμό και εισάγει τον αριθμό στον σωρό μεγίστων
    void deletemax(); //Η συνάρτηση deletemax διαγράφει το μέγιστο στοιχείο από τον σωρό μεγίστων
    void sortdeleted(int parent); //Η συνάρτηση sortdeleted χρησιμοποιείται για την αντιμετάθεση στοιχείων του σωρού έτσι ώστε το στοιχείο goneas να βρίσκεται στη κατάλληλη θέση και το αντικείμενο να παραμείνει σωρός μεγίστων
};

#endif