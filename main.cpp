#include <iostream>
#include <cmath>

using namespace std;
void best_preferred_dia(int *scrp,int *ifshort, int *d)
{
    int i=0,min_scrp=10;
    int count=0;
    int flag=0;
    //for loop to find min possible scrap left
    for(i=0;i<3;i++)
    {
         if(scrp[i]==min_scrp)
        {
           count++;
        }
        if(scrp[i]<min_scrp)
            {
                min_scrp=scrp[i];
                count=1;
            }

    }

   int choice;
    if(count==1)
        cout<<"you have one best option for selection of diameter\n\n";
    else if(count==2)
        cout<<"You have two best possible options for selection of diameter\n\n";
    else
        cout<<"You can choose any diameter\n\n";

    //to find which diameter contributes to min scrap
    for(i=0;i<3;i++)
    {
        if(scrp[i]==min_scrp)
        {
            cout<<i+1<<"."<<d[i]<<"mm \n"<<endl;
        }
    }


//to give options to user to select
char wrongchoice;

while(1){
        flag=0;
cout<<"Choose your option: ";
cin>>choice;
    switch(choice)
    {
        case 1:
                if(scrp[choice-1]!=min_scrp)
                {
                    cout<<"its not the best option. still wanna continue? y/n:  ";
                    cin>>wrongchoice;
                    if(wrongchoice=='Y'||wrongchoice=='y')
                        {cout<<"10mm chosen";
                         flag=1;
                        }
                }
                else
                {
                    cout<<"You chose 10mm";
                    flag=1;

                }
                break;
        case 2: if(scrp[choice-1]!=min_scrp)
                {
                    cout<<"its not the best option. still wanna continue? y/n: ";
                    cin>>wrongchoice;
                    if(wrongchoice=='Y'||wrongchoice=='y')
                        {cout<<"12mm chosen";
                         flag=1;
                        }
                }
                else
                {
                    cout<<"You chose 12mm";
                    flag=1;

                }
                break;;
        case 3: if(scrp[choice-1]!=min_scrp)
                {
                    cout<<"its not the best option. still wanna continue? y/n:  ";
                    cin>>wrongchoice;
                    if(wrongchoice=='Y'||wrongchoice=='y')
                        {cout<<"16mm chosen";
                         flag=1;
                        }
                }
                else
                {
                    cout<<"You chose 16mm";
                    flag=1;

                }
                break;
        default:cout<<"Wrong option\n\n";
    }
    if(flag==1)
    break;
}
cout<<endl<<endl;

}
int main()
{

    float billet_length;
    int i;
    int scrap[3];
    int short_length_bar[3]={0,0,0};
    int dia[3]={10,12,16};

    cout<<"Enter Billet Length in meters:  ";
    cin>>billet_length;


     /* if there is an estimated loss given then the volume of billet changes as
         billet volume = billet_length*150*150*(1-(loss/100))

      */



        for(i=0;i<3;i++)
        {
             scrap[i]=int((billet_length)*150*150*4/(3.14*dia[i]*dia[i]))%12;
             if(scrap[i]>=7)
             {
                 scrap[i]=0;
                 short_length_bar[i]=1;
             }
        }

       // Info about bars being produced
     cout<<"AVAILABLE DIAMETERS ARE:\n\t1.10mm\n\t2.12mm\n\t3.16mm"<<endl;
       for(i=0;i<3;i++)
    {
        cout<<i+1<<"."<<dia[i]<<"mm \nscrap="<<scrap[i]<<"\nshort length bars="<<short_length_bar[i]<<endl<<endl;
    }

      //function to select best diameter for particular length
       best_preferred_dia(scrap,short_length_bar,dia);


    return 0;

}
