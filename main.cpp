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

        if(words[0] == "exit")
            return 0;
        else if(words[0] == "help"){
            cout << "add # {first | last}" << endl <<
                    "show {# | all}" << endl <<
                    "exit" << endl;
        }
        else if(words[0] == "add"){
            if(words[2] == "last"){
                list.AddLast(stoi(words[1]));
                cout << "Ok i added " << words[1] << " at the end" << endl;
            }
        }
        else if(words[0] == "show"){
            if(words[1] == "all"){
                list.PrintAll();
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
