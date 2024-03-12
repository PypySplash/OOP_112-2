
// https://cplusplus.com/reference/string/string/getline/
// https://www.geeksforgeeks.org/cpp-program-for-string-to-double-conversion/ 
// https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // for atof() to work
#include <string>

using namespace std;

struct Student{
    string name;
    double score;
};

int main()
{
    ifstream read("val_comma.txt");
    
    if(!read.is_open()){
        cout << "file cannot open!!" << endl;
        return 0;
    }
    
    Student st;
    
    vector<Student> students;
    
    double scores_sum = 0;
    int num_stu = 0;
    
    string score;

    while(getline(read, st.name, ',')){
    	getline(read, score, ',');
    	//st.score = atof(score.c_str()); // #include <cstdlib>
    	st.score = stold(score);  // #include <string> convert score to long double
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
    
    read.close();
    
    return 0;
}