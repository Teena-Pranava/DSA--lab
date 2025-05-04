// Program to calculate area of square,cube,rectangle,cuboid

#include<stdio.h>
#include<stdlib.h>

class areas {
    private:
        int length;
        int breadth;
        int height;

    public:
        int square_area(int length){
            return (length*length);
        }
        int cube_area(int length){
            return (6*length*length);
        }
        int rectangle_area(int length,int breadth){
            return (length*breadth);
        }
        int cuboid_area(int length,int breadth,int height){
            return ((2*(length*breadth)+(breadth*height)+(length*height)));
        }
};

int main(){
    int choice;
    areas shape;
    int area;

    do{
        printf("Enter 1 for area of square:\n");
        printf("Enter 2 for area of cube:\n");
        printf("Enter 3 for area of rectangle:\n");
        printf("Enter 4 for area of cuboid:\n");
        printf("Enter 5 to End the Progarm:\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                int square_side;
                printf("Enter the side:");
                scanf("%d",&square_side);
                area=shape.square_area(square_side);
                printf("Area of square is %d\n\n",area);
                break;
            case 2:
                int cube_side;
                printf("Enter the side :");
                scanf("%d",&cube_side);
                area=shape.cube_area(cube_side);
                printf("Area of cube is %d\n\n",area);
                break;
            case 3:
                int rectangle_length;
                int rectangle_breadth;
                printf("Enter length of rectangle:");
                scanf("%d",&rectangle_length);
                printf("Enter breadth of rectangle:");
                scanf("%d",&rectangle_breadth);
                area=shape.rectangle_area(rectangle_length,rectangle_breadth);
                printf("Area of rectangle is %d\n\n",area);
                break;
            case 4:
                int cuboid_length;
                int cuboid_breadth;
                int cuboid_height;

                printf("Enter length of cuboid:");
                scanf("%d",&cuboid_length);
                printf("Enter breadth of cuboid:");
                scanf("%d",&cuboid_breadth);
                printf("Enter height of cuboid:");
                scanf("%d",&cuboid_height);
                area=shape.cuboid_area(cuboid_length,cuboid_breadth,cuboid_height);
                printf("Area of cuboid is %d\n\n",area);
                break;
            case 5:
                printf("Exit");
                return 0;
            default:
                printf("Enter valid choice\n");
                break;
                

        }
    }
    while(choice!=5);

}