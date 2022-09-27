/*Program Shift Cipher
Nama    : Nanda Raihan Sukma
NPM     : 140810200015    
Kelas   : A
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//enkripsi
string encrypt(string text, int key)
{
    string answer = "";
    for (char ch : text)
    {
        if (islower(ch))    // jika huruf lowercase
        {
            ch = (((ch - 97) + key) % 26) + 97;
        }
        else if (isupper(ch))   // jika huruf uppercase
        {
            ch = (((ch - 65) + key) % 26) + 65;
        }
        answer.push_back(ch);
    }
    return answer;
}
//deskripsi
string decrypt(string text, int key)
{
    string answer = "";
    for (char ch : text)
    {
        if (islower(ch))    // jika huruf lowercase
        {
            ch = ((ch + (26 - key) - 97) % 26) + 97;
        }
        else if (isupper(ch)) // jika huruf uppercase
        {
            ch = ((ch + (26 - key) - 65) % 26) + 65;
        }
        answer.push_back(ch);
    }
    return answer;
}


int main()
{
    string plain_text = "";
    string cipher_text = "";
    int key;
    int pilihan = 1;
    while (pilihan != 0)
    {
        cout << "------------------------\nMenu:\n1. Enkripsi\n2. Dekripsi\n0. Keluar\n";
        cout << "------------------------\nMasukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 0)
            cout << "keluar";
        else
        {
            switch (pilihan)
            {
            case 1:
                cout << "Enter plain text: ";
                cin.ignore();
                getline(cin, plain_text);
                cout << "Enter key: ";
                cin >> key;
                cipher_text = encrypt(plain_text, key);
                cout<<"Encryption:\n";
                cout << "Cipher Text: " << cipher_text << "\n";
                cout<<"Decryption:\n";
	            cout<<"Plain Text: "<<decrypt(cipher_text, key)<<endl;
                break;
            case 2:
                cout << "Enter cipher text: ";
                cin.ignore();
                getline(cin, cipher_text);
                cout << "Enter key: ";
                cin >> key;
                plain_text = decrypt(cipher_text, key);
                cout<<"Decryption:\n";
                cout << "Plain Text: " << plain_text << "\n";
                cout<<"encryption:\n";
	            cout<<"Cipher Text: "<<encrypt(plain_text, key)<<endl;
                break;
            default:
                cout << "input salah!\n";
                break;
            }
        }
    }
}