#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student{
    string name;
    double score;
};

int main()
{
    ifstream read("val.txt");
    
    if(!read.is_open()){
        cout << "file cannot open!!" << endl;
        return 0;
    }
    
    Student st;
    
    vector<Student> students;
    
    double scores_sum = 0;
    int num_stu = 0;
    
    while(read>>st.name>>st.score){
        cout << st.name << " has score " << st.score << endl;
        students.push_back(st);
        scores_sum += st.score;
        num_stu++;
    }
    
    double avg = scores_sum/num_stu;

    cout << "Average score is " << avg << endl;

    cout << "Students: " << endl;
    for(auto i = students.cbegin(); i != students.cend(); i++){
        if(i->score >= avg)
            cout << "\t" << i->name << endl;
    }
    cout << "have score greater than average!" << endl;
    
    ofstream myfile;
    myfile.open ("output_file.txt");
    
    myfile << "Average score is " << avg << endl;
    
    myfile << "Students: " << endl;
    for(auto i = students.cbegin(); i != students.cend(); i++){
        if(i->score >= avg)
            myfile << "\t" << i->name << endl;
    }
    myfile << "have score greater than average!" << endl;
    
    read.close();
    myfile.close();
    
    return 0;
}