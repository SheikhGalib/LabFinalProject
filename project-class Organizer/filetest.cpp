#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file;

    int n;
    cin>>n;
    file.open("Galib.txt", ios::in | ios:: out); // If only the file is present the file will be opened
    // But its like opening in write mode, it will delete anything the file was storing
    if (file.is_open())
    {
        cout<<"file opened successfully\n";
        file.close();
    }
    else{
        cout<<"Problem in opening the file\n";
    }
    // to open the file if it is not present then
    file.open("Okapia.txt", ios::trunc | ios:: in | ios:: out);

    if (file.is_open())
    {
        cout<<"file opened successfully\n";
        file.close();
    }
    else{
        cout<<"Problem in opening the file\n";
    }

    ofstream file2("Okapia2.txt"); // Automatically opens in trunc mode
    if (file2.is_open())
    {
        cout<<"File opened successfully\n";
        file2 << "Hello My firends\n" << " hello";
        file2 << "How are you just checking\n";
        file2.close();

        // file2.open("Okapia2.txt");
        // file2 << "When file is opened again, it removes any previous data\n";
        // file2 << "Thus gives us a new file each time\n";
        // file2.close();
    }
    else
    {
        cout<<"File nai hoi gesi\n";
    }

    ifstream file3("Okapia2.txt");

    if (file3.is_open())
    {
        string s;
        while(file3.good())
        {
            getline(file3, s);
            cout<<s<<endl;
        }
        file3.close();
    }
    else{
        cout<<"file e jhamela hoise\n";
    }

    fstream file4 ("Galib.txt", ios:: in | ios:: out | ios:: app); // Both for input ouput operation in append mode.
    if (file4.is_open())
    {
        // writing to the file.
        file4 << "Hola amigos, Lobon morich diya bhat khaisos\n thanks\n Ta Ta!\n";


        string s;
        file4.seekg(0); // write korar pore, cursor file er last e point kora chilo, oitare, abar shurute niya ashte hoise.
        while(file4.good())
        {
            getline(file4, s);
            cout<<s;
        }

    }
    else{
        cout<<"File mori gese\n";
    }
    

}