#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
using namespace std;

#include "node.h"

class avltree
{
public:
    int size; //Η μεταβλητή size είναι το μέγεθος του δένδρου avl
    node *root; //Ο δείκτης root σε αντικείμενο τύπου node είναι ο δείκτης που δείχνει στην ρίζα του δένδρου
public:
    avltree(); //default κατασκευαστής που αρχικοποιεί το μέγεθος του δένδρου με 0 και δίνει στον δείκτη root την τιμή NULL
    void build(const char *filename); //Συνάρτηση με παράμετρο το όνομα του αρχείου από το οποίο διαβάζει τις τιμές του δένδρου avl
    void insert(int number); //Συνάρτηση που εισάγει ένα  νούμερο στο δένδρο avl
    int getsize(); //getter του size
    int foo(node *node,int height); //Συνάρτηση με την οποία βρίσκω το υψος ενός δένδρου με ρίζα τον κόμβο node
    int findmin();
    void inorder(node *node); //Ενδοδιατεταγμένη προσπέλαση του δένδρου avl
    void preorder(node *node); //Προδιατεταγμένη προσπέλαση του δένδρου avl
    void right(node *node); //Συνάρτηση που υλοποιεί την δεξιά περιστροφή
    void left(node *node); //Συνάρτηση που υλοποιεί την αριστερή περιστροφή
    void peristrofes(node *node);
    string search(int n); //Η συνάρτηση search αναζητάει το στοιχείο με τιμή n στο δένδρο AVL και αν το βρει επιστρέφει το string "SUCCESS" αλλιώς επιστρέφει το string "FAILURE"
    void delete_node(int number); //Δημιουργούμε μία συνάρτηση delete η οποία διαγράφει ένα στοιχείο από το δένδρο avl ετσι ώστε αυτό να παραμείνει δένρο avl
};

#endif
