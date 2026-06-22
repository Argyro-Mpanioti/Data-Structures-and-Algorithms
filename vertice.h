#ifndef VERTICE_H
#define VERTICE_H


class vertice //Η κλάση vertice έχει για αντικείμενά της τις κορυφές του γράφου
{
private:
	int value; //Η τιμή της κορυφής
	vertice *edges; //Στον δυναμικό πίνακα edges αποθηκεύονται όλες οι κορυφές με τις οποίες συνδέεται η συγκεριμένη κορυφή 
	int pl_edges; //Στην μεταβλητή pl_edges αποθηκεύεται το πλήθος των προσπίπτουσων ακμών της συγκεριμένης κορυφής 
	int *weights; //Στον δυναμικό πίνακα weights αποθηκεύονται τα βάρη όλων των ακμών με τις οποίες είναι συνδεδεμένη η συγκεριμένη κορυφή. Στη θέση i του πίνακα weights αποθηκεύεται το βάρος της ακμής που συνδέει την συγκεριμένη κορυφή με την κορυφή edges[i]
	int *th_edges; //Στον δυναμικό πίνακα th_edges αποθηκεύονται οι θέσεις όλων των κορυφών με τις οποίες συνδέεται η συγκεριμένη κορυφή στον πίνακα koryfes
	int th_ston_koryfes; //Η θέση της στον πίνακα koryfes

public:
	vertice(); //default κατασκευαστής
	vertice(int value); //Κατασκευαστής με παράμετρο την τιμή της κορυφής
	vertice(const vertice& other); //Copy cosntructor
	void insert(vertice v2,int w,int t); //Η insert εισάγει στον γράφο την ακμή που συνδέει την κορυφή με την κορυφή v2 με βάρος w
	void delete_edge(vertice v2); //Η delete_edge διαγράφει από τον γράφο την ακμή που συνδέει την κορυφή με την κορυφή v2

	
	//getters
	int getvalue();
	int get_pl_edges();
	vertice get_edges(int i);
	int get_weights(int i);
	int get_th_ston_koryfes();
	int get_th_edges(int i);

	//setters
	void set_value(int i);
	void set_pl_edges(int i);
	void set_weights(int i,int j);
	void set_edges(int i,vertice j);
	void set_th_ston_koryfes(int i);

	void operator=(const vertice& s) 
    { 
        value=s.value;
		edges=s.edges;
		th_edges=s.th_edges;
		pl_edges=s.pl_edges;
		weights=s.weights;
		th_ston_koryfes=s.th_ston_koryfes;
    } 
};


#endif 