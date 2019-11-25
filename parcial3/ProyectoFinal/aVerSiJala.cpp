#include <bits/stdc++.h>

using namespace std;

enum Color {Rojo, Negro};

struct Node
{
	int dato;
	bool color;
	Node *izquierda, *derecha, *padre;

	Node(int dato)
	{
	this->dato = dato;
	izquierda = derecha = padre = NULL;
	this->color = Rojo;
	}
};

class RBArbol
{
private:
	Node *raiz;
protected:
	void rotarizquierda(Node *&, Node *&);
	void rotarderecha(Node *&, Node *&);
	void fixViolation(Node *&, Node *&);
public:
	RBArbol() { raiz = NULL; }
	void insertar(const int &n);
	void inorder();
	void levelOrder();
};

void inorderHelper(Node *raiz)
{
	if (raiz == NULL)
		return;

	inorderHelper(raiz->izquierda);
	cout << raiz->dato << " ";
	inorderHelper(raiz->derecha);
}

Node* BSTinsertar(Node* raiz, Node *pt)
{
	if (raiz == NULL)
	return pt;

	if (pt->dato < raiz->dato)
	{
		raiz->izquierda = BSTinsertar(raiz->izquierda, pt);
		raiz->izquierda->padre = raiz;
	}
	else if (pt->dato > raiz->dato)
	{
		raiz->derecha = BSTinsertar(raiz->derecha, pt);
		raiz->derecha->padre = raiz;
	}

	return raiz;
}

void levelOrderHelper(Node *raiz)
{
	if (raiz == NULL)
		return;

	queue<Node *> q;
	q.push(raiz);

	while (!q.empty())
	{
		Node *temp = q.front();
		cout << temp->dato << " ";
		q.pop();

		if (temp->izquierda != NULL)
			q.push(temp->izquierda);

		if (temp->derecha != NULL)
			q.push(temp->derecha);
	}
}

void RBArbol::rotarizquierda(Node *&raiz, Node *&pt)
{
	Node *pt_derecha = pt->derecha;

	pt->derecha = pt_derecha->izquierda;

	if (pt->derecha != NULL)
		pt->derecha->padre = pt;

	pt_derecha->padre = pt->padre;

	if (pt->padre == NULL)
		raiz = pt_derecha;

	else if (pt == pt->padre->izquierda)
		pt->padre->izquierda = pt_derecha;

	else
		pt->padre->derecha = pt_derecha;

	pt_derecha->izquierda = pt;
	pt->padre = pt_derecha;
}

void RBArbol::rotarderecha(Node *&raiz, Node *&pt)
{
	Node *pt_izquierda = pt->izquierda;

	pt->izquierda = pt_izquierda->derecha;

	if (pt->izquierda != NULL)
		pt->izquierda->padre = pt;

	pt_izquierda->padre = pt->padre;

	if (pt->padre == NULL)
		raiz = pt_izquierda;

	else if (pt == pt->padre->izquierda)
		pt->padre->izquierda = pt_izquierda;

	else
		pt->padre->derecha = pt_izquierda;

	pt_izquierda->derecha = pt;
	pt->padre = pt_izquierda;
}

void RBArbol::fixViolation(Node *&raiz, Node *&pt)
{
	Node *padre_pt = NULL;
	Node *grande_padre_pt = NULL;

	while ((pt != raiz) && (pt->color != Negro) &&
		(pt->padre->color == Rojo))
	{

		padre_pt = pt->padre;
		grande_padre_pt = pt->padre->padre;

		if (padre_pt == grande_padre_pt->izquierda)
		{

			Node *uncle_pt = grande_padre_pt->derecha;

			if (uncle_pt != NULL && uncle_pt->color == Rojo)
			{
				grande_padre_pt->color = Rojo;
				padre_pt->color = Negro;
				uncle_pt->color = Negro;
				pt = grande_padre_pt;
			}

			else
			{

				if (pt == padre_pt->derecha)
				{
					rotarizquierda(raiz, padre_pt);
					pt = padre_pt;
					padre_pt = pt->padre;
				}

				rotarderecha(raiz, grande_padre_pt);
				swap(padre_pt->color, grande_padre_pt->color);
				pt = padre_pt;
			}
		}

		else
		{
			Node *uncle_pt = grande_padre_pt->izquierda;

			if ((uncle_pt != NULL) && (uncle_pt->color == Rojo))
			{
				grande_padre_pt->color = Rojo;
				padre_pt->color = Negro;
				uncle_pt->color = Negro;
				pt = grande_padre_pt;
			}
			else
			{

				if (pt == padre_pt->izquierda)
				{
					rotarderecha(raiz, padre_pt);
					pt = padre_pt;
					padre_pt = pt->padre;
				}

				rotarizquierda(raiz, grande_padre_pt);
				swap(padre_pt->color, grande_padre_pt->color);
				pt = padre_pt;
			}
		}
	}

	raiz->color = Negro;
}

void RBArbol::insertar(const int &dato)
{
	Node *pt = new Node(dato);

	raiz = BSTinsertar(raiz, pt);

	fixViolation(raiz, pt);
}

void RBArbol::inorder()	 { inorderHelper(raiz);}
void RBArbol::levelOrder() { levelOrderHelper(raiz); }

int main()
{
	RBArbol Arbol;

	Arbol.insertar(7);
	Arbol.insertar(6);
	Arbol.insertar(5);
	Arbol.insertar(4);
	Arbol.insertar(3);
	Arbol.insertar(2);
	Arbol.insertar(1);

	cout << "Inoder Traversal of Created Arbol\n";
	Arbol.inorder();

	cout << "\n\nLevel Order Traversal of Created Arbol\n";
	Arbol.levelOrder();

	return 0;
}
