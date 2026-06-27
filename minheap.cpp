#include "minheap.h"
#include <iostream>
#include <fstream>
using namespace std;


//Υλοποιώ μια getter για την τιμή του πίνακα value που βρίσκεται στη θέση i
int minheap::getvalue(int i)
{
    return value[i];
}

//Υλοποιούμε τον default constructor της minheap
minheap::minheap ()
{
    value = NULL;
    size = 0;
}


//Υλοποιούμε μία συνάρτηση με παράμετρο το όνομα του αρχείου από το οποίο δέχεται τα δεδομένα που εισάγει στο σωρό
void minheap::build (const char *filename)
{
    ifstream g;
    string value;
    
    g.open(filename);//Ανοίγουμε το αρχείο filename από το οποίο θα διαβάσουμε τα δεδομένα
    if(g.is_open()) //Ελέγχουμε αν το αρχείο άνοιξε επιτυχώς
    {
        size=0;
        
        while(g>>value) //Όσο το αρχείο έχει γραμμές που δεν έχουν διαβαστεί αποθήκευσε την επόμενη γραμμή του στον string value
        {
            insert(stoi(value)); //Εισάγουμε το στοιχείο με την τιμή που διαβάζουμε κάθε φορά από το αρχείο στον σωρό μεγίστων
        }
        
        g.close(); //Κλείνουμε το αρχείο
    }
    else
    {
        cerr<<"Couldn't open file."; //Αν το αρχείο δεν μπορεί να ανοίξει επιτυχώς εμφανίζουμε ένα μήνυμα σφάλαμτος στην οθόνη
    }
}

int minheap::getsize() //Δημιουργούμε μία συνάρτηση getsize η οποία επιστρέφει το size γιατί το size είναι private μεταβλητή
{
    return size;
}

int minheap::findmin() //Δημιουργούμε μία συνάρτηση findmin η οποία επιστρέφει το περιεχόμενο της θέσης 0 του πίνακα value γιατί αυτή είναι η τιμή του ελάχιστου στοιχείου του σωρού 
{
    return value[0];
}


void minheap::insert(int number) //Δημιουργούμε μία συνάρτηση insert η οποία εισάγει ένα στοιχείο στην κατάλληλη θέση του στον σωρό ελαχίστων. Το στοιχείο αυτό έχει τιμή που δίνεται ως παράμετρος στην συνάρτηση
{
    int h;
    int temp;
    int array[size+1]; //Δημιουργούμε έναν πίνακα ακεραίων ο οποίος έχει μέγεθος ίσο με το μέγεθος του value αυξημένο κατά 1
    
    
    for(h=0;h<size;h++)
    {
        array[h]=value[h]; //Στον νέο πίνακα αντιγράφουμε όλα τα στοιχεία του value
    }
    array[h]=number; //Στον νέο πίνακα προσθέτουμε το στοιχείο που θέλουμε να προσθέσουμε στον σωρό

    delete[] value; //Aποδεσμεύουμε τον χώρο που δεσεμεύσαμε για τον πίνακα value

    
    size++; //Αυξάνουμε το μέγεθος του πίνακα
    value=new int[size]; //Δεσμεύουμε τόσες θέσεις για τον πίνακα value όσες είναι το νέο μέγεθός του
    int x;
    for(x=0;x<size;x++)
    {
        value[x]=array[x]; //Αποθηκεύουμε τις τιμές του πίνακα array στον πίνακα value
    }
    
    
    int new_element_position; //Στην μεταβλητή new_element_position αποθηκεύουμε τη θέση του νέου στοιχείου στον πίνακα που περιέχει τα στοιχεία του σωρού
    int parent_position; //Στην μεταβλητή parent_position αποθηκεύουμε την θέση του γονέα του νέου στοιχείου
    
    new_element_position=x-1; //Το νέο στοιχείο έχει προστεθεί στην τελευταία θέση του πίνακα value 
    parent_position=(new_element_position-1)/2; //Σύμφωνα με τύπο που μας έχει δοθεί από την θεωρία αυτή είναι η θέση του γονέα του νέου στοιχείου στον σωρό
    
    while(value[new_element_position]<value[parent_position])//Όσο το νέο στοιχείο έχει μικρότερη τιμή από τον γονέα του
    {
        //Αντιμεταθέτουμε τα στοιχεία αυτά
        temp=value[new_element_position];
        value[new_element_position]=value[parent_position];
        value[parent_position]=temp;
        
        new_element_position=parent_position; //Ξαναϋπολογίζουμε την θέση του νέου στοιχείου
        parent_position=(new_element_position-1)/2; //Ξαναϋπολογίζουμε την θέση του γονέα του νέου στοιχείου
    }
}


void minheap::deletemin() //Δημιουργούμε μία συνάρτηση deletemin η οποία διαγράφει το ελάχιστο στοιχείο από τον σωρό ελαχίστων. Αυτό το πραγματοποιεί με την βοήθεια της συνάρτησης sortdeleted 
{
    
    value[0]=value[size-1]; //Εκχωρώ στο πρώτο στοιχείο του σωρού το τελευταίο, χάνοντας έτσι την τιμή του πρώτου
    size--; //Μειώνω το μέγεθος του σωρού κατά 1
    
    sortdeleted(0); //Καλώ την συνάρτηση sortdeleted η οποία κάνει τις κατάλληλες αντιμεταθέσεις έτσι ώστε ο σωρός ελαχίστων να εξακολουθήσει να είναι σωρός ελαχίστων
}

void minheap::sortdeleted(int parent_position) //Η sortdeleted δέχεται ως παράμετρο τη θέση ενός γονέα στον πίνακα value και ελέγχει αν το  παιδί με τη μικρότερη τιμή έχει τιμή μικρότερη από την τιμή του γονέα. Αν ναι, τότε τις αντιμεταθέτει και επαναλαμβάνει τον έλεγχο για τον νέο γονέα του και τα παιδιά του (αν έχει). Αν όχι τότε επιστρέφει.
{
    int temp;
    //Στη μεταβλητή left_child_position αποθηκεύεται η θέση του αριστερού παιδιού και στη μεταβλητή right_child_position αποθηκεύεται η θέση του δεξιού παιδιού
    int left_child_position,right_child_position; 
    left_child_position=2*parent_position+1;
    right_child_position=2*parent_position+2;
    
    //Ελέγχουμε αν ο γονέας έχει δεξί παιδί. Αν ναι τότε σίγουρα έχει αριστερό επειδή έχουμε σωρό ελαχίστων
    if(right_child_position<size)
    {
        if(value[left_child_position]<=value[right_child_position]) //Αν από τα δύο παιδιά αυτό με τη μικρότερη τιμή είναι το αριστερό τότε κάνε το αριστερό παιδί γονέα, κάνε τον γονέα αριστερό παιδί και πήγαινε να ελέγξεις αν ο γονέας που έγινε αριστερό παιδί έχει τιμή μικρότερη από τα νέα παιδιά του (αν έχει)
        {
            if(value[left_child_position]<value[parent_position]) //Η παραπάνω διαδικασία αν το αριστερό παιδί έχει μικρότερη τιμή ή τα δύο παιδιά έχουν την ίδια τιμή 
            {
                temp=value[left_child_position];
                value[left_child_position]=value[parent_position];
                value[parent_position]=temp;
                sortdeleted(left_child_position); //Καλούμε την sortdeleted για την θέση του αριστερού παιδιού που όμως πλέον περιέχει την τιμή του γονέα
            }
            else //Αν το παιδί με την μικρότερη τιμή δεν έχει τιμή μικρότερη από την τιμή του γονέα, δηλαδή αν η τιμή του γονέα είναι μικρότερη από τις τιμές και των δύο παιδιών του, τότε το δένδρο είναι σωρός ελαχίστων οπότε δεν χρειάζονται άλλες αντιμεταθέσεις
            {
                return;
            }
        }
        else
        {
            if(value[right_child_position]<value[parent_position]) //Η παραπάνω διαδικασία αν το δεξί παιδί έχει μικρότερη τιμή 
            {
                temp=value[right_child_position];
                value[right_child_position]=value[parent_position];
                value[parent_position]=temp;
                sortdeleted(right_child_position); //Καλούμε την sortdeleted για την θέση του δεξιού παιδιού που όμως πλέον περιέχει την τιμή του γονέα
            }
            else
            {
                return;
            }
        }
    } 
    else //Αλλιώς, δηλαδή αν ο γονέας δεν έχει δεξί παιδί
    {
        if(left_child_position<size) //Αν ο γονέας έχει μόνο αριστερό παίδι
        {
            if(value[left_child_position]<value[parent_position]) 
            {
                temp=value[left_child_position];
                value[left_child_position]=value[parent_position];
                value[parent_position]=temp;
                sortdeleted(left_child_position); //Καλούμε την sortdeleted για την θέση του αριστερού παιδιού που όμως πλέον περιέχει την τιμή του κόμβου
            }
            else //Αν το παιδί με την μικρότερη τιμή δεν έχει τιμή μικρότερη από την τιμή του γονέα, δηλαδή αν η τιμή του γονέα είναι μικρότερη από τις τιμές και των δύο παιδιών του, τότε το δένδρο είναι σωρός ελαχίστων οπότε δεν χρειάζονται άλλες αντιμεταθέσεις
            {
                return;
            }
        }
        else //Αν ο γονέας δεν έχει κανένα παιδί
        {
            return;
        }
    }
}
