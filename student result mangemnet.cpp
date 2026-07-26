#include <iostream>
#include<string>
using namespace std;
struct student{
    int rollno;
    string name;
    float physics;
    float chemistry;
    float maths;
    float total;
    float percentage;
    string grade;
};
string calculategrade(float percentage){
    if (percentage>=90)
        return "A+";
    else if (percentage>=80)
        return "A";
    else if (percentage>=70)
        return "B";
    else if (percentage>=60)
        return "C";
    else if (percentage>=50)
        return "D";
    else
        return "F";
}
int main(){
    student s[100];
    int count=0;
    int choice;
    do{
        cout<<"\n===student result management system===\n";
        cout<<"1. Add student\n";
        cout<<"2. Display student\n";
        cout<<"3. Search student\n";
        cout<<"4. update student\n";
        cout<<"5. delete student\n";
        cout<<"6. Exit\n";
        cout<<"\n enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\n enter roll number:";
                cin>>s[count].rollno;
                cin.ignore();
                cout<<"enter student name: ";
                getline(cin,s[count].name);
                cout<<"enter physice marks: ";
                cin>>s[count].physics;
                cout<<"enter chemistry marks: ";
                cin>>s[count].chemistry;
                cout<<"enter mathematics marks: ";
                cin>>s[count].maths;
                s[count].total=s[count].physics+s[count].chemistry+s[count].maths;
                s[count].percentage=s[count].total/3;
                s[count].grade=calculategrade(s[count].percentage);
                count++;
                cout<<"\nStudent added successfully!\n";
                break;
            case 2:
                if (count==0){
                    cout<<"\nNo student record found !\n";
                    break;
                }
                cout<<"\n===Student Records===\n";
                for (int i=0;i<count;i++){
                    cout<<"\nStudent "<<i+1<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"roll number: "<<s[i].rollno<<endl;
                    cout<<"name: "<<s[i].name<<endl;
                    cout<<"physice: "<<s[i].physics<<endl;
                    cout<<"chemistry: "<<s[i].chemistry<<endl;
                    cout<<"mathematics: "<<s[i].maths<<endl;
                    cout<<"total marks: "<<s[i].total<<endl;
                    cout<<"percentage: "<<s[i].percentage<<"%"<<endl;
                    cout<<"grade: "<<s[i].grade<<endl;
                }
                break;
            case 3:
                {int roll;
                bool found=false;
                cout<<"\nEnter roll number to search: ";
                cin>>roll;
                for (int i=0;i<count;i++){
                    if (s[i].rollno==roll){
                        cout<<"\n===Student Found===\n";
                        cout<<"roll number : "<<s[i].rollno<<endl;
                        cout<<"name : "<<s[i].name<<endl;
                        cout<<"physics : "<<s[i].physics<<endl;
                        cout<<"chemistry : "<<s[i].chemistry<<endl;
                        cout<<"mathematics : "<<s[i].maths<<endl;
                        cout<<"total : "<<s[i].total<<endl;
                        cout<<"percentage : "<<s[i].percentage<<endl;
                        cout<<"grade : "<<s[i].grade<<endl;
                        found=true;
                        break;
                    }
                }
                if (!found){
                    cout<<"\nStudent record not found!\n";
                }
                break;
                }
            case 4:
                {
                    int roll;
                    bool found= false;
                    cout<<"\nEnter roll number to update: ";
                    cin>>roll;
                    for (int i=0;i<count;i++){
                        if(s[i].rollno==roll){
                            cout<<"\nEnter new physics marks: ";
                            cin>>s[i].physics;
                            cout<<"\nEnter new chemistry marks: ";
                            cin>>s[i].chemistry;
                            cout<<"\nEnter new mathematics marks: ";
                            cin>>s[i].maths;
                            s[i].total=s[i].physics+s[i].chemistry+s[i].maths;
                            s[i].percentage=s[i].total/3;
                            s[i].grade=calculategrade(s[i].percentage);
                            cout<<"\nStudent record updated successfully !!\n";
                            found=true;
                            break;
                        }
                    }
                    if (!found){
                        cout<<"\nStudent record not found !\n";
                    }
                    break;
                }
            case 5:
                {
                    int roll;
                    bool found=false;
                    cout<<"\nEnter roll number to delete: ";
                    cin>>roll;
                    for(int i =0;i<count;i++){
                        if (s[i].rollno==roll){
                            for (int j=i;j<count-1;j++){
                                s[j]=s[j+1];
                            }
                            count--;
                            cout<<"\nStudent record delected successfully !\n";
                            found=true;
                            break;
                        }
                    }
                    if (!found){
                        cout<<"\nSudent record not found !\n";
                    }
                    break;
                }
            case 6:
                cout<<"\nthankyou !\n";
                break;
            default:
                cout<<"\nInvalid choice! try again.\n";
        }
    }while(choice !=6);
    
    return 0;
}
