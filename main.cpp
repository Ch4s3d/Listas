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


#include "List.h"

vector<string> SplitSentence(string str);

int main()
{
    List list = *new List();

    for(int i=0 ; i<=10 ; i++){
        list.AddLast(rand());
    }

    string sentence;

    system("pause");

    while (true){

        system("CLS");

        cout << "Lists C++ example" << endl <<
                "Type 'help' for help" << endl <<endl;


        getline(cin, sentence);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        vector<string> words = SplitSentence(sentence);


        cout << "Size: " << words.size() << endl;
        for (int i=0 ; i< int(words.size()) ; i++){
            cout << i+1 << ": " << words[i] << endl;
        }

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
            if(words[2] == "first"){
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
            if(words[1] == "position"){
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


        cout << endl << endl;

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
