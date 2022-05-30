#include<iostream>
#include<conio.h>
using namespace std;

class graph 
{
    private:
//<=============================structure=============================>
int n;
        int **Adj;
        public:
        //<========================constructor=========================>
      /*  graph()
        {

            
        }*/
        //<=========================create=============================>
graph * create (int n)
{
    
    graph *g = new graph;
    g->n = n;
    g->Adj = new int*[n];

    for (int x = 0; x < n;x++)
        g->Adj[x] = new int[n];
for (int x = 0; x < g->n; x++)
            {
                for (int y = 0; y< g->n; y++)
                   g-> Adj[x][y] = 0;
            }

    return g;
}


void conect (int row , int col)
{

    if(row<n&&row>-1 && col<n &&col>-1)
    {
        Adj[row][col] = 1;
        cout << "\nSucssecful  conect.";
    }

    else{

        cout << "\nWorng error!";
    }


}
void disconect (int row , int col)
{

    if(row<n&&row>-1 && col<n &&col>-1)
    {
        Adj[row][col] = 0;
        cout << "\nSucssecful  disconect.";
    }

    else{

        cout << "\nWorng error!";
    }


}
void show ()
{

    for (int x = 0;x < this->n;x++)
    {
        for (int y = 0; y < this->n; y++)
        {
            if(this->Adj[x][y]==1)
                {cout << "V." << x << "<------------>V." << y;
                    cout << endl;
                }
        }
    }
}
void menu ()
{
    for (int x = 0; x < this->n; x++)
    {
        cout << "V." << x << "   ";
    }

        cout << "\n1.conect\n2.disconnnect\n3.show\n4.restart\n5.exit";
}
};



int main()
{
    restart:
        graph j;
        graph *g;
        system("cls");
        cout << "Enter no of vertex -";
        int n;
        cin >> n;
        g = j.create(n);

        while (1)
        {
            system("cls");

            g->menu();
            cout << "\nenter - ";
            cin >> n;
            switch (n)
            {
            case 1 :
                cout << "\nEnter vertix number whose you want to conect";
                int k, l;
                cin >> k >> l;
                g->conect(k, l);
                getch();
                break;
                case 2 :
                cout << "\nEnter vertix number whose you want to disconect";
                int m, n;
                cin >> m >> n;
                g->disconect(m, n);
                getch();
                break;
                case 3 :
                    g->show();
                    getch();
                    break;

                    case 4:
                        goto restart;
                        case 5:
                            exit(1);
                }
    }




}