#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class DiffieHellman{
private:
    int p;
    int a;
    int X;
    long int k;
public:
    int Y1;
    double Y2;
    DiffieHellman() {p=19; a=3; X=0; k=0;Y1=0;Y2=0;}
    void Generate_Prik()
    {
        X = 1 + rand()%p;
    }

    void Generate_Pubk()
    {
        double a1 = a*1.0;
        Y1=pow(a1,X);
        Y1=Y1%p;
    }

    void Exchange_Pubk(double Y)
    {
        Y2 = Y;
    }

    void Generate_ShareKey()
    {
        k = pow(Y2,X);
        k = k%p;
    }

    void Print_X()
    {
        std::cout << X << std::endl;
        // print the private key
    }

    void Print_Y1()
    {
        std::cout << Y1 << std::endl;
    }

    void Print_Y2()
    {
        std::cout << Y2 << std::endl;
    }

    void Print_Sharekey()
    {
        std::cout << "K=" << k << std::endl;
    }

};

int main()
{
    srand((int)time(0));
    DiffieHellman A;
    DiffieHellman B;
    A.Generate_Prik();
    B.Generate_Prik();
    A.Generate_Pubk();
    B.Generate_Pubk();
    A.Exchange_Pubk(B.Y1);
    B.Exchange_Pubk(A.Y1);
    A.Generate_ShareKey();
    B.Generate_ShareKey();
    std::cout << "A,B generate private keys" << std::endl;
    std::cout << "XA = ";
    A.Print_X();
    std::cout << "XB = ";
    B.Print_X();
    std::cout << endl;
    cout << "A,B generate their public key" << endl;
    cout << "YA = ";
    A.Print_Y1();
    cout << "YB = ";
    B.Print_Y1();
    cout<<endl;
    cout << "A and B exchange their public key" << endl;
    cout << "A receives the public key from YB = ";
    A.Print_Y2();
    cout << "B receives the public key from YA = ";
    B.Print_Y2();
    cout << endl;
    cout << "A and B generate their shared secret key" << endl;
    cout << "A: " << "   ";
    A.Print_Sharekey();
    cout << "B: " << "   ";
    B.Print_Sharekey();
    return 0;

}