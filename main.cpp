/* Git: @Ch453d
 *
 * Ing. Christopher Daniel Ramírez Flores
 *
 * contacto: ramozchris@gmail.com
 *
 * Fecha de creación: 09//06//2022
 *
 * Última fecha de revisión: 09//06//2022
 *
 */


#include "DinamicList.h"
#include "StaticList.h"

vector<string> SplitSentence(string str);
bool MenuStaticArray(StaticList list);
bool MenuDinamicArray(DinamicList list);


int main()
{
    DinamicList dlist = *new DinamicList();
    StaticList slist = *new StaticList();

    int option;

    dlist.fromStream();

    while (true){

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "1. Static Array \n2. Dinamic Array \n 0. Exit" << endl << endl <<
                "ListCommand> ";


        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch(option){
            case 0:
                return 1;
            break;
            case 1:
                MenuStaticArray(slist);
            break;
            case 2:
                MenuDinamicArray(dlist);
            break;
        }




        system("pause");
        system("CLS");

    }



    cout << "Done!\n";
    return 0;
}

vector<string> SplitSentence(string str){
    vector<string> result;
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            result.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    result.push_back(word);
    return result;
}

bool MenuStaticArray(StaticList list){

    string sentence;

    while (true){

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "Type 'help' for help" << endl << endl <<
                "ListCommand> ";


        getline(cin, sentence);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        vector<string> words = SplitSentence(sentence);

        /*
        cout << "Size: " << words.size() << endl;
        for (int i=0 ; i< int(words.size()) ; i++){
            cout << i+1 << ": " << words[i] << endl;
        }
        */

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "Type 'help' for help" << endl <<endl;

        //--------------------------------------EXIT

        if(words[0] == "exit")
            return 0;

        //--------------------------------------HELP

        else if(words[0] == "help"){
            cout << "add # {first | last}" << endl <<
                    "show {# | all}" << endl <<
                    "exit" << endl;
        }

        //--------------------------------------ADD

        else if(words[0] == "add"){
            if(words[1] == "random" || words[1] == "rand" ){
                list.AddRandom(stoi(words[2]));
                cout << "[Ok] I added " << words[2] << " random values" << endl;
            }
            else if(words[2] == "first"){
                list.AddFirst(stoi(words[1]));
                cout << "[Ok] I added " << words[1] << " at the start" << endl;
            }
            else if(words[2] == "last"){
                //list.AddLast(stoi(words[1]));
                cout << "[Ok] I added " << words[1] << " at the end" << endl;
            }

        }

        //--------------------------------------SHOW

        else if(words[0] == "show"){
            if(words[1] == "all"){
                list.ShowAll();
            }
        }


        cout << endl << endl;


        system("pause");
        system("CLS");

    }

}

bool MenuDinamicArray(DinamicList list){
    string sentence;

    while (true){

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "Type 'help' for help" << endl << endl <<
                "ListCommand> ";


        getline(cin, sentence);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        vector<string> words = SplitSentence(sentence);

        /*
        cout << "Size: " << words.size() << endl;
        for (int i=0 ; i< int(words.size()) ; i++){
            cout << i+1 << ": " << words[i] << endl;
        }
        */

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "Type 'help' for help" << endl <<endl;

        //--------------------------------------EXIT

        if(words[0] == "exit")
            return 0;

        //--------------------------------------HELP

        else if(words[0] == "help"){
            cout << "add # {first | last}" << endl <<
                    "show {# | all}" << endl <<
                    "exit" << endl;
        }

        //--------------------------------------ADD

        else if(words[0] == "add"){
            if(words[1] == "random" || words[1] == "rand" ){
                list.AddRandom(stoi(words[2]));
                cout << "[Ok] I added " << words[2] << " random values" << endl;
            }
            else if(words[2] == "first"){
                list.AddFirst(stoi(words[1]));
                cout << "[Ok] I added " << words[1] << " at the start" << endl;
            }
            else if(words[2] == "last"){
                list.AddLast(stoi(words[1]));
                cout << "[Ok] I added " << words[1] << " at the end" << endl;
            }

        }

        //--------------------------------------SHOW

        else if(words[0] == "show"){
            if(words[1] == "first"){
                list.Print("First: ", list.GetFirst());
            }
            else if(words[1] == "last"){
                list.Print("Last: ", list.GetLast());
            }
            else if(words[1] == "all"){
                list.PrintAll();
            }
        }

        //--------------------------------------SEARCH

        else if(words[0] == "search"){
            if(words[1] == "position"){
                cout << "Value: " << list.SearchGetValue(stoi(words[2]));
            }
            else if(words[1] == "value"){
                cout << "Found at position: " << list.SearchGetPosition(stoi(words[2]));
            }

        }

        //--------------------------------------DELETE

        else if(words[0] == "delete"){
            if(words[1] == "all"){
                list.DeleteAll();
            }
            else if(words[1] == "position"){
                list.Delete(list.SearchByPosition(stoi(words[2])));
            }
            else if(words[1] == "value"){
                list.Delete(list.SearchByValue(stoi(words[2])));
            }
            else if(words[1] == "first"){
                if(list.DeleteFirst())
                    cout << "Deleted Succesfully." << endl;
                else
                    cout << "ERROR" << endl;
            }
            else if(words[1] == "last"){
                if(list.DeleteLast())
                    cout << "Deleted Succesfully." << endl;
                else
                    cout << "ERROR" << endl;
            }
        }

        //--------------------------------------SAVE

        else if(words[0] == "save"){
            list.toStream();
            cout << "Saved Succesfully." << endl;
        }

        //--------------------------------------RESTORE

        else if(words[0] == "restore"){
            list.fromStream();
            cout << "Restored Succesfully." << endl;
        }

        //--------------------------------------OpenFileSave

        else if(words[0] == "openfile"){
            list.OpenFileNotepad();
        }

        //--------------------------------------SORT

        else if(words[0] == "sort"){
            if(words[1] == "bubble"){
                list.BubbleSort();
            }
            else if(words[1] == "selection"){
                list.SelectionSort();
            }
            else if(words[1] == "insertion"){
                list.InsertionSort();
            }
            else if(words[1] == "quick"){
                list.QuickSort();
            }
            cout << "Sorted Succesfully." << endl;
        }



        cout << endl << endl;


        system("pause");
        system("CLS");

    }

}

/* Git: @Ch453d
 *
 * Ing. Christopher Daniel Ramírez Flores
 *
 * contacto: ramozchris@gmail.com
 *
 * Fecha de creación: 09//06//2022
 *
 * Última fecha de revisión: 09//06//2022
 *
 */
