
// Ugur AKYOL
#include<iostream>
#include<cstring>
#include<string>
#include <time.h>
#include<stdlib.h>
using namespace std;



//for tree
struct  node {

	struct data{
	char title;
	int weight;
	}dt;
	struct node * left;
	struct node * right;
};
struct  node tree;


//for stack
struct nodes
{
    char title;
    int weight;
    struct nodes *next;
};

struct nodec
{
    char item; struct nodec *next;
};

//stack's functions

// nodec functions
struct nodec * createNodec(char data);

struct nodec * push(struct nodec *header, char data);

struct nodec *deleteFront(struct nodec *header);

struct nodec *pop(struct nodec *header);

void displaystackc(struct nodec *header);


// nodes functions
struct nodes * createNodes(char title,int weight);

struct nodes * pushtonodes(struct nodes *header, char title, int weight);

struct nodes * pushendofnodes(struct nodes *header, char title, int weight);

struct nodes *deleteFrontofnodes(struct nodec *header);

struct nodes *popfromnodes(struct nodes *header);

void displaystacknodes(struct nodes *header);

void swap(struct nodes * x, struct nodes * y);

void sortstack(struct nodes *data);







//tree's functions
int is_empty(struct mode *tree);
struct node * newNode(int w, char t);
struct node *createtree(struct node *tree);
struct node * insertLeft(struct node * , struct node *);
struct node * insertRight(struct node * , struct node *);
void inorderTraverse(struct node *tree);
void preorderTraverse(struct node * tree);
void postorderTraverse(struct node * tree);
int height(struct node * tree);
int max(int i, int j);
int size(struct node * tree);
struct node * deletion(struct node *, int);
int sum(struct node * tree);

string title;
void header(string title);
void writemenu(void);
//void createtree(struct node *tree);

void writetree(void);
void submenu(void);
void bfs(struct node *tree);
void ucs(struct node *tree);
void dfs(struct node *tree);



int main (void)
{
    system("clear");
    title= "Search Simulator";
    header(title);

    struct node *tree = NULL;

    tree=createtree(tree);

/*
    cout<<"a) In - Order Traversal -> Infix Form (left, root, right) : \n";
    inorderTraverse(tree);
    cout<<endl;
    cout<<endl;

    cout<<"b) Pre - Order Traversal -> Prefix Form (root, left, right) : \n";
    preorderTraverse(tree);
    cout<<endl;
    cout<<endl;

    cout<<"c) Post - Order Traversal -> Postfix Form (left, right, root) : \n";
    postorderTraverse(tree);
    cout<<endl;
    cout<<endl;
*/

    writemenu();


    return 0;
}




struct node * createtree(struct node *tree)
{

    tree=newNode(0,'S');

    tree->left=newNode(12,'G');
    tree->right=newNode(1,'A');

    tree->right->left=newNode(1,'C');
    tree->right->right=newNode(3,'B');

    tree->right->left->left=newNode(2,'G');
    tree->right->left->right=newNode(1,'D');
    tree->right->right->left=newNode(3,'D');

    tree->right->left->right->left=newNode(3,'G');
    tree->right->right->left->right=newNode(3,'G');

    return tree;

}

void writetree(void)
{

}

// this funwrite menu
void writemenu(void)
{
    char choise=' ';
    do
    {   char flag=' ';
        while(flag==' ')
        {
        cout<<"   Main Menu"<<endl;
        cout<<"1) Breadth First Search (BFS)"<<endl;
        cout<<"2) Uniform Cost Search (UCS)"<<endl;
        cout<<"3) Depth First Search (DFS)"<<endl;
        cout<<"4) End Program"<<endl;
        cout<<"Option >";

        // keyboard selection

        //printf("\nType in a number \n");
        cin>>choise;
        // this is clear the screen
        system("clear");

        // get the selection

        switch (choise)
        {
        case '1':
            header(title);
            bfs(&tree);
            break;

        case '2':
            header(title);
            ucs(&tree);
            break;

        case '3':

            header(title);

            dfs(&tree);

            submenu();

            break;


        case '4':
            header(title);
            cout<<"4) End Program \n\n";
            submenu();
            break;

        default:
           // header();
            cout<<"Please, enter a number between 1 and 4 \n";

            break;
        }
        cin>>flag;

        }

    }
    while(choise!='4');


}

void submenu(void)
{
    cout<<"8) Press <8> to Main Menu \n";
    cout<<"9) Press <9> to Exit \n";
    cout<<"Option >";
    char key;
    cin>>key;
    switch(key)
    {
        case '8':
            main();
        break;

        case '9':
            exit(0);
        break;

        default:
            cout<<"Please, enter a number between 8 and 9 \n";
            submenu();
        break;
    }


}

void bfs(struct node *tree)
{
    cout<<"1) Breadth First Search (BFS) \n\n";

    char title;
    int weight;
    int totalweights;

    tree=createtree(tree);

    if(&tree==NULL)
		return;
    struct nodes *header = NULL;

    cout<<"ROUTE      QUEUE"<<endl;
    // first level
    cout<<"  "<<tree->dt.title<<"        ";

    title=tree->right->dt.title;
    weight=tree->right->dt.weight;
	header = pushtonodes(header,title,weight);
    title=tree->left->dt.title;
    weight=tree->left->dt.weight;
    header = pushendofnodes(header,title,weight);

	//sortstack(header);
	displaystacknodes(header);
	totalweights=weight;

    // second level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);

    title=tree->right->left->dt.title;
    weight=weight+tree->right->left->dt.weight;//2
	header = pushendofnodes(header,title,weight);
	weight=weight-tree->right->left->dt.weight;

    title=tree->right->right->dt.title;
    weight=weight+tree->right->right->dt.weight;//4
    header = pushendofnodes(header,title,weight);
    weight=weight-tree->right->right->dt.weight;//1

	//sortstack(header);
	displaystacknodes(header);

    // third level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    weight=weight+tree->right->left->dt.weight;
    title=tree->right->left->left->dt.title;
    weight=weight+tree->right->left->left->dt.weight;
    header = pushendofnodes(header,title,weight);
    weight=weight-tree->right->left->left->dt.weight;
	header = pushendofnodes(header,title,weight);

    title=tree->right->left->right->dt.title;
    weight=weight+tree->right->left->right->dt.weight;
    header = pushendofnodes(header,title,weight);
    weight=weight-tree->right->left->right->dt.weight;
	header = pushendofnodes(header,title,weight);
	//sortstack(header);
	displaystacknodes(header);
/*
    // fourd level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    weight=weight+tree->right->left->right->dt.weight;
    title=tree->right->left->right->left->dt.title;
    weight=weight+tree->right->left->right->left->dt.weight;
	header = pushendofnodes(header,title,weight);
	//sortstack(header);
	displaystacknodes(header);

    // fifhlevel
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    displaystacknodes(header);
*/
    cout<<endl<<endl;




    submenu();

}

void ucs(struct node *tree)
{
    cout<<"2) Uniform Cost Search (UCS) \n\n";

    char title;
    int weight;
    int totalweights;

    tree=createtree(tree);

    if(&tree==NULL)
		return;
    struct nodes *header = NULL;

    cout<<"ROUTE      QUEUE"<<endl;
    // first level
    cout<<"  "<<tree->dt.title<<"        ";

    title=tree->left->dt.title;
    weight=tree->left->dt.weight;
	header = pushtonodes(header,title,weight);

    title=tree->right->dt.title;
    weight=tree->right->dt.weight;
    header = pushtonodes(header,title,weight);
	sortstack(header);
	displaystacknodes(header);
	totalweights=weight;

    // second level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);

    title=tree->right->left->dt.title;
    weight=weight+tree->right->left->dt.weight;//2
	header = pushtonodes(header,title,weight);
	weight=weight-tree->right->left->dt.weight;

    title=tree->right->right->dt.title;
    weight=weight+tree->right->right->dt.weight;//4
    header = pushtonodes(header,title,weight);
    weight=weight-tree->right->right->dt.weight;//1

	sortstack(header);
	displaystacknodes(header);

    // third level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    weight=weight+tree->right->left->dt.weight;
    title=tree->right->left->left->dt.title;
    weight=weight+tree->right->left->left->dt.weight;
    header = pushtonodes(header,title,weight);
    weight=weight-tree->right->left->left->dt.weight;
	header = pushtonodes(header,title,weight);

    title=tree->right->left->right->dt.title;
    weight=weight+tree->right->left->right->dt.weight;
    header = pushtonodes(header,title,weight);
    weight=weight-tree->right->left->right->dt.weight;
	header = pushtonodes(header,title,weight);
	sortstack(header);
	displaystacknodes(header);

    // fourd level
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    weight=weight+tree->right->left->right->dt.weight;
    title=tree->right->left->right->left->dt.title;
    weight=weight+tree->right->left->right->left->dt.weight;
	header = pushtonodes(header,title,weight);
	sortstack(header);
	displaystacknodes(header);

    // fifhlevel
    cout<<"  "<<header->title<<"        ";
	header=popfromnodes(header);
    displaystacknodes(header);

    cout<<endl<<endl;

    submenu();

}


void dfs(struct node *tree)
{

    cout<<"3) Depth First Search (DFS) \n\n";
    char data;

    tree=createtree(tree);

    if(&tree==NULL)
		return;
    struct nodec *header = NULL;

    cout<<"ROUTE      QUEUE"<<endl;
	cout<<"  "<<tree->dt.title<<"        ";

    data=tree->left->dt.title;
	header = push(header,data);
	data=tree->right->dt.title;
	header = push(header,data);
	displaystackc(header);

	header=pop(header);
	//deleteFront(header);

	cout<<"  "<<data<<"        ";
    data=tree->right->left->dt.title;
    header = push(header,data);
	data=tree->right->right->dt.title;
	header = push(header,data);
	displaystackc(header);
    header=pop(header);
	cout<<"  "<<data<<"        ";
	data=tree->right->right->left->dt.title;
	header = push(header,data);
	displaystackc(header);
    header=pop(header);
    cout<<"  "<<data<<"        ";
	data=tree->right->right->left->right->dt.title;
	header = push(header,data);
	displaystackc(header);
	header=pop(header);
	cout<<"  "<<data<<"        ";
    displaystackc(header);
    cout<<endl;

    return;
}

void header(string title)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    cout<<"\n~~~~~~~~~~~~~~~~~~  2018/2019  ~~~~~~~~~~~~~~~~~~\n";
    cout<<"       ~ Artificial Inteligent Homework ~        \n\n";
    printf("              %s \n", asctime(timeinfo) );
    cout<<"  STUDENT                      INSTRUCTOR        \n";
    cout<<" UGUR AKYOL            ASST. PROF. Kamil Yurtkan \n";
    cout<<"  2016903\n\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"      "<<title<<"\n\n";
}

int is_empty(struct mode *tree)
{
	if(tree==NULL)
return 1;
else
return 0;
}

struct node * newNode(int w, char t)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(node));
	temp->dt.weight = w;
	temp->dt.title = t;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node * insertLeft(struct node * tree, struct node *p)
{
	if(tree == NULL)
		return p;
	tree->left=insertLeft(tree->left, p);
	return tree;
}

struct node * insertRight(struct node * tree, struct node *p)
{
	if(tree ==NULL)
		return p;
	tree->right=insertRight(tree->right, p);
	return tree;
}

void inorderTraverse(struct node *tree)
{
	if(tree==NULL)
		return;
	inorderTraverse(tree->left);
	//cout<<tree->dt.title<<" ";
	cout<<"("<<tree->dt.title<<"-"<<tree->dt.weight<<") ";
	inorderTraverse(tree->right);
}


void preorderTraverse(struct node * tree)
{
	if(tree==NULL)
		return;
	//cout<<tree->dt.weight<<" ";
	cout<<"("<<tree->dt.title<<"-"<<tree->dt.weight<<") ";
	preorderTraverse(tree->left);
	preorderTraverse(tree->right);
}


void postorderTraverse(struct node * tree)
{
	if(tree==NULL)
		return;
	postorderTraverse(tree->left);
	postorderTraverse(tree->right);
	//cout<<tree->dt.weight<<" ";
	cout<<"("<<tree->dt.title<<"-"<<tree->dt.weight<<") ";
}

/*

struct node * deletion(struct node * tree, int d)
{
	struct node * temp;
	if(tree ==NULL)
      return NULL;
	if(d < tree->data)
	{ tree->left = deletion(tree->left, d);
	  return tree; }
	if(d > tree->data)
	{ tree->right = deletion(tree->right, d);
	  return tree;}
	//at this point, we know that d=tree->data
	if(tree->left==NULL && tree->right==NULL)
	{ free(tree);
	  return NULL;}
	if(tree->left==NULL)
	{ temp=tree->right;
	  free(temp);
	  return temp;}
	if(tree->right==NULL)
	{ temp=tree->left;
	  free(temp);
	  return temp;}

	temp=tree->left;
	temp=insertRight(temp, tree->right);
	free(tree);
	return temp;
}
*/
/*
int sum(struct node * tree)
{
    int a,b;
	if(tree==NULL)
		return 0;
	a=sum(tree->left);
    b=sum(tree->right);
    return (a + b + tree->data);
}
*/

int height(struct node * tree)
{
    int a,b,h;
	if(tree==NULL)
       return -1;
	a=height(tree->left);
	b=height(tree->right);
    if (a>b)
       h=a+1;
    else
       h=b+1;
	return h;
}

// stack's functions
// nodec functions
struct nodec * createNodec(char data)
{
     struct nodec * temp;
     temp = (struct nodec *) malloc(sizeof(nodec));
     temp->item = data;
     temp->next = NULL;
     return temp;
}
struct nodec * push(struct nodec *header, char data)
{
     struct nodec * temp = createNodec(data);
     temp->next = header;
     header=temp;
     return header;
}
struct nodec *deleteFront(struct nodec *header)
{
    struct nodec *temp;
    if(header==NULL)
        return header;
    temp=header;
	header= header->next;
    free(temp);
    return header;
}
struct nodec *pop(struct nodec *header)
{
    struct nodec *temp;
    if(header==NULL)
        return header;
    temp=header;
	header=header->next;
    free(temp);
    return header;
}

void displaystackc(struct nodec *header)
{
    if (header == NULL)
        cout << "List is empty" << endl;
    struct nodec *temp = header;
    while (temp != NULL)
    {
        cout << " -> "<< temp->item ;
        temp=temp->next;
    }
    cout << endl;
}


// nodes functions
struct nodes * createNodes(char title,int weight)
{
     struct nodes * temp;
     temp = (struct nodes *) malloc(sizeof(nodes));
     temp->title = title;
     temp->weight = weight;
     temp->next = NULL;
     return temp;
}
struct nodes * pushtonodes(struct nodes *header, char title, int weight)
{
     struct nodes * temp = createNodes(title,weight);
     temp->next = header;
     header=temp;
     return header;
}
struct nodes *deleteFrontofnodes(struct nodes *header)
{
    struct nodes *temp;
    if(header==NULL)
        return header;
    temp=header;
	header= header->next;
    free(temp);
    return header;
}
struct nodes *popfromnodes(struct nodes *header)
{
    struct nodes *temp;
    if(header==NULL)
        return header;
    temp=header;
	header=header->next;
    free(temp);
    return header;
}

void displaystacknodes(struct nodes *header)
{
    if (header == NULL)
        cout << "List is empty" << endl;
    struct nodes *temp = header;
    while (temp != NULL)
    {
        cout << " -> "<< temp->title ;
        temp=temp->next;
    }
    cout << endl;
}

struct nodes * pushendofnodes(struct nodes *header, char title, int weight)
{

    struct nodes *temp = header;
    while (temp != NULL)
    {
        //cout << " -> "<< temp->title ;
        if (temp->next == NULL)
        {
            struct nodes * tempnew = createNodes(title,weight);
            temp->next = tempnew;
            //header=temp;
            return header;
        }
        temp=temp->next;
    }

}

void swap(struct nodes * x, struct nodes * y)
{

    int temp_weight=x->weight;
    x->weight=y->weight;
    y->weight=temp_weight;

    char temp_title=x->title;
    x->title=y->title;
    y->title=temp_title;
}

void sortstack(struct nodes *data)
{
    int control=1;
    struct nodes *tempdata=data;
    struct nodes *tempsort;
    if (tempdata == NULL)
        exit(0);

    while(control){
        control=0;
        tempdata=data;

        while (tempdata->next!=NULL) {
            if (tempdata->weight>tempdata->next->weight)
            {
                swap(tempdata,tempdata->next);
                control=1;
            }

            tempdata=tempdata->next;
        }
        tempsort=tempdata;
    }

        data=tempsort;
}

