#include "minheap_gr.h"
#include "vertex.h"
#include <iostream>
#include <fstream>
using namespace std;


//Υλοποιώ μια getter για την τιμή του πίνακα v που βρίσκεται στη θέση i
vertex minheap_gr::getv(int i)
{
    return v[i];
}

//Υλοποιούμε τον default constructor της minheap_gr
minheap_gr::minheap_gr ()
{
    v=NULL;
    keys=NULL;
    position_in_k=NULL;
    size=0;
}

int minheap_gr::getsize() //Δημιουργούμε μία συνάρτηση getsize η οποία επιστρέφει το size γιατί το size είναι private μεταβλητή
{
    return size;
}

vertex minheap_gr::findmin() //Δημιουργούμε μία συνάρτηση findmin η οποία επιστρέφει το περιεχόμενο της θέσης 0 του πίνακα v γιατί αυτή είναι η τιμή του ελάχιστου στοιχείου του σωρού
{
    return v[0];
}

void minheap_gr::sort(int position) //Η συνάρτηση sort φροντίζει έτσι ώστε κάθε φορά ο γονέας του στοιχείου της θέσης position στον σωρό να έχει μικρότερη τιμή keys από την τιμή keys του παιδιού. Αν αυτό δεν ισχύει τότε τα αντιμεταθέτει και επαναλαμβάνει τον έλεγχο για το στοιχείο που είναι πλέον γονέας. Αλλιώς επιστρέφει.
{
    int temp;
    vertex temp2;
    if(position==0) //Αν εξετάζουμε την ρίζα
    {
        return;
    }
    else if(keys[position]>keys[(position-1)/2]) //Αν ο γονέας του στοιχείου της θέσης position εχει μικρότερη τιμή keys από το στοιχείο της θέσης position
    {
        return;
    }
    else //Αλλιώς
    {
        //Αντιμεταθέτει τις τιμές τους
        
        temp=keys[position];
        keys[position]=keys[(position-1)/2];
        keys[(position-1)/2]=temp;
        
        temp2=v[position];
        v[position]=v[(position-1)/2];
        v[(position-1)/2]=temp2;

        temp=position_in_k[position];
        position_in_k[position]=position_in_k[(position-1)/2];
        position_in_k[(position-1)/2]=temp;

        //Επαναλαμβάνει τον έλεγχο για το στοιχείο που βρίσκεται πλέον στη θέση του προηγούμενου γονέα του
        sort((position-1)/2);
    }
}


void minheap_gr::insert(vertex v1,int key,int position) //Δημιουργούμε μία συνάρτηση insert η οποία εισάγει ένα στοιχείο στην κατάλληλη θέση του στον σωρό ελαχίστων. Οι πληροφορίες του στοιχείου αυτού δίνονται ως παράμετροι.
{
    v1.set_position_in_vertices(position);

    
    vertex *temp;
    temp=new vertex[size+1];
    int *temp2;
    temp2=new int[size+1];
    int *temp3;
    temp3=new int[size+1];
    
    int i;
    for(i=0;i<size;i++)
    {
        temp[i]=v[i];
        temp2[i]=keys[i];
        temp3[i]=position_in_k[i];
    }
    
    temp[i]=v1;
    temp2[i]=key;
    temp3[i]=position;
    
    delete []v;
    delete []keys;
    delete []position_in_k;
    
    v=temp;
    keys=temp2;
    position_in_k=temp3;
    
    sort(i);
    size++;
}

vertex minheap_gr::deletemin() //Δημιουργούμε μία συνάρτηση deletemin η οποία διαγράφει το ελάχιστο στοιχείο από τον σωρό ελαχίστων. Αυτό το πραγματοποιεί με την βοήθεια της συνάρτησης sortdeleted
{
    vertex r;
    r=v[0];
    //Εκχωρώ στο πρώτο στοιχείο του σωρού το τελευταίο, χάνοντας έτσι την τιμή του πρώτου
    keys[0]=keys[size-1];
    v[0]=v[size-1]; 
    size--; //Μειώνω το μέγεθος του σωρού κατά 1

    sortdeleted(0); //Καλώ την συνάρτηση sortdeleted η οποία κάνει τις κατάλληλες αντιμεταθέσεις έτσι ώστε ο σωρός ελαχίστων να εξακολουθήσει να είναι σωρός ελαχίστων

    return r;
}

void minheap_gr::sortdeleted(int parent_position) //Η sortdeleted δέχεται ως παράμετρο τη θέση ενός γονέα στον πίνακα v και ελέγχει αν το  παιδί με τη μικρότερη τιμή έχει τιμή μικρότερη από την τιμή του γονέα. Αν ναι, τότε τις αντιμεταθέτει και επαναλαμβάνει τον έλεγχο για τον νέο γονέα του και τα παιδιά του (αν έχει). Αν όχι τότε επιστρέφει.
{
    int temp;
    vertex temp2;
    //Στη μεταβλητή left_child_position αποθηκεύεται η θέση του αριστερού παιδιού και στη μεταβλητή right_child_position αποθηκεύεται η θέση του δεξιού παιδιού
    int left_child_position,right_child_position; 
    left_child_position=2*parent_position+1;
    right_child_position=2*parent_position+2;
    
    //Ελέγχουμε αν ο γονέας έχει δεξί παιδί. Αν ναι τότε σίγουρα έχει αριστερό επειδή έχουμε σωρό ελαχίστων
    if(right_child_position<size)
    {
        if(keys[left_child_position]<=keys[right_child_position]) //Αν από τα δύο παιδιά αυτό με τη μικρότερη τιμή είναι το αριστερό τότε κάνε το αριστερό παιδί γονέα, κάνε τον γονέα αριστερό παιδί και πήγαινε να ελέγξεις αν ο γονέας που έγινε αριστερό παιδί έχει τιμή μικρότερη από τα νέα παιδιά του (αν έχει)
        {
            if(keys[left_child_position]<keys[parent_position]) //Η παραπάνω διαδικασία αν το αριστερό παιδί έχει μικρότερη τιμή ή τα δύο παιδιά έχουν την ίδια τιμή 
            {
                temp=keys[left_child_position];
                keys[left_child_position]=keys[parent_position];
                keys[parent_position]=temp;
                
                temp2=v[left_child_position];
                v[left_child_position]=v[parent_position];
                v[parent_position]=temp2;

                temp=position_in_k[left_child_position];
                position_in_k[left_child_position]=position_in_k[parent_position];
                position_in_k[parent_position]=temp;

                sortdeleted(left_child_position); //Καλούμε την sortdeleted για την θέση του αριστερού παιδιού που όμως πλέον περιέχει την τιμή του γονέα
            }
            else //Αν το παιδί με την μικρότερη τιμή δεν έχει τιμή μικρότερη από την τιμή του γονέα, δηλαδή αν η τιμή του γονέα είναι μικρότερη από τις τιμές και των δύο παιδιών του, τότε το δένδρο είναι σωρός ελαχίστων οπότε δεν χρειάζονται άλλες αντιμεταθέσεις
            {
                return;
            }
        }
        else
        {
            if(keys[right_child_position]<keys[parent_position]) //Η παραπάνω διαδικασία αν το δεξί παιδί έχει μικρότερη τιμή 
            {
                temp=keys[right_child_position];
                keys[right_child_position]=keys[parent_position];
                keys[parent_position]=temp;
                
                temp2=v[right_child_position];
                v[right_child_position]=v[parent_position];
                v[parent_position]=temp2;

                temp=position_in_k[right_child_position];
                position_in_k[right_child_position]=position_in_k[parent_position];
                position_in_k[parent_position]=temp;
                
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
            if(keys[left_child_position]<keys[parent_position]) 
            {
                temp=keys[left_child_position];
                keys[left_child_position]=keys[parent_position];
                keys[parent_position]=temp;
                
                temp2=v[left_child_position];
                v[left_child_position]=v[parent_position];
                v[parent_position]=temp2;

                temp=position_in_k[left_child_position];
                position_in_k[left_child_position]=position_in_k[parent_position];
                position_in_k[parent_position]=temp;
                
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


void minheap_gr::decreasekey(vertex v1,int key) //Η συνάρτηση decreasekey εντοπίζει την κορυφή που δέχεται ως πρώτη παράμετρο στον σωρό, και σε εκείνο το στοιχείο του σωρού αποθηκεύει στο keys την 2η παράμετρο.
{
    int i;
    
    for(i=0;i<size;i++) //Για κάθε στοιχείο του σωρού
    {
        if(v1.getvalue()==v[i].getvalue()) //Αν αυτό είναι το στοιχείο που έχει κορυφή την v1 
        {
            //Το keys του γίνεται key
            keys[i]=key;
            //Γίνονται οι κατάλληλες αντιμεταθέσεις έτσι ώστε ο σωρός να παραμείνει σωρός ελαχίστων
            sortdeleted(i);
            sort(i);
        }
    }
}
