#ifndef VERTICE_H
#define VERTICE_H


class vertex //Η κλάση vertice έχει για αντικείμενά της τις κορυφές του γράφου
{
private:
	int value; //Η τιμή της κορυφής
	vertex *edges; //Στον δυναμικό πίνακα edges αποθηκεύονται όλες οι κορυφές με τις οποίες συνδέεται η συγκεριμένη κορυφή
	int edges_count; //Στην μεταβλητή edges_count αποθηκεύεται το πλήθος των προσπίπτουσων ακμών της συγκεριμένης κορυφής 
	int *weights; //Στον δυναμικό πίνακα weights αποθηκεύονται τα βάρη όλων των ακμών με τις οποίες είναι συνδεδεμένη η συγκεριμένη κορυφή. Στη θέση i του πίνακα weights αποθηκεύεται το βάρος της ακμής που συνδέει την συγκεριμένη κορυφή με την κορυφή edges[i]
	int *edges_positions; //Στον δυναμικό πίνακα edges_positions αποθηκεύονται οι θέσεις όλων των κορυφών με τις οποίες συνδέεται η συγκεριμένη κορυφή στον πίνακα vertices
	int position_in_vertices; //Η θέση της στον πίνακα vertices

public:
	vertex(); //default κατασκευαστής
	vertex(int value); //Κατασκευαστής με παράμετρο την τιμή της κορυφής
	vertex(const vertex& other); //Copy constructor
	void insert(vertex v2,int w,int t); //Η insert εισάγει στον γράφο την ακμή που συνδέει την κορυφή με την κορυφή v2 με βάρος w
	void delete_edge(vertex v2); //Η delete_edge διαγράφει από τον γράφο την ακμή που συνδέει την κορυφή με την κορυφή v2

	
	//getters
	int getvalue();
	int get_edges_count();
	vertex get_edges(int i);
	int get_weights(int i);
	int get_position_in_vertices();
	int get_edges_positions(int i);

	//setters
	void set_value(int i);
	void set_edges_count(int i);
	void set_weights(int i,int j);
	void set_edges(int i,vertex j);
	void set_position_in_vertices(int i);

	void operator=(const vertex& s)
    { 
        value=s.value;
		edges=s.edges;
		edges_positions=s.edges_positions;
		edges_count=s.edges_count;
		weights=s.weights;
		position_in_vertices=s.position_in_vertices;
    } 
};


#endif 
