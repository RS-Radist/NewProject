//
//  main.cpp
//  Project Final
//
//  Created by iMac on 31.05.17.
//  Copyright © 2017 Project Final. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

struct AirPlane
{
    char* name;
    char* Number;
    char* MaxSpeed;
    int pasangersCapacity;
};

struct Coordinates

{

    int x;
    int y;
};

struct Plane_Dep
{
    union
    {
        int hour;
        int min;
    };
    Coordinates Start;
    Coordinates End;
    AirPlane FINAL;
    
    
};
#pragma pac(1)

int main()
{
    FILE * SAVE = fopen("AirPlane.txt", "w+");
    srand((time_t)NULL);
    size_t flotSize = 0;
    AirPlane* flot = NULL;
    AirPlane* numberFlot = NULL;
    AirPlane* speedFlot= NULL;
    AirPlane* pasangers=new AirPlane[flotSize];
  
    Coordinates* Start_Cor=new Coordinates[flotSize];
    Coordinates* End_Cor=new Coordinates[flotSize];
    
    Plane_Dep* hour_Stuct=new Plane_Dep[flotSize];
    Plane_Dep* hour_Stuct1=new Plane_Dep[flotSize];
    Plane_Dep* min_Desimal=new Plane_Dep[flotSize];
    Plane_Dep* min_Desimal1=new Plane_Dep[flotSize];
    
    
   
    
    
    int action = 0;

    while(action != 5)
    {
        std::cout
        << "Press 1 for add ariplane information\n"
        << "Press 2 for show airplane information\n"
        << "Press 3 for add Coordinate system\n"
        << "Press 4 Scan Coordinates\n"
        << "Press 5 for exit\n";
        std::cin >> action;
        
        switch(action)
        {
            case 1 :
            {
                if(flot == NULL&& numberFlot==NULL && speedFlot==NULL)
                {
                    
                    
         //Название самолета
                    
                    flot = new AirPlane();
                    char buff[50] = {0};
                    std::cout << "Enter airplane name: ";
                    std::cin.get();
                    std::cin.getline(buff, 50);
                    flot->name = new char[strlen(buff)];
                    strcpy(flot->name, buff);
         //Номер
                    
                    numberFlot = new AirPlane();
                    char buffNumber[50] = {0};
                    std::cout<<"Enter airplane Number № ";
                    std::cin.getline(buffNumber,50);
                    numberFlot->Number=new char [strlen(buffNumber)];
                    strcpy(numberFlot->Number, buffNumber);
                    
        // Скорость
                    
                    speedFlot = new AirPlane();
                    char buffSpeed[50] = {0};
                    std::cout<<"Enter airplane Max Speed  ";
                    std::cin.getline(buffSpeed,50);
                    speedFlot->MaxSpeed=new char [strlen(buffSpeed)];
                    strcpy(speedFlot->MaxSpeed, buffSpeed);
                    
        

        // кол-во пассажиров
                    
                    flotSize++;
                    std::cout<<"Enter airplane Max Pasangers  ";
                
                    if (flotSize==1)
                    {
                        
                        std::cin>>pasangers[0].pasangersCapacity;
                        
                        
                    }
                }
                
                else
                {
                    flotSize++;
                    
         //Название самолета
                    
                    AirPlane* temp = new AirPlane[flotSize];
                    memcpy(temp, flot, (flotSize-1)*sizeof(AirPlane));
                    delete[] flot;
                    char buff[50] = {0};
                    std::cout << "Enter airplane name: ";
                    std::cin.get();
                    std::cin.getline(buff, 50);
                    temp[flotSize-1].name = new char[strlen(buff)];
                    strcpy(temp[flotSize-1].name, buff);
                    flot=temp;
                    
         //Номер
            
                    AirPlane * active=new AirPlane[flotSize];
                    memcpy(active, numberFlot, (flotSize-1)*sizeof(AirPlane));
                    delete [] numberFlot;
                    char buffNumber[50]={0};
                    std::cout<<"Enter airplane Number № ";
                    std::cin.getline(buffNumber,50);
                    active[flotSize-1].Number=new char [strlen(buffNumber)];
                    strcpy(active[flotSize-1].Number,buffNumber);
                    numberFlot=active;
                    
        // Скорость
                    AirPlane * Speed = new AirPlane[flotSize];
                    memcpy(Speed, speedFlot, (flotSize-1)*sizeof(AirPlane));
                    delete [] speedFlot;
                    char buffSpeed[50]={0};
                    std::cout<<"Enter airplane Max Speed ";
                    std::cin.getline(buffSpeed,50);
                    Speed[flotSize-1].MaxSpeed=new char [strlen(buffSpeed)];
                    strcpy(Speed[flotSize-1].MaxSpeed,buffSpeed);
                    speedFlot=Speed;
                    

                    
        // кол-во пассажиров
                    std::cout<<"Enter airplane Max Pasangers  ";
                    std::cin>>pasangers[flotSize-1].pasangersCapacity;
                    
                 
                }
        
                
            }
                break;
                
                
                
      // На ЭКРАН
            case 2:
            {
                for (size_t i=0;i<flotSize;++i)
                {
                    std::cout<<"PLANE № "<<1+i<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<"FLOT....."<<" [ "<<flot[i].name<<" ] "<<std::endl;
                    std::cout<<"NUMBER..."<<" [ "<<numberFlot[i].Number<<" ] "<<std::endl;
                    std::cout<<"MAXSPEED."<<" [ "<<speedFlot[i].MaxSpeed<<" ] "<<std::endl;
                    std::cout<<"PASANGERS"<<" [ "<<pasangers[i].pasangersCapacity<<" ] "<<std::endl;
    
                }
                
                
                std::cin.get();
            }
                break;
        
            // Информация по маршруту
                
            case 3:
            {
                if (Start_Cor==NULL && End_Cor==NULL && hour_Stuct && NULL)
                {
                    
            //Рандом на время
                        hour_Stuct[0].hour=0+arc4random()%2;
                        if (hour_Stuct[0].hour==1&&hour_Stuct[0].hour==0)
                        {
                        hour_Stuct1[0].hour=0+arc4random()%9;
                        }
                        else
                        {
                        hour_Stuct1[0].hour=0+arc4random()%4;
                        }

                        min_Desimal[0].min=0+arc4random()%5;
                        min_Desimal1[0].min=0+arc4random()%9;
      
                
                flotSize++;
                
                
               
                std::cout<<"Enter the coordinates --X-- of the beginning of the route № "<<flotSize<<std::endl;
                    std::cin>>Start_Cor[0].x;
                std::cout<<"Enter the coordinates --Y-- of the beginning of the route № "<<flotSize<<std::endl;
                    std::cin>>Start_Cor[0].y;
          
                   
                        
                std::cout<<"Enter the coordinates --X-- of the end of the route № "<<flotSize<<" Plane "<<std::endl;
                    std::cin>>End_Cor[0].x;
                std::cout<<"Enter the coordinates --Y-- of the end of the route № "<<flotSize<<" Plane "<<std::endl;
                    std::cin>>End_Cor[0].y;
                        
                    
                    
                flotSize++;
                    
                }
                
                else
                    
                {
            
                    flotSize++;
                    
                    hour_Stuct[flotSize-1].hour=0+arc4random()%2;
                    if (hour_Stuct[flotSize-1].hour==1 && hour_Stuct[0].hour==0)
                    {
                        hour_Stuct1[flotSize-1].hour=0+arc4random()%9;
                    }
                    else
                    {
                        hour_Stuct1[flotSize-1].hour=0+arc4random()%4;
                    }
                    
                    min_Desimal[flotSize-1].min=0+arc4random()%5;
                    min_Desimal1[flotSize-1].min=0+arc4random()%9;
                    
                    
                    
                        std::cout<<"Enter the coordinates --X-- of the beginning of the route № "<<flotSize<<std::endl;
                        std::cin>>Start_Cor[flotSize-1].x;
                        std::cout<<"Enter the coordinates --Y-- of the beginning of the route № "<<flotSize<<std::endl;
                        std::cin>>Start_Cor[flotSize-1].y;
                    
                    
                    
                    
                    
                        std::cout<<"Enter the coordinates --X-- of the end of the route № "<<flotSize<<" Plane "<<std::endl;
                        std::cin>>End_Cor[flotSize-1].x;
                        std::cout<<"Enter the coordinates --Y-- of the end of the route № "<<flotSize<<" Plane "<<std::endl;
                        std::cin>>End_Cor[flotSize-1].y;
                    
                    
                }
            }
                break;
                
                
            case 4:
            {
                for (int i=0;i<flotSize;++i)
                {
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    std::cout<< "TIME SORTIE " << "№" <<1+i<<"    "<<hour_Stuct[i].hour<<hour_Stuct1[i].hour<<" : "<<min_Desimal[i].min<<min_Desimal1[i].min;
                    std::cout<<std::endl;
                    std::cout<<"Point Start  - "<<1+i<<" Coordinates ="<<" [ "<<Start_Cor[i].x<<" ] "<<" [ "<<Start_Cor[i].y<<" ] "<<std::endl;
                    std::cout<<"Point Finish - "<<1+i<<" Coordinates ="<<" [ "<<End_Cor[i].x<<" ] "<<" [ "<<End_Cor[i].x<<" ] "<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<"....................................................................................."<<std::endl;
                    
                }
                
                for (int i=0;i<flotSize;++i)
                {
                    printf ("%d" ,hour_Stuct[i].hour);
                    fwrite(&hour_Stuct[i].hour, sizeof(hour_Stuct), 1, SAVE);
                    fwrite(&hour_Stuct1[i].hour, 100, 1, SAVE);
                    /*
                    fwrite(&Start_Cor[i].y, 50, 1, SAVE);
                    fwrite(&End_Cor[i].x, 50, 1, SAVE);
                    fwrite(&End_Cor[i].y, 50, 1, SAVE);
                     */
                }
                

            }
            break;
                
                
                
            default :
            {
                std::cout << "Wrong command\n";
            }
                
        }
    }
    
    

    fclose(SAVE);
}
