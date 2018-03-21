
#include <stdio.h>
#include <math.h>
/* NAME- VIVEK RAJ; ROLL-1601CS49; DATE-17-01-2017*/
//Program to test collinearity/non-collinearity condition and finding area and type of triangle formed.
int main(void)
{
        float x1,x2,x3,y1,y2,y3;                 // assigning data type to variable coordinates point
        float area;                              // assigning data type to variable area of the triangle
        float length1,length2,length3,s,pytha;   // assigning data type to variable lengths of the triangle and some intermediate variables


        printf("Enter the points:\n");           // taking the coordinates of the points.
        printf("Point1:");
        scanf("%f,%f", &x1,&y1);
        printf("Point2:");
        scanf("%f,%f",&x2,&y2);
        printf("Point3:");
        scanf("%f,%f",&x3,&y3);


        length1=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);   //Calculating length of the formed triangle
        length3=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        length2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);

        length1=sqrt(length1);
        length2=sqrt(length2);
        length3=sqrt(length3);

        s=length1+length2+length3;                  //Calculating area of the formed triangle by Heron's formula
        s=s/2;
        area=s*(s-length1)*(s-length2)*(s-length3);
        area=sqrt(area);





if(area == 0 ){
        printf("The  points  are collinear.");      //checking if the given points are collinear or not
}



 if (length1>length2 && length1>length3){          //Checking the type of triangle

       pytha=(length2*length2)+(length3*length1);
       pytha=sqrt(pytha);


        if (pytha==length1)
            {printf("The points are non-collinear. The formed triangle is a right-angled triangle with area = %.2f.",area);} /* Printing the type of triangle*/
        if (pytha>length1)
            {printf("The points are non-collinear. The formed triangle is a acute-angled triangle with area = %.2f.",area);}
        if (pytha<length1)
            {printf("The points are non-collinear. The formed triangle is a obtuse-angled triangle with area = %.2f.",area);}
    }


 if (length2>length1 && length2>length3){

       pytha=(length1*length1)+(length3*length3);
       pytha=sqrt(pytha);


        if (pytha==length2)
            {printf("The points are non-collinear. The formed triangle is a right-angled triangle with area = %.2f.",area);} /* Printing the type of triangle*/
        if (pytha>length2)
            {printf("The points are non-collinear. The formed triangle is a acute-angled triangle with area = %.2f.",area);}
        if (pytha<length2)
            {printf("The points are non-collinear. The formed triangle is a obtuse-angled triangle with area = %.2f.",area);}
    }



 if (length3>length1 && length3>length2){

         pytha=(length1*length1)+(length2*length2);
       pytha=sqrt(pytha);



        if (pytha==length3)
            {printf("The points are non-collinear. The formed triangle is a right-angled triangle with area = %.2f.",area);} /* Printing the type of triangle*/
        if (pytha>length3)
            {printf("The points are non-collinear. The formed triangle is a acute-angled triangle with area = %.2f.",area);}
        if (pytha<length3)
            {printf("The points are non-collinear. The formed triangle is a obtuse-angled triangle with area = %.2f.",area);}
    }







return 0;

}
