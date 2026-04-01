#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter number of cource :";
  cin>>n;

  float grade,credit;
  float totalCredit= 0, totalGradePoints= 0;
  
  for(int i=1; i<=n; i++){
    cout<<"\nCourse"<<i<<endl;

    cout<<"enter grade: ";
    cin>>grade;

    cout<<"enter credit: ";
    cin>>credit;

    totalCredit += credit;
    totalGradePoints += grade * credit;

  }
    float cgpa = totalGradePoints / totalCredit;

    cout<<"\nTotal Credit = "<<totalCredit<<endl;
    cout<<"Total Grade Points = "<<totalGradePoints<<endl;
    cout<<"CGPA = "<<cgpa<<endl;   
     
     return 0;
}                       