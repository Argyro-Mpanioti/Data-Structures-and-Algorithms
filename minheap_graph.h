#ifndef MINHEAP_GR_H
#define MINHEAP_GR_H

#include "vertex.h"

class minheap_graph
{
private:
    int size; //Το μέγεθος του σωρού
    vertex *v; //Ο πίνακας με τις κορυφές των κόμβων του σωρού
    int *keys; 
    int *position_in_vertices; //Στον δυναμικό πίνακα position_in_vertices αποθηκεύονται οι θέσεις των κορυφών του πίνακα v στον πίνακα vertices
public:
    minheap_graph(); //default κατασκευαστής που αρχικοποιεί το μέγεθος του σωρού με 0 και δίνει στον δείκτη value την τιμή NULL
    vertex getv(int i); //Getter για την τιμή της i θέσης του πίνακα value
    int getsize(); //Η συνάρτηση getsize είναι η getter που επιστρέφει το μέγεθος του σωρού
    vertex findmin(); //Η συνάρτηση getmin επιστρέφει το ελάχιστο στοιχείο του σωρού
    void insert(vertex v1,int key,int position); //Η συνάρτηση insert έχει ως όρισμα mία κορυφή εισάγει στον σωρό ελαχίστων
    vertex deletemin(); //Η συνάρτηση deletemin διαγράφει το ελάχιστο στοιχείο από τον σωρό ελαχίστων
    void decreasekey(vertex v,int key); //Η συνάρτηση decreasekey εντοπίζει την κορυφή που δέχεται ως πρώτη παράμετρο στον σωρό, και σε εκείνο το στοιχείο του σωρού αποθηκεύει στο keys την 2η παράμετρο
    void sort(int position); //Η συνάρτηση sort φροντίζει έτσι ώστε κάθε φορά ο γονέας του στοιχείου της θέσης position στον σωρό να έχει μικρότερη τιμή keys από την τιμή keys του παιδιού
    void sortdeleted(int parent); //Η συνάρτηση sortdeleted χρησιμοποιείται για την αντιμετάθεση στοιχείων του σωρού έτσι ώστε το στοιχείο parent να βρίσκεται στη κατάλληλη θέση και το αντικείμενο να παραμείνει σωρός ελαχίστων
};

#endif
