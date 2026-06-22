#include "minheap_gr.h"
#include "vertice.h"
#include <iostream>
#include <fstream>
using namespace std;


//Υλοποιώ μια getter για την τιμή του πίνακα v που βρίσκεται στη θέση i
vertice minheap_gr::getv(int i)
{
    return v[i];
}

//Υλοποιούμε τον default constructor της minheap_gr
minheap_gr::minheap_gr ()
{
    v=NULL;
    keys=NULL;
    th_ston_k=NULL;
    size=0;
}

int minheap_gr::getsize() //Δημιουργούμε μία συνάρτηση getsize η οποία επιστρέφει το size γιατί το size είναι private μεταβλητή
{
    return size;
}

vertice minheap_gr::findmin() //Δημιουργούμε μία συνάρτηση findmin η οποία επιστρέφει το περιεχόμενο της θέσης 0 του πίνακα v γιατί αυτή είναι η τιμή του ελάχιστου στοιχείου του σωρού 
{
    return v[0];
}

void minheap_gr::sort(int th) //Η συνάρτηση sort φροντίζει έτσι ώστε κάθε φορά ο γονέας του στοιχείου της θέσης th στον σωρό να έχει μικρότερη τιμή keys από την τιμή keys του παιδιού. Αν αυτό δεν ισχύει τότε τα αντιμεταθέτει και επαναλαμβάνει τον έλεγχο για το στοιχείο που είναι πλέον γονέας. Αλλιώς επιστρέφει.
{
    int temp;
    vertice temp2;
    if(th==0) //Αν εξετάζουμε την ρίζα
    {
        return;
    }
    else if(keys[th]>keys[(th-1)/2]) //Αν ο γονέας του στοιχείου της θέσης th εχει μικρότερη τιμή keys από το στοιχείο της θέσης th
    {
        return;
    }
    else //Αλλιώς
    {
        //Αντιμεταθέτει τις τιμές τους
        
        temp=keys[th];
        keys[th]=keys[(th-1)/2];
        keys[(th-1)/2]=temp;
        
        temp2=v[th];
        v[th]=v[(th-1)/2];
        v[(th-1)/2]=temp2;

        temp=th_ston_k[th];
        th_ston_k[th]=th_ston_k[(th-1)/2];
        th_ston_k[(th-1)/2]=temp;

        //Επαναλαμβάνει τον έλεγχο για το στοιχείο που βρίσκεται πλέον στη θέση του προηγούμενου γονέα του
        sort((th-1)/2);
    }
}


void minheap_gr::insert(vertice v1,int key,int th) //Δημιουργούμε μία συνάρτηση insert η οποία εισάγει ένα στοιχείο στην κατάλληλη θέση του στον σωρό ελαχίστων. Οι πληροφορίες του στοιχείου αυτού δίνονται ως παράμετροι. 
{
    v1.set_th_ston_koryfes(th);

    
    vertice *temp;
    temp=new vertice[size+1];
    int *temp2;
    temp2=new int[size+1];
    int *temp3;
    temp3=new int[size+1];
    
    int i;
    for(i=0;i<size;i++)
    {
        temp[i]=v[i];
        temp2[i]=keys[i];
        temp3[i]=th_ston_k[i];
    }
    
    temp[i]=v1;
    temp2[i]=key;
    temp3[i]=th;
    
    delete []v;
    delete []keys;
    delete []th_ston_k;
    
    v=temp;
    keys=temp2;
    th_ston_k=temp3;
    
    sort(i);
    size++;
}

vertice minheap_gr::deletemin() //Δημιουργούμε μία συνάρτηση deletemin η οποία διαγράφει το ελάχιστο στοιχείο από τον σωρό ελαχίστων. Αυτό το πραγματοποιεί με την βοήθεια της συνάρτησης sortdeleted 
{
    vertice r;
    r=v[0];
    //Εκχωρώ στο πρώτο στοιχείο του σωρού το τελευταίο, χάνοντας έτσι την τιμή του πρώτου
    keys[0]=keys[size-1];
    v[0]=v[size-1]; 
    size--; //Μειώνω το μέγεθος του σωρού κατά 1

    sortdeleted(0); //Καλώ την συνάρτηση sortdeleted η οποία κάνει τις κατάλληλες αντιμεταθέσεις έτσι ώστε ο σωρός ελαχίστων να εξακολουθήσει να είναι σωρός ελαχίστων

    return r;
}

void minheap_gr::sortdeleted(int goneas) //Η sortdeleted δέχεται ως παράμετρο τη θέση ενός γονέα στον πίνακα v και ελέγχει αν το  παιδί με τη μικρότερη τιμή έχει τιμή μικρότερη από την τιμή του γονέα. Αν ναι, τότε τις αντιμεταθέτει και επαναλαμβάνει τον έλεγχο για τον νέο γονέα του και τα παιδιά του (αν έχει). Αν όχι τότε επιστρέφει.
{
    int temp;
    vertice temp2;
    //Στη μεταβλητή apaidi αποθηκεύεται η θέση του αριστερού παιδιού και στη μεταβλητή dpaidi αποθηκεύεται η θέση του δεξιού παιδιού
    int apaidi,dpaidi; 
    apaidi=2*goneas+1;
    dpaidi=2*goneas+2;
    
    //Ελέγχουμε αν ο γονέας έχει δεξί παιδί. Αν ναι τότε σίγουρα έχει αριστερό επειδή έχουμε σωρό ελαχίστων
    if(dpaidi<size)
    {
        if(keys[apaidi]<=keys[dpaidi]) //Αν από τα δύο παιδιά αυτό με τη μικρότερη τιμή είναι το αριστερό τότε κάνε το αριστερό παιδί γονέα, κάνε τον γονέα αριστερό παιδί και πήγαινε να ελέγξεις αν ο γονέας που έγινε αριστερό παιδί έχει τιμή μικρότερη από τα νέα παιδιά του (αν έχει)
        {
            if(keys[apaidi]<keys[goneas]) //Η παραπάνω διαδικασία αν το αριστερό παιδί έχει μικρότερη τιμή ή τα δύο παιδιά έχουν την ίδια τιμή 
            {
                temp=keys[apaidi];
                keys[apaidi]=keys[goneas];
                keys[goneas]=temp;
                
                temp2=v[apaidi];
                v[apaidi]=v[goneas];
                v[goneas]=temp2;

                temp=th_ston_k[apaidi];
                th_ston_k[apaidi]=th_ston_k[goneas];
                th_ston_k[goneas]=temp;

                sortdeleted(apaidi); //Καλούμε την sortdeleted για την θέση του αριστερού παιδιού που όμως πλέον περιέχει την τιμή του γονέα
            }
            else //Αν το παιδί με την μικρότερη τιμή δεν έχει τιμή μικρότερη από την τιμή του γονέα, δηλαδή αν η τιμή του γονέα είναι μικρότερη από τις τιμές και των δύο παιδιών του, τότε το δένδρο είναι σωρός ελαχίστων οπότε δεν χρειάζονται άλλες αντιμεταθέσεις
            {
                return;
            }
        }
        else
        {
            if(keys[dpaidi]<keys[goneas]) //Η παραπάνω διαδικασία αν το δεξί παιδί έχει μικρότερη τιμή 
            {
                temp=keys[dpaidi];
                keys[dpaidi]=keys[goneas];
                keys[goneas]=temp;
                
                temp2=v[dpaidi];
                v[dpaidi]=v[goneas];
                v[goneas]=temp2;

                temp=th_ston_k[dpaidi];
                th_ston_k[dpaidi]=th_ston_k[goneas];
                th_ston_k[goneas]=temp;
                
                sortdeleted(dpaidi); //Καλούμε την sortdeleted για την θέση του δεξιού παιδιού που όμως πλέον περιέχει την τιμή του γονέα
            }
            else
            {
                return;
            }
        }
} 
    else //Αλλιώς, δηλαδή αν ο γονέας δεν έχει δεξί παιδί
    {
        if(apaidi<size) //Αν ο γονέας έχει μόνο αριστερό παίδι
        {
            if(keys[apaidi]<keys[goneas]) 
            {
                temp=keys[apaidi];
                keys[apaidi]=keys[goneas];
                keys[goneas]=temp;
                
                temp2=v[apaidi];
                v[apaidi]=v[goneas];
                v[goneas]=temp2;

                temp=th_ston_k[apaidi];
                th_ston_k[apaidi]=th_ston_k[goneas];
                th_ston_k[goneas]=temp;
                
                sortdeleted(apaidi); //Καλούμε την sortdeleted για την θέση του αριστερού παιδιού που όμως πλέον περιέχει την τιμή του κόμβου
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


void minheap_gr::decreasekey(vertice v1,int key) //Η συνάρτηση decreasekey εντοπίζει την κορυφή που δέχεται ως πρώτη παράμετρο στον σωρό, και σε εκείνο το στοιχείο του σωρού αποθηκεύει στο keys την 2η παράμετρο.
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