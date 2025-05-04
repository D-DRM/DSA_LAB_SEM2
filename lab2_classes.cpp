#include <cstdio>
#include <iostream>
using namespace std;

class Shape{
private:
    double length,breadth,height;
public:
    //area of square
    void square_area(double side){
        length=side;
        cout<<"Area of square: "<<length*length<<"sq. units"<<endl;
    }
    //area of cube
    void cube_area(double side){
        length=side;
        cout<<"area of cube is :"<<(length*length*length)<<"sq units"<<endl;
    }
    //area of rectangle
    void rectangle_area(double l, double b){
        length=l;
        breadth=b;
        cout<<"area of the rectangle is:"<<length*breadth<<"sq. units"<<endl;
    }
    //area of cuboid
    void cuboid_area(double l, double b, double h){
        length=l;
        breadth=b;
        height=h;
        cout<<"Area of the cuboid is:"<<length*breadth*height<<"sq units"<<endl;
    }

};
//menu driven program:
void displaymenu(){
    cout<<"\n Menu: \n";
    cout << "a) Square\n";
    cout << "b) Cube\n";
    cout << "c) Rectangle\n";
    cout << "d) Cuboid\n";
    cout << "e) Exit\n";
    cout << "Enter your choice: ";
}

int main(){
    char choice;
    Shape shape;
    do{
        displaymenu();
        cin>>choice;
        switch (choice){
            case 'a':{
                double side;
                cout<<"enter side of square";
                cin>>side;
                shape.square_area(side);
                break;
            }
                

            case 'b':{
                double side;
                cout<<"enter side of the cube: \n";
                cin>>side;
                shape.cube_area(side);
                break;
            }

            case 'c':{
                double length, breadth;
                cout<<"enter length and breath of rectangle : ";
                cin>>length>>breadth;
                shape.rectangle_area(length,breadth);
                break;
            }
                
            case 'd':{
                double length, breadth, height;
                cout<<"enter length breadth and height of cuboid :\n";
                cin>>length>>breadth>>height;
                shape.cuboid_area(length,breadth,height);
                break;
            }
                

            case 'e':{
                cout<<"exciting program. \n";
                break;
            }
               

            default:
                cout<<"invalid choice, try again. \n";
        }
    }while(choice !='e');
    return 0;
}