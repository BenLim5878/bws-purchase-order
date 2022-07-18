#pragma once
#include "DataAccess.h"
#include <iomanip>

using namespace std;

namespace ViewComponent {
    class UserTable {
    public:
        LinkedList<User>* data = nullptr;
        UserTable(LinkedList<User>* data) {
            this->data = data;
        }

        void show() {
            int max_username_string_space = 0;
            for (int i = 0; i < this->data->length; i++) {
                int stringLen = this->data->get(i)->name.length();
                if (max_username_string_space < stringLen) {
                    max_username_string_space = stringLen;
                }
            }

            int max_email_string_space = 0;
            for (int i = 0; i < this->data->length; i++) {
                int stringLen = this->data->get(i)->emailAddress.length();
                if (max_email_string_space < stringLen) {
                    max_email_string_space = stringLen;
                }
            }

            std::cout << "==========================================================================================================" << endl;
            cout
                << left
                << setw(10)
                << "UserID"
                << left
                << setw(5 + max_username_string_space)
                << "UserName"
                << setw(6 + max_email_string_space)
                << left
                << "Email"
                << left
                << setw(25)
                << "Role"
                << left
                << setw(15)
                << "Phone NO"
                << left
                << setw(22)
                << "IC NO"
                << endl;
            std::cout << "==========================================================================================================" << endl;

            int totalUser = 0, totalAdmin = 0, totalSOE = 0;

            for (int i = 0; i < this->data->length; i++) {
                User* user = this->data->get(i);
                totalUser++;
                if (user->role == UserRole::Admin)
                {
                    totalAdmin++;
                }
                else
                {
                    totalSOE++;
                }
                cout
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(7)
                    << user->getUserID()
                    << left
                    << setw(5 + max_username_string_space)
                    << user->name
                    << left
                    << setw(6 + max_email_string_space)
                    << user->emailAddress
                    << left
                    << setw(25)
                    << User::userRoleToString(user->role)
                    << left
                    << setw(15)
                    << user->phoneNo
                    << left
                    << setw(12)
                    << user->nationalID
                    << endl;
            }
            cout << endl;
            cout << "==============================" << endl;
            cout << "User Table Summary" << endl;
            cout << "==============================" << endl;

            cout << "Total User: " << totalUser << endl;
            cout << "Total Admin: " << totalAdmin << endl;
            cout << "Total Sales Order Executive: " << totalSOE << endl;
        };
    };
}


