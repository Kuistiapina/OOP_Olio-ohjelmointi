#include <iostream>
#include <student.h>
#include <vector>
#include <algorithm>

using namespace std;


int main ()
{
    int selection =0;
    vector<Student>studentList;
    string uusiNimi;
    int uusiIka;
    string etsittavaOppilas;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout << "Valitsit numeron 0: Uuden opiskelijan lisaaminen." << endl<<endl;
            cout << "Anna opiskelijan nimi: ";
            cin >> uusiNimi;
            cout << "Anna opiskelijan ika: ";
            cin >> uusiIka;
            studentList.emplace_back(uusiNimi, uusiIka);
            cout << "Lisattiin: " << uusiNimi << ", " << uusiIka << endl <<endl;
            break;

        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            cout << "Valitsit numeron 1: Tulostetaan kaikkien opiskelijoiden tiedot." << endl << endl;
            for (auto sl = studentList.begin(); sl != studentList.end(); ++sl){
                cout << "Oppilas " << sl->getName() << " on " << sl->getAge() << " vuotta vanha." << endl;
            }

            /*
             Vaihtoehtoinen looppaus for-eachilla:

            for (auto& sl : studentList){
                cout << "Oppilas " << sl.getName() << " on " << sl.getAge() << " vuotta vanha." << endl;
            }

            */
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            cout << "Valitsit numeron 2: Tulostetaan opiskeljoiden tiedot nimen mukaan." << endl << endl;
            // Lajitellaan lista (vektori) studentList sort-toiminnon avulla
            sort(studentList.begin(), studentList.end(), [](Student &a, Student &b){
                return a.getName() < b.getName();
            });
            for (auto& sl : studentList){
                sl.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            cout << "Valitsit numeron 3: Tulostetaan opiskelijoiden tiedot ian mukaan. " << endl << endl;
            // Lajitellaan lista (vektori) studentList sort-toiminnon avulla
            sort(studentList.begin(), studentList.end(), [](Student &a, Student &b){
                return a.getAge() < b.getAge();
            });
            for (auto& sl : studentList){
                sl.printStudentInfo();
            }
            break;

        case 4:{ // KOKO KEISSI AALTOSULKEISIIN MAHDOLLISTAA MUUTTUJAN ALUSTUKSEN SWITCH-CASEN SISÄLLÄ!!!

            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot
            cout << "Valitsit numeron 4: Opiskelijan tietojen haku nimen avulla." << endl << endl;
            cout << "Anna opiskelijan nimi: ";
            cin >> etsittavaOppilas;
            auto it = find_if(studentList.begin(),studentList.end(),[etsittavaOppilas](Student &a) {
               return a.getName() == etsittavaOppilas;
            });
            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                cout << "Oppilasta " << etsittavaOppilas << " ei loytynyt" << endl << endl;
            }
            break;
        }

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
    }
}while(selection < 5);

return 0;
}
