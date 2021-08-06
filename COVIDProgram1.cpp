#include <iostream>

using namespace std;

class ForUser {
    private:

    void askUserQuestions(){

        string userInfo[] = {"Title (Mr, Mrs,Ms)",
                                "First Name",
                                "Middle Name",
                                "Last Name",
                                "Age",
                                "Gender",
                                "Job",
                                "Weight",
                                "Height",
                                "Phone No",
                                "Address" };

        string userArray[0];

        for(int i = 0; i <= 10; i++) {
            cout << "Enter your " << userInfo[i] << "!" << endl;
            cin >> userArray[i];
        }

        cout << "\n \n";
        cout << "Patient Information : " << endl;
        cout << "Name : " << userInfo[0] << ". " << userInfo[1] << " "
        << userInfo[2] << " " << userInfo[3] << endl << "Age : " << userInfo[4] << endl << "Gender : "
        << userInfo[5] << endl << "Job : " << userInfo[6] << endl << "Weight : " << userInfo[7] << " lb" << endl << "Height : "
        << userInfo[8] << " ft" << endl << "Address : " << userInfo[10] << "\n \n";
    }

    public:
    void interface_UserInfo () {
        askUserQuestions();
    }
};

class COVIDQuestion {
    private:

    void askCOVIDQuestion () {

        string questions[] = {"fever",
                                 "sore throat",
                                 "tiredness",
                                 "loss of taste or smell",
                                 "difficulty breathing or shortness of breath",
                                 "chest pain or pressure",
                                 "loss of speech or movement"};
        int marks[] = {5, 10, 5, 15, 30, 15, 20};
        char answer;
        int marksForQuestion;
        int totalMarks = 0;

        cout << "Please answer the following question for your COVD-19 Test." << "\n \n";

        for (int i = 0; i < 7; i++) {
            cout << "Are you having " << questions[i] << "? " << "(" << marks[i] << "% )" <<endl;
            cin >> answer;

            switch (answer)
            {
            case 'Y':
            case 'y':
            marksForQuestion= marks[i];
                break;
            case 'N':
            case 'n':
            marksForQuestion = 0;
            default:
                break;
            }

            totalMarks += marksForQuestion;
        }

        if (totalMarks >= 60) {
            cout << "You may be Positive!" << "( " << totalMarks << "% ) \n \n";
        } else {
            cout << "You may not be Positive" << "( " << totalMarks << "% ) \n \n";
        }

    }

    public:
    void interface_COVIDProgram () {
        askCOVIDQuestion();
    }

};

bool loop_Program () {

    char answerToStop;
    for(int j = 1; j > 0; j++) {
        cout << "Do you want to test for next person ? ( Y/n ) " << "\n";
        cin >> answerToStop;
        switch (answerToStop)
        {
            case 'Y':
            case 'y':
            ForUser User_Info;
            User_Info.interface_UserInfo();

            COVIDQuestion COVID_Info;
            COVID_Info.interface_COVIDProgram();
             break;
            case 'N':
            case 'n':
            cout << "Thanks for your time!";
            return false;
            break;
        }
    }
    return true;
}

int main() {

    ForUser User_Info;
    User_Info.interface_UserInfo();

    COVIDQuestion COVID_Info;
    COVID_Info.interface_COVIDProgram();

    loop_Program();

    return 0;
}
