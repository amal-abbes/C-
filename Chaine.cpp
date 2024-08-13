#include <iostream>
#include <string.h>
using namespace std1;

class Chaine
{   int lg;
    char *s;
    public:
        Chaine (char *x=NULL);
        ~Chaine (){delete [] s;}
        Chaine (const Chaine &);
        Chaine &operator= (const Chaine &);
        Chaine operator+ (const Chaine &);
        Chaine &operator+= (const Chaine &);
        friend ostream &operator<< (ostream &, const Chaine &);
};
//--------------------------- Méthodes de la classe Chaine ---------------------
Chaine::Chaine (char *x)
{
    if (x!=NULL)
    {lg = strlen (x);
    s=new char [lg+1];
    if (s==NULL)cout<<"\nERREUR  Memoire";
    else
        strcpy(s,x);
    }
}
//---------------------------------------------------------------
Chaine::Chaine(const Chaine &x)
{
    lg=x.lg;
    if (lg>0)
    {
        s=new char [lg+1];
        if (s==NULL)cout<<"\nERREUR  Memoire";
        else
            strcpy(s,x.s);
    }
}
//--------------------------------
Chaine Chaine::operator+ (const Chaine &x)
{
    Chaine w;
    w.lg=lg+x.lg;
    w.s=new char [w.lg+1];
    if (w.s==NULL)cout<<"\nERREUR  Memoire";
    else
        { strcpy (w.s,s);
            strcpy(w.s+lg,x.s);
        }
    return w;
}
//----------------------------------------
Chaine &Chaine::operator= (const Chaine &x)
{
    delete []s;
    lg=x.lg;
    s=new char [lg+1];
    if (s==NULL)cout<<"\nERREUR  Memoire";
    else
    {
        strcpy(s,x.s);
    }
    return *this;
}
//--------------------------------------------
Chaine &Chaine::operator+= (const Chaine &x)
{
    char *q;
    q=new char [lg+x.lg+1];
    if (q==NULL)cout<<"\nERREUR  Memoire";
    else
    {
        strcpy(q,s);
        strcpy (q+lg,x.s);
        lg=lg+x.lg;
        delete [] s;
        s=q;
    }
    return *this;
}
//---------------------------------------------

ostream &operator<< (ostream &Toto , const Chaine &x)
{
    Toto<<x.s;
    return Toto;
}
main ()
{
    Chaine CH1 ("Salut");
    Chaine CH2;
    Chaine CH3=CH1;
    CH2= "Bonjour";
    cout << "Bonjour : " << CH2<<endl;
    CH2 = CH1;
    cout << "Salut : " << CH2<<endl;
    CH2 = (Chaine)"Bonjour" + "Monsieur";
    cout << "Bonjour Monsieur : " << CH2<<"\n";
    CH2= CH1 + CH3;
    cout << "Salut Salut : " << CH2<<"\n";
    CH2 += CH1;
    cout << "Salut Salut Salut : " << CH2<<"\n";

}
