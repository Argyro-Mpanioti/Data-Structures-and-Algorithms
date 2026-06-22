#ifndef NODE_H
#define NODE_H

class node //Υλοποιώ μία βοηθητική κλάση node που θα έχει για αντικείμενά της τους κόμβους των δένδρων avl
{
private:
    int value; //Στην ακέραια μεταβλητή value αποθηκεύω την τιμή του κόμβου
    node *lc; //Στον δείκτη σε κόμβο lc αποθηκεύουμε το αριστερό παιδί του κόμβου. Αν ο κόμβος δεν έχει αριστερό παιδί τότε ο δείκτης παίρνει την τιμή NULL.
    node *rc; //Στον δείκτη σε κόμβο rc αποθηκεύουμε το δεξί παιδί του κόμβου. Αν ο κόμβος δεν έχει δεξί παιδί τότε ο δείκτης παίρνει την τιμή NULL.
    node *pr; //Στον δείκτη σε κόμβο pr αποθηκεύουμε τον γονέα του κόμβου. Αν ο κόμβος είναι η ρίζα τότε ο δείκτης παίρνει την τιμή NULL.
public:
    node();
    node(int value);
    
    //Setters και getters για τις private μεταβλητές της
    
    void setvalue(int number);
    void setlc(node *left_child);
    void setrc(node *right_child);
    void setpr(node *parent);
    int getvalue();
    node *getlc();
    node *getrc();
    node *getpr();
};

#endif
