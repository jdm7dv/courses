// Examples 10.63 and 10.64

#include <iostream>
using std::cout;

class person {
public:
    int id;
};

class system_user {
public:
    int id;
};

class student : public virtual person, public system_user {
};

class professor : public virtual person, public system_user {
};

class student_prof : public student, public professor {
};

int main() {
    student_prof sp;

    student* std = &sp;
    professor* prof = &sp;
    person* std_p = std;
    person* prof_p = prof;
    system_user* std_u = std;
    system_user* prof_u = prof;

    std_u->id = 1;
    prof_u->id = 2;     // separate from std_u->id
    std_p->id = 3;
    prof_p->id = 4;     // overwrites std_p->id

    cout << std_u->id << " "
         << prof_u->id << " "
         << std_p->id << " "
         << prof_p->id << "\n";
}
