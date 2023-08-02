#include <windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void menuLogo() {
    SetColor(4);
    cout << "     QQQQQQQQQ     UUUUUUUU     UUUUUUUUIIIIIIIIIIZZZZZZZZZZZZZZZZZZZ" << endl;
    cout << "   QQ:::::::::QQ   U::::::U     U::::::UI::::::::IZ:::::::::::::::::Z" << endl;
    cout << " QQ:::::::::::::QQ U::::::U     U::::::UI::::::::IZ:::::::::::::::::Z" << endl;
    cout << "Q:::::::QQQ:::::::QUU:::::U     U:::::UUII::::::IIZ:::ZZZZZZZZ:::::Z " << endl;
    cout << "Q::::::O   Q::::::Q U:::::U     U:::::U   I::::I  ZZZZZ     Z:::::Z  " << endl;
    cout << "Q:::::O     Q:::::Q U:::::D     D:::::U   I::::I          Z:::::Z    " << endl;
    cout << "Q:::::O     Q:::::Q U:::::D     D:::::U   I::::I         Z:::::Z     " << endl;
    cout << "Q:::::O     Q:::::Q U:::::D     D:::::U   I::::I        Z:::::Z      " << endl;
    cout << "Q:::::O     Q:::::Q U:::::D     D:::::U   I::::I       Z:::::Z       " << endl;
    cout << "Q:::::O     Q:::::Q U:::::D     D:::::U   I::::I      Z:::::Z        " << endl;
    cout << "Q:::::O  QQQQ:::::Q U:::::D     D:::::U   I::::I     Z:::::Z         " << endl;
    cout << "Q::::::O Q::::::::Q U::::::U   U::::::U   I::::I  ZZZ:::::Z     ZZZZZ" << endl;
    cout << "Q:::::::QQ::::::::Q U:::::::UUU:::::::U II::::::IIZ::::::ZZZZZZZZ:::Z" << endl;
    cout << " QQ::::::::::::::Q   UU:::::::::::::UU  I::::::::IZ:::::::::::::::::Z" << endl;
    cout << "   QQ:::::::::::Q      UU:::::::::UU    I::::::::IZ:::::::::::::::::Z" << endl;
    cout << "     QQQQQQQQ::::QQ      UUUUUUUUU      IIIIIIIIIIZZZZZZZZZZZZZZZZZZZ" << endl;
    cout << "             Q:::::Q                                                 " << endl;
    cout << "              QQQQQQ                                                 " << endl;
    SetColor(7);
}


class Player {
public:
    string _player;
    int _dogru;
    int _yanlis;
public:
    Player(string playerName)
    {
        _player = playerName;
        _dogru = 0;
        _yanlis = 0;
    }

    void increaseCorrectAnswerCount() {
        _dogru++;
    }

    void increaseWrongAnswerCount() {
        _yanlis++;
    }
};

class Sual {
    string _sual;
    string _A;
    string _B;
    string _C;
    string _dogrucavab;
    bool _saved;
public:
    Sual(string sual, string A, string B, string C, string dogrucavab, bool saved)
    {
        _sual = sual;
        _A = A;
        _B = B;
        _C = C;
        _dogrucavab = dogrucavab;
        _saved = saved;
    }
    string getCorrectVariant() {
        return _dogrucavab;
    }
    bool getSavedVariant() {
        return _saved;
    }
    void beSavedVariant() {
        _saved = true;
    }
    void printSual() {
        cout << "\t\t\t*****Questions*****" << endl;
        cout << _sual << endl;
        cout << "A) " << _A << endl;
        cout << "B) " << _B << endl;
        cout << "C) " << _C << endl;
    }
    friend class Quiz;
};

vector<Sual> suallarvector;
vector<Sual> quiz;
vector<Player> player;

class Quiz {
    string _name;
    vector<Sual> _sual;
public:
    Quiz(string name, vector<Sual> questions)
    {
        _sual = questions;
        _name = name;
    }
    void pushTextfile() {
        ofstream sualtxt;
        sualtxt.open(_name + ".txt", ios::out);
        for (size_t i = 0; i < _sual.size(); i++)
        {
            sualtxt << "Question " << i + 1 << " : " << _sual[i]._sual << endl;
            sualtxt << "Option A : " << _sual[i]._A << endl;
            sualtxt << "Option B : " << _sual[i]._B << endl;
            sualtxt << "Option C : " << _sual[i]._C << endl;
            sualtxt << "Correct Answer : " << _sual[i]._dogrucavab << endl;
            sualtxt << endl;
        }
        sualtxt.close();
    }
};

void readTXT(string txtLoc) {
    ofstream file(txtLoc, ios::out);
}

void createQuiz() {
    string quizname;
    char secim;
    int selectedOption = 1;
    int i = 1;
    system("CLS");
    cout << "Suallar listine ad daxil edin => ";
    cin >> quizname;
    system("CLS");
    while (true) {
        menuLogo();
        cout << endl;
        SetColor(4);
        cout << "\t ---Menu---" << endl;
        SetColor(7);
        cout << "[1] New Question" << endl;
        cout << "[2] Back" << endl;
        cout << "[3] Save" << endl;
        cout << endl;
        for (int i = 1; i <= 3; i++) {
            if (i == selectedOption) {
                SetColor(4);
            }
            cout << "[" << i << "]";
            SetColor(7);
            cout << " ";
        }

        secim = _getch();

        if (secim == 0 || secim == -32) {
            char klavyatura = _getch();
            if (klavyatura == 72) {
                selectedOption--;
                if (selectedOption < 1) {
                    selectedOption = 3;
                }
            }
            else if (klavyatura == 80) {
                selectedOption++;
                if (selectedOption > 3) {
                    selectedOption = 1;
                }
            }
        }

        if (secim == 13) {
            if (selectedOption == 1) {
                string sual;
                string optionA;
                string optionB;
                string optionC;
                string correctAnswer;
                cout << "Question " << i << ": ";
                cin.ignore();
                getline(cin, sual);
                cout << "Option A: ";
                getline(cin, optionA);
                cout << "Option B: ";
                getline(cin, optionB);
                cout << "Option C: ";
                getline(cin, optionC);
                cout << "Correct Answer: ";
                cin >> correctAnswer;
                Sual Q1(sual, optionA, optionB, optionC, correctAnswer, false);
                suallarvector.push_back(Q1);
                system("CLS");
                i++;
            }
            else if (selectedOption == 2) {
                system("CLS");
            }
            else if (selectedOption == 3) {
                Quiz A(quizname, suallarvector);
                A.pushTextfile();
                cout << "Suallar TXT-filesine ugurla yuklendi." << endl;
                system("CLS");
                break;
            }
        }
        system("CLS");
    }
}


int Dogrucavab = 0;
int Yanliscavab = 0;

void playSavedQuiz() {
    string quizname, guestName;
    int selectedOption = 1;

    cout << "Adinizi daxil edin: ";
    cin >> guestName;
    cin.ignore();
    Player currentPlayer(guestName);
    Sleep(1000);

    system("CLS");
    cout << "TXT File adini daxil edin: ";
    cin >> quizname;
    ifstream savedQuiz(quizname + ".txt");
    if (!savedQuiz) {
        cout << "TXT File tapilmadi!" << endl;
        return;
    }
    system("cls");
    while (true) {
        menuLogo();
        cout << endl;
        SetColor(4);
        cout << "\t ---Menu---" << endl;
        SetColor(7);
        cout << "[1] Next Question" << endl;
        cout << "[2] Back" << endl;
        cout << endl;
        for (int i = 1; i <= 2; i++) {
            if (i == selectedOption) {
                SetColor(4);
            }
            cout << "[" << i << "]";
            SetColor(7);
            cout << " ";
        }

        char secim = _getch();

        if (secim == 0 || secim == -32) {
            char klavyatura = _getch();
            if (klavyatura == 72) {
                selectedOption--;
                if (selectedOption < 1) {
                    selectedOption = 2;
                }
            }
            else if (klavyatura == 80) {
                selectedOption++;
                if (selectedOption > 2) {
                    selectedOption = 1;
                }
            }
        }

        if (secim == 13) {
            if (selectedOption == 1) {
                system("CLS");
                string line;
                string question;
                string optionA, optionB, optionC;
                string correctAnswer;

                if (!getline(savedQuiz, line)) {
                    break;
                }

                for (int j = 0; j < 5; j++) {
                    if (j == 0) {
                        question = line;
                    }
                    else if (j == 1) {
                        optionA = line;
                    }
                    else if (j == 2) {
                        optionB = line;
                    }
                    else if (j == 3) {
                        optionC = line;
                    }
                    else if (j == 4) {
                        correctAnswer = line.substr(line.find_last_of(':') + 2);
                    }

                    if (!getline(savedQuiz, line)) {
                        break;
                    }
                }

                cout << question << endl;
                cout << optionA << endl;
                cout << optionB << endl;
                cout << optionC << endl;
                cout << endl;

                string answer;
                cout << "Cavab: ";
                cin >> answer;

                if (answer == correctAnswer) {
                    Dogrucavab++;
                    currentPlayer.increaseCorrectAnswerCount();
                }
                else {
                    Yanliscavab++;
                    currentPlayer.increaseWrongAnswerCount();
                }

                system("CLS");
            }
            else if (selectedOption == 2) {
                savedQuiz.close();
                system("CLS");
                break;
            }
        }
    }

    ofstream playerFile("players.txt", ios::app);
    playerFile << "Name: " << currentPlayer._player << " Dogru Cavab: "  << currentPlayer._dogru << " Yanlis Cavab: " << currentPlayer._yanlis << endl;
    playerFile.close();

    cout << "Butun sullar tamamlandi !" << endl;
    cout << "Duzgun cavab: " << Dogrucavab << endl;
    cout << "Yanlis cavab: " << Yanliscavab << endl;
    Sleep(10000);

    system("CLS");
}


void guestMenu() {
    char secim;
    int selectedOption = 1;

    while (true) {
        system("CLS");
        menuLogo();
        cout << endl;
        SetColor(4);
        cout << "\t ----QUESTION GAME----" << endl;
        SetColor(7);
        cout << "[1] Create Quiz" << endl;
        cout << "[2] Continue" << endl;
        cout << "[3] Back" << endl;

        cout << endl;
        for (int i = 1; i <= 3; i++) {
            if (i == selectedOption) {
                SetColor(4);
            }
            cout << "[" << i << "]";
            SetColor(7);
            cout << " ";
        }
        secim = _getch();

        if (secim == 0 || secim == -32) {
            char klavyatura = _getch();
            if (klavyatura == 72) {
                selectedOption--;
                if (selectedOption < 1) {
                    selectedOption = 3;
                }
            }
            else if (klavyatura == 80) {
                selectedOption++;
                if (selectedOption > 3) {
                    selectedOption = 1;
                }
            }
        }

        if (secim == 13) {
            if (selectedOption == 1) {
                system("CLS");
                createQuiz();
            }
            else if (selectedOption == 2) {
                system("CLS");
                playSavedQuiz();
            }
            else if (selectedOption == 3) {
                system("CLS");
                break;
            }
        }
    }
}

void guestPlay() {
    guestMenu();
}

int main() {
    guestPlay();
    return 0;
}


// --------------------------------------------------------
/*Quiz Haqqinda
-Suallar TXT var continue secimi etdikden sonra sizden oyunumuz ad soruşur və sonra TXT filesinin adını
-TXT file adına final qeyd etməyiniz xaiş olunur əyərki öz yaratdığınız suallar varsa Həmən TXT filesinin adını daxil edin
-Suallar A-B-C Olaraq seçilmir ! Seçim etmək istediyiniz sualın cavabını yazmaqınız lazımdır Mələsən
A)Baku
B)Yasamal
C)Ayna sultanov

Cavab: Baku
Zəhmət olmasa cavab bölməsini bu formada doldurasınız.
Suallar txt file bittikden sonra Player TXT file yaranır ve dogru cavablarınız sehf cavablarınız adınız ilə birlikdə
Həmən TXT filesine qeyd olunur.
*/
// --------------------------------------------------------